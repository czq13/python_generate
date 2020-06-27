#pragma once
// MESSAGE SUPPORTED_TUNES PACKING

#define MAVLINK_MSG_ID_SUPPORTED_TUNES 401

typedef struct __mavlink_supported_tunes_t {
 uint32_t format; /*<  Bitfield of supported tune formats.*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
} mavlink_supported_tunes_t;

#define MAVLINK_MSG_ID_SUPPORTED_TUNES_LEN 6
#define MAVLINK_MSG_ID_SUPPORTED_TUNES_MIN_LEN 6
#define MAVLINK_MSG_ID_401_LEN 6
#define MAVLINK_MSG_ID_401_MIN_LEN 6

#define MAVLINK_MSG_ID_SUPPORTED_TUNES_CRC 183
#define MAVLINK_MSG_ID_401_CRC 183



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SUPPORTED_TUNES { \
    401, \
    "SUPPORTED_TUNES", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_supported_tunes_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_supported_tunes_t, target_component) }, \
         { "format", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_supported_tunes_t, format) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SUPPORTED_TUNES { \
    "SUPPORTED_TUNES", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_supported_tunes_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_supported_tunes_t, target_component) }, \
         { "format", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_supported_tunes_t, format) }, \
         } \
}
#endif

/**
 * @brief Pack a supported_tunes message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param format  Bitfield of supported tune formats.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_supported_tunes_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint32_t format)
{
    _mav_put_uint32_t(msg->payloads, 0, format);
    _mav_put_uint8_t(msg->payloads, 4, target_system);
    _mav_put_uint8_t(msg->payloads, 5, target_component);

    msg->msgid = MAVLINK_MSG_ID_SUPPORTED_TUNES;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SUPPORTED_TUNES_MIN_LEN, MAVLINK_MSG_ID_SUPPORTED_TUNES_LEN, MAVLINK_MSG_ID_SUPPORTED_TUNES_CRC);
}

/**
 * @brief Pack a supported_tunes message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param format  Bitfield of supported tune formats.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_supported_tunes_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint32_t format)
{
    _mav_put_uint32_t(msg->payloads, 0, format);
    _mav_put_uint8_t(msg->payloads, 4, target_system);
    _mav_put_uint8_t(msg->payloads, 5, target_component);


    msg->msgid = MAVLINK_MSG_ID_SUPPORTED_TUNES;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SUPPORTED_TUNES_MIN_LEN, MAVLINK_MSG_ID_SUPPORTED_TUNES_LEN, MAVLINK_MSG_ID_SUPPORTED_TUNES_CRC);
}

/**
 * @brief Encode a supported_tunes struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param supported_tunes C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_supported_tunes_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_supported_tunes_t* supported_tunes)
{
    return mavlink_msg_supported_tunes_pack(system_id, component_id, msg, supported_tunes->target_system, supported_tunes->target_component, supported_tunes->format);
}

/**
 * @brief Encode a supported_tunes struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param supported_tunes C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_supported_tunes_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_supported_tunes_t* supported_tunes)
{
    return mavlink_msg_supported_tunes_pack_chan(system_id, component_id, chan, msg, supported_tunes->target_system, supported_tunes->target_component, supported_tunes->format);
}

// MESSAGE SUPPORTED_TUNES UNPACKING


/**
 * @brief Get field target_system from supported_tunes message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_supported_tunes_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field target_component from supported_tunes message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_supported_tunes_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field format from supported_tunes message
 *
 * @return  Bitfield of supported tune formats.
 */
static inline uint32_t mavlink_msg_supported_tunes_get_format(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a supported_tunes message into a struct
 *
 * @param msg The message to decode
 * @param supported_tunes C-struct to decode the message contents into
 */
static inline void mavlink_msg_supported_tunes_decode(const mavlink_message_t* msg, mavlink_supported_tunes_t* supported_tunes)
{
    supported_tunes->format = mavlink_msg_supported_tunes_get_format(msg);
    supported_tunes->target_system = mavlink_msg_supported_tunes_get_target_system(msg);
    supported_tunes->target_component = mavlink_msg_supported_tunes_get_target_component(msg);
}
