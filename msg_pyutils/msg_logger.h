#ifndef MSG_LOGGER_H
#define MSG_LOGGER_H
#include "stdio.h"
#include "stdint.h"
class msg_logger {
public:
    FILE * file;
    void start_log_file();
    void stop_log_file();
    void write_all_add_logged_msg();
    void write_add_logged_msg();
    void write_header();
    void write_format();
    void write_formats();
    void write_version();
    void write_info(const char * name,const char * value);
    void write_info(const char * name,int32_t value);

    void write_parameters();
    void write_message(void * ptr,uint16_t size);

};

#endif