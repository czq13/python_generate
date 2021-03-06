#ifndef MAVLINK_MSG_log_data
#define MAVLINK_MSG_log_data
// MESSAGE LOG_DATA PACKING

#define MAVLINK_MSG_ID_LOG_DATA 120

typedef struct __mavlink_log_data_t {
 uint32_t ofs; /*<  Offset into the log*/
 uint16_t id; /*<  Log id (from LOG_ENTRY reply)*/
 uint8_t count; /*< [bytes] Number of bytes (zero for end of log)*/
 uint8_t data[90]; /*<  log data*/
} mavlink_log_data_t;

#define MAVLINK_MSG_ID_LOG_DATA_LEN 97
#define MAVLINK_MSG_ID_LOG_DATA_MIN_LEN 97
#define MAVLINK_MSG_ID_120_LEN 97
#define MAVLINK_MSG_ID_120_MIN_LEN 97

#define MAVLINK_MSG_ID_LOG_DATA_CRC 134
#define MAVLINK_MSG_ID_120_CRC 134

#define MAVLINK_MSG_LOG_DATA_FIELD_DATA_LEN 90

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LOG_DATA { \
    120, \
    "LOG_DATA", \
    4, \
    {  { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_log_data_t, id) }, \
         { "ofs", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_log_data_t, ofs) }, \
         { "count", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_log_data_t, count) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 90, 7, offsetof(mavlink_log_data_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LOG_DATA { \
    "LOG_DATA", \
    4, \
    {  { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_log_data_t, id) }, \
         { "ofs", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_log_data_t, ofs) }, \
         { "count", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_log_data_t, count) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 90, 7, offsetof(mavlink_log_data_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a log_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id  Log id (from LOG_ENTRY reply)
 * @param ofs  Offset into the log
 * @param count [bytes] Number of bytes (zero for end of log)
 * @param data  log data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_log_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t id, uint32_t ofs, uint8_t count, const uint8_t *data)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, ofs);
    _mav_put_uint16_t(((char*)msg->payloads), 4, id);
    _mav_put_uint8_t(((char*)msg->payloads), 6, count);
    _mav_put_uint8_t_array(((char*)msg->payloads), 7, data, 90);
    msg->msgid = MAVLINK_MSG_ID_LOG_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LOG_DATA_MIN_LEN, MAVLINK_MSG_ID_LOG_DATA_LEN, MAVLINK_MSG_ID_LOG_DATA_CRC);
}

/**
 * @brief Pack a log_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id  Log id (from LOG_ENTRY reply)
 * @param ofs  Offset into the log
 * @param count [bytes] Number of bytes (zero for end of log)
 * @param data  log data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_log_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t id,uint32_t ofs,uint8_t count,const uint8_t *data)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, ofs);
    _mav_put_uint16_t(((char*)msg->payloads), 4, id);
    _mav_put_uint8_t(((char*)msg->payloads), 6, count);
    _mav_put_uint8_t_array(((char*)msg->payloads), 7, data, 90);

    msg->msgid = MAVLINK_MSG_ID_LOG_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LOG_DATA_MIN_LEN, MAVLINK_MSG_ID_LOG_DATA_LEN, MAVLINK_MSG_ID_LOG_DATA_CRC);
}

/**
 * @brief Encode a log_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param log_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_log_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_log_data_t* log_data)
{
    return mavlink_msg_log_data_pack(system_id, component_id, msg, log_data->id, log_data->ofs, log_data->count, log_data->data);
}

/**
 * @brief Encode a log_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param log_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_log_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_log_data_t* log_data)
{
    return mavlink_msg_log_data_pack_chan(system_id, component_id, chan, msg, log_data->id, log_data->ofs, log_data->count, log_data->data);
}

// MESSAGE LOG_DATA UNPACKING


/**
 * @brief Get field id from log_data message
 *
 * @return  Log id (from LOG_ENTRY reply)
 */
static inline uint16_t mavlink_msg_log_data_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field ofs from log_data message
 *
 * @return  Offset into the log
 */
static inline uint32_t mavlink_msg_log_data_get_ofs(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field count from log_data message
 *
 * @return [bytes] Number of bytes (zero for end of log)
 */
static inline uint8_t mavlink_msg_log_data_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field data from log_data message
 *
 * @return  log data
 */
static inline uint16_t mavlink_msg_log_data_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 90,  7);
}

/**
 * @brief Decode a log_data message into a struct
 *
 * @param msg The message to decode
 * @param log_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_log_data_decode(const mavlink_message_t* msg, mavlink_log_data_t* log_data)
{
    log_data->ofs = mavlink_msg_log_data_get_ofs(msg);
    log_data->id = mavlink_msg_log_data_get_id(msg);
    log_data->count = mavlink_msg_log_data_get_count(msg);
    mavlink_msg_log_data_get_data(msg, log_data->data);
}
#endif
