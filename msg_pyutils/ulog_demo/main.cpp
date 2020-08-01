#include <iostream>
#include "msg_logger.h"
#include "Message_Attitude.h"
#include "Message_Position.h"
char position_msg_define[] = "uint64_t timestamp;float32 x;float32 y;float32 z;float32 vx;float32 vy;float32 vz;";
char attitude_msg_define[] = "uint64_t timestamp;float32 phi;float32 theta;float32 psi;";
Message_Attitude attitude_msg;
Message_Position position_msg;
unsigned char message_buffer[256];
int main(int, char**) {
    mlog.start_log_file();
    for (int i = 1;i < 1000;i++) {
        attitude_msg.update_timestamp = i * 10;
        attitude_msg.phi = i*1.0;
        attitude_msg.theta = i*1.0/5.0;
        attitude_msg.psi = 0;
        position_msg.update_timestamp = i * 10;
        position_msg.x = position_msg.y = position_msg.z = i;
        position_msg.vx = position_msg.vy = position_msg.vz = i * 10;
        int len = attitude_msg.get_str(message_buffer+5)+2;
        message_buffer[0] = (uint8_t) len;
        message_buffer[1] = (uint8_t) (len >> 8);
        message_buffer[2] = (uint8_t) (ULogMessageType::DATA);
        message_buffer[3] = (uint8_t) 1;
        message_buffer[4] = 0;
        //for (int j = 0;j < len+3;j++) printf("%x ",message_buffer[j]);
        //printf("\n");
        mlog.write_buffer(len+3,message_buffer);

        len = position_msg.get_str(message_buffer+5)+2;
        message_buffer[0] = (uint8_t) len;
        message_buffer[1] = (uint8_t) (len >> 8);
        message_buffer[2] = (uint8_t) (ULogMessageType::DATA);
        message_buffer[3] = (uint8_t) 2;
        message_buffer[4] = 0;
        mlog.write_buffer(len+3,message_buffer);
        //for (int j = 0;j < len+3;j++) printf("%x ",message_buffer[j]);
        //printf("\n");

        message_buffer[0] = (uint8_t) 8;
        message_buffer[1] = (uint8_t) 0;
        message_buffer[2] = (uint8_t) (ULogMessageType::SYNC);
        message_buffer[3] = 0x2F;
		message_buffer[4] = 0x73;
		message_buffer[5] = 0x13;
		message_buffer[6] = 0x20;
		message_buffer[7] = 0x25;
		message_buffer[8] = 0x0C;
		message_buffer[9] = 0xBB;
		message_buffer[10] = 0x12;
        mlog.write_buffer(11,message_buffer);
        //for (int j = 0;j < 11;j++) printf("%x ",message_buffer[j]);
        //printf("\n");
    }
    fclose(mlog.file);
    return 0;
}
