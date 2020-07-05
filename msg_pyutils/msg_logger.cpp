#include <string.h>
#include "msg_logger.h"
#include "Message_Attitude.h"
#include "messages.h"

void msg_logger::start_log_file() {
    file = fopen("ulog_exam/test.ulg","w");
    write_header();
    write_version();
    write_formats();
    write_all_add_logged_msg();
}
void msg_logger::stop_log_file() {

}
void msg_logger::write_all_add_logged_msg() {
    write_add_logged_msg("Attitude",1,1);
    write_add_logged_msg("Position",2,1);
}
void msg_logger::write_add_logged_msg(const char * name,int msg_id,int multi_id) {
    ulog_message_add_logged_s msg;
    msg.msg_id = msg_id;
    msg.multi_id = multi_id;
    memcpy(msg.message_name,name);
    int len = sprintf(msg.message_name,"%s",name);
    msg.msg_size = 6 + len;
    fwrite((void*) &msg,msg.msg_size,1,file);
}
void msg_logger::write_header() {
    ulog_file_header_s header;
    header.magic[0] = 'U';
	header.magic[1] = 'L';
	header.magic[2] = 'o';
	header.magic[3] = 'g';
	header.magic[4] = 0x01;
	header.magic[5] = 0x12;
	header.magic[6] = 0x35;
	header.magic[7] = 0x01; //file version 1
	header.timestamp = 0;
    fwrite((void*) &header,sizeof(header),1,file);
}
void msg_logger::write_format(ulog_message_format_s &msg,const char * name,const char * field) {
    int format_len = sprintf(msg.format, "%s:%s",name,field);
    msg.msg_size = 3 + format_len;
    fwrite((void*) &msg,msg.msg_size,1,file);
}
void msg_logger::write_formats() {
    ulog_message_format_s msg;
    write_format(msg,"Attitude",attitude_msg_define);
    write_format(msg,"Position",position_msg_define);
}
void msg_logger::write_version() {
    write_info("czq autopilot version","0.1");
}
void msg_logger::write_info(const char * name,const char * value) {
    ulog_message_info_header_s msg;
    int vlen = strlen(value);
    msg.key_len = sprintf(msg.key,"char[%d] %s",vlen,name);
    vlen = sprintf(msg.key + msg.key_len,"%s",value);
    msg.msg_size = 4 + msg.key_len + vlen;
    fwrite((void*) &msg,msg.msg_size,1,file);
}
void msg_logger::write_info(const char * name,int32_t value) {
    ulog_message_info_header_s msg;
    int vlen = 4;
    msg.key_len = sprintf(msg.key,"char[%d] %s",vlen,name);
    vlen = sprintf(msg.key + msg.key_len,"%d",value);
    msg.msg_size = 4 + msg.key_len + vlen;
    fwrite((void*) &msg,msg.msg_size,1,file);
}
void msg_logger::write_info_multiple(const char * name,const char * value,bool is_continued) {
    ulog_message_info_multiple_header_s msg;
    int vlen = strlen(value);
    msg.key_len = sprintf(msg.key,"char[%d] %s",vlen,name);
    vlen = sprintf(msg.key + msg.key_len,"%s",value);
    msg.msg_size = 5 + msg.key_len + vlen;
    fwrite((void*) &msg,msg.msg_size,1,file);
}

void msg_logger::write_parameters() {

}

msg_logger mlog;