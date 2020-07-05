#ifndef MESSAGE_BASE
#define MESSAGE_BASE
#include "stdio.h"
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
class Message_Base {
public:
    uint64_t update_timestamp;
    uint64_t print_timestamp;
    uint16_t print_freq;
    virtual void get_str(char * str);
    virtual void set_str(char * str);
};

#endif