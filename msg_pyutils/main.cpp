#include <iostream>
#include "msg_logger.h"
#include "Message_Attitude.h"
#include "Message_Position.h"
char position_msg_define[] = "float32 x;float32 y;float32 z;float32 vx;float32 vy;float32 vz;";
char attitude_msg_define[] = "float32 phi;float32 theta;float32 psi;";
Message_Attitude attitude_msg;
Message_Position position_msg;
int main(int, char**) {
    mlog.start_log_file();
    char buf[1000];
    for (int i = 0;i < 1000;i++) {
        attitude_msg.phi = i*1.0;
        attitude_msg.theta = i*1.0/5.0;
        attitude_msg.psi = 0;
        position_msg.x = position_msg.y = position_msg.z = i;
        position_msg.vx = position_msg.vy = position_msg.vz = i * 10;
        
    }
    return 0;
}
