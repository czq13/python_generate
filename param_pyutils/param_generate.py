import json
import os

def generate_headers(directory,ret_dict):
    f = open(os.path.join(directory,"Params_Macro.h"), mode='w')
    params_list = ret_dict['parameters']
    f.write('#ifndef PARAMS_MACRO\n')
    f.write('#define PARAMS_MACRO\n')
    for i,param in enumerate(params_list):
        param_str = '#define %s %d \n' % (param['name'],i)
        f.write(param_str)
    f.write('#define PARAM_NUM %d\n' % (len(params_list)))
    f.write('#endif')
    f.close()

def generate_repository_def(directory,ret_dict):
    f = open(os.path.join(directory,"Params_Repo_Def.h"), mode='w')
    params_list = ret_dict['parameters']
    #f.write('#include "Modules/Parameters.h"\n')
    f.write('#ifndef PARAMS_REPO_DEF\n')
    f.write('#define PARAMS_REPO_DEF\n')
    f.write('char params_repo[PARAM_NUM][12] = {\n')
    for i,param in enumerate(params_list):
        param_str = '  "' + param['name'][0:11] + '\\0'
        if (i+1 != len(params_list)):
            param_str += '",\n'
        else:
            param_str += '"\n'
        f.write(param_str)
    f.write('};\n')
    f.write('void init_parameters(){\n')
    for i,param in enumerate(params_list):
        f.write('  parameters.parameters[%s]=%f;\n' % (param['name'],param['default']))
    f.write('}\n')
    f.write('#endif')

def generate(basename, file_name):
    with open(file_name, 'r', encoding='utf-8') as f:
        ret_dict = json.load(f)
        generate_headers(basename,ret_dict)
        generate_repository_def(basename,ret_dict)