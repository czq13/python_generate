#ifndef MAVLINK_MSG_autopilot_state_for_gimbal_device
#define MAVLINK_MSG_autopilot_state_for_gimbal_device
// MESSAGE AUTOPILOT_STATE_FOR_GIMBAL_DEVICE PACKING

#define MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE 286

typedef struct __mavlink_autopilot_state_for_gimbal_device_t {
 uint64_t time_boot_us; /*< [us] Timestamp (time since system boot).*/
 float q[4]; /*<  Quaternion components of autopilot attitude: w, x, y, z (1 0 0 0 is the null-rotation, Hamiltonian convention).*/
 uint32_t q_estimated_delay_us; /*< [us] Estimated delay of the attitude data.*/
 float vx; /*< [m/s] X Speed in NED (North, East, Down).*/
 float vy; /*< [m/s] Y Speed in NED (North, East, Down).*/
 float vz; /*< [m/s] Z Speed in NED (North, East, Down).*/
 uint32_t v_estimated_delay_us; /*< [us] Estimated delay of the speed data.*/
 float feed_forward_angular_velocity_z; /*< [rad/s] Feed forward Z component of angular velocity, positive is yawing to the right, NaN to be ignored. This is to indicate if the autopilot is actively yawing.*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
} mavlink_autopilot_state_for_gimbal_device_t;

#define MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_LEN 50
#define MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_MIN_LEN 50
#define MAVLINK_MSG_ID_286_LEN 50
#define MAVLINK_MSG_ID_286_MIN_LEN 50

#define MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_CRC 62
#define MAVLINK_MSG_ID_286_CRC 62

#define MAVLINK_MSG_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE { \
    286, \
    "AUTOPILOT_STATE_FOR_GIMBAL_DEVICE", \
    10, \
    {  { "time_boot_us", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_autopilot_state_for_gimbal_device_t, time_boot_us) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_autopilot_state_for_gimbal_device_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_autopilot_state_for_gimbal_device_t, target_component) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_autopilot_state_for_gimbal_device_t, q) }, \
         { "q_estimated_delay_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_autopilot_state_for_gimbal_device_t, q_estimated_delay_us) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_autopilot_state_for_gimbal_device_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_autopilot_state_for_gimbal_device_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_autopilot_state_for_gimbal_device_t, vz) }, \
         { "v_estimated_delay_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 40, offsetof(mavlink_autopilot_state_for_gimbal_device_t, v_estimated_delay_us) }, \
         { "feed_forward_angular_velocity_z", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_autopilot_state_for_gimbal_device_t, feed_forward_angular_velocity_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE { \
    "AUTOPILOT_STATE_FOR_GIMBAL_DEVICE", \
    10, \
    {  { "time_boot_us", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_autopilot_state_for_gimbal_device_t, time_boot_us) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_autopilot_state_for_gimbal_device_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_autopilot_state_for_gimbal_device_t, target_component) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_autopilot_state_for_gimbal_device_t, q) }, \
         { "q_estimated_delay_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_autopilot_state_for_gimbal_device_t, q_estimated_delay_us) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_autopilot_state_for_gimbal_device_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_autopilot_state_for_gimbal_device_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_autopilot_state_for_gimbal_device_t, vz) }, \
         { "v_estimated_delay_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 40, offsetof(mavlink_autopilot_state_for_gimbal_device_t, v_estimated_delay_us) }, \
         { "feed_forward_angular_velocity_z", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_autopilot_state_for_gimbal_device_t, feed_forward_angular_velocity_z) }, \
         } \
}
#endif

/**
 * @brief Pack a autopilot_state_for_gimbal_device message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_us [us] Timestamp (time since system boot).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param q  Quaternion components of autopilot attitude: w, x, y, z (1 0 0 0 is the null-rotation, Hamiltonian convention).
 * @param q_estimated_delay_us [us] Estimated delay of the attitude data.
 * @param vx [m/s] X Speed in NED (North, East, Down).
 * @param vy [m/s] Y Speed in NED (North, East, Down).
 * @param vz [m/s] Z Speed in NED (North, East, Down).
 * @param v_estimated_delay_us [us] Estimated delay of the speed data.
 * @param feed_forward_angular_velocity_z [rad/s] Feed forward Z component of angular velocity, positive is yawing to the right, NaN to be ignored. This is to indicate if the autopilot is actively yawing.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_autopilot_state_for_gimbal_device_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_boot_us, uint8_t target_system, uint8_t target_component, const float *q, uint32_t q_estimated_delay_us, float vx, float vy, float vz, uint32_t v_estimated_delay_us, float feed_forward_angular_velocity_z)
{
    _mav_put_uint64_t(msg->payloads, 0, time_boot_us);
    _mav_put_uint32_t(msg->payloads, 24, q_estimated_delay_us);
    _mav_put_float(msg->payloads, 28, vx);
    _mav_put_float(msg->payloads, 32, vy);
    _mav_put_float(msg->payloads, 36, vz);
    _mav_put_uint32_t(msg->payloads, 40, v_estimated_delay_us);
    _mav_put_float(msg->payloads, 44, feed_forward_angular_velocity_z);
    _mav_put_uint8_t(msg->payloads, 48, target_system);
    _mav_put_uint8_t(msg->payloads, 49, target_component);
    _mav_put_float_array(msg->payloads, 8, q, 4);
    msg->msgid = MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_MIN_LEN, MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_LEN, MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_CRC);
}

/**
 * @brief Pack a autopilot_state_for_gimbal_device message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_us [us] Timestamp (time since system boot).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param q  Quaternion components of autopilot attitude: w, x, y, z (1 0 0 0 is the null-rotation, Hamiltonian convention).
 * @param q_estimated_delay_us [us] Estimated delay of the attitude data.
 * @param vx [m/s] X Speed in NED (North, East, Down).
 * @param vy [m/s] Y Speed in NED (North, East, Down).
 * @param vz [m/s] Z Speed in NED (North, East, Down).
 * @param v_estimated_delay_us [us] Estimated delay of the speed data.
 * @param feed_forward_angular_velocity_z [rad/s] Feed forward Z component of angular velocity, positive is yawing to the right, NaN to be ignored. This is to indicate if the autopilot is actively yawing.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_autopilot_state_for_gimbal_device_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_boot_us,uint8_t target_system,uint8_t target_component,const float *q,uint32_t q_estimated_delay_us,float vx,float vy,float vz,uint32_t v_estimated_delay_us,float feed_forward_angular_velocity_z)
{
    _mav_put_uint64_t(msg->payloads, 0, time_boot_us);
    _mav_put_uint32_t(msg->payloads, 24, q_estimated_delay_us);
    _mav_put_float(msg->payloads, 28, vx);
    _mav_put_float(msg->payloads, 32, vy);
    _mav_put_float(msg->payloads, 36, vz);
    _mav_put_uint32_t(msg->payloads, 40, v_estimated_delay_us);
    _mav_put_float(msg->payloads, 44, feed_forward_angular_velocity_z);
    _mav_put_uint8_t(msg->payloads, 48, target_system);
    _mav_put_uint8_t(msg->payloads, 49, target_component);
    _mav_put_float_array(msg->payloads, 8, q, 4);

    msg->msgid = MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_MIN_LEN, MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_LEN, MAVLINK_MSG_ID_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_CRC);
}

/**
 * @brief Encode a autopilot_state_for_gimbal_device struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param autopilot_state_for_gimbal_device C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_autopilot_state_for_gimbal_device_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_autopilot_state_for_gimbal_device_t* autopilot_state_for_gimbal_device)
{
    return mavlink_msg_autopilot_state_for_gimbal_device_pack(system_id, component_id, msg, autopilot_state_for_gimbal_device->time_boot_us, autopilot_state_for_gimbal_device->target_system, autopilot_state_for_gimbal_device->target_component, autopilot_state_for_gimbal_device->q, autopilot_state_for_gimbal_device->q_estimated_delay_us, autopilot_state_for_gimbal_device->vx, autopilot_state_for_gimbal_device->vy, autopilot_state_for_gimbal_device->vz, autopilot_state_for_gimbal_device->v_estimated_delay_us, autopilot_state_for_gimbal_device->feed_forward_angular_velocity_z);
}

/**
 * @brief Encode a autopilot_state_for_gimbal_device struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param autopilot_state_for_gimbal_device C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_autopilot_state_for_gimbal_device_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_autopilot_state_for_gimbal_device_t* autopilot_state_for_gimbal_device)
{
    return mavlink_msg_autopilot_state_for_gimbal_device_pack_chan(system_id, component_id, chan, msg, autopilot_state_for_gimbal_device->time_boot_us, autopilot_state_for_gimbal_device->target_system, autopilot_state_for_gimbal_device->target_component, autopilot_state_for_gimbal_device->q, autopilot_state_for_gimbal_device->q_estimated_delay_us, autopilot_state_for_gimbal_device->vx, autopilot_state_for_gimbal_device->vy, autopilot_state_for_gimbal_device->vz, autopilot_state_for_gimbal_device->v_estimated_delay_us, autopilot_state_for_gimbal_device->feed_forward_angular_velocity_z);
}

// MESSAGE AUTOPILOT_STATE_FOR_GIMBAL_DEVICE UNPACKING


/**
 * @brief Get field time_boot_us from autopilot_state_for_gimbal_device message
 *
 * @return [us] Timestamp (time since system boot).
 */
static inline uint64_t mavlink_msg_autopilot_state_for_gimbal_device_get_time_boot_us(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_system from autopilot_state_for_gimbal_device message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_autopilot_state_for_gimbal_device_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  48);
}

/**
 * @brief Get field target_component from autopilot_state_for_gimbal_device message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_autopilot_state_for_gimbal_device_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  49);
}

/**
 * @brief Get field q from autopilot_state_for_gimbal_device message
 *
 * @return  Quaternion components of autopilot attitude: w, x, y, z (1 0 0 0 is the null-rotation, Hamiltonian convention).
 */
static inline uint16_t mavlink_msg_autopilot_state_for_gimbal_device_get_q(const mavlink_message_t* msg, float *q)
{
    return _MAV_RETURN_float_array(msg, q, 4,  8);
}

/**
 * @brief Get field q_estimated_delay_us from autopilot_state_for_gimbal_device message
 *
 * @return [us] Estimated delay of the attitude data.
 */
static inline uint32_t mavlink_msg_autopilot_state_for_gimbal_device_get_q_estimated_delay_us(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field vx from autopilot_state_for_gimbal_device message
 *
 * @return [m/s] X Speed in NED (North, East, Down).
 */
static inline float mavlink_msg_autopilot_state_for_gimbal_device_get_vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field vy from autopilot_state_for_gimbal_device message
 *
 * @return [m/s] Y Speed in NED (North, East, Down).
 */
static inline float mavlink_msg_autopilot_state_for_gimbal_device_get_vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field vz from autopilot_state_for_gimbal_device message
 *
 * @return [m/s] Z Speed in NED (North, East, Down).
 */
static inline float mavlink_msg_autopilot_state_for_gimbal_device_get_vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field v_estimated_delay_us from autopilot_state_for_gimbal_device message
 *
 * @return [us] Estimated delay of the speed data.
 */
static inline uint32_t mavlink_msg_autopilot_state_for_gimbal_device_get_v_estimated_delay_us(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  40);
}

/**
 * @brief Get field feed_forward_angular_velocity_z from autopilot_state_for_gimbal_device message
 *
 * @return [rad/s] Feed forward Z component of angular velocity, positive is yawing to the right, NaN to be ignored. This is to indicate if the autopilot is actively yawing.
 */
static inline float mavlink_msg_autopilot_state_for_gimbal_device_get_feed_forward_angular_velocity_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Decode a autopilot_state_for_gimbal_device message into a struct
 *
 * @param msg The message to decode
 * @param autopilot_state_for_gimbal_device C-struct to decode the message contents into
 */
static inline void mavlink_msg_autopilot_state_for_gimbal_device_decode(const mavlink_message_t* msg, mavlink_autopilot_state_for_gimbal_device_t* autopilot_state_for_gimbal_device)
{
    autopilot_state_for_gimbal_device->time_boot_us = mavlink_msg_autopilot_state_for_gimbal_device_get_time_boot_us(msg);
    mavlink_msg_autopilot_state_for_gimbal_device_get_q(msg, autopilot_state_for_gimbal_device->q);
    autopilot_state_for_gimbal_device->q_estimated_delay_us = mavlink_msg_autopilot_state_for_gimbal_device_get_q_estimated_delay_us(msg);
    autopilot_state_for_gimbal_device->vx = mavlink_msg_autopilot_state_for_gimbal_device_get_vx(msg);
    autopilot_state_for_gimbal_device->vy = mavlink_msg_autopilot_state_for_gimbal_device_get_vy(msg);
    autopilot_state_for_gimbal_device->vz = mavlink_msg_autopilot_state_for_gimbal_device_get_vz(msg);
    autopilot_state_for_gimbal_device->v_estimated_delay_us = mavlink_msg_autopilot_state_for_gimbal_device_get_v_estimated_delay_us(msg);
    autopilot_state_for_gimbal_device->feed_forward_angular_velocity_z = mavlink_msg_autopilot_state_for_gimbal_device_get_feed_forward_angular_velocity_z(msg);
    autopilot_state_for_gimbal_device->target_system = mavlink_msg_autopilot_state_for_gimbal_device_get_target_system(msg);
    autopilot_state_for_gimbal_device->target_component = mavlink_msg_autopilot_state_for_gimbal_device_get_target_component(msg);
}
#endif
