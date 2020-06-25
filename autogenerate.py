import os
import re
import sys
import argparse

import mavgen
import mavparse
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
    args = parser.parse_args()
    xml_abs_path = os.path.join(os.path.abspath('.'),args.base_dir)
    opts = mavgen.Opts(xml_abs_path,wire_protocol='2.0',language='C',validate=True,strict_units=False)
    file_list = [os.path.join(os.path.abspath('.'),args.xml_file)]
    try:
        mavgen.mavgen(opts,file_list)
        print('successfully generated headers')
    except Exception as ex:
        exStr = formatErrorMessage(str(ex))
        print('Error!','{0!s}'.format(exStr))

    print(args)
    print(os.path.abspath('.'))