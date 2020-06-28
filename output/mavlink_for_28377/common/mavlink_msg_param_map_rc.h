#ifndef MAVLINK_MSG_param_map_rc
#define MAVLINK_MSG_param_map_rc
// MESSAGE PARAM_MAP_RC PACKING

#define MAVLINK_MSG_ID_PARAM_MAP_RC 50

typedef struct __mavlink_param_map_rc_t {
 float param_value0; /*<  Initial parameter value*/
 float scale; /*<  Scale, maps the RC range [-1, 1] to a parameter value*/
 float param_value_min; /*<  Minimum param value. The protocol does not define if this overwrites an onboard minimum value. (Depends on implementation)*/
 float param_value_max; /*<  Maximum param value. The protocol does not define if this overwrites an onboard maximum value. (Depends on implementation)*/
 int16_t param_index; /*<  Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored), send -2 to disable any existing map for this rc_channel_index.*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 char param_id[16]; /*<  Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
 uint8_t parameter_rc_channel_index; /*<  Index of parameter RC channel. Not equal to the RC channel id. Typically corresponds to a potentiometer-knob on the RC.*/
} mavlink_param_map_rc_t;

#define MAVLINK_MSG_ID_PARAM_MAP_RC_LEN 37
#define MAVLINK_MSG_ID_PARAM_MAP_RC_MIN_LEN 37
#define MAVLINK_MSG_ID_50_LEN 37
#define MAVLINK_MSG_ID_50_MIN_LEN 37

#define MAVLINK_MSG_ID_PARAM_MAP_RC_CRC 78
#define MAVLINK_MSG_ID_50_CRC 78

#define MAVLINK_MSG_PARAM_MAP_RC_FIELD_PARAM_ID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_MAP_RC { \
    50, \
    "PARAM_MAP_RC", \
    9, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_param_map_rc_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_param_map_rc_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 20, offsetof(mavlink_param_map_rc_t, param_id) }, \
         { "param_index", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_param_map_rc_t, param_index) }, \
         { "parameter_rc_channel_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_param_map_rc_t, parameter_rc_channel_index) }, \
         { "param_value0", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_param_map_rc_t, param_value0) }, \
         { "scale", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_param_map_rc_t, scale) }, \
         { "param_value_min", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_param_map_rc_t, param_value_min) }, \
         { "param_value_max", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_param_map_rc_t, param_value_max) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_MAP_RC { \
    "PARAM_MAP_RC", \
    9, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_param_map_rc_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_param_map_rc_t, target_component) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 20, offsetof(mavlink_param_map_rc_t, param_id) }, \
         { "param_index", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_param_map_rc_t, param_index) }, \
         { "parameter_rc_channel_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_param_map_rc_t, parameter_rc_channel_index) }, \
         { "param_value0", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_param_map_rc_t, param_value0) }, \
         { "scale", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_param_map_rc_t, scale) }, \
         { "param_value_min", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_param_map_rc_t, param_value_min) }, \
         { "param_value_max", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_param_map_rc_t, param_value_max) }, \
         } \
}
#endif

/**
 * @brief Pack a param_map_rc message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param_id  Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_index  Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored), send -2 to disable any existing map for this rc_channel_index.
 * @param parameter_rc_channel_index  Index of parameter RC channel. Not equal to the RC channel id. Typically corresponds to a potentiometer-knob on the RC.
 * @param param_value0  Initial parameter value
 * @param scale  Scale, maps the RC range [-1, 1] to a parameter value
 * @param param_value_min  Minimum param value. The protocol does not define if this overwrites an onboard minimum value. (Depends on implementation)
 * @param param_value_max  Maximum param value. The protocol does not define if this overwrites an onboard maximum value. (Depends on implementation)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_map_rc_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *param_id, int16_t param_index, uint8_t parameter_rc_channel_index, float param_value0, float scale, float param_value_min, float param_value_max)
{
    _mav_put_float(((char*)msg->payloads), 0, param_value0);
    _mav_put_float(((char*)msg->payloads), 4, scale);
    _mav_put_float(((char*)msg->payloads), 8, param_value_min);
    _mav_put_float(((char*)msg->payloads), 12, param_value_max);
    _mav_put_int16_t(((char*)msg->payloads), 16, param_index);
    _mav_put_uint8_t(((char*)msg->payloads), 18, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 19, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 36, parameter_rc_channel_index);
    _mav_put_char_array(((char*)msg->payloads), 20, param_id, 16);
    msg->msgid = MAVLINK_MSG_ID_PARAM_MAP_RC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_MAP_RC_MIN_LEN, MAVLINK_MSG_ID_PARAM_MAP_RC_LEN, MAVLINK_MSG_ID_PARAM_MAP_RC_CRC);
}

/**
 * @brief Pack a param_map_rc message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param param_id  Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_index  Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored), send -2 to disable any existing map for this rc_channel_index.
 * @param parameter_rc_channel_index  Index of parameter RC channel. Not equal to the RC channel id. Typically corresponds to a potentiometer-knob on the RC.
 * @param param_value0  Initial parameter value
 * @param scale  Scale, maps the RC range [-1, 1] to a parameter value
 * @param param_value_min  Minimum param value. The protocol does not define if this overwrites an onboard minimum value. (Depends on implementation)
 * @param param_value_max  Maximum param value. The protocol does not define if this overwrites an onboard maximum value. (Depends on implementation)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_map_rc_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const char *param_id,int16_t param_index,uint8_t parameter_rc_channel_index,float param_value0,float scale,float param_value_min,float param_value_max)
{
    _mav_put_float(((char*)msg->payloads), 0, param_value0);
    _mav_put_float(((char*)msg->payloads), 4, scale);
    _mav_put_float(((char*)msg->payloads), 8, param_value_min);
    _mav_put_float(((char*)msg->payloads), 12, param_value_max);
    _mav_put_int16_t(((char*)msg->payloads), 16, param_index);
    _mav_put_uint8_t(((char*)msg->payloads), 18, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 19, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 36, parameter_rc_channel_index);
    _mav_put_char_array(((char*)msg->payloads), 20, param_id, 16);

    msg->msgid = MAVLINK_MSG_ID_PARAM_MAP_RC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_MAP_RC_MIN_LEN, MAVLINK_MSG_ID_PARAM_MAP_RC_LEN, MAVLINK_MSG_ID_PARAM_MAP_RC_CRC);
}

/**
 * @brief Encode a param_map_rc struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_map_rc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_map_rc_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_map_rc_t* param_map_rc)
{
    return mavlink_msg_param_map_rc_pack(system_id, component_id, msg, param_map_rc->target_system, param_map_rc->target_component, param_map_rc->param_id, param_map_rc->param_index, param_map_rc->parameter_rc_channel_index, param_map_rc->param_value0, param_map_rc->scale, param_map_rc->param_value_min, param_map_rc->param_value_max);
}

/**
 * @brief Encode a param_map_rc struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_map_rc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_map_rc_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_map_rc_t* param_map_rc)
{
    return mavlink_msg_param_map_rc_pack_chan(system_id, component_id, chan, msg, param_map_rc->target_system, param_map_rc->target_component, param_map_rc->param_id, param_map_rc->param_index, param_map_rc->parameter_rc_channel_index, param_map_rc->param_value0, param_map_rc->scale, param_map_rc->param_value_min, param_map_rc->param_value_max);
}

// MESSAGE PARAM_MAP_RC UNPACKING


/**
 * @brief Get field target_system from param_map_rc message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_param_map_rc_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field target_component from param_map_rc message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_param_map_rc_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field param_id from param_map_rc message
 *
 * @return  Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 */
static inline uint16_t mavlink_msg_param_map_rc_get_param_id(const mavlink_message_t* msg, char *param_id)
{
    return _MAV_RETURN_char_array(msg, param_id, 16,  20);
}

/**
 * @brief Get field param_index from param_map_rc message
 *
 * @return  Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored), send -2 to disable any existing map for this rc_channel_index.
 */
static inline int16_t mavlink_msg_param_map_rc_get_param_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field parameter_rc_channel_index from param_map_rc message
 *
 * @return  Index of parameter RC channel. Not equal to the RC channel id. Typically corresponds to a potentiometer-knob on the RC.
 */
static inline uint8_t mavlink_msg_param_map_rc_get_parameter_rc_channel_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field param_value0 from param_map_rc message
 *
 * @return  Initial parameter value
 */
static inline float mavlink_msg_param_map_rc_get_param_value0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field scale from param_map_rc message
 *
 * @return  Scale, maps the RC range [-1, 1] to a parameter value
 */
static inline float mavlink_msg_param_map_rc_get_scale(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param_value_min from param_map_rc message
 *
 * @return  Minimum param value. The protocol does not define if this overwrites an onboard minimum value. (Depends on implementation)
 */
static inline float mavlink_msg_param_map_rc_get_param_value_min(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param_value_max from param_map_rc message
 *
 * @return  Maximum param value. The protocol does not define if this overwrites an onboard maximum value. (Depends on implementation)
 */
static inline float mavlink_msg_param_map_rc_get_param_value_max(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a param_map_rc message into a struct
 *
 * @param msg The message to decode
 * @param param_map_rc C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_map_rc_decode(const mavlink_message_t* msg, mavlink_param_map_rc_t* param_map_rc)
{
    param_map_rc->param_value0 = mavlink_msg_param_map_rc_get_param_value0(msg);
    param_map_rc->scale = mavlink_msg_param_map_rc_get_scale(msg);
    param_map_rc->param_value_min = mavlink_msg_param_map_rc_get_param_value_min(msg);
    param_map_rc->param_value_max = mavlink_msg_param_map_rc_get_param_value_max(msg);
    param_map_rc->param_index = mavlink_msg_param_map_rc_get_param_index(msg);
    param_map_rc->target_system = mavlink_msg_param_map_rc_get_target_system(msg);
    param_map_rc->target_component = mavlink_msg_param_map_rc_get_target_component(msg);
    mavlink_msg_param_map_rc_get_param_id(msg, param_map_rc->param_id);
    param_map_rc->parameter_rc_channel_index = mavlink_msg_param_map_rc_get_parameter_rc_channel_index(msg);
}
#endif
