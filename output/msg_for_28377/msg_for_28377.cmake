
set(MATLAB_ROOT_DIR F:/matlab2019b)
find_package(Matlab REQUIRED)
include_directories(${Matlab_INCLUDE_DIRS})
MESSAGE("${Matlab_INCLUDE_DIRS}")
set(module_path D:/chWorkSpace/code/AutoPilot/Modules)
set(msg_path D:/chWorkSpace/code/AutoPilot/auto_generate/python_generate)

LIST(APPEND src ${module_path}/SD/device/SD_Windows.cpp)
LIST(APPEND src ${module_path}/Clock//device/Clock_Windows.cpp)
LIST(APPEND src ${module_path}/Logger/Logger.cpp)
LIST(APPEND src ${msg_path}/output/msg_for_28377/msg_source/Msg_Attitude.cpp)
LIST(APPEND src ${msg_path}/output/msg_for_28377/msg_src.cpp)
LIST(APPEND src ${msg_path}/output/msg_for_28377/test_msg.cpp)

include_directories(${module_path})
include_directories(${module_path}/..)
include_directories(${msg_path}/output/msg_for_28377)
include_directories(${msg_path}/output/msg_for_28377/msg_header)

add_executable(Ulog_demo2 ${src})

