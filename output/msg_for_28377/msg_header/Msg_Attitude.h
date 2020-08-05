
#include "msg_base.h"

class Msg_Attitude : public msg_base {
public:
    float16_t phi;
    float16_t theta;
    float16_t psi;
    Msg_Attitude() {
        print_freq = 1000;
        disp_freq = 0;
        msg_id = 1;
    }
    int get_str() {
        int ans_len = 0;
        char * str = &(public_buffer[public_buffer_pos]);
        _msg_put_uint64_t(str,ans_len,timestamp);
        ans_len += uint64_t_len/8;
        _msg_put_float16_t(str,ans_len,phi);
        ans_len += float16_t_len/8;
        _msg_put_float16_t(str,ans_len,theta);
        ans_len += float16_t_len/8;
        _msg_put_float16_t(str,ans_len,psi);
        ans_len += float16_t_len/8;
        return ans_len;
    }
    void set_str(char * str) {return;}
};
extern char Msg_Attitude_char[];// = "uint64_t timestamp;float16_t phi;float16_t theta;float16_t psi;";