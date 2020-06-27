#ifndef MAVLINK_MSG_vicon_position_estimate
#define MAVLINK_MSG_vicon_position_estimate
// MESSAGE VICON_POSITION_ESTIMATE PACKING

#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE 104

typedef struct __mavlink_vicon_position_estimate_t {
 uint64_t usec; /*< [us] Timestamp (UNIX time or time since system boot)*/
 float x; /*< [m] Global X position*/
 float y; /*< [m] Global Y position*/
 float z; /*< [m] Global Z position*/
 float roll; /*< [rad] Roll angle*/
 float pitch; /*< [rad] Pitch angle*/
 float yaw; /*< [rad] Yaw angle*/
 float covariance[21]; /*<  Row-major representation of 6x6 pose cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array.*/
} mavlink_vicon_position_estimate_t;

#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_LEN 116
#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_MIN_LEN 32
#define MAVLINK_MSG_ID_104_LEN 116
#define MAVLINK_MSG_ID_104_MIN_LEN 32

#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_CRC 56
#define MAVLINK_MSG_ID_104_CRC 56

#define MAVLINK_MSG_VICON_POSITION_ESTIMATE_FIELD_COVARIANCE_LEN 21

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VICON_POSITION_ESTIMATE { \
    104, \
    "VICON_POSITION_ESTIMATE", \
    8, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vicon_position_estimate_t, usec) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vicon_position_estimate_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vicon_position_estimate_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vicon_position_estimate_t, z) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vicon_position_estimate_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_vicon_position_estimate_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_vicon_position_estimate_t, yaw) }, \
         { "covariance", NULL, MAVLINK_TYPE_FLOAT, 21, 32, offsetof(mavlink_vicon_position_estimate_t, covariance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VICON_POSITION_ESTIMATE { \
    "VICON_POSITION_ESTIMATE", \
    8, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vicon_position_estimate_t, usec) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vicon_position_estimate_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vicon_position_estimate_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vicon_position_estimate_t, z) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vicon_position_estimate_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_vicon_position_estimate_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_vicon_position_estimate_t, yaw) }, \
         { "covariance", NULL, MAVLINK_TYPE_FLOAT, 21, 32, offsetof(mavlink_vicon_position_estimate_t, covariance) }, \
         } \
}
#endif

/**
 * @brief Pack a vicon_position_estimate message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec [us] Timestamp (UNIX time or time since system boot)
 * @param x [m] Global X position
 * @param y [m] Global Y position
 * @param z [m] Global Z position
 * @param roll [rad] Roll angle
 * @param pitch [rad] Pitch angle
 * @param yaw [rad] Yaw angle
 * @param covariance  Row-major representation of 6x6 pose cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_position_estimate_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t usec, float x, float y, float z, float roll, float pitch, float yaw, const float *covariance)
{
    _mav_put_uint64_t(msg->payloads, 0, usec);
    _mav_put_float(msg->payloads, 8, x);
    _mav_put_float(msg->payloads, 12, y);
    _mav_put_float(msg->payloads, 16, z);
    _mav_put_float(msg->payloads, 20, roll);
    _mav_put_float(msg->payloads, 24, pitch);
    _mav_put_float(msg->payloads, 28, yaw);
    _mav_put_float_array(msg->payloads, 32, covariance, 21);
    msg->msgid = MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_MIN_LEN, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_LEN, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_CRC);
}

/**
 * @brief Pack a vicon_position_estimate message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec [us] Timestamp (UNIX time or time since system boot)
 * @param x [m] Global X position
 * @param y [m] Global Y position
 * @param z [m] Global Z position
 * @param roll [rad] Roll angle
 * @param pitch [rad] Pitch angle
 * @param yaw [rad] Yaw angle
 * @param covariance  Row-major representation of 6x6 pose cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_position_estimate_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t usec,float x,float y,float z,float roll,float pitch,float yaw,const float *covariance)
{
    _mav_put_uint64_t(msg->payloads, 0, usec);
    _mav_put_float(msg->payloads, 8, x);
    _mav_put_float(msg->payloads, 12, y);
    _mav_put_float(msg->payloads, 16, z);
    _mav_put_float(msg->payloads, 20, roll);
    _mav_put_float(msg->payloads, 24, pitch);
    _mav_put_float(msg->payloads, 28, yaw);
    _mav_put_float_array(msg->payloads, 32, covariance, 21);

    msg->msgid = MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_MIN_LEN, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_LEN, MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE_CRC);
}

/**
 * @brief Encode a vicon_position_estimate struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vicon_position_estimate C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vicon_position_estimate_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vicon_position_estimate_t* vicon_position_estimate)
{
    return mavlink_msg_vicon_position_estimate_pack(system_id, component_id, msg, vicon_position_estimate->usec, vicon_position_estimate->x, vicon_position_estimate->y, vicon_position_estimate->z, vicon_position_estimate->roll, vicon_position_estimate->pitch, vicon_position_estimate->yaw, vicon_position_estimate->covariance);
}

/**
 * @brief Encode a vicon_position_estimate struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vicon_position_estimate C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vicon_position_estimate_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vicon_position_estimate_t* vicon_position_estimate)
{
    return mavlink_msg_vicon_position_estimate_pack_chan(system_id, component_id, chan, msg, vicon_position_estimate->usec, vicon_position_estimate->x, vicon_position_estimate->y, vicon_position_estimate->z, vicon_position_estimate->roll, vicon_position_estimate->pitch, vicon_position_estimate->yaw, vicon_position_estimate->covariance);
}

// MESSAGE VICON_POSITION_ESTIMATE UNPACKING


/**
 * @brief Get field usec from vicon_position_estimate message
 *
 * @return [us] Timestamp (UNIX time or time since system boot)
 */
static inline uint64_t mavlink_msg_vicon_position_estimate_get_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field x from vicon_position_estimate message
 *
 * @return [m] Global X position
 */
static inline float mavlink_msg_vicon_position_estimate_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field y from vicon_position_estimate message
 *
 * @return [m] Global Y position
 */
static inline float mavlink_msg_vicon_position_estimate_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field z from vicon_position_estimate message
 *
 * @return [m] Global Z position
 */
static inline float mavlink_msg_vicon_position_estimate_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field roll from vicon_position_estimate message
 *
 * @return [rad] Roll angle
 */
static inline float mavlink_msg_vicon_position_estimate_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field pitch from vicon_position_estimate message
 *
 * @return [rad] Pitch angle
 */
static inline float mavlink_msg_vicon_position_estimate_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field yaw from vicon_position_estimate message
 *
 * @return [rad] Yaw angle
 */
static inline float mavlink_msg_vicon_position_estimate_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field covariance from vicon_position_estimate message
 *
 * @return  Row-major representation of 6x6 pose cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array.
 */
static inline uint16_t mavlink_msg_vicon_position_estimate_get_covariance(const mavlink_message_t* msg, float *covariance)
{
    return _MAV_RETURN_float_array(msg, covariance, 21,  32);
}

/**
 * @brief Decode a vicon_position_estimate message into a struct
 *
 * @param msg The message to decode
 * @param vicon_position_estimate C-struct to decode the message contents into
 */
static inline void mavlink_msg_vicon_position_estimate_decode(const mavlink_message_t* msg, mavlink_vicon_position_estimate_t* vicon_position_estimate)
{
    vicon_position_estimate->usec = mavlink_msg_vicon_position_estimate_get_usec(msg);
    vicon_position_estimate->x = mavlink_msg_vicon_position_estimate_get_x(msg);
    vicon_position_estimate->y = mavlink_msg_vicon_position_estimate_get_y(msg);
    vicon_position_estimate->z = mavlink_msg_vicon_position_estimate_get_z(msg);
    vicon_position_estimate->roll = mavlink_msg_vicon_position_estimate_get_roll(msg);
    vicon_position_estimate->pitch = mavlink_msg_vicon_position_estimate_get_pitch(msg);
    vicon_position_estimate->yaw = mavlink_msg_vicon_position_estimate_get_yaw(msg);
    mavlink_msg_vicon_position_estimate_get_covariance(msg, vicon_position_estimate->covariance);
}
#endif
