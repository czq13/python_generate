#ifndef PROTOCOL_H
#define PROTOCOL_H
#include "string.h"
#include "mavlink_types.h"
#ifdef PLATFORM_28377
#define CHAR_LEN 16
#else
#define CHAR_LEN 8
#endif

/**
 * @brief Get the required buffer size for this message
 */
static inline uint16_t mavlink_msg_get_send_buffer_length(const mavlink_message_t* msg)
{
	if (msg->magic == MAVLINK_STX_MAVLINK1) {
		return msg->len + MAVLINK_CORE_HEADER_MAVLINK1_LEN+1 + 2;
	}
    	uint16_t signature_len = (msg->incompat_flags & MAVLINK_IFLAG_SIGNED)?MAVLINK_SIGNATURE_BLOCK_LEN:0;
	return msg->len + MAVLINK_NUM_NON_PAYLOAD_BYTES + signature_len;
}

static inline void byte_put_n(char *dst,const char *src,char n) {
	int i = 0,j = 0;
	for (i = 0;i < n/CHAR_LEN;i++) {
		dst[j++] = src[i] & 0xff;
		#ifdef PLATFORM_28377
		dst[j++] = (src[i] >> 8) & 0xff;
		#endif
	}
}

#define _mav_put_uint8_t(buf, wire_offset, b) buf[wire_offset]=b
#define _mav_put_int8_t(buf, wire_offset, b)  buf[wire_offset]=b
#define _mav_put_char(buf, wire_offset, b)    buf[wire_offset]=b

#define _mav_put_uint16_t(buf, wire_offset, b) byte_put_n(&buf[wire_offset],(const char *)&b,16)
#define _mav_put_int16_t(buf, wire_offset, b)  byte_put_n(&buf[wire_offset], (const char *)&b,16)
#define _mav_put_uint32_t(buf, wire_offset, b) byte_put_n(&buf[wire_offset], (const char *)&b,32)
#define _mav_put_int32_t(buf, wire_offset, b)  byte_put_n(&buf[wire_offset], (const char *)&b,32)
#define _mav_put_uint64_t(buf, wire_offset, b) byte_put_n(&buf[wire_offset], (const char *)&b,64)
#define _mav_put_int64_t(buf, wire_offset, b)  byte_put_n(&buf[wire_offset], (const char *)&b,64)
#define _mav_put_float(buf, wire_offset, b)    byte_put_n(&buf[wire_offset], (const char *)&b,32)
#define _mav_put_double(buf, wire_offset, b)   byte_put_n(&buf[wire_offset], (const char *)&b,32)

#define _MAV_PUT_ARRAY(TYPE,V) \
static inline void _mav_put_ ## TYPE ##_array(char *buf,uint8_t wire_offset,const TYPE * b,uint8_t array_lenth) {\
	int i = 0;\
	for (i = 0;i < array_lenth;i++) {\
		_mav_put_ ## TYPE (buf, wire_offset,b[i]);\
		wire_offset += V / 8;\
	}\
}
_MAV_PUT_ARRAY(char, 8)
_MAV_PUT_ARRAY(uint8_t, 8)
_MAV_PUT_ARRAY(int8_t, 8)
_MAV_PUT_ARRAY(uint16_t, 16)
_MAV_PUT_ARRAY(uint32_t, 32)
_MAV_PUT_ARRAY(uint64_t, 64)
_MAV_PUT_ARRAY(int16_t,  16)
_MAV_PUT_ARRAY(int32_t,  32)
_MAV_PUT_ARRAY(int64_t,  64)
_MAV_PUT_ARRAY(float,    32)
_MAV_PUT_ARRAY(double,   32)

#define _MAV_MSG_RETURN_TYPE(TYPE,V) \
static inline TYPE _MAV_RETURN_## TYPE(const mavlink_message_t * msg, uint8_t ofs) {\
	TYPE r = 0;\
	int i = 0;\
	for (i = V/8-1;i >= 0;i--) {\
		r = (r << 8) | (msg->payloads[ofs+i] & 0xff); \
	} \
	return r;\
}
#define _MAV_RETURN_char(msg, wire_offset)             (char)_MAV_PAYLOAD(msg)[wire_offset]
#define _MAV_RETURN_int8_t(msg, wire_offset)   (int8_t)_MAV_PAYLOAD(msg)[wire_offset]
#define _MAV_RETURN_uint8_t(msg, wire_offset) (uint8_t)_MAV_PAYLOAD(msg)[wire_offset]
_MAV_MSG_RETURN_TYPE(uint16_t, 16)
_MAV_MSG_RETURN_TYPE(int16_t,  16)
_MAV_MSG_RETURN_TYPE(uint32_t, 32)
_MAV_MSG_RETURN_TYPE(int32_t,  32)
_MAV_MSG_RETURN_TYPE(uint64_t, 64)
_MAV_MSG_RETURN_TYPE(int64_t,  64)

//_MAV_MSG_RETURN_TYPE(float,    32)
//_MAV_MSG_RETURN_TYPE(double,   32)
static inline float _MAV_RETURN_float(const mavlink_message_t * msg, uint8_t ofs) {
	float r = 0;
	char * point = (char *) &r;
	#ifdef PLATFORM_28377
	point[0] = (msg->payloads[ofs]<<8) | (msg->payloads[ofs+1]);
	point[1] = (msg->payloads[ofs+2]<<8) | (msg->payloads[ofs+3]);
	#else
	point[0] = msg->payloads[ofs+3];
	point[1] = msg->payloads[ofs+2];
	point[2] = msg->payloads[ofs+1];
	point[3] = msg->payloads[ofs];
	#endif
}
static inline double _MAV_RETURN_double(const mavlink_message_t * msg, uint8_t ofs) {
	return (double)_MAV_RETURN_float(msg,ofs);
}

static inline uint16_t _MAV_RETURN_char_array(const mavlink_message_t *msg, char *value, 
						     uint8_t array_length, uint8_t wire_offset)
{
	memcpy(value, &_MAV_PAYLOAD(msg)[wire_offset], array_length);
	return array_length;
}

static inline uint16_t _MAV_RETURN_uint8_t_array(const mavlink_message_t *msg, uint8_t *value, 
							uint8_t array_length, uint8_t wire_offset)
{
	memcpy(value, &_MAV_PAYLOAD(msg)[wire_offset], array_length);
	return array_length;
}

static inline uint16_t _MAV_RETURN_int8_t_array(const mavlink_message_t *msg, int8_t *value, 
						       uint8_t array_length, uint8_t wire_offset)
{
	memcpy(value, &_MAV_PAYLOAD(msg)[wire_offset], array_length);
	return array_length;
}

#define _MAV_RETURN_ARRAY(TYPE, V) \
static inline uint16_t _MAV_RETURN_## TYPE ##_array(const mavlink_message_t *msg, TYPE *value,uint8_t array_length, uint8_t wire_offset) {\
	int i;\
	for (i = 0;i < array_length;i++) {\
		value[i] = _MAV_RETURN_## TYPE(msg,wire_offset+(i*V/8));\
	}\
	return array_length*V/8;\
}
_MAV_RETURN_ARRAY(uint16_t, 16)
_MAV_RETURN_ARRAY(uint32_t, 32)
_MAV_RETURN_ARRAY(uint64_t, 64)
_MAV_RETURN_ARRAY(int16_t,  16)
_MAV_RETURN_ARRAY(int32_t,  32)
_MAV_RETURN_ARRAY(int64_t,  64)
_MAV_RETURN_ARRAY(float,    32)
_MAV_RETURN_ARRAY(double,   32)

#include "mavlink_helpers.h"
#endif