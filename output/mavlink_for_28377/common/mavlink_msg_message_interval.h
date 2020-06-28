#ifndef MAVLINK_MSG_message_interval
#define MAVLINK_MSG_message_interval
// MESSAGE MESSAGE_INTERVAL PACKING

#define MAVLINK_MSG_ID_MESSAGE_INTERVAL 244

typedef struct __mavlink_message_interval_t {
 int32_t interval_us; /*< [us] The interval between two messages. A value of -1 indicates this stream is disabled, 0 indicates it is not available, > 0 indicates the interval at which it is sent.*/
 uint16_t message_id; /*<  The ID of the requested MAVLink message. v1.0 is limited to 254 messages.*/
} mavlink_message_interval_t;

#define MAVLINK_MSG_ID_MESSAGE_INTERVAL_LEN 6
#define MAVLINK_MSG_ID_MESSAGE_INTERVAL_MIN_LEN 6
#define MAVLINK_MSG_ID_244_LEN 6
#define MAVLINK_MSG_ID_244_MIN_LEN 6

#define MAVLINK_MSG_ID_MESSAGE_INTERVAL_CRC 95
#define MAVLINK_MSG_ID_244_CRC 95



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MESSAGE_INTERVAL { \
    244, \
    "MESSAGE_INTERVAL", \
    2, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_message_interval_t, message_id) }, \
         { "interval_us", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_message_interval_t, interval_us) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MESSAGE_INTERVAL { \
    "MESSAGE_INTERVAL", \
    2, \
    {  { "message_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_message_interval_t, message_id) }, \
         { "interval_us", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_message_interval_t, interval_us) }, \
         } \
}
#endif

/**
 * @brief Pack a message_interval message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param message_id  The ID of the requested MAVLink message. v1.0 is limited to 254 messages.
 * @param interval_us [us] The interval between two messages. A value of -1 indicates this stream is disabled, 0 indicates it is not available, > 0 indicates the interval at which it is sent.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_message_interval_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t message_id, int32_t interval_us)
{
    _mav_put_int32_t(((char*)msg->payloads), 0, interval_us);
    _mav_put_uint16_t(((char*)msg->payloads), 4, message_id);

    msg->msgid = MAVLINK_MSG_ID_MESSAGE_INTERVAL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MESSAGE_INTERVAL_MIN_LEN, MAVLINK_MSG_ID_MESSAGE_INTERVAL_LEN, MAVLINK_MSG_ID_MESSAGE_INTERVAL_CRC);
}

/**
 * @brief Pack a message_interval message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param message_id  The ID of the requested MAVLink message. v1.0 is limited to 254 messages.
 * @param interval_us [us] The interval between two messages. A value of -1 indicates this stream is disabled, 0 indicates it is not available, > 0 indicates the interval at which it is sent.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_message_interval_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t message_id,int32_t interval_us)
{
    _mav_put_int32_t(((char*)msg->payloads), 0, interval_us);
    _mav_put_uint16_t(((char*)msg->payloads), 4, message_id);


    msg->msgid = MAVLINK_MSG_ID_MESSAGE_INTERVAL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MESSAGE_INTERVAL_MIN_LEN, MAVLINK_MSG_ID_MESSAGE_INTERVAL_LEN, MAVLINK_MSG_ID_MESSAGE_INTERVAL_CRC);
}

/**
 * @brief Encode a message_interval struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param message_interval C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_message_interval_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_message_interval_t* message_interval)
{
    return mavlink_msg_message_interval_pack(system_id, component_id, msg, message_interval->message_id, message_interval->interval_us);
}

/**
 * @brief Encode a message_interval struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param message_interval C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_message_interval_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_message_interval_t* message_interval)
{
    return mavlink_msg_message_interval_pack_chan(system_id, component_id, chan, msg, message_interval->message_id, message_interval->interval_us);
}

// MESSAGE MESSAGE_INTERVAL UNPACKING


/**
 * @brief Get field message_id from message_interval message
 *
 * @return  The ID of the requested MAVLink message. v1.0 is limited to 254 messages.
 */
static inline uint16_t mavlink_msg_message_interval_get_message_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field interval_us from message_interval message
 *
 * @return [us] The interval between two messages. A value of -1 indicates this stream is disabled, 0 indicates it is not available, > 0 indicates the interval at which it is sent.
 */
static inline int32_t mavlink_msg_message_interval_get_interval_us(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Decode a message_interval message into a struct
 *
 * @param msg The message to decode
 * @param message_interval C-struct to decode the message contents into
 */
static inline void mavlink_msg_message_interval_decode(const mavlink_message_t* msg, mavlink_message_interval_t* message_interval)
{
    message_interval->interval_us = mavlink_msg_message_interval_get_interval_us(msg);
    message_interval->message_id = mavlink_msg_message_interval_get_message_id(msg);
}
#endif
