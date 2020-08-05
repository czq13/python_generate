#ifndef MSG_BASE
#define MSG_BASE

#include "configure.h"
#ifdef PLATFORM_28377
#define CHAR_LEN 16
#define float16_t_len 16
#define float32_t_len 32
#define uint16_t_len 16
#define uint32_t_len 32
#define int16_t_len 16
#define int32_t_len 32
#define uint64_t_len 64
#define int64_t_len 64
#else
#include "string.h"
#define CHAR_LEN 8
#define float16_t_len 32
#define float32_t_len 32
#define uint16_t_len 16
#define uint32_t_len 32
#define int16_t_len 16
#define int32_t_len 32
#define uint64_t_len 64
#define int64_t_len 64
#define float16_t float
#endif
extern char public_buffer[256];
extern int public_buffer_pos;

class msg_base {
public:
    uint64_t timestamp;
    uint64_t print_timestamp;
    uint64_t disp_timestamp;
    uint16_t print_freq;
    uint16_t disp_freq;
	uint16_t msg_id;

    virtual int get_str() {return 0;}
    virtual void set_str() {return;}
};

static inline void byte_put_nbit(char *dst,const char *src,char n) {
	int i = 0,j = 0;
	for (i = 0;i < n/CHAR_LEN;i++) {
		dst[j++] = src[i] & 0xff;
		#ifdef PLATFORM_28377
		dst[j++] = (src[i] >> 8) & 0xff;
		#endif
	}
}

#define _msg_put_uint8_t(buf, wire_offset, b) buf[wire_offset]=b
#define _msg_put_int8_t(buf, wire_offset, b)  buf[wire_offset]=b
#define _msg_put_char(buf, wire_offset, b)    buf[wire_offset]=b

#define _msg_put_uint16_t(buf, wire_offset, b) byte_put_nbit(&buf[wire_offset],(const char *)&b,16)
#define _msg_put_int16_t(buf, wire_offset, b)  byte_put_nbit(&buf[wire_offset], (const char *)&b,16)
#define _msg_put_uint32_t(buf, wire_offset, b) byte_put_nbit(&buf[wire_offset], (const char *)&b,32)
#define _msg_put_int32_t(buf, wire_offset, b)  byte_put_nbit(&buf[wire_offset], (const char *)&b,32)
#define _msg_put_uint64_t(buf, wire_offset, b) byte_put_nbit(&buf[wire_offset], (const char *)&b,64)
#define _msg_put_int64_t(buf, wire_offset, b)  byte_put_nbit(&buf[wire_offset], (const char *)&b,64)
#define _msg_put_float(buf, wire_offset, b)    byte_put_nbit(&buf[wire_offset], (const char *)&b,32)
#define _msg_put_float16_t(buf, wire_offset, b)    byte_put_nbit(&buf[wire_offset], (const char *)&b,float16_t_len)
#define _msg_put_float32_t(buf, wire_offset, b)    byte_put_nbit(&buf[wire_offset], (const char *)&b,float32_t_len)
#define _msg_put_double(buf, wire_offset, b)   byte_put_nbit(&buf[wire_offset], (const char *)&b,32)

#define _MSG_PUT_ARRAY(TYPE,V) \
static inline void _msg_put_ ## TYPE ##_array(char *buf,uint8_t wire_offset,const TYPE * b,uint8_t array_lenth) {\
	int i = 0;\
	for (i = 0;i < array_lenth;i++) {\
		_msg_put_ ## TYPE (buf, wire_offset,b[i]);\
		wire_offset += V / 8;\
	}\
}
_MSG_PUT_ARRAY(char, 8)
_MSG_PUT_ARRAY(uint8_t, 8)
_MSG_PUT_ARRAY(int8_t, 8)
_MSG_PUT_ARRAY(uint16_t, 16)
_MSG_PUT_ARRAY(uint32_t, 32)
_MSG_PUT_ARRAY(uint64_t, 64)
_MSG_PUT_ARRAY(int16_t,  16)
_MSG_PUT_ARRAY(int32_t,  32)
_MSG_PUT_ARRAY(int64_t,  64)
_MSG_PUT_ARRAY(float,    32)
_MSG_PUT_ARRAY(double,   32)

#define _MSG_RETURN_TYPE(TYPE,V) \
static inline TYPE _MSG_RETURN_## TYPE(const char * buffer, uint8_t ofs) {\
	TYPE r = 0;\
	int i = 0;\
	for (i = V/8-1;i >= 0;i--) {\
		r = (r << 8) | (buffer[ofs+i] & 0xff); \
	} \
	return r;\
}
_MSG_RETURN_TYPE(uint16_t, 16)
_MSG_RETURN_TYPE(int16_t,  16)
_MSG_RETURN_TYPE(uint32_t, 32)
_MSG_RETURN_TYPE(int32_t,  32)
_MSG_RETURN_TYPE(uint64_t, 64)
_MSG_RETURN_TYPE(int64_t,  64)

//_MAV_MSG_RETURN_TYPE(float,    32)
//_MAV_MSG_RETURN_TYPE(double,   32)
static inline float _MSG_RETURN_float(const char * buffer, uint8_t ofs) {
	float r = 0;
	char * point = (char *) &r;
	#ifdef PLATFORM_28377
	point[0] = (buffer[ofs]<<8) | (buffer[ofs+1]);
	point[1] = (buffer[ofs+2]<<8) | (buffer[ofs+3]);
	#else
	point[0] = buffer[ofs];
	point[1] = buffer[ofs+1];
	point[2] = buffer[ofs+2];
	point[3] = buffer[ofs+3];
	#endif
	return r;
}
static inline double _MSG_RETURN_double(const char * buffer, uint8_t ofs) {
	return (double)_MSG_RETURN_float(buffer,ofs);
}

static inline uint16_t _MAV_RETURN_char_array(const char *buffer, char *value, 
						     uint8_t array_length, uint8_t wire_offset)
{
	memcpy(value, &buffer[wire_offset], array_length);
	return array_length;
}

#define _MSG_RETURN_ARRAY(TYPE, V) \
static inline uint16_t _MSG_RETURN_## TYPE ##_array(const char *buffer, TYPE *value,uint8_t array_length, uint8_t wire_offset) {\
	int i;\
	for (i = 0;i < array_length;i++) {\
		value[i] = _MSG_RETURN_## TYPE(buffer,wire_offset+(i*V/8));\
	}\
	return array_length*V/8;\
}
_MSG_RETURN_ARRAY(uint16_t, 16)
_MSG_RETURN_ARRAY(uint32_t, 32)
_MSG_RETURN_ARRAY(uint64_t, 64)
_MSG_RETURN_ARRAY(int16_t,  16)
_MSG_RETURN_ARRAY(int32_t,  32)
_MSG_RETURN_ARRAY(int64_t,  64)
_MSG_RETURN_ARRAY(float,    32)
_MSG_RETURN_ARRAY(double,   32)

#define ULOGTYPE_FORMAT 70
#define ULOGTYPE_DATA	68
#define ULOGTYPE_INFO	73
#define ULOGTYPE_MULTPLE	77
#define ULOGTYPE_PARAMETER	80
#define ULOGTYPE_ADD_LOGGED_MSG 65
#define ULOGTYPE_REMOVE_LOGGED_MSG 82
#define ULOGTYPE_SYNC 83
#define ULOGTYPE_DROPOUT 79
#define ULOGTYPE_LOGGING 76
#define ULOGTYPE_LOGGING_TAGGED 67
#define ULOGTYPE_FLAG_BITS 66

#endif