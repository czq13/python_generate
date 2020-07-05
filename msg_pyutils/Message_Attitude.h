#ifndef MESSAGE_ATTITUDE
#define MESSAGE_ATTITUDE
#include "Message_Base.h"
#include "string.h"
class Message_Attitude : public Message_Base {
public:
    float x,y,z,vx,vy,vz;
    char msg_define[] = "float32 x;float32 y;float32 z;float32 vx;float32 vy;float32 vz;";
    void get_str(char * str) {
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
#endif