#pragma once
// MESSAGE RAW_RPM PACKING

#define MAVLINK_MSG_ID_RAW_RPM 339

typedef struct __mavlink_raw_rpm_t {
 float frequency; /*< [rpm] Indicated rate*/
 uint8_t index; /*<  Index of this RPM sensor (0-indexed)*/
} mavlink_raw_rpm_t;

#define MAVLINK_MSG_ID_RAW_RPM_LEN 5
#define MAVLINK_MSG_ID_RAW_RPM_MIN_LEN 5
#define MAVLINK_MSG_ID_339_LEN 5
#define MAVLINK_MSG_ID_339_MIN_LEN 5

#define MAVLINK_MSG_ID_RAW_RPM_CRC 199
#define MAVLINK_MSG_ID_339_CRC 199



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RAW_RPM { \
    339, \
    "RAW_RPM", \
    2, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_raw_rpm_t, index) }, \
         { "frequency", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_raw_rpm_t, frequency) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RAW_RPM { \
    "RAW_RPM", \
    2, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_raw_rpm_t, index) }, \
         { "frequency", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_raw_rpm_t, frequency) }, \
         } \
}
#endif

/**
 * @brief Pack a raw_rpm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of this RPM sensor (0-indexed)
 * @param frequency [rpm] Indicated rate
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_raw_rpm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t index, float frequency)
{
    _mav_put_float(msg->payloads, 0, frequency);
    _mav_put_uint8_t(msg->payloads, 4, index);

    msg->msgid = MAVLINK_MSG_ID_RAW_RPM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RAW_RPM_MIN_LEN, MAVLINK_MSG_ID_RAW_RPM_LEN, MAVLINK_MSG_ID_RAW_RPM_CRC);
}

/**
 * @brief Pack a raw_rpm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  Index of this RPM sensor (0-indexed)
 * @param frequency [rpm] Indicated rate
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_raw_rpm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t index,float frequency)
{
    _mav_put_float(msg->payloads, 0, frequency);
    _mav_put_uint8_t(msg->payloads, 4, index);


    msg->msgid = MAVLINK_MSG_ID_RAW_RPM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RAW_RPM_MIN_LEN, MAVLINK_MSG_ID_RAW_RPM_LEN, MAVLINK_MSG_ID_RAW_RPM_CRC);
}

/**
 * @brief Encode a raw_rpm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param raw_rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_raw_rpm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_raw_rpm_t* raw_rpm)
{
    return mavlink_msg_raw_rpm_pack(system_id, component_id, msg, raw_rpm->index, raw_rpm->frequency);
}

/**
 * @brief Encode a raw_rpm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param raw_rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_raw_rpm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_raw_rpm_t* raw_rpm)
{
    return mavlink_msg_raw_rpm_pack_chan(system_id, component_id, chan, msg, raw_rpm->index, raw_rpm->frequency);
}

// MESSAGE RAW_RPM UNPACKING


/**
 * @brief Get field index from raw_rpm message
 *
 * @return  Index of this RPM sensor (0-indexed)
 */
static inline uint8_t mavlink_msg_raw_rpm_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field frequency from raw_rpm message
 *
 * @return [rpm] Indicated rate
 */
static inline float mavlink_msg_raw_rpm_get_frequency(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a raw_rpm message into a struct
 *
 * @param msg The message to decode
 * @param raw_rpm C-struct to decode the message contents into
 */
static inline void mavlink_msg_raw_rpm_decode(const mavlink_message_t* msg, mavlink_raw_rpm_t* raw_rpm)
{
    raw_rpm->frequency = mavlink_msg_raw_rpm_get_frequency(msg);
    raw_rpm->index = mavlink_msg_raw_rpm_get_index(msg);
}
