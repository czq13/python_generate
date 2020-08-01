
file(GLOB src ${PROJECT_SOURCE_DIR}/msg_pyutils/ulog_demo/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/msg_pyutils/ulog_demo)
add_executable(Ulog_demo ${src})