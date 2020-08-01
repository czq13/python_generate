#ifndef MAVLINK_MSG_play_tune
#define MAVLINK_MSG_play_tune
// MESSAGE PLAY_TUNE PACKING

#define MAVLINK_MSG_ID_PLAY_TUNE 258

typedef struct __mavlink_play_tune_t {
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 char tune[30]; /*<  tune in board specific format*/
 char tune2[200]; /*<  tune extension (appended to tune)*/
} mavlink_play_tune_t;

#define MAVLINK_MSG_ID_PLAY_TUNE_LEN 232
#define MAVLINK_MSG_ID_PLAY_TUNE_MIN_LEN 32
#define MAVLINK_MSG_ID_258_LEN 232
#define MAVLINK_MSG_ID_258_MIN_LEN 32

#define MAVLINK_MSG_ID_PLAY_TUNE_CRC 187
#define MAVLINK_MSG_ID_258_CRC 187

#define MAVLINK_MSG_PLAY_TUNE_FIELD_TUNE_LEN 30
#define MAVLINK_MSG_PLAY_TUNE_FIELD_TUNE2_LEN 200

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PLAY_TUNE { \
    258, \
    "PLAY_TUNE", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_play_tune_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_play_tune_t, target_component) }, \
         { "tune", NULL, MAVLINK_TYPE_CHAR, 30, 2, offsetof(mavlink_play_tune_t, tune) }, \
         { "tune2", NULL, MAVLINK_TYPE_CHAR, 200, 32, offsetof(mavlink_play_tune_t, tune2) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PLAY_TUNE { \
    "PLAY_TUNE", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_play_tune_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_play_tune_t, target_component) }, \
         { "tune", NULL, MAVLINK_TYPE_CHAR, 30, 2, offsetof(mavlink_play_tune_t, tune) }, \
         { "tune2", NULL, MAVLINK_TYPE_CHAR, 200, 32, offsetof(mavlink_play_tune_t, tune2) }, \
         } \
}
#endif

/**
 * @brief Pack a play_tune message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param tune  tune in board specific format
 * @param tune2  tune extension (appended to tune)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_play_tune_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *tune, const char *tune2)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 1, target_component);
    _mav_put_char_array(((char*)msg->payloads), 2, tune, 30);
    _mav_put_char_array(((char*)msg->payloads), 32, tune2, 200);
    msg->msgid = MAVLINK_MSG_ID_PLAY_TUNE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PLAY_TUNE_MIN_LEN, MAVLINK_MSG_ID_PLAY_TUNE_LEN, MAVLINK_MSG_ID_PLAY_TUNE_CRC);
}

/**
 * @brief Pack a play_tune message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param tune  tune in board specific format
 * @param tune2  tune extension (appended to tune)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_play_tune_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const char *tune,const char *tune2)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 1, target_component);
    _mav_put_char_array(((char*)msg->payloads), 2, tune, 30);
    _mav_put_char_array(((char*)msg->payloads), 32, tune2, 200);

    msg->msgid = MAVLINK_MSG_ID_PLAY_TUNE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PLAY_TUNE_MIN_LEN, MAVLINK_MSG_ID_PLAY_TUNE_LEN, MAVLINK_MSG_ID_PLAY_TUNE_CRC);
}

/**
 * @brief Encode a play_tune struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param play_tune C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_play_tune_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_play_tune_t* play_tune)
{
    return mavlink_msg_play_tune_pack(system_id, component_id, msg, play_tune->target_system, play_tune->target_component, play_tune->tune, play_tune->tune2);
}

/**
 * @brief Encode a play_tune struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param play_tune C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_play_tune_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_play_tune_t* play_tune)
{
    return mavlink_msg_play_tune_pack_chan(system_id, component_id, chan, msg, play_tune->target_system, play_tune->target_component, play_tune->tune, play_tune->tune2);
}

// MESSAGE PLAY_TUNE UNPACKING


/**
 * @brief Get field target_system from play_tune message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_play_tune_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from play_tune message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_play_tune_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field tune from play_tune message
 *
 * @return  tune in board specific format
 */
static inline uint16_t mavlink_msg_play_tune_get_tune(const mavlink_message_t* msg, char *tune)
{
    return _MAV_RETURN_char_array(msg, tune, 30,  2);
}

/**
 * @brief Get field tune2 from play_tune message
 *
 * @return  tune extension (appended to tune)
 */
static inline uint16_t mavlink_msg_play_tune_get_tune2(const mavlink_message_t* msg, char *tune2)
{
    return _MAV_RETURN_char_array(msg, tune2, 200,  32);
}

/**
 * @brief Decode a play_tune message into a struct
 *
 * @param msg The message to decode
 * @param play_tune C-struct to decode the message contents into
 */
static inline void mavlink_msg_play_tune_decode(const mavlink_message_t* msg, mavlink_play_tune_t* play_tune)
{
    play_tune->target_system = mavlink_msg_play_tune_get_target_system(msg);
    play_tune->target_component = mavlink_msg_play_tune_get_target_component(msg);
    mavlink_msg_play_tune_get_tune(msg, play_tune->tune);
    mavlink_msg_play_tune_get_tune2(msg, play_tune->tune2);
}
#endif
