#ifndef MESSAGE_ATTITUDE
#define MESSAGE_ATTITUDE
#include "Message_Base.h"
#include "string.h"
extern char attitude_msg_define[];
class Message_Attitude : public Message_Base {
public:
    Message_Attitude() {}
    float phi,theta,psi;
    void get_str(char * str) {
        memcpy(str,&phi,sizeof(float));
        str += sizeof(float);
        memcpy(str,&theta,sizeof(float));
        str += sizeof(float);
        memcpy(str,&psi,sizeof(float));
    }
    void set_str(char * str) {
        memcpy(&phi,str,sizeof(float));
        str += sizeof(float);
        memcpy(&theta,str,sizeof(float));
        str += sizeof(float);
        memcpy(&psi,str,sizeof(float));
    }
};
extern Message_Attitude attitude_msg;
#endif