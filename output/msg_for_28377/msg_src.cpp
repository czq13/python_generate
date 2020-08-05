#include "string.h"
#include "msg_include.h"
#include "Modules/Clock/Clock.h"
#include "Modules/Logger/Logger.h"
#include "Modules/SD/SD_Driver.h"
//#include "SD"
Msg_Attitude msg_attitude;
msg_base * msgs[10];

char public_buffer[256];
int public_buffer_pos;

void msg_init() {
    msgs[0] = &msg_attitude;
    msgs[1] = NULL;
}

void msg_print_check() {
    int pos = 0,len = 0;
    while(msgs[pos] != NULL) {
        if (msgs[pos]->print_freq > 0) {
            uint32_t timegap = 1e7 / msgs[pos]->print_freq;
            if (clk.time()-msgs[pos]->print_timestamp > timegap) {
                msgs[pos]->print_timestamp = clk.time();
                public_buffer_pos = 5;
                len = msgs[pos]->get_str() + 2;
                public_buffer[0] =  (len & 0xff);
                public_buffer[1] = (len >> 8) & 0xff;
                public_buffer[2] = ULOGTYPE_DATA; 
                public_buffer[3] = msgs[pos]->msg_id & 0x0ff;
                public_buffer[4] = (msgs[pos]->msg_id >> 8) & 0x0ff;
                sd0.sd_printf(public_buffer,len + 3);
            }
        }
        pos++;
    }
}

void msg_disp_check() {

}

void Logger::write_formats() {
    write_format("Attitude\0",Msg_Attitude_char);
}

void Logger::write_all_add_logged_msg() {
    write_add_logged_msg("Attitude\0",1,1);
}