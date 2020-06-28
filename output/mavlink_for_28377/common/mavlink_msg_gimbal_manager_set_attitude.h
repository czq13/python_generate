#ifndef MAVLINK_MSG_gimbal_manager_set_attitude
#define MAVLINK_MSG_gimbal_manager_set_attitude
// MESSAGE GIMBAL_MANAGER_SET_ATTITUDE PACKING

#define MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE 282

typedef struct __mavlink_gimbal_manager_set_attitude_t {
 uint32_t flags; /*<  High level gimbal manager flags to use.*/
 float q[4]; /*<  Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation, the frame is depends on whether the flag GIMBAL_MANAGER_FLAGS_YAW_LOCK is set)*/
 float angular_velocity_x; /*< [rad/s] X component of angular velocity, positive is banking to the right, NaN to be ignored.*/
 float angular_velocity_y; /*< [rad/s] Y component of angular velocity, positive is tilting up, NaN to be ignored.*/
 float angular_velocity_z; /*< [rad/s] Z component of angular velocity, positive is panning to the right, NaN to be ignored.*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t gimbal_device_id; /*<  Component ID of gimbal device to address (or 1-6 for non-MAVLink gimbal), 0 for all gimbal device components. (Send command multiple times for more than one but not all gimbals.)*/
} mavlink_gimbal_manager_set_attitude_t;

#define MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE_LEN 35
#define MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE_MIN_LEN 35
#define MAVLINK_MSG_ID_282_LEN 35
#define MAVLINK_MSG_ID_282_MIN_LEN 35

#define MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE_CRC 123
#define MAVLINK_MSG_ID_282_CRC 123

#define MAVLINK_MSG_GIMBAL_MANAGER_SET_ATTITUDE_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GIMBAL_MANAGER_SET_ATTITUDE { \
    282, \
    "GIMBAL_MANAGER_SET_ATTITUDE", \
    8, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_gimbal_manager_set_attitude_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_gimbal_manager_set_attitude_t, target_component) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gimbal_manager_set_attitude_t, flags) }, \
         { "gimbal_device_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_gimbal_manager_set_attitude_t, gimbal_device_id) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_gimbal_manager_set_attitude_t, q) }, \
         { "angular_velocity_x", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gimbal_manager_set_attitude_t, angular_velocity_x) }, \
         { "angular_velocity_y", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_gimbal_manager_set_attitude_t, angular_velocity_y) }, \
         { "angular_velocity_z", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_gimbal_manager_set_attitude_t, angular_velocity_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GIMBAL_MANAGER_SET_ATTITUDE { \
    "GIMBAL_MANAGER_SET_ATTITUDE", \
    8, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_gimbal_manager_set_attitude_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_gimbal_manager_set_attitude_t, target_component) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gimbal_manager_set_attitude_t, flags) }, \
         { "gimbal_device_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_gimbal_manager_set_attitude_t, gimbal_device_id) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_gimbal_manager_set_attitude_t, q) }, \
         { "angular_velocity_x", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gimbal_manager_set_attitude_t, angular_velocity_x) }, \
         { "angular_velocity_y", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_gimbal_manager_set_attitude_t, angular_velocity_y) }, \
         { "angular_velocity_z", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_gimbal_manager_set_attitude_t, angular_velocity_z) }, \
         } \
}
#endif

/**
 * @brief Pack a gimbal_manager_set_attitude message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param flags  High level gimbal manager flags to use.
 * @param gimbal_device_id  Component ID of gimbal device to address (or 1-6 for non-MAVLink gimbal), 0 for all gimbal device components. (Send command multiple times for more than one but not all gimbals.)
 * @param q  Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation, the frame is depends on whether the flag GIMBAL_MANAGER_FLAGS_YAW_LOCK is set)
 * @param angular_velocity_x [rad/s] X component of angular velocity, positive is banking to the right, NaN to be ignored.
 * @param angular_velocity_y [rad/s] Y component of angular velocity, positive is tilting up, NaN to be ignored.
 * @param angular_velocity_z [rad/s] Z component of angular velocity, positive is panning to the right, NaN to be ignored.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gimbal_manager_set_attitude_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint32_t flags, uint8_t gimbal_device_id, const float *q, float angular_velocity_x, float angular_velocity_y, float angular_velocity_z)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, flags);
    _mav_put_float(((char*)msg->payloads), 20, angular_velocity_x);
    _mav_put_float(((char*)msg->payloads), 24, angular_velocity_y);
    _mav_put_float(((char*)msg->payloads), 28, angular_velocity_z);
    _mav_put_uint8_t(((char*)msg->payloads), 32, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 33, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 34, gimbal_device_id);
    _mav_put_float_array(((char*)msg->payloads), 4, q, 4);
    msg->msgid = MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE_MIN_LEN, MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE_LEN, MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE_CRC);
}

/**
 * @brief Pack a gimbal_manager_set_attitude message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param flags  High level gimbal manager flags to use.
 * @param gimbal_device_id  Component ID of gimbal device to address (or 1-6 for non-MAVLink gimbal), 0 for all gimbal device components. (Send command multiple times for more than one but not all gimbals.)
 * @param q  Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation, the frame is depends on whether the flag GIMBAL_MANAGER_FLAGS_YAW_LOCK is set)
 * @param angular_velocity_x [rad/s] X component of angular velocity, positive is banking to the right, NaN to be ignored.
 * @param angular_velocity_y [rad/s] Y component of angular velocity, positive is tilting up, NaN to be ignored.
 * @param angular_velocity_z [rad/s] Z component of angular velocity, positive is panning to the right, NaN to be ignored.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gimbal_manager_set_attitude_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint32_t flags,uint8_t gimbal_device_id,const float *q,float angular_velocity_x,float angular_velocity_y,float angular_velocity_z)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, flags);
    _mav_put_float(((char*)msg->payloads), 20, angular_velocity_x);
    _mav_put_float(((char*)msg->payloads), 24, angular_velocity_y);
    _mav_put_float(((char*)msg->payloads), 28, angular_velocity_z);
    _mav_put_uint8_t(((char*)msg->payloads), 32, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 33, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 34, gimbal_device_id);
    _mav_put_float_array(((char*)msg->payloads), 4, q, 4);

    msg->msgid = MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE_MIN_LEN, MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE_LEN, MAVLINK_MSG_ID_GIMBAL_MANAGER_SET_ATTITUDE_CRC);
}

/**
 * @brief Encode a gimbal_manager_set_attitude struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gimbal_manager_set_attitude C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gimbal_manager_set_attitude_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gimbal_manager_set_attitude_t* gimbal_manager_set_attitude)
{
    return mavlink_msg_gimbal_manager_set_attitude_pack(system_id, component_id, msg, gimbal_manager_set_attitude->target_system, gimbal_manager_set_attitude->target_component, gimbal_manager_set_attitude->flags, gimbal_manager_set_attitude->gimbal_device_id, gimbal_manager_set_attitude->q, gimbal_manager_set_attitude->angular_velocity_x, gimbal_manager_set_attitude->angular_velocity_y, gimbal_manager_set_attitude->angular_velocity_z);
}

/**
 * @brief Encode a gimbal_manager_set_attitude struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gimbal_manager_set_attitude C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gimbal_manager_set_attitude_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gimbal_manager_set_attitude_t* gimbal_manager_set_attitude)
{
    return mavlink_msg_gimbal_manager_set_attitude_pack_chan(system_id, component_id, chan, msg, gimbal_manager_set_attitude->target_system, gimbal_manager_set_attitude->target_component, gimbal_manager_set_attitude->flags, gimbal_manager_set_attitude->gimbal_device_id, gimbal_manager_set_attitude->q, gimbal_manager_set_attitude->angular_velocity_x, gimbal_manager_set_attitude->angular_velocity_y, gimbal_manager_set_attitude->angular_velocity_z);
}

// MESSAGE GIMBAL_MANAGER_SET_ATTITUDE UNPACKING


/**
 * @brief Get field target_system from gimbal_manager_set_attitude message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_gimbal_manager_set_attitude_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field target_component from gimbal_manager_set_attitude message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_gimbal_manager_set_attitude_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Get field flags from gimbal_manager_set_attitude message
 *
 * @return  High level gimbal manager flags to use.
 */
static inline uint32_t mavlink_msg_gimbal_manager_set_attitude_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field gimbal_device_id from gimbal_manager_set_attitude message
 *
 * @return  Component ID of gimbal device to address (or 1-6 for non-MAVLink gimbal), 0 for all gimbal device components. (Send command multiple times for more than one but not all gimbals.)
 */
static inline uint8_t mavlink_msg_gimbal_manager_set_attitude_get_gimbal_device_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field q from gimbal_manager_set_attitude message
 *
 * @return  Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation, the frame is depends on whether the flag GIMBAL_MANAGER_FLAGS_YAW_LOCK is set)
 */
static inline uint16_t mavlink_msg_gimbal_manager_set_attitude_get_q(const mavlink_message_t* msg, float *q)
{
    return _MAV_RETURN_float_array(msg, q, 4,  4);
}

/**
 * @brief Get field angular_velocity_x from gimbal_manager_set_attitude message
 *
 * @return [rad/s] X component of angular velocity, positive is banking to the right, NaN to be ignored.
 */
static inline float mavlink_msg_gimbal_manager_set_attitude_get_angular_velocity_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field angular_velocity_y from gimbal_manager_set_attitude message
 *
 * @return [rad/s] Y component of angular velocity, positive is tilting up, NaN to be ignored.
 */
static inline float mavlink_msg_gimbal_manager_set_attitude_get_angular_velocity_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field angular_velocity_z from gimbal_manager_set_attitude message
 *
 * @return [rad/s] Z component of angular velocity, positive is panning to the right, NaN to be ignored.
 */
static inline float mavlink_msg_gimbal_manager_set_attitude_get_angular_velocity_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a gimbal_manager_set_attitude message into a struct
 *
 * @param msg The message to decode
 * @param gimbal_manager_set_attitude C-struct to decode the message contents into
 */
static inline void mavlink_msg_gimbal_manager_set_attitude_decode(const mavlink_message_t* msg, mavlink_gimbal_manager_set_attitude_t* gimbal_manager_set_attitude)
{
    gimbal_manager_set_attitude->flags = mavlink_msg_gimbal_manager_set_attitude_get_flags(msg);
    mavlink_msg_gimbal_manager_set_attitude_get_q(msg, gimbal_manager_set_attitude->q);
    gimbal_manager_set_attitude->angular_velocity_x = mavlink_msg_gimbal_manager_set_attitude_get_angular_velocity_x(msg);
    gimbal_manager_set_attitude->angular_velocity_y = mavlink_msg_gimbal_manager_set_attitude_get_angular_velocity_y(msg);
    gimbal_manager_set_attitude->angular_velocity_z = mavlink_msg_gimbal_manager_set_attitude_get_angular_velocity_z(msg);
    gimbal_manager_set_attitude->target_system = mavlink_msg_gimbal_manager_set_attitude_get_target_system(msg);
    gimbal_manager_set_attitude->target_component = mavlink_msg_gimbal_manager_set_attitude_get_target_component(msg);
    gimbal_manager_set_attitude->gimbal_device_id = mavlink_msg_gimbal_manager_set_attitude_get_gimbal_device_id(msg);
}
#endif
