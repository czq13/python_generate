#pragma once
// MESSAGE VIBRATION PACKING

#define MAVLINK_MSG_ID_VIBRATION 241

typedef struct __mavlink_vibration_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float vibration_x; /*<  Vibration levels on X-axis*/
 float vibration_y; /*<  Vibration levels on Y-axis*/
 float vibration_z; /*<  Vibration levels on Z-axis*/
 uint32_t clipping_0; /*<  first accelerometer clipping count*/
 uint32_t clipping_1; /*<  second accelerometer clipping count*/
 uint32_t clipping_2; /*<  third accelerometer clipping count*/
} mavlink_vibration_t;

#define MAVLINK_MSG_ID_VIBRATION_LEN 32
#define MAVLINK_MSG_ID_VIBRATION_MIN_LEN 32
#define MAVLINK_MSG_ID_241_LEN 32
#define MAVLINK_MSG_ID_241_MIN_LEN 32

#define MAVLINK_MSG_ID_VIBRATION_CRC 90
#define MAVLINK_MSG_ID_241_CRC 90



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VIBRATION { \
    241, \
    "VIBRATION", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vibration_t, time_usec) }, \
         { "vibration_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vibration_t, vibration_x) }, \
         { "vibration_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vibration_t, vibration_y) }, \
         { "vibration_z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vibration_t, vibration_z) }, \
         { "clipping_0", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_vibration_t, clipping_0) }, \
         { "clipping_1", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_vibration_t, clipping_1) }, \
         { "clipping_2", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_vibration_t, clipping_2) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VIBRATION { \
    "VIBRATION", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vibration_t, time_usec) }, \
         { "vibration_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vibration_t, vibration_x) }, \
         { "vibration_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vibration_t, vibration_y) }, \
         { "vibration_z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vibration_t, vibration_z) }, \
         { "clipping_0", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_vibration_t, clipping_0) }, \
         { "clipping_1", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_vibration_t, clipping_1) }, \
         { "clipping_2", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_vibration_t, clipping_2) }, \
         } \
}
#endif

/**
 * @brief Pack a vibration message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param vibration_x  Vibration levels on X-axis
 * @param vibration_y  Vibration levels on Y-axis
 * @param vibration_z  Vibration levels on Z-axis
 * @param clipping_0  first accelerometer clipping count
 * @param clipping_1  second accelerometer clipping count
 * @param clipping_2  third accelerometer clipping count
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vibration_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, float vibration_x, float vibration_y, float vibration_z, uint32_t clipping_0, uint32_t clipping_1, uint32_t clipping_2)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_float(msg->payloads, 8, vibration_x);
    _mav_put_float(msg->payloads, 12, vibration_y);
    _mav_put_float(msg->payloads, 16, vibration_z);
    _mav_put_uint32_t(msg->payloads, 20, clipping_0);
    _mav_put_uint32_t(msg->payloads, 24, clipping_1);
    _mav_put_uint32_t(msg->payloads, 28, clipping_2);

    msg->msgid = MAVLINK_MSG_ID_VIBRATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VIBRATION_MIN_LEN, MAVLINK_MSG_ID_VIBRATION_LEN, MAVLINK_MSG_ID_VIBRATION_CRC);
}

/**
 * @brief Pack a vibration message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param vibration_x  Vibration levels on X-axis
 * @param vibration_y  Vibration levels on Y-axis
 * @param vibration_z  Vibration levels on Z-axis
 * @param clipping_0  first accelerometer clipping count
 * @param clipping_1  second accelerometer clipping count
 * @param clipping_2  third accelerometer clipping count
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vibration_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,float vibration_x,float vibration_y,float vibration_z,uint32_t clipping_0,uint32_t clipping_1,uint32_t clipping_2)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_float(msg->payloads, 8, vibration_x);
    _mav_put_float(msg->payloads, 12, vibration_y);
    _mav_put_float(msg->payloads, 16, vibration_z);
    _mav_put_uint32_t(msg->payloads, 20, clipping_0);
    _mav_put_uint32_t(msg->payloads, 24, clipping_1);
    _mav_put_uint32_t(msg->payloads, 28, clipping_2);


    msg->msgid = MAVLINK_MSG_ID_VIBRATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VIBRATION_MIN_LEN, MAVLINK_MSG_ID_VIBRATION_LEN, MAVLINK_MSG_ID_VIBRATION_CRC);
}

/**
 * @brief Encode a vibration struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vibration C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vibration_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vibration_t* vibration)
{
    return mavlink_msg_vibration_pack(system_id, component_id, msg, vibration->time_usec, vibration->vibration_x, vibration->vibration_y, vibration->vibration_z, vibration->clipping_0, vibration->clipping_1, vibration->clipping_2);
}

/**
 * @brief Encode a vibration struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vibration C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vibration_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vibration_t* vibration)
{
    return mavlink_msg_vibration_pack_chan(system_id, component_id, chan, msg, vibration->time_usec, vibration->vibration_x, vibration->vibration_y, vibration->vibration_z, vibration->clipping_0, vibration->clipping_1, vibration->clipping_2);
}

// MESSAGE VIBRATION UNPACKING


/**
 * @brief Get field time_usec from vibration message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_vibration_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field vibration_x from vibration message
 *
 * @return  Vibration levels on X-axis
 */
static inline float mavlink_msg_vibration_get_vibration_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field vibration_y from vibration message
 *
 * @return  Vibration levels on Y-axis
 */
static inline float mavlink_msg_vibration_get_vibration_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field vibration_z from vibration message
 *
 * @return  Vibration levels on Z-axis
 */
static inline float mavlink_msg_vibration_get_vibration_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field clipping_0 from vibration message
 *
 * @return  first accelerometer clipping count
 */
static inline uint32_t mavlink_msg_vibration_get_clipping_0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field clipping_1 from vibration message
 *
 * @return  second accelerometer clipping count
 */
static inline uint32_t mavlink_msg_vibration_get_clipping_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field clipping_2 from vibration message
 *
 * @return  third accelerometer clipping count
 */
static inline uint32_t mavlink_msg_vibration_get_clipping_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  28);
}

/**
 * @brief Decode a vibration message into a struct
 *
 * @param msg The message to decode
 * @param vibration C-struct to decode the message contents into
 */
static inline void mavlink_msg_vibration_decode(const mavlink_message_t* msg, mavlink_vibration_t* vibration)
{
    vibration->time_usec = mavlink_msg_vibration_get_time_usec(msg);
    vibration->vibration_x = mavlink_msg_vibration_get_vibration_x(msg);
    vibration->vibration_y = mavlink_msg_vibration_get_vibration_y(msg);
    vibration->vibration_z = mavlink_msg_vibration_get_vibration_z(msg);
    vibration->clipping_0 = mavlink_msg_vibration_get_clipping_0(msg);
    vibration->clipping_1 = mavlink_msg_vibration_get_clipping_1(msg);
    vibration->clipping_2 = mavlink_msg_vibration_get_clipping_2(msg);
}