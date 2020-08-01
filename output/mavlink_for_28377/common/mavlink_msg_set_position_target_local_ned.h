#ifndef MAVLINK_MSG_set_position_target_local_ned
#define MAVLINK_MSG_set_position_target_local_ned
// MESSAGE SET_POSITION_TARGET_LOCAL_NED PACKING

#define MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED 84

typedef struct __mavlink_set_position_target_local_ned_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float x; /*< [m] X Position in NED frame*/
 float y; /*< [m] Y Position in NED frame*/
 float z; /*< [m] Z Position in NED frame (note, altitude is negative in NED)*/
 float vx; /*< [m/s] X velocity in NED frame*/
 float vy; /*< [m/s] Y velocity in NED frame*/
 float vz; /*< [m/s] Z velocity in NED frame*/
 float afx; /*< [m/s/s] X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N*/
 float afy; /*< [m/s/s] Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N*/
 float afz; /*< [m/s/s] Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N*/
 float yaw; /*< [rad] yaw setpoint*/
 float yaw_rate; /*< [rad/s] yaw rate setpoint*/
 uint16_t type_mask; /*<  Bitmap to indicate which dimensions should be ignored by the vehicle.*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t coordinate_frame; /*<  Valid options are: MAV_FRAME_LOCAL_NED = 1, MAV_FRAME_LOCAL_OFFSET_NED = 7, MAV_FRAME_BODY_NED = 8, MAV_FRAME_BODY_OFFSET_NED = 9*/
} mavlink_set_position_target_local_ned_t;

#define MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_LEN 53
#define MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_MIN_LEN 53
#define MAVLINK_MSG_ID_84_LEN 53
#define MAVLINK_MSG_ID_84_MIN_LEN 53

#define MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_CRC 143
#define MAVLINK_MSG_ID_84_CRC 143



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_POSITION_TARGET_LOCAL_NED { \
    84, \
    "SET_POSITION_TARGET_LOCAL_NED", \
    16, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_position_target_local_ned_t, time_boot_ms) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_set_position_target_local_ned_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 51, offsetof(mavlink_set_position_target_local_ned_t, target_component) }, \
         { "coordinate_frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_set_position_target_local_ned_t, coordinate_frame) }, \
         { "type_mask", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_set_position_target_local_ned_t, type_mask) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_set_position_target_local_ned_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_set_position_target_local_ned_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_set_position_target_local_ned_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_set_position_target_local_ned_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_set_position_target_local_ned_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_set_position_target_local_ned_t, vz) }, \
         { "afx", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_set_position_target_local_ned_t, afx) }, \
         { "afy", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_set_position_target_local_ned_t, afy) }, \
         { "afz", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_set_position_target_local_ned_t, afz) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_set_position_target_local_ned_t, yaw) }, \
         { "yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_set_position_target_local_ned_t, yaw_rate) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_POSITION_TARGET_LOCAL_NED { \
    "SET_POSITION_TARGET_LOCAL_NED", \
    16, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_position_target_local_ned_t, time_boot_ms) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_set_position_target_local_ned_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 51, offsetof(mavlink_set_position_target_local_ned_t, target_component) }, \
         { "coordinate_frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_set_position_target_local_ned_t, coordinate_frame) }, \
         { "type_mask", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_set_position_target_local_ned_t, type_mask) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_set_position_target_local_ned_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_set_position_target_local_ned_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_set_position_target_local_ned_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_set_position_target_local_ned_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_set_position_target_local_ned_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_set_position_target_local_ned_t, vz) }, \
         { "afx", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_set_position_target_local_ned_t, afx) }, \
         { "afy", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_set_position_target_local_ned_t, afy) }, \
         { "afz", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_set_position_target_local_ned_t, afz) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_set_position_target_local_ned_t, yaw) }, \
         { "yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_set_position_target_local_ned_t, yaw_rate) }, \
         } \
}
#endif

/**
 * @brief Pack a set_position_target_local_ned message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param coordinate_frame  Valid options are: MAV_FRAME_LOCAL_NED = 1, MAV_FRAME_LOCAL_OFFSET_NED = 7, MAV_FRAME_BODY_NED = 8, MAV_FRAME_BODY_OFFSET_NED = 9
 * @param type_mask  Bitmap to indicate which dimensions should be ignored by the vehicle.
 * @param x [m] X Position in NED frame
 * @param y [m] Y Position in NED frame
 * @param z [m] Z Position in NED frame (note, altitude is negative in NED)
 * @param vx [m/s] X velocity in NED frame
 * @param vy [m/s] Y velocity in NED frame
 * @param vz [m/s] Z velocity in NED frame
 * @param afx [m/s/s] X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 * @param afy [m/s/s] Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 * @param afz [m/s/s] Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 * @param yaw [rad] yaw setpoint
 * @param yaw_rate [rad/s] yaw rate setpoint
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_position_target_local_ned_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t target_system, uint8_t target_component, uint8_t coordinate_frame, uint16_t type_mask, float x, float y, float z, float vx, float vy, float vz, float afx, float afy, float afz, float yaw, float yaw_rate)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_float(((char*)msg->payloads), 4, x);
    _mav_put_float(((char*)msg->payloads), 8, y);
    _mav_put_float(((char*)msg->payloads), 12, z);
    _mav_put_float(((char*)msg->payloads), 16, vx);
    _mav_put_float(((char*)msg->payloads), 20, vy);
    _mav_put_float(((char*)msg->payloads), 24, vz);
    _mav_put_float(((char*)msg->payloads), 28, afx);
    _mav_put_float(((char*)msg->payloads), 32, afy);
    _mav_put_float(((char*)msg->payloads), 36, afz);
    _mav_put_float(((char*)msg->payloads), 40, yaw);
    _mav_put_float(((char*)msg->payloads), 44, yaw_rate);
    _mav_put_uint16_t(((char*)msg->payloads), 48, type_mask);
    _mav_put_uint8_t(((char*)msg->payloads), 50, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 51, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 52, coordinate_frame);

    msg->msgid = MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_MIN_LEN, MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_LEN, MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_CRC);
}

/**
 * @brief Pack a set_position_target_local_ned message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param coordinate_frame  Valid options are: MAV_FRAME_LOCAL_NED = 1, MAV_FRAME_LOCAL_OFFSET_NED = 7, MAV_FRAME_BODY_NED = 8, MAV_FRAME_BODY_OFFSET_NED = 9
 * @param type_mask  Bitmap to indicate which dimensions should be ignored by the vehicle.
 * @param x [m] X Position in NED frame
 * @param y [m] Y Position in NED frame
 * @param z [m] Z Position in NED frame (note, altitude is negative in NED)
 * @param vx [m/s] X velocity in NED frame
 * @param vy [m/s] Y velocity in NED frame
 * @param vz [m/s] Z velocity in NED frame
 * @param afx [m/s/s] X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 * @param afy [m/s/s] Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 * @param afz [m/s/s] Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 * @param yaw [rad] yaw setpoint
 * @param yaw_rate [rad/s] yaw rate setpoint
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_position_target_local_ned_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t target_system,uint8_t target_component,uint8_t coordinate_frame,uint16_t type_mask,float x,float y,float z,float vx,float vy,float vz,float afx,float afy,float afz,float yaw,float yaw_rate)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_float(((char*)msg->payloads), 4, x);
    _mav_put_float(((char*)msg->payloads), 8, y);
    _mav_put_float(((char*)msg->payloads), 12, z);
    _mav_put_float(((char*)msg->payloads), 16, vx);
    _mav_put_float(((char*)msg->payloads), 20, vy);
    _mav_put_float(((char*)msg->payloads), 24, vz);
    _mav_put_float(((char*)msg->payloads), 28, afx);
    _mav_put_float(((char*)msg->payloads), 32, afy);
    _mav_put_float(((char*)msg->payloads), 36, afz);
    _mav_put_float(((char*)msg->payloads), 40, yaw);
    _mav_put_float(((char*)msg->payloads), 44, yaw_rate);
    _mav_put_uint16_t(((char*)msg->payloads), 48, type_mask);
    _mav_put_uint8_t(((char*)msg->payloads), 50, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 51, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 52, coordinate_frame);


    msg->msgid = MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_MIN_LEN, MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_LEN, MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED_CRC);
}

/**
 * @brief Encode a set_position_target_local_ned struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_position_target_local_ned C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_position_target_local_ned_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_position_target_local_ned_t* set_position_target_local_ned)
{
    return mavlink_msg_set_position_target_local_ned_pack(system_id, component_id, msg, set_position_target_local_ned->time_boot_ms, set_position_target_local_ned->target_system, set_position_target_local_ned->target_component, set_position_target_local_ned->coordinate_frame, set_position_target_local_ned->type_mask, set_position_target_local_ned->x, set_position_target_local_ned->y, set_position_target_local_ned->z, set_position_target_local_ned->vx, set_position_target_local_ned->vy, set_position_target_local_ned->vz, set_position_target_local_ned->afx, set_position_target_local_ned->afy, set_position_target_local_ned->afz, set_position_target_local_ned->yaw, set_position_target_local_ned->yaw_rate);
}

/**
 * @brief Encode a set_position_target_local_ned struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_position_target_local_ned C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_position_target_local_ned_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_position_target_local_ned_t* set_position_target_local_ned)
{
    return mavlink_msg_set_position_target_local_ned_pack_chan(system_id, component_id, chan, msg, set_position_target_local_ned->time_boot_ms, set_position_target_local_ned->target_system, set_position_target_local_ned->target_component, set_position_target_local_ned->coordinate_frame, set_position_target_local_ned->type_mask, set_position_target_local_ned->x, set_position_target_local_ned->y, set_position_target_local_ned->z, set_position_target_local_ned->vx, set_position_target_local_ned->vy, set_position_target_local_ned->vz, set_position_target_local_ned->afx, set_position_target_local_ned->afy, set_position_target_local_ned->afz, set_position_target_local_ned->yaw, set_position_target_local_ned->yaw_rate);
}

// MESSAGE SET_POSITION_TARGET_LOCAL_NED UNPACKING


/**
 * @brief Get field time_boot_ms from set_position_target_local_ned message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_set_position_target_local_ned_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field target_system from set_position_target_local_ned message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_set_position_target_local_ned_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  50);
}

/**
 * @brief Get field target_component from set_position_target_local_ned message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_set_position_target_local_ned_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  51);
}

/**
 * @brief Get field coordinate_frame from set_position_target_local_ned message
 *
 * @return  Valid options are: MAV_FRAME_LOCAL_NED = 1, MAV_FRAME_LOCAL_OFFSET_NED = 7, MAV_FRAME_BODY_NED = 8, MAV_FRAME_BODY_OFFSET_NED = 9
 */
static inline uint8_t mavlink_msg_set_position_target_local_ned_get_coordinate_frame(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  52);
}

/**
 * @brief Get field type_mask from set_position_target_local_ned message
 *
 * @return  Bitmap to indicate which dimensions should be ignored by the vehicle.
 */
static inline uint16_t mavlink_msg_set_position_target_local_ned_get_type_mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  48);
}

/**
 * @brief Get field x from set_position_target_local_ned message
 *
 * @return [m] X Position in NED frame
 */
static inline float mavlink_msg_set_position_target_local_ned_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field y from set_position_target_local_ned message
 *
 * @return [m] Y Position in NED frame
 */
static inline float mavlink_msg_set_position_target_local_ned_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field z from set_position_target_local_ned message
 *
 * @return [m] Z Position in NED frame (note, altitude is negative in NED)
 */
static inline float mavlink_msg_set_position_target_local_ned_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field vx from set_position_target_local_ned message
 *
 * @return [m/s] X velocity in NED frame
 */
static inline float mavlink_msg_set_position_target_local_ned_get_vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field vy from set_position_target_local_ned message
 *
 * @return [m/s] Y velocity in NED frame
 */
static inline float mavlink_msg_set_position_target_local_ned_get_vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field vz from set_position_target_local_ned message
 *
 * @return [m/s] Z velocity in NED frame
 */
static inline float mavlink_msg_set_position_target_local_ned_get_vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field afx from set_position_target_local_ned message
 *
 * @return [m/s/s] X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 */
static inline float mavlink_msg_set_position_target_local_ned_get_afx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field afy from set_position_target_local_ned message
 *
 * @return [m/s/s] Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 */
static inline float mavlink_msg_set_position_target_local_ned_get_afy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field afz from set_position_target_local_ned message
 *
 * @return [m/s/s] Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 */
static inline float mavlink_msg_set_position_target_local_ned_get_afz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field yaw from set_position_target_local_ned message
 *
 * @return [rad] yaw setpoint
 */
static inline float mavlink_msg_set_position_target_local_ned_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field yaw_rate from set_position_target_local_ned message
 *
 * @return [rad/s] yaw rate setpoint
 */
static inline float mavlink_msg_set_position_target_local_ned_get_yaw_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Decode a set_position_target_local_ned message into a struct
 *
 * @param msg The message to decode
 * @param set_position_target_local_ned C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_position_target_local_ned_decode(const mavlink_message_t* msg, mavlink_set_position_target_local_ned_t* set_position_target_local_ned)
{
    set_position_target_local_ned->time_boot_ms = mavlink_msg_set_position_target_local_ned_get_time_boot_ms(msg);
    set_position_target_local_ned->x = mavlink_msg_set_position_target_local_ned_get_x(msg);
    set_position_target_local_ned->y = mavlink_msg_set_position_target_local_ned_get_y(msg);
    set_position_target_local_ned->z = mavlink_msg_set_position_target_local_ned_get_z(msg);
    set_position_target_local_ned->vx = mavlink_msg_set_position_target_local_ned_get_vx(msg);
    set_position_target_local_ned->vy = mavlink_msg_set_position_target_local_ned_get_vy(msg);
    set_position_target_local_ned->vz = mavlink_msg_set_position_target_local_ned_get_vz(msg);
    set_position_target_local_ned->afx = mavlink_msg_set_position_target_local_ned_get_afx(msg);
    set_position_target_local_ned->afy = mavlink_msg_set_position_target_local_ned_get_afy(msg);
    set_position_target_local_ned->afz = mavlink_msg_set_position_target_local_ned_get_afz(msg);
    set_position_target_local_ned->yaw = mavlink_msg_set_position_target_local_ned_get_yaw(msg);
    set_position_target_local_ned->yaw_rate = mavlink_msg_set_position_target_local_ned_get_yaw_rate(msg);
    set_position_target_local_ned->type_mask = mavlink_msg_set_position_target_local_ned_get_type_mask(msg);
    set_position_target_local_ned->target_system = mavlink_msg_set_position_target_local_ned_get_target_system(msg);
    set_position_target_local_ned->target_component = mavlink_msg_set_position_target_local_ned_get_target_component(msg);
    set_position_target_local_ned->coordinate_frame = mavlink_msg_set_position_target_local_ned_get_coordinate_frame(msg);
}
#endif
