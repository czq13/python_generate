#ifndef MAVLINK_MSG_vision_position_estimate
#define MAVLINK_MSG_vision_position_estimate
// MESSAGE VISION_POSITION_ESTIMATE PACKING

#define MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE 102

typedef struct __mavlink_vision_position_estimate_t {
 uint64_t usec; /*< [us] Timestamp (UNIX time or time since system boot)*/
 float x; /*< [m] Local X position*/
 float y; /*< [m] Local Y position*/
 float z; /*< [m] Local Z position*/
 float roll; /*< [rad] Roll angle*/
 float pitch; /*< [rad] Pitch angle*/
 float yaw; /*< [rad] Yaw angle*/
 float covariance[21]; /*<  Row-major representation of pose 6x6 cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array.*/
 uint8_t reset_counter; /*<  Estimate reset counter. This should be incremented when the estimate resets in any of the dimensions (position, velocity, attitude, angular speed). This is designed to be used when e.g an external SLAM system detects a loop-closure and the estimate jumps.*/
} mavlink_vision_position_estimate_t;

#define MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE_LEN 117
#define MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE_MIN_LEN 32
#define MAVLINK_MSG_ID_102_LEN 117
#define MAVLINK_MSG_ID_102_MIN_LEN 32

#define MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE_CRC 158
#define MAVLINK_MSG_ID_102_CRC 158

#define MAVLINK_MSG_VISION_POSITION_ESTIMATE_FIELD_COVARIANCE_LEN 21

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VISION_POSITION_ESTIMATE { \
    102, \
    "VISION_POSITION_ESTIMATE", \
    9, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vision_position_estimate_t, usec) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vision_position_estimate_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vision_position_estimate_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vision_position_estimate_t, z) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vision_position_estimate_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_vision_position_estimate_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_vision_position_estimate_t, yaw) }, \
         { "covariance", NULL, MAVLINK_TYPE_FLOAT, 21, 32, offsetof(mavlink_vision_position_estimate_t, covariance) }, \
         { "reset_counter", NULL, MAVLINK_TYPE_UINT8_T, 0, 116, offsetof(mavlink_vision_position_estimate_t, reset_counter) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VISION_POSITION_ESTIMATE { \
    "VISION_POSITION_ESTIMATE", \
    9, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vision_position_estimate_t, usec) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vision_position_estimate_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vision_position_estimate_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vision_position_estimate_t, z) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vision_position_estimate_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_vision_position_estimate_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_vision_position_estimate_t, yaw) }, \
         { "covariance", NULL, MAVLINK_TYPE_FLOAT, 21, 32, offsetof(mavlink_vision_position_estimate_t, covariance) }, \
         { "reset_counter", NULL, MAVLINK_TYPE_UINT8_T, 0, 116, offsetof(mavlink_vision_position_estimate_t, reset_counter) }, \
         } \
}
#endif

/**
 * @brief Pack a vision_position_estimate message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec [us] Timestamp (UNIX time or time since system boot)
 * @param x [m] Local X position
 * @param y [m] Local Y position
 * @param z [m] Local Z position
 * @param roll [rad] Roll angle
 * @param pitch [rad] Pitch angle
 * @param yaw [rad] Yaw angle
 * @param covariance  Row-major representation of pose 6x6 cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array.
 * @param reset_counter  Estimate reset counter. This should be incremented when the estimate resets in any of the dimensions (position, velocity, attitude, angular speed). This is designed to be used when e.g an external SLAM system detects a loop-closure and the estimate jumps.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vision_position_estimate_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t usec, float x, float y, float z, float roll, float pitch, float yaw, const float *covariance, uint8_t reset_counter)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, usec);
    _mav_put_float(((char*)msg->payloads), 8, x);
    _mav_put_float(((char*)msg->payloads), 12, y);
    _mav_put_float(((char*)msg->payloads), 16, z);
    _mav_put_float(((char*)msg->payloads), 20, roll);
    _mav_put_float(((char*)msg->payloads), 24, pitch);
    _mav_put_float(((char*)msg->payloads), 28, yaw);
    _mav_put_uint8_t(((char*)msg->payloads), 116, reset_counter);
    _mav_put_float_array(((char*)msg->payloads), 32, covariance, 21);
    msg->msgid = MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE_MIN_LEN, MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE_LEN, MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE_CRC);
}

/**
 * @brief Pack a vision_position_estimate message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec [us] Timestamp (UNIX time or time since system boot)
 * @param x [m] Local X position
 * @param y [m] Local Y position
 * @param z [m] Local Z position
 * @param roll [rad] Roll angle
 * @param pitch [rad] Pitch angle
 * @param yaw [rad] Yaw angle
 * @param covariance  Row-major representation of pose 6x6 cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array.
 * @param reset_counter  Estimate reset counter. This should be incremented when the estimate resets in any of the dimensions (position, velocity, attitude, angular speed). This is designed to be used when e.g an external SLAM system detects a loop-closure and the estimate jumps.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vision_position_estimate_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t usec,float x,float y,float z,float roll,float pitch,float yaw,const float *covariance,uint8_t reset_counter)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, usec);
    _mav_put_float(((char*)msg->payloads), 8, x);
    _mav_put_float(((char*)msg->payloads), 12, y);
    _mav_put_float(((char*)msg->payloads), 16, z);
    _mav_put_float(((char*)msg->payloads), 20, roll);
    _mav_put_float(((char*)msg->payloads), 24, pitch);
    _mav_put_float(((char*)msg->payloads), 28, yaw);
    _mav_put_uint8_t(((char*)msg->payloads), 116, reset_counter);
    _mav_put_float_array(((char*)msg->payloads), 32, covariance, 21);

    msg->msgid = MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE_MIN_LEN, MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE_LEN, MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE_CRC);
}

/**
 * @brief Encode a vision_position_estimate struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vision_position_estimate C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vision_position_estimate_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vision_position_estimate_t* vision_position_estimate)
{
    return mavlink_msg_vision_position_estimate_pack(system_id, component_id, msg, vision_position_estimate->usec, vision_position_estimate->x, vision_position_estimate->y, vision_position_estimate->z, vision_position_estimate->roll, vision_position_estimate->pitch, vision_position_estimate->yaw, vision_position_estimate->covariance, vision_position_estimate->reset_counter);
}

/**
 * @brief Encode a vision_position_estimate struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vision_position_estimate C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vision_position_estimate_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vision_position_estimate_t* vision_position_estimate)
{
    return mavlink_msg_vision_position_estimate_pack_chan(system_id, component_id, chan, msg, vision_position_estimate->usec, vision_position_estimate->x, vision_position_estimate->y, vision_position_estimate->z, vision_position_estimate->roll, vision_position_estimate->pitch, vision_position_estimate->yaw, vision_position_estimate->covariance, vision_position_estimate->reset_counter);
}

// MESSAGE VISION_POSITION_ESTIMATE UNPACKING


/**
 * @brief Get field usec from vision_position_estimate message
 *
 * @return [us] Timestamp (UNIX time or time since system boot)
 */
static inline uint64_t mavlink_msg_vision_position_estimate_get_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field x from vision_position_estimate message
 *
 * @return [m] Local X position
 */
static inline float mavlink_msg_vision_position_estimate_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field y from vision_position_estimate message
 *
 * @return [m] Local Y position
 */
static inline float mavlink_msg_vision_position_estimate_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field z from vision_position_estimate message
 *
 * @return [m] Local Z position
 */
static inline float mavlink_msg_vision_position_estimate_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field roll from vision_position_estimate message
 *
 * @return [rad] Roll angle
 */
static inline float mavlink_msg_vision_position_estimate_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field pitch from vision_position_estimate message
 *
 * @return [rad] Pitch angle
 */
static inline float mavlink_msg_vision_position_estimate_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field yaw from vision_position_estimate message
 *
 * @return [rad] Yaw angle
 */
static inline float mavlink_msg_vision_position_estimate_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field covariance from vision_position_estimate message
 *
 * @return  Row-major representation of pose 6x6 cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array.
 */
static inline uint16_t mavlink_msg_vision_position_estimate_get_covariance(const mavlink_message_t* msg, float *covariance)
{
    return _MAV_RETURN_float_array(msg, covariance, 21,  32);
}

/**
 * @brief Get field reset_counter from vision_position_estimate message
 *
 * @return  Estimate reset counter. This should be incremented when the estimate resets in any of the dimensions (position, velocity, attitude, angular speed). This is designed to be used when e.g an external SLAM system detects a loop-closure and the estimate jumps.
 */
static inline uint8_t mavlink_msg_vision_position_estimate_get_reset_counter(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  116);
}

/**
 * @brief Decode a vision_position_estimate message into a struct
 *
 * @param msg The message to decode
 * @param vision_position_estimate C-struct to decode the message contents into
 */
static inline void mavlink_msg_vision_position_estimate_decode(const mavlink_message_t* msg, mavlink_vision_position_estimate_t* vision_position_estimate)
{
    vision_position_estimate->usec = mavlink_msg_vision_position_estimate_get_usec(msg);
    vision_position_estimate->x = mavlink_msg_vision_position_estimate_get_x(msg);
    vision_position_estimate->y = mavlink_msg_vision_position_estimate_get_y(msg);
    vision_position_estimate->z = mavlink_msg_vision_position_estimate_get_z(msg);
    vision_position_estimate->roll = mavlink_msg_vision_position_estimate_get_roll(msg);
    vision_position_estimate->pitch = mavlink_msg_vision_position_estimate_get_pitch(msg);
    vision_position_estimate->yaw = mavlink_msg_vision_position_estimate_get_yaw(msg);
    mavlink_msg_vision_position_estimate_get_covariance(msg, vision_position_estimate->covariance);
    vision_position_estimate->reset_counter = mavlink_msg_vision_position_estimate_get_reset_counter(msg);
}
#endif
