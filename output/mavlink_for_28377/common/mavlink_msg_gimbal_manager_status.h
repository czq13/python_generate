#ifndef MAVLINK_MSG_gimbal_manager_status
#define MAVLINK_MSG_gimbal_manager_status
// MESSAGE GIMBAL_MANAGER_STATUS PACKING

#define MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS 281

typedef struct __mavlink_gimbal_manager_status_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 uint32_t flags; /*<  High level gimbal manager flags currently applied.*/
 uint8_t gimbal_device_id; /*<  Gimbal device ID that this gimbal manager is responsible for.*/
} mavlink_gimbal_manager_status_t;

#define MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS_LEN 9
#define MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS_MIN_LEN 9
#define MAVLINK_MSG_ID_281_LEN 9
#define MAVLINK_MSG_ID_281_MIN_LEN 9

#define MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS_CRC 0
#define MAVLINK_MSG_ID_281_CRC 0



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GIMBAL_MANAGER_STATUS { \
    281, \
    "GIMBAL_MANAGER_STATUS", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gimbal_manager_status_t, time_boot_ms) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_gimbal_manager_status_t, flags) }, \
         { "gimbal_device_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_gimbal_manager_status_t, gimbal_device_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GIMBAL_MANAGER_STATUS { \
    "GIMBAL_MANAGER_STATUS", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gimbal_manager_status_t, time_boot_ms) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_gimbal_manager_status_t, flags) }, \
         { "gimbal_device_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_gimbal_manager_status_t, gimbal_device_id) }, \
         } \
}
#endif

/**
 * @brief Pack a gimbal_manager_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param flags  High level gimbal manager flags currently applied.
 * @param gimbal_device_id  Gimbal device ID that this gimbal manager is responsible for.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gimbal_manager_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t flags, uint8_t gimbal_device_id)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_uint32_t(((char*)msg->payloads), 4, flags);
    _mav_put_uint8_t(((char*)msg->payloads), 8, gimbal_device_id);

    msg->msgid = MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS_MIN_LEN, MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS_LEN, MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS_CRC);
}

/**
 * @brief Pack a gimbal_manager_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param flags  High level gimbal manager flags currently applied.
 * @param gimbal_device_id  Gimbal device ID that this gimbal manager is responsible for.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gimbal_manager_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t flags,uint8_t gimbal_device_id)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_uint32_t(((char*)msg->payloads), 4, flags);
    _mav_put_uint8_t(((char*)msg->payloads), 8, gimbal_device_id);


    msg->msgid = MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS_MIN_LEN, MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS_LEN, MAVLINK_MSG_ID_GIMBAL_MANAGER_STATUS_CRC);
}

/**
 * @brief Encode a gimbal_manager_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gimbal_manager_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gimbal_manager_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gimbal_manager_status_t* gimbal_manager_status)
{
    return mavlink_msg_gimbal_manager_status_pack(system_id, component_id, msg, gimbal_manager_status->time_boot_ms, gimbal_manager_status->flags, gimbal_manager_status->gimbal_device_id);
}

/**
 * @brief Encode a gimbal_manager_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gimbal_manager_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gimbal_manager_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gimbal_manager_status_t* gimbal_manager_status)
{
    return mavlink_msg_gimbal_manager_status_pack_chan(system_id, component_id, chan, msg, gimbal_manager_status->time_boot_ms, gimbal_manager_status->flags, gimbal_manager_status->gimbal_device_id);
}

// MESSAGE GIMBAL_MANAGER_STATUS UNPACKING


/**
 * @brief Get field time_boot_ms from gimbal_manager_status message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_gimbal_manager_status_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field flags from gimbal_manager_status message
 *
 * @return  High level gimbal manager flags currently applied.
 */
static inline uint32_t mavlink_msg_gimbal_manager_status_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field gimbal_device_id from gimbal_manager_status message
 *
 * @return  Gimbal device ID that this gimbal manager is responsible for.
 */
static inline uint8_t mavlink_msg_gimbal_manager_status_get_gimbal_device_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a gimbal_manager_status message into a struct
 *
 * @param msg The message to decode
 * @param gimbal_manager_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_gimbal_manager_status_decode(const mavlink_message_t* msg, mavlink_gimbal_manager_status_t* gimbal_manager_status)
{
    gimbal_manager_status->time_boot_ms = mavlink_msg_gimbal_manager_status_get_time_boot_ms(msg);
    gimbal_manager_status->flags = mavlink_msg_gimbal_manager_status_get_flags(msg);
    gimbal_manager_status->gimbal_device_id = mavlink_msg_gimbal_manager_status_get_gimbal_device_id(msg);
}
#endif
