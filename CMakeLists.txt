cmake_minimum_required(VERSION 3.0.0)
project(Auto_Generate_For_28377 VERSION 0.1.0)

include_directories(${PROJECT_SOURCE_DIR}/output/mavlink_for_28377)
include_directories(${PROJECT_SOURCE_DIR}/output/mavlink_for_28377/common)
enable_testing()

add_compile_options(-fgnu89-inline)
file(GLOB src output/mavlink_for_28377/Sources/*.c)
add_executable(Auto_Generate_For_28377 ${PROJECT_SOURCE_DIR}/c_test/mavlink_udp.c ${src})
add_definitions(-DPLATFORM_Ubuntu=2)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
