#pragma once
// MESSAGE PARAM_EXT_ACK PACKING

#define MAVLINK_MSG_ID_PARAM_EXT_ACK 324

typedef struct __mavlink_param_ext_ack_t {
 char param_id[16]; /*<  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
 char param_value[128]; /*<  Parameter value (new value if PARAM_ACK_ACCEPTED, current value otherwise)*/
 uint8_t param_type; /*<  Parameter type.*/
 uint8_t param_result; /*<  Result code.*/
} mavlink_param_ext_ack_t;

#define MAVLINK_MSG_ID_PARAM_EXT_ACK_LEN 146
#define MAVLINK_MSG_ID_PARAM_EXT_ACK_MIN_LEN 146
#define MAVLINK_MSG_ID_324_LEN 146
#define MAVLINK_MSG_ID_324_MIN_LEN 146

#define MAVLINK_MSG_ID_PARAM_EXT_ACK_CRC 132
#define MAVLINK_MSG_ID_324_CRC 132

#define MAVLINK_MSG_PARAM_EXT_ACK_FIELD_PARAM_ID_LEN 16
#define MAVLINK_MSG_PARAM_EXT_ACK_FIELD_PARAM_VALUE_LEN 128

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_ACK { \
    324, \
    "PARAM_EXT_ACK", \
    4, \
    {  { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 0, offsetof(mavlink_param_ext_ack_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_CHAR, 128, 16, offsetof(mavlink_param_ext_ack_t, param_value) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 144, offsetof(mavlink_param_ext_ack_t, param_type) }, \
         { "param_result", NULL, MAVLINK_TYPE_UINT8_T, 0, 145, offsetof(mavlink_param_ext_ack_t, param_result) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_ACK { \
    "PARAM_EXT_ACK", \
    4, \
    {  { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 0, offsetof(mavlink_param_ext_ack_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_CHAR, 128, 16, offsetof(mavlink_param_ext_ack_t, param_value) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 144, offsetof(mavlink_param_ext_ack_t, param_type) }, \
         { "param_result", NULL, MAVLINK_TYPE_UINT8_T, 0, 145, offsetof(mavlink_param_ext_ack_t, param_result) }, \
         } \
}
#endif

/**
 * @brief Pack a param_ext_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param param_id  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value  Parameter value (new value if PARAM_ACK_ACCEPTED, current value otherwise)
 * @param param_type  Parameter type.
 * @param param_result  Result code.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *param_id, const char *param_value, uint8_t param_type, uint8_t param_result)
{
    _mav_put_uint8_t(msg->payloads, 144, param_type);
    _mav_put_uint8_t(msg->payloads, 145, param_result);
    _mav_put_char_array(msg->payloads, 0, param_id, 16);
    _mav_put_char_array(msg->payloads, 16, param_value, 128);
    msg->msgid = MAVLINK_MSG_ID_PARAM_EXT_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_EXT_ACK_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_CRC);
}

/**
 * @brief Pack a param_ext_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_id  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value  Parameter value (new value if PARAM_ACK_ACCEPTED, current value otherwise)
 * @param param_type  Parameter type.
 * @param param_result  Result code.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *param_id,const char *param_value,uint8_t param_type,uint8_t param_result)
{
    _mav_put_uint8_t(msg->payloads, 144, param_type);
    _mav_put_uint8_t(msg->payloads, 145, param_result);
    _mav_put_char_array(msg->payloads, 0, param_id, 16);
    _mav_put_char_array(msg->payloads, 16, param_value, 128);

    msg->msgid = MAVLINK_MSG_ID_PARAM_EXT_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_EXT_ACK_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_CRC);
}

/**
 * @brief Encode a param_ext_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_ext_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_ext_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_ext_ack_t* param_ext_ack)
{
    return mavlink_msg_param_ext_ack_pack(system_id, component_id, msg, param_ext_ack->param_id, param_ext_ack->param_value, param_ext_ack->param_type, param_ext_ack->param_result);
}

/**
 * @brief Encode a param_ext_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_ext_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_ext_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_ext_ack_t* param_ext_ack)
{
    return mavlink_msg_param_ext_ack_pack_chan(system_id, component_id, chan, msg, param_ext_ack->param_id, param_ext_ack->param_value, param_ext_ack->param_type, param_ext_ack->param_result);
}

// MESSAGE PARAM_EXT_ACK UNPACKING


/**
 * @brief Get field param_id from param_ext_ack message
 *
 * @return  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 */
static inline uint16_t mavlink_msg_param_ext_ack_get_param_id(const mavlink_message_t* msg, char *param_id)
{
    return _MAV_RETURN_char_array(msg, param_id, 16,  0);
}

/**
 * @brief Get field param_value from param_ext_ack message
 *
 * @return  Parameter value (new value if PARAM_ACK_ACCEPTED, current value otherwise)
 */
static inline uint16_t mavlink_msg_param_ext_ack_get_param_value(const mavlink_message_t* msg, char *param_value)
{
    return _MAV_RETURN_char_array(msg, param_value, 128,  16);
}

/**
 * @brief Get field param_type from param_ext_ack message
 *
 * @return  Parameter type.
 */
static inline uint8_t mavlink_msg_param_ext_ack_get_param_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  144);
}

/**
 * @brief Get field param_result from param_ext_ack message
 *
 * @return  Result code.
 */
static inline uint8_t mavlink_msg_param_ext_ack_get_param_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  145);
}

/**
 * @brief Decode a param_ext_ack message into a struct
 *
 * @param msg The message to decode
 * @param param_ext_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_ext_ack_decode(const mavlink_message_t* msg, mavlink_param_ext_ack_t* param_ext_ack)
{
    mavlink_msg_param_ext_ack_get_param_id(msg, param_ext_ack->param_id);
    mavlink_msg_param_ext_ack_get_param_value(msg, param_ext_ack->param_value);
    param_ext_ack->param_type = mavlink_msg_param_ext_ack_get_param_type(msg);
    param_ext_ack->param_result = mavlink_msg_param_ext_ack_get_param_result(msg);
}
