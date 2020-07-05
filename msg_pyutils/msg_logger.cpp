#include <string.h>
#include "msg_logger.h"
#include "messages.h"

void msg_logger::start_log_file() {
    file = fopen("test.ulg","w");
    write_header();
    write_info("czq_test","success!");
}
void msg_logger::stop_log_file() {

}
void msg_logger::write_all_add_logged_msg() {

}
void msg_logger::write_add_logged_msg() {

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
void msg_logger::write_format() {

}
void msg_logger::write_formats() {

}
void msg_logger::write_version() {

}
void msg_logger::write_info(const char * name,const char * value) {
    ulog_message_info_header_s msg;
    int vlen = strlen(value);
    msg.key_len = sprintf(msg.key,"char[%d] %s",vlen,name);
    vlen = sprintf(msg.key + msg.key_len,"%s",value);
    msg.msg_size = 4 + msg.key_len + vlen;
    fwrite((void*) &msg,sizeof(msg),1,file);
}
void msg_logger::write_info(const char * name,int32_t value) {

}

void msg_logger::write_parameters() {

}
void msg_logger::write_message(void * ptr,uint16_t size) {

}

msg_logger mlog;
int main() {
    mlog.start_log_file();
    return 0;
}