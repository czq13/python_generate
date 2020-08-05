
#include "configure.h"
#include "msg_include.h"
#include "Modules/Clock/Clock.h"
#include "Modules/Logger/Logger.h"
#include "Modules/SD/SD_Driver.h"

int main() {
    sd0.init();
    sd0.open_record_file();
    clk.init();
    mlog.start_log_file();
    msg_init();
    for (int i = 0;i < 100000;i++) {
        global_timer_10us = i * 100;
        msg_attitude.timestamp = clk.time();
        msg_attitude.phi = float(i) / 100;
        msg_attitude.theta = float(i) / 1000;
        msg_attitude.psi = float(i)/10;
        msg_print_check();
    }
    printf("finish!~\n");
    sd0.close_record_file();
    return 0;
}