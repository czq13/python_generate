#ifndef MAVLINK_MSG_system_time
#define MAVLINK_MSG_system_time
// MESSAGE SYSTEM_TIME PACKING

#define MAVLINK_MSG_ID_SYSTEM_TIME 2

typedef struct __mavlink_system_time_t {
 uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time).*/
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
} mavlink_system_time_t;

#define MAVLINK_MSG_ID_SYSTEM_TIME_LEN 12
#define MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN 12
#define MAVLINK_MSG_ID_2_LEN 12
#define MAVLINK_MSG_ID_2_MIN_LEN 12

#define MAVLINK_MSG_ID_SYSTEM_TIME_CRC 137
#define MAVLINK_MSG_ID_2_CRC 137



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYSTEM_TIME { \
    2, \
    "SYSTEM_TIME", \
    2, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_system_time_t, time_unix_usec) }, \
         { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_system_time_t, time_boot_ms) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYSTEM_TIME { \
    "SYSTEM_TIME", \
    2, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_system_time_t, time_unix_usec) }, \
         { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_system_time_t, time_boot_ms) }, \
         } \
}
#endif

/**
 * @brief Pack a system_time message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_time_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_unix_usec, uint32_t time_boot_ms)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_unix_usec);
    _mav_put_uint32_t(((char*)msg->payloads), 8, time_boot_ms);

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_TIME;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_CRC);
}

/**
 * @brief Pack a system_time message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_time_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_unix_usec,uint32_t time_boot_ms)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_unix_usec);
    _mav_put_uint32_t(((char*)msg->payloads), 8, time_boot_ms);


    msg->msgid = MAVLINK_MSG_ID_SYSTEM_TIME;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_CRC);
}

/**
 * @brief Encode a system_time struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param system_time C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_time_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_system_time_t* system_time)
{
    return mavlink_msg_system_time_pack(system_id, component_id, msg, system_time->time_unix_usec, system_time->time_boot_ms);
}

/**
 * @brief Encode a system_time struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param system_time C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_time_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_system_time_t* system_time)
{
    return mavlink_msg_system_time_pack_chan(system_id, component_id, chan, msg, system_time->time_unix_usec, system_time->time_boot_ms);
}

// MESSAGE SYSTEM_TIME UNPACKING


/**
 * @brief Get field time_unix_usec from system_time message
 *
 * @return [us] Timestamp (UNIX epoch time).
 */
static inline uint64_t mavlink_msg_system_time_get_time_unix_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field time_boot_ms from system_time message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_system_time_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Decode a system_time message into a struct
 *
 * @param msg The message to decode
 * @param system_time C-struct to decode the message contents into
 */
static inline void mavlink_msg_system_time_decode(const mavlink_message_t* msg, mavlink_system_time_t* system_time)
{
    system_time->time_unix_usec = mavlink_msg_system_time_get_time_unix_usec(msg);
    system_time->time_boot_ms = mavlink_msg_system_time_get_time_boot_ms(msg);
}
#endif
