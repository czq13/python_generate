#ifndef MAVLINK_MSG_param_ext_request_list
#define MAVLINK_MSG_param_ext_request_list
// MESSAGE PARAM_EXT_REQUEST_LIST PACKING

#define MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST 321

typedef struct __mavlink_param_ext_request_list_t {
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
} mavlink_param_ext_request_list_t;

#define MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST_LEN 2
#define MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST_MIN_LEN 2
#define MAVLINK_MSG_ID_321_LEN 2
#define MAVLINK_MSG_ID_321_MIN_LEN 2

#define MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST_CRC 88
#define MAVLINK_MSG_ID_321_CRC 88



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_REQUEST_LIST { \
    321, \
    "PARAM_EXT_REQUEST_LIST", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_ext_request_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_ext_request_list_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_REQUEST_LIST { \
    "PARAM_EXT_REQUEST_LIST", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_ext_request_list_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_ext_request_list_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a param_ext_request_list message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_request_list_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 1, target_component);

    msg->msgid = MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST_LEN, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST_CRC);
}

/**
 * @brief Pack a param_ext_request_list message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_request_list_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 1, target_component);


    msg->msgid = MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST_LEN, MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST_CRC);
}

/**
 * @brief Encode a param_ext_request_list struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_ext_request_list C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_ext_request_list_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_ext_request_list_t* param_ext_request_list)
{
    return mavlink_msg_param_ext_request_list_pack(system_id, component_id, msg, param_ext_request_list->target_system, param_ext_request_list->target_component);
}

/**
 * @brief Encode a param_ext_request_list struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_ext_request_list C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_ext_request_list_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_ext_request_list_t* param_ext_request_list)
{
    return mavlink_msg_param_ext_request_list_pack_chan(system_id, component_id, chan, msg, param_ext_request_list->target_system, param_ext_request_list->target_component);
}

// MESSAGE PARAM_EXT_REQUEST_LIST UNPACKING


/**
 * @brief Get field target_system from param_ext_request_list message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_param_ext_request_list_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from param_ext_request_list message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_param_ext_request_list_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a param_ext_request_list message into a struct
 *
 * @param msg The message to decode
 * @param param_ext_request_list C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_ext_request_list_decode(const mavlink_message_t* msg, mavlink_param_ext_request_list_t* param_ext_request_list)
{
    param_ext_request_list->target_system = mavlink_msg_param_ext_request_list_get_target_system(msg);
    param_ext_request_list->target_component = mavlink_msg_param_ext_request_list_get_target_component(msg);
}
#endif
