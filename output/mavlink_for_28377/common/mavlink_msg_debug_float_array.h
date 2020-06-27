#pragma once
// MESSAGE DEBUG_FLOAT_ARRAY PACKING

#define MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY 350

typedef struct __mavlink_debug_float_array_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint16_t array_id; /*<  Unique ID used to discriminate between arrays*/
 char name[10]; /*<  Name, for human-friendly display in a Ground Control Station*/
 float data[58]; /*<  data*/
} mavlink_debug_float_array_t;

#define MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_LEN 252
#define MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_MIN_LEN 20
#define MAVLINK_MSG_ID_350_LEN 252
#define MAVLINK_MSG_ID_350_MIN_LEN 20

#define MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_CRC 232
#define MAVLINK_MSG_ID_350_CRC 232

#define MAVLINK_MSG_DEBUG_FLOAT_ARRAY_FIELD_NAME_LEN 10
#define MAVLINK_MSG_DEBUG_FLOAT_ARRAY_FIELD_DATA_LEN 58

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DEBUG_FLOAT_ARRAY { \
    350, \
    "DEBUG_FLOAT_ARRAY", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_debug_float_array_t, time_usec) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 10, 10, offsetof(mavlink_debug_float_array_t, name) }, \
         { "array_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_debug_float_array_t, array_id) }, \
         { "data", NULL, MAVLINK_TYPE_FLOAT, 58, 20, offsetof(mavlink_debug_float_array_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DEBUG_FLOAT_ARRAY { \
    "DEBUG_FLOAT_ARRAY", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_debug_float_array_t, time_usec) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 10, 10, offsetof(mavlink_debug_float_array_t, name) }, \
         { "array_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_debug_float_array_t, array_id) }, \
         { "data", NULL, MAVLINK_TYPE_FLOAT, 58, 20, offsetof(mavlink_debug_float_array_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a debug_float_array message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param name  Name, for human-friendly display in a Ground Control Station
 * @param array_id  Unique ID used to discriminate between arrays
 * @param data  data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_debug_float_array_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const char *name, uint16_t array_id, const float *data)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint16_t(msg->payloads, 8, array_id);
    _mav_put_char_array(msg->payloads, 10, name, 10);
    _mav_put_float_array(msg->payloads, 20, data, 58);
    msg->msgid = MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_MIN_LEN, MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_LEN, MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_CRC);
}

/**
 * @brief Pack a debug_float_array message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param name  Name, for human-friendly display in a Ground Control Station
 * @param array_id  Unique ID used to discriminate between arrays
 * @param data  data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_debug_float_array_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const char *name,uint16_t array_id,const float *data)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint16_t(msg->payloads, 8, array_id);
    _mav_put_char_array(msg->payloads, 10, name, 10);
    _mav_put_float_array(msg->payloads, 20, data, 58);

    msg->msgid = MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_MIN_LEN, MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_LEN, MAVLINK_MSG_ID_DEBUG_FLOAT_ARRAY_CRC);
}

/**
 * @brief Encode a debug_float_array struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param debug_float_array C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_debug_float_array_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_debug_float_array_t* debug_float_array)
{
    return mavlink_msg_debug_float_array_pack(system_id, component_id, msg, debug_float_array->time_usec, debug_float_array->name, debug_float_array->array_id, debug_float_array->data);
}

/**
 * @brief Encode a debug_float_array struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param debug_float_array C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_debug_float_array_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_debug_float_array_t* debug_float_array)
{
    return mavlink_msg_debug_float_array_pack_chan(system_id, component_id, chan, msg, debug_float_array->time_usec, debug_float_array->name, debug_float_array->array_id, debug_float_array->data);
}

// MESSAGE DEBUG_FLOAT_ARRAY UNPACKING


/**
 * @brief Get field time_usec from debug_float_array message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_debug_float_array_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field name from debug_float_array message
 *
 * @return  Name, for human-friendly display in a Ground Control Station
 */
static inline uint16_t mavlink_msg_debug_float_array_get_name(const mavlink_message_t* msg, char *name)
{
    return _MAV_RETURN_char_array(msg, name, 10,  10);
}

/**
 * @brief Get field array_id from debug_float_array message
 *
 * @return  Unique ID used to discriminate between arrays
 */
static inline uint16_t mavlink_msg_debug_float_array_get_array_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field data from debug_float_array message
 *
 * @return  data
 */
static inline uint16_t mavlink_msg_debug_float_array_get_data(const mavlink_message_t* msg, float *data)
{
    return _MAV_RETURN_float_array(msg, data, 58,  20);
}

/**
 * @brief Decode a debug_float_array message into a struct
 *
 * @param msg The message to decode
 * @param debug_float_array C-struct to decode the message contents into
 */
static inline void mavlink_msg_debug_float_array_decode(const mavlink_message_t* msg, mavlink_debug_float_array_t* debug_float_array)
{
    debug_float_array->time_usec = mavlink_msg_debug_float_array_get_time_usec(msg);
    debug_float_array->array_id = mavlink_msg_debug_float_array_get_array_id(msg);
    mavlink_msg_debug_float_array_get_name(msg, debug_float_array->name);
    mavlink_msg_debug_float_array_get_data(msg, debug_float_array->data);
}
