#ifndef MAVLINK_MSG_actuator_output_status
#define MAVLINK_MSG_actuator_output_status
// MESSAGE ACTUATOR_OUTPUT_STATUS PACKING

#define MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS 375

typedef struct __mavlink_actuator_output_status_t {
 uint64_t time_usec; /*< [us] Timestamp (since system boot).*/
 uint32_t active; /*<  Active outputs*/
 float actuator[32]; /*<  Servo / motor output array values. Zero values indicate unused channels.*/
} mavlink_actuator_output_status_t;

#define MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS_LEN 140
#define MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS_MIN_LEN 140
#define MAVLINK_MSG_ID_375_LEN 140
#define MAVLINK_MSG_ID_375_MIN_LEN 140

#define MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS_CRC 251
#define MAVLINK_MSG_ID_375_CRC 251

#define MAVLINK_MSG_ACTUATOR_OUTPUT_STATUS_FIELD_ACTUATOR_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ACTUATOR_OUTPUT_STATUS { \
    375, \
    "ACTUATOR_OUTPUT_STATUS", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_actuator_output_status_t, time_usec) }, \
         { "active", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_actuator_output_status_t, active) }, \
         { "actuator", NULL, MAVLINK_TYPE_FLOAT, 32, 12, offsetof(mavlink_actuator_output_status_t, actuator) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ACTUATOR_OUTPUT_STATUS { \
    "ACTUATOR_OUTPUT_STATUS", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_actuator_output_status_t, time_usec) }, \
         { "active", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_actuator_output_status_t, active) }, \
         { "actuator", NULL, MAVLINK_TYPE_FLOAT, 32, 12, offsetof(mavlink_actuator_output_status_t, actuator) }, \
         } \
}
#endif

/**
 * @brief Pack a actuator_output_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (since system boot).
 * @param active  Active outputs
 * @param actuator  Servo / motor output array values. Zero values indicate unused channels.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_actuator_output_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint32_t active, const float *actuator)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_uint32_t(((char*)msg->payloads), 8, active);
    _mav_put_float_array(((char*)msg->payloads), 12, actuator, 32);
    msg->msgid = MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS_LEN, MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS_CRC);
}

/**
 * @brief Pack a actuator_output_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (since system boot).
 * @param active  Active outputs
 * @param actuator  Servo / motor output array values. Zero values indicate unused channels.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_actuator_output_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint32_t active,const float *actuator)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_uint32_t(((char*)msg->payloads), 8, active);
    _mav_put_float_array(((char*)msg->payloads), 12, actuator, 32);

    msg->msgid = MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS_LEN, MAVLINK_MSG_ID_ACTUATOR_OUTPUT_STATUS_CRC);
}

/**
 * @brief Encode a actuator_output_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param actuator_output_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_actuator_output_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_actuator_output_status_t* actuator_output_status)
{
    return mavlink_msg_actuator_output_status_pack(system_id, component_id, msg, actuator_output_status->time_usec, actuator_output_status->active, actuator_output_status->actuator);
}

/**
 * @brief Encode a actuator_output_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param actuator_output_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_actuator_output_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_actuator_output_status_t* actuator_output_status)
{
    return mavlink_msg_actuator_output_status_pack_chan(system_id, component_id, chan, msg, actuator_output_status->time_usec, actuator_output_status->active, actuator_output_status->actuator);
}

// MESSAGE ACTUATOR_OUTPUT_STATUS UNPACKING


/**
 * @brief Get field time_usec from actuator_output_status message
 *
 * @return [us] Timestamp (since system boot).
 */
static inline uint64_t mavlink_msg_actuator_output_status_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field active from actuator_output_status message
 *
 * @return  Active outputs
 */
static inline uint32_t mavlink_msg_actuator_output_status_get_active(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field actuator from actuator_output_status message
 *
 * @return  Servo / motor output array values. Zero values indicate unused channels.
 */
static inline uint16_t mavlink_msg_actuator_output_status_get_actuator(const mavlink_message_t* msg, float *actuator)
{
    return _MAV_RETURN_float_array(msg, actuator, 32,  12);
}

/**
 * @brief Decode a actuator_output_status message into a struct
 *
 * @param msg The message to decode
 * @param actuator_output_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_actuator_output_status_decode(const mavlink_message_t* msg, mavlink_actuator_output_status_t* actuator_output_status)
{
    actuator_output_status->time_usec = mavlink_msg_actuator_output_status_get_time_usec(msg);
    actuator_output_status->active = mavlink_msg_actuator_output_status_get_active(msg);
    mavlink_msg_actuator_output_status_get_actuator(msg, actuator_output_status->actuator);
}
#endif
