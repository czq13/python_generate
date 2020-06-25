#pragma once
// MESSAGE STORAGE_INFORMATION PACKING

#define MAVLINK_MSG_ID_STORAGE_INFORMATION 261

typedef struct __mavlink_storage_information_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float total_capacity; /*< [MiB] Total capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.*/
 float used_capacity; /*< [MiB] Used capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.*/
 float available_capacity; /*< [MiB] Available storage capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.*/
 float read_speed; /*< [MiB/s] Read speed.*/
 float write_speed; /*< [MiB/s] Write speed.*/
 uint8_t storage_id; /*<  Storage ID (1 for first, 2 for second, etc.)*/
 uint8_t storage_count; /*<  Number of storage devices*/
 uint8_t status; /*<  Status of storage*/
} mavlink_storage_information_t;

#define MAVLINK_MSG_ID_STORAGE_INFORMATION_LEN 27
#define MAVLINK_MSG_ID_STORAGE_INFORMATION_MIN_LEN 27
#define MAVLINK_MSG_ID_261_LEN 27
#define MAVLINK_MSG_ID_261_MIN_LEN 27

#define MAVLINK_MSG_ID_STORAGE_INFORMATION_CRC 179
#define MAVLINK_MSG_ID_261_CRC 179



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_STORAGE_INFORMATION { \
    261, \
    "STORAGE_INFORMATION", \
    9, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_storage_information_t, time_boot_ms) }, \
         { "storage_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_storage_information_t, storage_id) }, \
         { "storage_count", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_storage_information_t, storage_count) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_storage_information_t, status) }, \
         { "total_capacity", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_storage_information_t, total_capacity) }, \
         { "used_capacity", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_storage_information_t, used_capacity) }, \
         { "available_capacity", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_storage_information_t, available_capacity) }, \
         { "read_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_storage_information_t, read_speed) }, \
         { "write_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_storage_information_t, write_speed) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_STORAGE_INFORMATION { \
    "STORAGE_INFORMATION", \
    9, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_storage_information_t, time_boot_ms) }, \
         { "storage_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_storage_information_t, storage_id) }, \
         { "storage_count", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_storage_information_t, storage_count) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_storage_information_t, status) }, \
         { "total_capacity", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_storage_information_t, total_capacity) }, \
         { "used_capacity", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_storage_information_t, used_capacity) }, \
         { "available_capacity", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_storage_information_t, available_capacity) }, \
         { "read_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_storage_information_t, read_speed) }, \
         { "write_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_storage_information_t, write_speed) }, \
         } \
}
#endif

/**
 * @brief Pack a storage_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param storage_id  Storage ID (1 for first, 2 for second, etc.)
 * @param storage_count  Number of storage devices
 * @param status  Status of storage
 * @param total_capacity [MiB] Total capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.
 * @param used_capacity [MiB] Used capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.
 * @param available_capacity [MiB] Available storage capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.
 * @param read_speed [MiB/s] Read speed.
 * @param write_speed [MiB/s] Write speed.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_storage_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t storage_id, uint8_t storage_count, uint8_t status, float total_capacity, float used_capacity, float available_capacity, float read_speed, float write_speed)
{
    _mav_put_uint32_t(msg->payloads, 0, time_boot_ms);
    _mav_put_float(msg->payloads, 4, total_capacity);
    _mav_put_float(msg->payloads, 8, used_capacity);
    _mav_put_float(msg->payloads, 12, available_capacity);
    _mav_put_float(msg->payloads, 16, read_speed);
    _mav_put_float(msg->payloads, 20, write_speed);
    _mav_put_uint8_t(msg->payloads, 24, storage_id);
    _mav_put_uint8_t(msg->payloads, 25, storage_count);
    _mav_put_uint8_t(msg->payloads, 26, status);

    msg->msgid = MAVLINK_MSG_ID_STORAGE_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_STORAGE_INFORMATION_LEN, MAVLINK_MSG_ID_STORAGE_INFORMATION_CRC);
}

/**
 * @brief Pack a storage_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param storage_id  Storage ID (1 for first, 2 for second, etc.)
 * @param storage_count  Number of storage devices
 * @param status  Status of storage
 * @param total_capacity [MiB] Total capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.
 * @param used_capacity [MiB] Used capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.
 * @param available_capacity [MiB] Available storage capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.
 * @param read_speed [MiB/s] Read speed.
 * @param write_speed [MiB/s] Write speed.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_storage_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t storage_id,uint8_t storage_count,uint8_t status,float total_capacity,float used_capacity,float available_capacity,float read_speed,float write_speed)
{
    _mav_put_uint32_t(msg->payloads, 0, time_boot_ms);
    _mav_put_float(msg->payloads, 4, total_capacity);
    _mav_put_float(msg->payloads, 8, used_capacity);
    _mav_put_float(msg->payloads, 12, available_capacity);
    _mav_put_float(msg->payloads, 16, read_speed);
    _mav_put_float(msg->payloads, 20, write_speed);
    _mav_put_uint8_t(msg->payloads, 24, storage_id);
    _mav_put_uint8_t(msg->payloads, 25, storage_count);
    _mav_put_uint8_t(msg->payloads, 26, status);


    msg->msgid = MAVLINK_MSG_ID_STORAGE_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_STORAGE_INFORMATION_LEN, MAVLINK_MSG_ID_STORAGE_INFORMATION_CRC);
}

/**
 * @brief Encode a storage_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param storage_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_storage_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_storage_information_t* storage_information)
{
    return mavlink_msg_storage_information_pack(system_id, component_id, msg, storage_information->time_boot_ms, storage_information->storage_id, storage_information->storage_count, storage_information->status, storage_information->total_capacity, storage_information->used_capacity, storage_information->available_capacity, storage_information->read_speed, storage_information->write_speed);
}

/**
 * @brief Encode a storage_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param storage_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_storage_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_storage_information_t* storage_information)
{
    return mavlink_msg_storage_information_pack_chan(system_id, component_id, chan, msg, storage_information->time_boot_ms, storage_information->storage_id, storage_information->storage_count, storage_information->status, storage_information->total_capacity, storage_information->used_capacity, storage_information->available_capacity, storage_information->read_speed, storage_information->write_speed);
}

// MESSAGE STORAGE_INFORMATION UNPACKING


/**
 * @brief Get field time_boot_ms from storage_information message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_storage_information_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field storage_id from storage_information message
 *
 * @return  Storage ID (1 for first, 2 for second, etc.)
 */
static inline uint8_t mavlink_msg_storage_information_get_storage_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field storage_count from storage_information message
 *
 * @return  Number of storage devices
 */
static inline uint8_t mavlink_msg_storage_information_get_storage_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field status from storage_information message
 *
 * @return  Status of storage
 */
static inline uint8_t mavlink_msg_storage_information_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  26);
}

/**
 * @brief Get field total_capacity from storage_information message
 *
 * @return [MiB] Total capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.
 */
static inline float mavlink_msg_storage_information_get_total_capacity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field used_capacity from storage_information message
 *
 * @return [MiB] Used capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.
 */
static inline float mavlink_msg_storage_information_get_used_capacity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field available_capacity from storage_information message
 *
 * @return [MiB] Available storage capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored.
 */
static inline float mavlink_msg_storage_information_get_available_capacity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field read_speed from storage_information message
 *
 * @return [MiB/s] Read speed.
 */
static inline float mavlink_msg_storage_information_get_read_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field write_speed from storage_information message
 *
 * @return [MiB/s] Write speed.
 */
static inline float mavlink_msg_storage_information_get_write_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a storage_information message into a struct
 *
 * @param msg The message to decode
 * @param storage_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_storage_information_decode(const mavlink_message_t* msg, mavlink_storage_information_t* storage_information)
{
    storage_information->time_boot_ms = mavlink_msg_storage_information_get_time_boot_ms(msg);
    storage_information->total_capacity = mavlink_msg_storage_information_get_total_capacity(msg);
    storage_information->used_capacity = mavlink_msg_storage_information_get_used_capacity(msg);
    storage_information->available_capacity = mavlink_msg_storage_information_get_available_capacity(msg);
    storage_information->read_speed = mavlink_msg_storage_information_get_read_speed(msg);
    storage_information->write_speed = mavlink_msg_storage_information_get_write_speed(msg);
    storage_information->storage_id = mavlink_msg_storage_information_get_storage_id(msg);
    storage_information->storage_count = mavlink_msg_storage_information_get_storage_count(msg);
    storage_information->status = mavlink_msg_storage_information_get_status(msg);
}
