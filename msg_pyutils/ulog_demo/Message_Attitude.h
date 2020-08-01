#ifndef MESSAGE_ATTITUDE
#define MESSAGE_ATTITUDE
#include "Message_Base.h"
#include "string.h"
extern char attitude_msg_define[];
class Message_Attitude : public Message_Base {
public:
    Message_Attitude() {}
    float phi,theta,psi;
    int get_str(char * str) {
        int ans_len = 0;
        memcpy(str,&update_timestamp,sizeof(uint64_t));
        str += sizeof(uint64_t);
        ans_len += sizeof(uint64_t);
        memcpy(str,&phi,sizeof(float));
        str += sizeof(float);
        ans_len += sizeof(float);
        memcpy(str,&theta,sizeof(float));
        str += sizeof(float);
        ans_len += sizeof(float);
        memcpy(str,&psi,sizeof(float));
        ans_len += sizeof(float);
        return ans_len;
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