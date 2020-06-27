#ifndef MAVLINK_MSG_play_tune_v2
#define MAVLINK_MSG_play_tune_v2
// MESSAGE PLAY_TUNE_V2 PACKING

#define MAVLINK_MSG_ID_PLAY_TUNE_V2 400

typedef struct __mavlink_play_tune_v2_t {
 uint32_t format; /*<  Tune format*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 char tune[248]; /*<  Tune definition as a NULL-terminated string.*/
} mavlink_play_tune_v2_t;

#define MAVLINK_MSG_ID_PLAY_TUNE_V2_LEN 254
#define MAVLINK_MSG_ID_PLAY_TUNE_V2_MIN_LEN 254
#define MAVLINK_MSG_ID_400_LEN 254
#define MAVLINK_MSG_ID_400_MIN_LEN 254

#define MAVLINK_MSG_ID_PLAY_TUNE_V2_CRC 110
#define MAVLINK_MSG_ID_400_CRC 110

#define MAVLINK_MSG_PLAY_TUNE_V2_FIELD_TUNE_LEN 248

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PLAY_TUNE_V2 { \
    400, \
    "PLAY_TUNE_V2", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_play_tune_v2_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_play_tune_v2_t, target_component) }, \
         { "format", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_play_tune_v2_t, format) }, \
         { "tune", NULL, MAVLINK_TYPE_CHAR, 248, 6, offsetof(mavlink_play_tune_v2_t, tune) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PLAY_TUNE_V2 { \
    "PLAY_TUNE_V2", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_play_tune_v2_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_play_tune_v2_t, target_component) }, \
         { "format", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_play_tune_v2_t, format) }, \
         { "tune", NULL, MAVLINK_TYPE_CHAR, 248, 6, offsetof(mavlink_play_tune_v2_t, tune) }, \
         } \
}
#endif

/**
 * @brief Pack a play_tune_v2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param format  Tune format
 * @param tune  Tune definition as a NULL-terminated string.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_play_tune_v2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint32_t format, const char *tune)
{
    _mav_put_uint32_t(msg->payloads, 0, format);
    _mav_put_uint8_t(msg->payloads, 4, target_system);
    _mav_put_uint8_t(msg->payloads, 5, target_component);
    _mav_put_char_array(msg->payloads, 6, tune, 248);
    msg->msgid = MAVLINK_MSG_ID_PLAY_TUNE_V2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PLAY_TUNE_V2_MIN_LEN, MAVLINK_MSG_ID_PLAY_TUNE_V2_LEN, MAVLINK_MSG_ID_PLAY_TUNE_V2_CRC);
}

/**
 * @brief Pack a play_tune_v2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param format  Tune format
 * @param tune  Tune definition as a NULL-terminated string.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_play_tune_v2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint32_t format,const char *tune)
{
    _mav_put_uint32_t(msg->payloads, 0, format);
    _mav_put_uint8_t(msg->payloads, 4, target_system);
    _mav_put_uint8_t(msg->payloads, 5, target_component);
    _mav_put_char_array(msg->payloads, 6, tune, 248);

    msg->msgid = MAVLINK_MSG_ID_PLAY_TUNE_V2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PLAY_TUNE_V2_MIN_LEN, MAVLINK_MSG_ID_PLAY_TUNE_V2_LEN, MAVLINK_MSG_ID_PLAY_TUNE_V2_CRC);
}

/**
 * @brief Encode a play_tune_v2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param play_tune_v2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_play_tune_v2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_play_tune_v2_t* play_tune_v2)
{
    return mavlink_msg_play_tune_v2_pack(system_id, component_id, msg, play_tune_v2->target_system, play_tune_v2->target_component, play_tune_v2->format, play_tune_v2->tune);
}

/**
 * @brief Encode a play_tune_v2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param play_tune_v2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_play_tune_v2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_play_tune_v2_t* play_tune_v2)
{
    return mavlink_msg_play_tune_v2_pack_chan(system_id, component_id, chan, msg, play_tune_v2->target_system, play_tune_v2->target_component, play_tune_v2->format, play_tune_v2->tune);
}

// MESSAGE PLAY_TUNE_V2 UNPACKING


/**
 * @brief Get field target_system from play_tune_v2 message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_play_tune_v2_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field target_component from play_tune_v2 message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_play_tune_v2_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field format from play_tune_v2 message
 *
 * @return  Tune format
 */
static inline uint32_t mavlink_msg_play_tune_v2_get_format(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field tune from play_tune_v2 message
 *
 * @return  Tune definition as a NULL-terminated string.
 */
static inline uint16_t mavlink_msg_play_tune_v2_get_tune(const mavlink_message_t* msg, char *tune)
{
    return _MAV_RETURN_char_array(msg, tune, 248,  6);
}

/**
 * @brief Decode a play_tune_v2 message into a struct
 *
 * @param msg The message to decode
 * @param play_tune_v2 C-struct to decode the message contents into
 */
static inline void mavlink_msg_play_tune_v2_decode(const mavlink_message_t* msg, mavlink_play_tune_v2_t* play_tune_v2)
{
    play_tune_v2->format = mavlink_msg_play_tune_v2_get_format(msg);
    play_tune_v2->target_system = mavlink_msg_play_tune_v2_get_target_system(msg);
    play_tune_v2->target_component = mavlink_msg_play_tune_v2_get_target_component(msg);
    mavlink_msg_play_tune_v2_get_tune(msg, play_tune_v2->tune);
}
#endif
