#!/usr/bin/env python
'''
parse a MAVLink protocol XML file and generate a C implementation

Copyright Andrew Tridgell 2011
Released under GNU GPL version 3 or later
'''
from __future__ import print_function
from future.utils import iteritems

from builtins import range
from builtins import object

import os
from msg_pyutils import msgtemplate, msgparse

t = msgtemplate.MAVTemplate()

def generate_msg_x_header(directory, xml):
    f = open(os.path.join(directory, "headers\\%s.h"%xml.class_name), mode='w')
    t.write(f, '''
#ifndef ${basename_upper}_H
#define ${basename_upper}_H
#include "Class_Base.h"

class ${class_name} : public Class_Base_Msg {
public:
    ${{ordered_fields:${type} ${name}${array_suffix}; /*< ${units} ${description}*/
    }}
    ${class_name}() {
        ${{default_value:${dname}=${dvalue};
        }}
    }
    int get_str() {
        char * str = &(public_buffer[public_buffer_pos]);
        ${{scalar_fields:_msg_put_${type}(str, ${wire_offset}, ${name});
        }}
        ${{array_fields:_msg_put_${type}_array(str, ${wire_offset}, ${name}, ${array_length});
        }}
        return ${wire_length};
    }
    void set_str(const char * buffer) {
        ${{scalar_fields:${name} = _MSG_RETURN_${type}(buffer,${wire_offset});
        }}
        ${{array_fields:_MSG_RETURN_${type}_array(buffer,${name},${array_length},${wire_offset});
        }}

    }
};
extern char ${class_name}_char[];
extern ${class_name} ${name_lower};
#endif
''',xml)

    f.close()

def generate_msg_x_src(directory,xml):
    f = open(os.path.join(directory, "sources\\%s.cpp"%xml.class_name), mode='w')
    t.write(f, '''
#include "Modules/Logger/headers/${class_name}.h"
char ${class_name}_char[] = "${class_string}";
''',xml)
    f.close()

def generate_msg_header(directory,xml):
    f = open(os.path.join(directory,"msg_header.h"), mode='w')
    t.write(f,'''
#ifndef LOGGER_MEASSAGE_HEADER
#define LOGGER_MEASSAGE_HEADER
#include "stdint.h"
#include "Class_Base.h"
extern void msg_init();
extern void msg_print_check();
extern void msg_disp_check();
extern char public_buffer[512];
extern int public_buffer_pos;
${{message:#include "Modules/Logger/headers/${class_name}.h"
}}
${{message:extern ${class_name} ${name_lower};
}}
#endif
    ''',xml)
    f.close()

def generate_msg_src(directory,xml):
    f = open(os.path.join(directory,"msg_source.cpp"),mode='w')
    t.write(f,'''
#include "Modules/Logger/msg_header.h"
#include "Modules/Logger/Logger.h"
#include "Modules/Clock/Clock.h"
#include "Modules/SD/SD_Driver.h"
#include "string.h"
char public_buffer[512];
int public_buffer_pos;
Class_Base_Msg * msg_points[${class_num}+1];
void msg_print_check() {
    int pos = 0,len = 0;
    while(msg_points[pos] != NULL) {
        if (msg_points[pos]->print_freq > 0) {
            uint32_t timegap = 1e7 / msg_points[pos]->print_freq;
            if (clk.time()-msg_points[pos]->print_timestamp > timegap) {
                msg_points[pos]->print_timestamp = clk.time();
                public_buffer_pos = 5;
                len = msg_points[pos]->get_str() + 2;
                public_buffer[0] =  (len & 0xff);
                public_buffer[1] = (len >> 8) & 0xff;
                public_buffer[2] = ULOGTYPE_DATA; 
                public_buffer[3] = msg_points[pos]->msg_id & 0x0ff;
                public_buffer[4] = (msg_points[pos]->msg_id >> 8) & 0x0ff;
                sd0.sd_printf(public_buffer,len + 3);
            }
        }
        pos++;
    }
}

void msg_disp_check() {}

${{message:${class_name} ${name_lower};
}}

void msg_init() {
    ${{message:msg_points[${id}] = &${name_lower};
    }}
    msg_points[${class_num}] = NULL;
}
void Logger::write_formats() {
    ${{message:write_format("${class_name}\\0",${class_name}_char);
    }}
}
void Logger::write_all_add_logged_msg() {
    ${{message:write_add_logged_msg("${class_name}\\0",${id},1);
    }}
}
''',xml)
    f.close()

def generate_one(directory,xml):
    for m in xml.message:
        generate_msg_x_src(directory,m)
        generate_msg_x_header(directory,m)
    generate_msg_header(directory,xml)
    generate_msg_src(directory,xml)


def generate(basename, xml_list):
    '''generate complete MAVLink C implemenation'''

    for idx in range(len(xml_list)):
        xml = xml_list[idx]
        xml.xml_idx = idx
        generate_one(basename,xml)
