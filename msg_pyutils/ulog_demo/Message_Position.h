#ifndef MESSAGE_POSITION
#define MESSAGE_POSITION
#include "Message_Base.h"
#include "string.h"
extern char position_msg_define[];
class Message_Position : public Message_Base {
public:
    Message_Position() {}
    float x,y,z,vx,vy,vz;
    int get_str(char * str) {
        int ans_len = 0;
        memcpy(str,&update_timestamp,sizeof(uint64_t));
        str += sizeof(uint64_t);
        ans_len += sizeof(uint64_t);
        memcpy(str,&x,sizeof(float));
        str += sizeof(float);
        memcpy(str,&y,sizeof(float));
        str += sizeof(float);
        memcpy(str,&z,sizeof(float));
        str += sizeof(float);
        memcpy(str,&vx,sizeof(float));
        str += sizeof(float);
        memcpy(str,&vy,sizeof(float));
        str += sizeof(float);
        memcpy(str,&vz,sizeof(float));
        ans_len += sizeof(float) * 6;
        return ans_len;
    }
    void set_str(char * str) {
        memcpy(&x,str,sizeof(float));
        str += sizeof(float);
        memcpy(&y,str,sizeof(float));
        str += sizeof(float);
        memcpy(&z,str,sizeof(float));
        str += sizeof(float);
        memcpy(&vx,str,sizeof(float));
        str += sizeof(float);
        memcpy(&vy,str,sizeof(float));
        str += sizeof(float);
        memcpy(&vz,str,sizeof(float));
    }
};
extern Message_Position position_msg;
#endif