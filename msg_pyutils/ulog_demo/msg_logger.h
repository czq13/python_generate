#ifndef MSG_LOGGER_H
#define MSG_LOGGER_H
#include "stdio.h"
#include "stdint.h"
#include "messages.h"
class msg_logger {
public:
    FILE * file;
    void start_log_file();
    void stop_log_file();
    void write_all_add_logged_msg();
    void write_add_logged_msg(const char * name,int msg_id,int multi_id);
    void write_header();
    void write_format(ulog_message_format_s &msg,const char * name,const char * field);
    void write_formats();
    void write_version();
    void write_info(const char * name,const char * value);
    void write_info(const char * name,int32_t value);
    void write_info_multiple(const char * name,const char * value,bool is_continued);

    void write_parameters();
    void write_buffer(int buffer_len,char * buffer);
};
extern msg_logger mlog;

#endif