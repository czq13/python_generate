#pragma once
// MESSAGE PARAM_EXT_SET PACKING

#define MAVLINK_MSG_ID_PARAM_EXT_SET 323

typedef struct __mavlink_param_ext_set_t {
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 char param_id[16]; /*<  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
 char param_value[128]; /*<  Parameter value*/
 uint8_t param_type; /*<  Parameter type.*/
} mavlink_param_ext_set_t;

#define MAVLINK_MSG_ID_PARAM_EXT_SET_LEN 147
#define MAVLINK_MSG_ID_PARAM_EXT_SET_MIN_LEN 147
#define MAVLINK_MSG_ID_323_LEN 147
#define MAVLINK_MSG_ID_323_MIN_LEN 147

#define MAVLINK_MSG_ID_PARAM_EXT_SET_CRC 78
#define MAVLINK_MSG_ID_323_CRC 78

#define MAVLINK_MSG_PARAM_EXT_SET_FIELD_PARAM_ID_LEN 16
#define MAVLINK_MSG_PARAM_EXT_SET_FIELD_PARAM_VALUE_LEN 128

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_SET { \
    323, \
    "PARAM_EXT_SET", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_ext_set_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_ext_set_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 2, offsetof(mavlink_param_ext_set_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_CHAR, 128, 18, offsetof(mavlink_param_ext_set_t, param_value) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 146, offsetof(mavlink_param_ext_set_t, param_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_SET { \
    "PARAM_EXT_SET", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_ext_set_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_ext_set_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 2, offsetof(mavlink_param_ext_set_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_CHAR, 128, 18, offsetof(mavlink_param_ext_set_t, param_value) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 146, offsetof(mavlink_param_ext_set_t, param_type) }, \
         } \
}
#endif

/**
 * @brief Pack a param_ext_set message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param_id  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value  Parameter value
 * @param param_type  Parameter type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_set_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *param_id, const char *param_value, uint8_t param_type)
{
    _mav_put_uint8_t(msg->payloads, 0, target_system);
    _mav_put_uint8_t(msg->payloads, 1, target_component);
    _mav_put_uint8_t(msg->payloads, 146, param_type);
    _mav_put_char_array(msg->payloads, 2, param_id, 16);
    _mav_put_char_array(msg->payloads, 18, param_value, 128);
    msg->msgid = MAVLINK_MSG_ID_PARAM_EXT_SET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_EXT_SET_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_SET_LEN, MAVLINK_MSG_ID_PARAM_EXT_SET_CRC);
}

/**
 * @brief Pack a param_ext_set message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param_id  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value  Parameter value
 * @param param_type  Parameter type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_set_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const char *param_id,const char *param_value,uint8_t param_type)
{
    _mav_put_uint8_t(msg->payloads, 0, target_system);
    _mav_put_uint8_t(msg->payloads, 1, target_component);
    _mav_put_uint8_t(msg->payloads, 146, param_type);
    _mav_put_char_array(msg->payloads, 2, param_id, 16);
    _mav_put_char_array(msg->payloads, 18, param_value, 128);

    msg->msgid = MAVLINK_MSG_ID_PARAM_EXT_SET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_EXT_SET_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_SET_LEN, MAVLINK_MSG_ID_PARAM_EXT_SET_CRC);
}

/**
 * @brief Encode a param_ext_set struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_ext_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_ext_set_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_ext_set_t* param_ext_set)
{
    return mavlink_msg_param_ext_set_pack(system_id, component_id, msg, param_ext_set->target_system, param_ext_set->target_component, param_ext_set->param_id, param_ext_set->param_value, param_ext_set->param_type);
}

/**
 * @brief Encode a param_ext_set struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_ext_set C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_ext_set_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_ext_set_t* param_ext_set)
{
    return mavlink_msg_param_ext_set_pack_chan(system_id, component_id, chan, msg, param_ext_set->target_system, param_ext_set->target_component, param_ext_set->param_id, param_ext_set->param_value, param_ext_set->param_type);
}

// MESSAGE PARAM_EXT_SET UNPACKING


/**
 * @brief Get field target_system from param_ext_set message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_param_ext_set_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from param_ext_set message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_param_ext_set_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field param_id from param_ext_set message
 *
 * @return  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 */
static inline uint16_t mavlink_msg_param_ext_set_get_param_id(const mavlink_message_t* msg, char *param_id)
{
    return _MAV_RETURN_char_array(msg, param_id, 16,  2);
}

/**
 * @brief Get field param_value from param_ext_set message
 *
 * @return  Parameter value
 */
static inline uint16_t mavlink_msg_param_ext_set_get_param_value(const mavlink_message_t* msg, char *param_value)
{
    return _MAV_RETURN_char_array(msg, param_value, 128,  18);
}

/**
 * @brief Get field param_type from param_ext_set message
 *
 * @return  Parameter type.
 */
static inline uint8_t mavlink_msg_param_ext_set_get_param_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  146);
}

/**
 * @brief Decode a param_ext_set message into a struct
 *
 * @param msg The message to decode
 * @param param_ext_set C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_ext_set_decode(const mavlink_message_t* msg, mavlink_param_ext_set_t* param_ext_set)
{
    param_ext_set->target_system = mavlink_msg_param_ext_set_get_target_system(msg);
    param_ext_set->target_component = mavlink_msg_param_ext_set_get_target_component(msg);
    mavlink_msg_param_ext_set_get_param_id(msg, param_ext_set->param_id);
    mavlink_msg_param_ext_set_get_param_value(msg, param_ext_set->param_value);
    param_ext_set->param_type = mavlink_msg_param_ext_set_get_param_type(msg);
}
