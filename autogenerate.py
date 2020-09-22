import os
import re
import argparse

from mav_pyutils import mavgen


def formatErrorMessage(message):
    reObj = re.compile(r'^(ERROR):\s+',re.M)
    matches = re.findall(reObj, message)
    prefix = ("An error occurred in mavgen:" if len(matches) == 1 else "Errors occurred in mavgen:\n")
    message = re.sub(reObj, '\n', message)

    return prefix + message

if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='try adjust everything for C2000')
    parser.add_argument('--xml_file',help='convert source file')
    parser.add_argument('--base_dir',help='directory of ccs root')
    parser.add_argument('--target',help='target may be:mavlink,msg,parameter,calibration')
    args = parser.parse_args()
    xml_abs_path = os.path.join(os.path.abspath('.'),args.base_dir)
    if args.target == 'mavlink':
        opts = mavgen.Opts(xml_abs_path, wire_protocol='2.0', language='C', validate=True, strict_units=False)
        file_list = [os.path.join(os.path.abspath('.'),args.xml_file)]
        mavgen.mavgen(opts, file_list)
    elif args.target == 'msg':
        file_list = [os.path.join(os.path.abspath('.'),args.xml_file)]
        from msg_pyutils import msgparse
        from msg_pyutils import autogen_msgc
        xml = []
        for fname in file_list:
            xml.append(msgparse.MSGXML(fname))
        #basedir = 'D:\\chWorkSpace\\code\\AutoPilot\\Modules\\Logger'
        basedir = os.path.abspath('..\\..\\Modules\\Logger')
        autogen_msgc.generate(basedir,xml)
    print('successfully generated headers')

    print(args)
    print(os.path.abspath('.'))