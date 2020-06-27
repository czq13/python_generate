#ifndef MAVLINK_MSG_trajectory_representation_bezier
#define MAVLINK_MSG_trajectory_representation_bezier
// MESSAGE TRAJECTORY_REPRESENTATION_BEZIER PACKING

#define MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER 333

typedef struct __mavlink_trajectory_representation_bezier_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float pos_x[5]; /*< [m] X-coordinate of bezier control points. Set to NaN if not being used*/
 float pos_y[5]; /*< [m] Y-coordinate of bezier control points. Set to NaN if not being used*/
 float pos_z[5]; /*< [m] Z-coordinate of bezier control points. Set to NaN if not being used*/
 float delta[5]; /*< [s] Bezier time horizon. Set to NaN if velocity/acceleration should not be incorporated*/
 float pos_yaw[5]; /*< [rad] Yaw. Set to NaN for unchanged*/
 uint8_t valid_points; /*<  Number of valid control points (up-to 5 points are possible)*/
} mavlink_trajectory_representation_bezier_t;

#define MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_LEN 109
#define MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_MIN_LEN 109
#define MAVLINK_MSG_ID_333_LEN 109
#define MAVLINK_MSG_ID_333_MIN_LEN 109

#define MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_CRC 231
#define MAVLINK_MSG_ID_333_CRC 231

#define MAVLINK_MSG_TRAJECTORY_REPRESENTATION_BEZIER_FIELD_POS_X_LEN 5
#define MAVLINK_MSG_TRAJECTORY_REPRESENTATION_BEZIER_FIELD_POS_Y_LEN 5
#define MAVLINK_MSG_TRAJECTORY_REPRESENTATION_BEZIER_FIELD_POS_Z_LEN 5
#define MAVLINK_MSG_TRAJECTORY_REPRESENTATION_BEZIER_FIELD_DELTA_LEN 5
#define MAVLINK_MSG_TRAJECTORY_REPRESENTATION_BEZIER_FIELD_POS_YAW_LEN 5

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TRAJECTORY_REPRESENTATION_BEZIER { \
    333, \
    "TRAJECTORY_REPRESENTATION_BEZIER", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_trajectory_representation_bezier_t, time_usec) }, \
         { "valid_points", NULL, MAVLINK_TYPE_UINT8_T, 0, 108, offsetof(mavlink_trajectory_representation_bezier_t, valid_points) }, \
         { "pos_x", NULL, MAVLINK_TYPE_FLOAT, 5, 8, offsetof(mavlink_trajectory_representation_bezier_t, pos_x) }, \
         { "pos_y", NULL, MAVLINK_TYPE_FLOAT, 5, 28, offsetof(mavlink_trajectory_representation_bezier_t, pos_y) }, \
         { "pos_z", NULL, MAVLINK_TYPE_FLOAT, 5, 48, offsetof(mavlink_trajectory_representation_bezier_t, pos_z) }, \
         { "delta", NULL, MAVLINK_TYPE_FLOAT, 5, 68, offsetof(mavlink_trajectory_representation_bezier_t, delta) }, \
         { "pos_yaw", NULL, MAVLINK_TYPE_FLOAT, 5, 88, offsetof(mavlink_trajectory_representation_bezier_t, pos_yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TRAJECTORY_REPRESENTATION_BEZIER { \
    "TRAJECTORY_REPRESENTATION_BEZIER", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_trajectory_representation_bezier_t, time_usec) }, \
         { "valid_points", NULL, MAVLINK_TYPE_UINT8_T, 0, 108, offsetof(mavlink_trajectory_representation_bezier_t, valid_points) }, \
         { "pos_x", NULL, MAVLINK_TYPE_FLOAT, 5, 8, offsetof(mavlink_trajectory_representation_bezier_t, pos_x) }, \
         { "pos_y", NULL, MAVLINK_TYPE_FLOAT, 5, 28, offsetof(mavlink_trajectory_representation_bezier_t, pos_y) }, \
         { "pos_z", NULL, MAVLINK_TYPE_FLOAT, 5, 48, offsetof(mavlink_trajectory_representation_bezier_t, pos_z) }, \
         { "delta", NULL, MAVLINK_TYPE_FLOAT, 5, 68, offsetof(mavlink_trajectory_representation_bezier_t, delta) }, \
         { "pos_yaw", NULL, MAVLINK_TYPE_FLOAT, 5, 88, offsetof(mavlink_trajectory_representation_bezier_t, pos_yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a trajectory_representation_bezier message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param valid_points  Number of valid control points (up-to 5 points are possible)
 * @param pos_x [m] X-coordinate of bezier control points. Set to NaN if not being used
 * @param pos_y [m] Y-coordinate of bezier control points. Set to NaN if not being used
 * @param pos_z [m] Z-coordinate of bezier control points. Set to NaN if not being used
 * @param delta [s] Bezier time horizon. Set to NaN if velocity/acceleration should not be incorporated
 * @param pos_yaw [rad] Yaw. Set to NaN for unchanged
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_trajectory_representation_bezier_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t valid_points, const float *pos_x, const float *pos_y, const float *pos_z, const float *delta, const float *pos_yaw)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint8_t(msg->payloads, 108, valid_points);
    _mav_put_float_array(msg->payloads, 8, pos_x, 5);
    _mav_put_float_array(msg->payloads, 28, pos_y, 5);
    _mav_put_float_array(msg->payloads, 48, pos_z, 5);
    _mav_put_float_array(msg->payloads, 68, delta, 5);
    _mav_put_float_array(msg->payloads, 88, pos_yaw, 5);
    msg->msgid = MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_LEN, MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_CRC);
}

/**
 * @brief Pack a trajectory_representation_bezier message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param valid_points  Number of valid control points (up-to 5 points are possible)
 * @param pos_x [m] X-coordinate of bezier control points. Set to NaN if not being used
 * @param pos_y [m] Y-coordinate of bezier control points. Set to NaN if not being used
 * @param pos_z [m] Z-coordinate of bezier control points. Set to NaN if not being used
 * @param delta [s] Bezier time horizon. Set to NaN if velocity/acceleration should not be incorporated
 * @param pos_yaw [rad] Yaw. Set to NaN for unchanged
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_trajectory_representation_bezier_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t valid_points,const float *pos_x,const float *pos_y,const float *pos_z,const float *delta,const float *pos_yaw)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint8_t(msg->payloads, 108, valid_points);
    _mav_put_float_array(msg->payloads, 8, pos_x, 5);
    _mav_put_float_array(msg->payloads, 28, pos_y, 5);
    _mav_put_float_array(msg->payloads, 48, pos_z, 5);
    _mav_put_float_array(msg->payloads, 68, delta, 5);
    _mav_put_float_array(msg->payloads, 88, pos_yaw, 5);

    msg->msgid = MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_LEN, MAVLINK_MSG_ID_TRAJECTORY_REPRESENTATION_BEZIER_CRC);
}

/**
 * @brief Encode a trajectory_representation_bezier struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param trajectory_representation_bezier C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_trajectory_representation_bezier_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_trajectory_representation_bezier_t* trajectory_representation_bezier)
{
    return mavlink_msg_trajectory_representation_bezier_pack(system_id, component_id, msg, trajectory_representation_bezier->time_usec, trajectory_representation_bezier->valid_points, trajectory_representation_bezier->pos_x, trajectory_representation_bezier->pos_y, trajectory_representation_bezier->pos_z, trajectory_representation_bezier->delta, trajectory_representation_bezier->pos_yaw);
}

/**
 * @brief Encode a trajectory_representation_bezier struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param trajectory_representation_bezier C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_trajectory_representation_bezier_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_trajectory_representation_bezier_t* trajectory_representation_bezier)
{
    return mavlink_msg_trajectory_representation_bezier_pack_chan(system_id, component_id, chan, msg, trajectory_representation_bezier->time_usec, trajectory_representation_bezier->valid_points, trajectory_representation_bezier->pos_x, trajectory_representation_bezier->pos_y, trajectory_representation_bezier->pos_z, trajectory_representation_bezier->delta, trajectory_representation_bezier->pos_yaw);
}

// MESSAGE TRAJECTORY_REPRESENTATION_BEZIER UNPACKING


/**
 * @brief Get field time_usec from trajectory_representation_bezier message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_trajectory_representation_bezier_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field valid_points from trajectory_representation_bezier message
 *
 * @return  Number of valid control points (up-to 5 points are possible)
 */
static inline uint8_t mavlink_msg_trajectory_representation_bezier_get_valid_points(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  108);
}

/**
 * @brief Get field pos_x from trajectory_representation_bezier message
 *
 * @return [m] X-coordinate of bezier control points. Set to NaN if not being used
 */
static inline uint16_t mavlink_msg_trajectory_representation_bezier_get_pos_x(const mavlink_message_t* msg, float *pos_x)
{
    return _MAV_RETURN_float_array(msg, pos_x, 5,  8);
}

/**
 * @brief Get field pos_y from trajectory_representation_bezier message
 *
 * @return [m] Y-coordinate of bezier control points. Set to NaN if not being used
 */
static inline uint16_t mavlink_msg_trajectory_representation_bezier_get_pos_y(const mavlink_message_t* msg, float *pos_y)
{
    return _MAV_RETURN_float_array(msg, pos_y, 5,  28);
}

/**
 * @brief Get field pos_z from trajectory_representation_bezier message
 *
 * @return [m] Z-coordinate of bezier control points. Set to NaN if not being used
 */
static inline uint16_t mavlink_msg_trajectory_representation_bezier_get_pos_z(const mavlink_message_t* msg, float *pos_z)
{
    return _MAV_RETURN_float_array(msg, pos_z, 5,  48);
}

/**
 * @brief Get field delta from trajectory_representation_bezier message
 *
 * @return [s] Bezier time horizon. Set to NaN if velocity/acceleration should not be incorporated
 */
static inline uint16_t mavlink_msg_trajectory_representation_bezier_get_delta(const mavlink_message_t* msg, float *delta)
{
    return _MAV_RETURN_float_array(msg, delta, 5,  68);
}

/**
 * @brief Get field pos_yaw from trajectory_representation_bezier message
 *
 * @return [rad] Yaw. Set to NaN for unchanged
 */
static inline uint16_t mavlink_msg_trajectory_representation_bezier_get_pos_yaw(const mavlink_message_t* msg, float *pos_yaw)
{
    return _MAV_RETURN_float_array(msg, pos_yaw, 5,  88);
}

/**
 * @brief Decode a trajectory_representation_bezier message into a struct
 *
 * @param msg The message to decode
 * @param trajectory_representation_bezier C-struct to decode the message contents into
 */
static inline void mavlink_msg_trajectory_representation_bezier_decode(const mavlink_message_t* msg, mavlink_trajectory_representation_bezier_t* trajectory_representation_bezier)
{
    trajectory_representation_bezier->time_usec = mavlink_msg_trajectory_representation_bezier_get_time_usec(msg);
    mavlink_msg_trajectory_representation_bezier_get_pos_x(msg, trajectory_representation_bezier->pos_x);
    mavlink_msg_trajectory_representation_bezier_get_pos_y(msg, trajectory_representation_bezier->pos_y);
    mavlink_msg_trajectory_representation_bezier_get_pos_z(msg, trajectory_representation_bezier->pos_z);
    mavlink_msg_trajectory_representation_bezier_get_delta(msg, trajectory_representation_bezier->delta);
    mavlink_msg_trajectory_representation_bezier_get_pos_yaw(msg, trajectory_representation_bezier->pos_yaw);
    trajectory_representation_bezier->valid_points = mavlink_msg_trajectory_representation_bezier_get_valid_points(msg);
}
#endif
