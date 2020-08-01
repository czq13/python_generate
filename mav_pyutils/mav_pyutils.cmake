
include_directories(${PROJECT_SOURCE_DIR}/output/mavlink_for_28377)
include_directories(${PROJECT_SOURCE_DIR}/output/mavlink_for_28377/common)

file(GLOB src ${PROJECT_SOURCE_DIR}/output/mavlink_for_28377/Sources/*c)

add_executable(Auto_Generate_For_28377 ${PROJECT_SOURCE_DIR}/mav_pyutils/c_test/mavlink_testsuit_main.c ${src})
