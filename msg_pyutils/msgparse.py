#!/usr/bin/env python
from __future__ import print_function
from builtins import range
from builtins import object

import errno
import operator
import os
import sys
import time
import xml.parsers.expat
import copy

class MSGParseError(Exception):
    def __init__(self, message, inner_exception=None):
        self.message = message
        self.inner_exception = inner_exception
        self.exception_info = sys.exc_info()
    def __str__(self):
        return self.message

    def gen_test_value(self, i):
        '''generate a testsuite value for a MAVField'''
        if self.const_value:
            return self.const_value
        elif self.type == 'float':
            return 17.0 + i
        elif self.type == 'double':
            return 123.0 + i
        elif self.type == 'char':
            return chr(ord('A') + (i)%26)
        elif self.type in [ 'int8_t', 'uint8_t' ]:
            return (5 + i) & 0xFF
        elif self.type in ['int16_t', 'uint16_t']:
            return (17235 + i) & 0xFFFF
        elif self.type in ['int32_t', 'uint32_t']:
            return (963497464 + i)&0xFFFFFFFF
        elif self.type in ['int64_t', 'uint64_t']:
            return 93372036854775807 + i
        else:
            raise MSGParseError('unknown type %s' % self.type)

    def set_test_value(self):
        '''set a testsuite value for a MAVField'''
        if self.array_length:
            self.test_value = []
            for i in range(self.array_length):
                self.test_value.append(self.gen_test_value(i))
        else:
                self.test_value = self.gen_test_value(0)
        if self.type == 'char' and self.array_length:
            v = ""
            for c in self.test_value:
                v += c
            self.test_value = v[:-1]

class CMSGField(object):
    def __init__(self, attrs):
        self.name = attrs['name']
        self.name_upper = self.name.upper()
        self.description = ''
        self.array_length = 0
        self.enum = attrs.get('enum','')
        self.display = attrs.get('display','')
        self.units = attrs.get('units','')
        self.omit_arg = False
        self.const_value = None
        self.print_format = attrs.get('print_format',None)
        self.default_value = attrs.get('default','')
        self.nostr = eval(attrs.get('nostr','False'))
        self.nodecl = eval(attrs.get('nodecl','False'))
        self.noset = eval(attrs.get('noset','False'))
        self.noget = eval(attrs.get('noget','False'))
        if self.units:
            self.units = '[' + self.units + ']'
        type = attrs['type']
        lengths = {
        'float'    : 4,
        'double'   : 4,
        'char'     : 1,
        'int8_t'   : 1,
        'uint8_t'  : 1,
        'int16_t'  : 2,
        'uint16_t' : 2,
        'int32_t'  : 4,
        'uint32_t' : 4,
        'int64_t'  : 8,
        'uint64_t' : 8,
        }

        aidx = type.find("[")
        self.array_suffix = ''
        if aidx != -1:
            assert type[-1:] == ']'
            self.array_length = int(type[aidx+1:-1])
            type = type[0:aidx]
            if type == 'array':
                type = 'int8_t'
            self.array_suffix = ('[%d]'%self.array_length)
        if type in lengths:
            self.type_length = lengths[type]
            self.type = type
        elif (type+"_t") in lengths:
            self.type_length = lengths[type+"_t"]
            self.type = type+'_t'
        else:
            raise MSGParseError("unknown type '%s'" % type)
        if self.array_length != 0:
            self.wire_length = self.array_length * self.type_length
        else:
            self.wire_length = self.type_length
        self.type_upper = self.type.upper()
class MSGType(object):
    def __init__(self, name, id, module_name, linenumber , description=''):
        self.name = name
        self.class_name = 'Msg_'+self.name
        self.name_lower = name.lower()
        self.basename_upper = name.upper()
        self.linenumber = linenumber
        self.id = int(id)
        self.description = description
        self.fields = []
        self.cfields = []
        self.fieldnames = []
        self.default_fields = []
        self.extensions_start = None
        self.needs_pack = False
        self.module_name = module_name
    def base_fields(self):
        '''return number of non-extended fields'''
        if self.extensions_start is None:
            return len(self.fields)
        return len(self.fields[:self.extensions_start])

class MAVEnumParam(object):
    def __init__(self, index, description='', label='', units='', enum='', increment='', minValue='', maxValue='', reserved=False, default=''):
        self.index = index
        self.description = description
        self.label = label
        self.units = units
        self.enum = enum
        self.increment = increment
        self.minValue = minValue
        self.maxValue = maxValue
        self.reserved = reserved
        self.default = default
        if self.reserved and not self.default:
            self.default = '0'
        self.set_description(description)

    def set_description(self, description):
        if not description.strip() and self.reserved:
            self.description = 'Reserved (default:%s)' % self.default
        else:
            self.description = description

class MAVEnumEntry(object):
    def __init__(self, name, value, description='', end_marker=False, autovalue=False, origin_file='', origin_line=0):
        self.name = name
        self.value = value
        self.description = description
        self.param = []
        self.end_marker = end_marker
        self.autovalue = autovalue  # True if value was *not* specified in XML
        self.origin_file = origin_file
        self.origin_line = origin_line

class MAVEnum(object):
    def __init__(self, name, linenumber, description=''):
        self.name = name
        self.description = description
        self.entry = []
        self.start_value = None
        self.highest_value = 0
        self.linenumber = linenumber

class MSGXML(object):
    '''parse a mavlink XML file'''
    def __init__(self, filename, wire_protocol_version=None):
        self.filename = filename
        self.basename = os.path.basename(filename)
        if self.basename.lower().endswith(".xml"):
            self.basename = self.basename[:-4]
        self.basename_upper = self.basename.upper()
        self.message = []
        self.enum = []
        # we use only the day for the parse_time, as otherwise
        # it causes a lot of unnecessary cache misses with ccache
        self.parse_time = time.strftime("%a %b %d %Y")
        self.version = 2
        self.include = []
        self.wire_protocol_version = wire_protocol_version
        self.sort_fields = False

        in_element_list = []

        def check_attrs(attrs, check, where):
            for c in check:
                if c not in attrs:
                    raise MSGParseError('expected missing %s "%s" attribute at %s:%u' % (
                        where, c, filename, p.CurrentLineNumber))

        def start_element(name, attrs):
            in_element_list.append(name)
            in_element = '.'.join(in_element_list)
            #print in_element
            if in_element == "msg.messages.message":
                check_attrs(attrs, ['name', 'id','module'], 'message')
                self.message.append(MSGType(attrs['name'], len(self.message),attrs['module'], p.CurrentLineNumber))
            elif in_element == "msg.messages.message.extensions":
                self.message[-1].extensions_start = len(self.message[-1].fields)
            elif in_element == "msg.messages.message.field":
                check_attrs(attrs, ['name', 'type'], 'field')
                new_cfield = CMSGField(attrs)
                self.message[-1].cfields.append(new_cfield)
            elif in_element == "msg.enums.enum":
                check_attrs(attrs, ['name'], 'enum')
                self.enum.append(MAVEnum(attrs['name'], p.CurrentLineNumber))
            elif in_element == "msg.enums.enum.entry":
                check_attrs(attrs, ['name'], 'enum entry')
                # determine value and if it was automatically assigned (for possible merging later)
                if 'value' in attrs:
                    value = eval(attrs['value'])
                    autovalue = False
                else:
                    value = self.enum[-1].highest_value + 1
                    autovalue = True
                # check lowest value
                if (self.enum[-1].start_value is None or value < self.enum[-1].start_value):
                    self.enum[-1].start_value = value
                # check highest value
                if (value > self.enum[-1].highest_value):
                    self.enum[-1].highest_value = value
                # append the new entry
                self.enum[-1].entry.append(MAVEnumEntry(attrs['name'], value, '', False, autovalue, self.filename, p.CurrentLineNumber))
            elif in_element == "msg.enums.enum.entry.param":
                check_attrs(attrs, ['index'], 'enum param')
                self.enum[-1].entry[-1].param.append(
                                                MAVEnumParam(attrs['index'], 
                                                        label=attrs.get('label', ''), units=attrs.get('units', ''), 
                                                        enum=attrs.get('enum', ''), increment=attrs.get('increment', ''), 
                                                        minValue=attrs.get('minValue', ''), 
                                                        maxValue=attrs.get('maxValue', ''), default=attrs.get('default', '0'), 
                                                        reserved=attrs.get('reserved', False) ))

        def is_target_system_field(m, f):
            if f.name == 'target_system':
                return True
            if m.name == "MANUAL_CONTROL" and f.name == "target":
                return True
            return False

        def end_element(name):
            in_element_list.pop()

        def char_data(data):
            in_element = '.'.join(in_element_list)
            if in_element == "msg.messages.message.description":
                self.message[-1].description += data
            elif in_element == "msg.messages.message.field":
                if self.message[-1].extensions_start is None or self.allow_extensions:
                    self.message[-1].cfields[-1].description += data
            elif in_element == "msg.enums.enum.description":
                self.enum[-1].description += data
            elif in_element == "msg.enums.enum.entry.description":
                self.enum[-1].entry[-1].description += data
            elif in_element == "msg.enums.enum.entry.param":
                self.enum[-1].entry[-1].param[-1].description += data
            elif in_element == "msg.version":
                self.version = int(data)
            elif in_element == "msg.include":
                self.include.append(data)

        f = open(filename, mode='rb')
        p = xml.parsers.expat.ParserCreate()
        p.StartElementHandler = start_element
        p.EndElementHandler = end_element
        p.CharacterDataHandler = char_data
        p.ParseFile(f)
        f.close()
   
        self.class_num = len(self.message)
        #Post process to add reserved params (for docs)
        for current_enum in self.enum:
            if not 'MAV_CMD' in current_enum.name:
                continue
            for enum_entry in current_enum.entry:
                if len(enum_entry.param) == 7:
                    continue
                params_dict=dict()
                for param_index in range (1,8):
                    params_dict[param_index] = MAVEnumParam(param_index, label='', units='', enum='', increment='', 
                                                        minValue='', maxValue='', default='0', reserved='True')

                for a_param in enum_entry.param:
                    params_dict[int(a_param.index)] = a_param
                enum_entry.param=params_dict.values()
        
        #get share_default
        self.share_default = None
        for m in self.message:
            if m.name == 'share_default':
                self.share_default = copy.deepcopy(m)
                self.message.remove(m)

        for m in self.message:
            m.wire_length = 0
            m.wire_min_length = 0
            m.fields = []
            m.fieldnames = []
            m.fieldlengths = []
            m.ordered_fieldnames = []
            m.ordered_fieldtypes = []
            m.class_string = ''
            m.array_fields = []
            m.scalar_fields = []
            m.decl_fields = []
            m.default_fields = []
            m.set_fields = []
            m.get_fields = []
            m.set_fields_scalar = []
            m.set_fields_array = []
            m.get_fields_scalar = []
            m.get_fields_array = []
            m.set_wire = 0
            m.get_wire = 0
            #classify the fields
            for f in m.cfields:
                if not f.nodecl:
                    m.decl_fields.append(f)
                if not f.nostr:
                    if not f.noset:
                        m.set_fields.append(copy.deepcopy(f))
                    if not f.noget:
                        m.get_fields.append(copy.deepcopy(f))
                    m.fields.append(f)
                if f.default_value != '':
                    m.default_fields.append(f)
                
            for f in self.share_default.cfields:
                field = copy.deepcopy(f)
                for ft in m.cfields:
                    if field.name == ft.name:
                        field.default_value = ft.default_value
                if field.name == 'msg_id':
                    field.default_value = m.id
                m.default_fields.append(field)
             
            #first deal the set fields
            for f in m.set_fields:
                if f.array_length != 0:
                    m.set_fields_array.append(f)
                else:
                    m.set_fields_scalar.append(f)
                f.wire_offset = m.set_wire
                m.set_wire += f.wire_length
            for f in m.get_fields:
                if f.array_length != 0:
                    m.get_fields_array.append(f)
                else:
                    m.get_fields_scalar.append(f)
                f.wire_offset = m.get_wire
                m.get_wire += f.wire_length
                m.class_string += (f.type+f.array_suffix+' '+f.name+';')
                
            m.num_fields = len(m.fieldnames)

    def __str__(self):
        return "MAVXML for %s from %s (%u message, %u enums)" % (
            self.basename, self.filename, len(self.message), len(self.enum))


def message_checksum(msg):
    '''calculate a 8-bit checksum of the key fields of a message, so we
       can detect incompatible XML changes'''
    from mav_pyutils.mavcrc import x25crc
    crc = x25crc()
    crc.accumulate_str(msg.name + ' ')
    # in order to allow for extensions the crc does not include
    # any field extensions
    crc_end = msg.base_fields()
    for i in range(crc_end):
        f = msg.ordered_fields[i]
        crc.accumulate_str(f.type + ' ')
        crc.accumulate_str(f.name + ' ')
        if f.array_length:
            crc.accumulate([f.array_length])
    return (crc.crc&0xFF) ^ (crc.crc>>8)

def merge_enums(xml):
    '''merge enums between XML files'''
    emap = {}
    for x in xml:
        newenums = []
        for enum in x.enum:
            if enum.name in emap:
                emapitem = emap[enum.name]
                # check for possible conflicting auto-assigned values after merge
                if (emapitem.start_value <= enum.highest_value and emapitem.highest_value >= enum.start_value):
                    for entry in emapitem.entry:
                        # correct the value if necessary, but only if it was auto-assigned to begin with
                        if entry.value <= enum.highest_value and entry.autovalue is True:
                            entry.value = enum.highest_value + 1
                            enum.highest_value = entry.value
                # merge the entries
                emapitem.entry.extend(enum.entry)
                if not emapitem.description:
                    emapitem.description = enum.description
                print("Merged enum %s" % enum.name)
            else:
                newenums.append(enum)
                emap[enum.name] = enum
        x.enum = newenums
    for e in emap:
        # sort by value
        emap[e].entry = sorted(emap[e].entry,
                               key=operator.attrgetter('value'),
                               reverse=False)
        # add a ENUM_END
        emap[e].entry.append(MAVEnumEntry("%s_ENUM_END" % emap[e].name,
                                            emap[e].entry[-1].value+1, end_marker=True))

def check_duplicates(xml):
    '''check for duplicate message IDs'''

    merge_enums(xml)

    msgmap = {}
    msg_name_map = {}
    enummap = {}
    for x in xml:
        for m in x.message:
            key = m.id
            if key in msgmap:
                print("ERROR: Duplicate message id %u for %s (%s:%u) also used by %s" % (
                    m.id,
                    m.name,
                    x.filename, m.linenumber,
                    msgmap[key]))
                return True
            fieldset = set()
            for f in m.fields:
                if f.name in fieldset:
                    print("ERROR: Duplicate field %s in message %s (%s:%u)" % (
                        f.name, m.name,
                        x.filename, m.linenumber))
                    return True
                fieldset.add(f.name)
            msgmap[key] = '%s (%s:%u)' % (m.name, x.filename, m.linenumber)
            # Check for duplicate message names
            if m.name in msg_name_map:
                print("ERROR: Duplicate message name %s for id:%u (%s:%u) also used by %s" % (
                    m.name,
                    m.id,
                    x.filename, m.linenumber,
                    msg_name_map[m.name]))
                return True
            msg_name_map[m.name] = '%s (%s:%u)' % (m.id, x.filename, m.linenumber)
        for enum in x.enum:
            for entry in enum.entry:
                if entry.autovalue is True and "common.xml" not in entry.origin_file:
                    print("Note: An enum value was auto-generated: %s = %u" % (entry.name, entry.value))
                s1 = "%s.%s" % (enum.name, entry.name)
                s2 = "%s.%s" % (enum.name, entry.value)
                if s1 in enummap or s2 in enummap:
                    print("ERROR: Duplicate enum %s:\n\t%s = %s @ %s:%u\n\t%s" % (
                        "names" if s1 in enummap else "values",
                        s1, entry.value, entry.origin_file, entry.origin_line,
                        enummap.get(s1) or enummap.get(s2)))
                    return True
                enummap[s1] = enummap[s2] = "%s.%s = %s @ %s:%u" % (enum.name, entry.name, entry.value, entry.origin_file, entry.origin_line)

    return False



def total_msgs(xml):
    '''count total number of msgs'''
    count = 0
    for x in xml:
        count += len(x.message)
    return count

def mkdir_p(dir):
    try:
        os.makedirs(dir)
    except OSError as exc:
        if exc.errno != errno.EEXIST:
            raise

# check version consistent
# add test.xml
# finish test suite
# printf style error macro, if defined call errors
