#ifndef MAVLINK_MSG_log_erase
#define MAVLINK_MSG_log_erase
// MESSAGE LOG_ERASE PACKING

#define MAVLINK_MSG_ID_LOG_ERASE 121

typedef struct __mavlink_log_erase_t {
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
} mavlink_log_erase_t;

#define MAVLINK_MSG_ID_LOG_ERASE_LEN 2
#define MAVLINK_MSG_ID_LOG_ERASE_MIN_LEN 2
#define MAVLINK_MSG_ID_121_LEN 2
#define MAVLINK_MSG_ID_121_MIN_LEN 2

#define MAVLINK_MSG_ID_LOG_ERASE_CRC 237
#define MAVLINK_MSG_ID_121_CRC 237



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LOG_ERASE { \
    121, \
    "LOG_ERASE", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_log_erase_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_log_erase_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LOG_ERASE { \
    "LOG_ERASE", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_log_erase_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_log_erase_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a log_erase message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_log_erase_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 1, target_component);

    msg->msgid = MAVLINK_MSG_ID_LOG_ERASE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LOG_ERASE_MIN_LEN, MAVLINK_MSG_ID_LOG_ERASE_LEN, MAVLINK_MSG_ID_LOG_ERASE_CRC);
}

/**
 * @brief Pack a log_erase message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_log_erase_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 1, target_component);


    msg->msgid = MAVLINK_MSG_ID_LOG_ERASE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LOG_ERASE_MIN_LEN, MAVLINK_MSG_ID_LOG_ERASE_LEN, MAVLINK_MSG_ID_LOG_ERASE_CRC);
}

/**
 * @brief Encode a log_erase struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param log_erase C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_log_erase_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_log_erase_t* log_erase)
{
    return mavlink_msg_log_erase_pack(system_id, component_id, msg, log_erase->target_system, log_erase->target_component);
}

/**
 * @brief Encode a log_erase struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param log_erase C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_log_erase_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_log_erase_t* log_erase)
{
    return mavlink_msg_log_erase_pack_chan(system_id, component_id, chan, msg, log_erase->target_system, log_erase->target_component);
}

// MESSAGE LOG_ERASE UNPACKING


/**
 * @brief Get field target_system from log_erase message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_log_erase_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from log_erase message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_log_erase_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a log_erase message into a struct
 *
 * @param msg The message to decode
 * @param log_erase C-struct to decode the message contents into
 */
static inline void mavlink_msg_log_erase_decode(const mavlink_message_t* msg, mavlink_log_erase_t* log_erase)
{
    log_erase->target_system = mavlink_msg_log_erase_get_target_system(msg);
    log_erase->target_component = mavlink_msg_log_erase_get_target_component(msg);
}
#endif
