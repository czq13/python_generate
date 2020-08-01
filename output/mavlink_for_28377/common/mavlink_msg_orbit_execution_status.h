#ifndef MAVLINK_MSG_orbit_execution_status
#define MAVLINK_MSG_orbit_execution_status
// MESSAGE ORBIT_EXECUTION_STATUS PACKING

#define MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS 360

typedef struct __mavlink_orbit_execution_status_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float radius; /*< [m] Radius of the orbit circle. Positive values orbit clockwise, negative values orbit counter-clockwise.*/
 int32_t x; /*<  X coordinate of center point. Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7.*/
 int32_t y; /*<  Y coordinate of center point.  Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7.*/
 float z; /*< [m] Altitude of center point. Coordinate system depends on frame field.*/
 uint8_t frame; /*<  The coordinate system of the fields: x, y, z.*/
} mavlink_orbit_execution_status_t;

#define MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_LEN 25
#define MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_MIN_LEN 25
#define MAVLINK_MSG_ID_360_LEN 25
#define MAVLINK_MSG_ID_360_MIN_LEN 25

#define MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_CRC 11
#define MAVLINK_MSG_ID_360_CRC 11



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ORBIT_EXECUTION_STATUS { \
    360, \
    "ORBIT_EXECUTION_STATUS", \
    6, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_orbit_execution_status_t, time_usec) }, \
         { "radius", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_orbit_execution_status_t, radius) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_orbit_execution_status_t, frame) }, \
         { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_orbit_execution_status_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_orbit_execution_status_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_orbit_execution_status_t, z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ORBIT_EXECUTION_STATUS { \
    "ORBIT_EXECUTION_STATUS", \
    6, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_orbit_execution_status_t, time_usec) }, \
         { "radius", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_orbit_execution_status_t, radius) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_orbit_execution_status_t, frame) }, \
         { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_orbit_execution_status_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_orbit_execution_status_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_orbit_execution_status_t, z) }, \
         } \
}
#endif

/**
 * @brief Pack a orbit_execution_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param radius [m] Radius of the orbit circle. Positive values orbit clockwise, negative values orbit counter-clockwise.
 * @param frame  The coordinate system of the fields: x, y, z.
 * @param x  X coordinate of center point. Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7.
 * @param y  Y coordinate of center point.  Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7.
 * @param z [m] Altitude of center point. Coordinate system depends on frame field.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_orbit_execution_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, float radius, uint8_t frame, int32_t x, int32_t y, float z)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_float(((char*)msg->payloads), 8, radius);
    _mav_put_int32_t(((char*)msg->payloads), 12, x);
    _mav_put_int32_t(((char*)msg->payloads), 16, y);
    _mav_put_float(((char*)msg->payloads), 20, z);
    _mav_put_uint8_t(((char*)msg->payloads), 24, frame);

    msg->msgid = MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_LEN, MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_CRC);
}

/**
 * @brief Pack a orbit_execution_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param radius [m] Radius of the orbit circle. Positive values orbit clockwise, negative values orbit counter-clockwise.
 * @param frame  The coordinate system of the fields: x, y, z.
 * @param x  X coordinate of center point. Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7.
 * @param y  Y coordinate of center point.  Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7.
 * @param z [m] Altitude of center point. Coordinate system depends on frame field.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_orbit_execution_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,float radius,uint8_t frame,int32_t x,int32_t y,float z)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_float(((char*)msg->payloads), 8, radius);
    _mav_put_int32_t(((char*)msg->payloads), 12, x);
    _mav_put_int32_t(((char*)msg->payloads), 16, y);
    _mav_put_float(((char*)msg->payloads), 20, z);
    _mav_put_uint8_t(((char*)msg->payloads), 24, frame);


    msg->msgid = MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_LEN, MAVLINK_MSG_ID_ORBIT_EXECUTION_STATUS_CRC);
}

/**
 * @brief Encode a orbit_execution_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param orbit_execution_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_orbit_execution_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_orbit_execution_status_t* orbit_execution_status)
{
    return mavlink_msg_orbit_execution_status_pack(system_id, component_id, msg, orbit_execution_status->time_usec, orbit_execution_status->radius, orbit_execution_status->frame, orbit_execution_status->x, orbit_execution_status->y, orbit_execution_status->z);
}

/**
 * @brief Encode a orbit_execution_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param orbit_execution_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_orbit_execution_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_orbit_execution_status_t* orbit_execution_status)
{
    return mavlink_msg_orbit_execution_status_pack_chan(system_id, component_id, chan, msg, orbit_execution_status->time_usec, orbit_execution_status->radius, orbit_execution_status->frame, orbit_execution_status->x, orbit_execution_status->y, orbit_execution_status->z);
}

// MESSAGE ORBIT_EXECUTION_STATUS UNPACKING


/**
 * @brief Get field time_usec from orbit_execution_status message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_orbit_execution_status_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field radius from orbit_execution_status message
 *
 * @return [m] Radius of the orbit circle. Positive values orbit clockwise, negative values orbit counter-clockwise.
 */
static inline float mavlink_msg_orbit_execution_status_get_radius(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field frame from orbit_execution_status message
 *
 * @return  The coordinate system of the fields: x, y, z.
 */
static inline uint8_t mavlink_msg_orbit_execution_status_get_frame(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field x from orbit_execution_status message
 *
 * @return  X coordinate of center point. Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7.
 */
static inline int32_t mavlink_msg_orbit_execution_status_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field y from orbit_execution_status message
 *
 * @return  Y coordinate of center point.  Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7.
 */
static inline int32_t mavlink_msg_orbit_execution_status_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field z from orbit_execution_status message
 *
 * @return [m] Altitude of center point. Coordinate system depends on frame field.
 */
static inline float mavlink_msg_orbit_execution_status_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a orbit_execution_status message into a struct
 *
 * @param msg The message to decode
 * @param orbit_execution_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_orbit_execution_status_decode(const mavlink_message_t* msg, mavlink_orbit_execution_status_t* orbit_execution_status)
{
    orbit_execution_status->time_usec = mavlink_msg_orbit_execution_status_get_time_usec(msg);
    orbit_execution_status->radius = mavlink_msg_orbit_execution_status_get_radius(msg);
    orbit_execution_status->x = mavlink_msg_orbit_execution_status_get_x(msg);
    orbit_execution_status->y = mavlink_msg_orbit_execution_status_get_y(msg);
    orbit_execution_status->z = mavlink_msg_orbit_execution_status_get_z(msg);
    orbit_execution_status->frame = mavlink_msg_orbit_execution_status_get_frame(msg);
}
#endif
