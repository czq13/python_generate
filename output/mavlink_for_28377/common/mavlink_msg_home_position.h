#ifndef MAVLINK_MSG_home_position
#define MAVLINK_MSG_home_position
// MESSAGE HOME_POSITION PACKING

#define MAVLINK_MSG_ID_HOME_POSITION 242

typedef struct __mavlink_home_position_t {
 int32_t latitude; /*< [degE7] Latitude (WGS84)*/
 int32_t longitude; /*< [degE7] Longitude (WGS84)*/
 int32_t altitude; /*< [mm] Altitude (MSL). Positive for up.*/
 float x; /*< [m] Local X position of this position in the local coordinate frame*/
 float y; /*< [m] Local Y position of this position in the local coordinate frame*/
 float z; /*< [m] Local Z position of this position in the local coordinate frame*/
 float q[4]; /*<  World to surface normal and heading transformation of the takeoff position. Used to indicate the heading and slope of the ground*/
 float approach_x; /*< [m] Local X position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.*/
 float approach_y; /*< [m] Local Y position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.*/
 float approach_z; /*< [m] Local Z position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.*/
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
} mavlink_home_position_t;

#define MAVLINK_MSG_ID_HOME_POSITION_LEN 60
#define MAVLINK_MSG_ID_HOME_POSITION_MIN_LEN 52
#define MAVLINK_MSG_ID_242_LEN 60
#define MAVLINK_MSG_ID_242_MIN_LEN 52

#define MAVLINK_MSG_ID_HOME_POSITION_CRC 104
#define MAVLINK_MSG_ID_242_CRC 104

#define MAVLINK_MSG_HOME_POSITION_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HOME_POSITION { \
    242, \
    "HOME_POSITION", \
    11, \
    {  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_home_position_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_home_position_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_home_position_t, altitude) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_home_position_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_home_position_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_home_position_t, z) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 24, offsetof(mavlink_home_position_t, q) }, \
         { "approach_x", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_home_position_t, approach_x) }, \
         { "approach_y", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_home_position_t, approach_y) }, \
         { "approach_z", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_home_position_t, approach_z) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 52, offsetof(mavlink_home_position_t, time_usec) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HOME_POSITION { \
    "HOME_POSITION", \
    11, \
    {  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_home_position_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_home_position_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_home_position_t, altitude) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_home_position_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_home_position_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_home_position_t, z) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 24, offsetof(mavlink_home_position_t, q) }, \
         { "approach_x", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_home_position_t, approach_x) }, \
         { "approach_y", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_home_position_t, approach_y) }, \
         { "approach_z", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_home_position_t, approach_z) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 52, offsetof(mavlink_home_position_t, time_usec) }, \
         } \
}
#endif

/**
 * @brief Pack a home_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param latitude [degE7] Latitude (WGS84)
 * @param longitude [degE7] Longitude (WGS84)
 * @param altitude [mm] Altitude (MSL). Positive for up.
 * @param x [m] Local X position of this position in the local coordinate frame
 * @param y [m] Local Y position of this position in the local coordinate frame
 * @param z [m] Local Z position of this position in the local coordinate frame
 * @param q  World to surface normal and heading transformation of the takeoff position. Used to indicate the heading and slope of the ground
 * @param approach_x [m] Local X position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
 * @param approach_y [m] Local Y position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
 * @param approach_z [m] Local Z position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_home_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t latitude, int32_t longitude, int32_t altitude, float x, float y, float z, const float *q, float approach_x, float approach_y, float approach_z, uint64_t time_usec)
{
    _mav_put_int32_t(((char*)msg->payloads), 0, latitude);
    _mav_put_int32_t(((char*)msg->payloads), 4, longitude);
    _mav_put_int32_t(((char*)msg->payloads), 8, altitude);
    _mav_put_float(((char*)msg->payloads), 12, x);
    _mav_put_float(((char*)msg->payloads), 16, y);
    _mav_put_float(((char*)msg->payloads), 20, z);
    _mav_put_float(((char*)msg->payloads), 40, approach_x);
    _mav_put_float(((char*)msg->payloads), 44, approach_y);
    _mav_put_float(((char*)msg->payloads), 48, approach_z);
    _mav_put_uint64_t(((char*)msg->payloads), 52, time_usec);
    _mav_put_float_array(((char*)msg->payloads), 24, q, 4);
    msg->msgid = MAVLINK_MSG_ID_HOME_POSITION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HOME_POSITION_MIN_LEN, MAVLINK_MSG_ID_HOME_POSITION_LEN, MAVLINK_MSG_ID_HOME_POSITION_CRC);
}

/**
 * @brief Pack a home_position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param latitude [degE7] Latitude (WGS84)
 * @param longitude [degE7] Longitude (WGS84)
 * @param altitude [mm] Altitude (MSL). Positive for up.
 * @param x [m] Local X position of this position in the local coordinate frame
 * @param y [m] Local Y position of this position in the local coordinate frame
 * @param z [m] Local Z position of this position in the local coordinate frame
 * @param q  World to surface normal and heading transformation of the takeoff position. Used to indicate the heading and slope of the ground
 * @param approach_x [m] Local X position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
 * @param approach_y [m] Local Y position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
 * @param approach_z [m] Local Z position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_home_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t latitude,int32_t longitude,int32_t altitude,float x,float y,float z,const float *q,float approach_x,float approach_y,float approach_z,uint64_t time_usec)
{
    _mav_put_int32_t(((char*)msg->payloads), 0, latitude);
    _mav_put_int32_t(((char*)msg->payloads), 4, longitude);
    _mav_put_int32_t(((char*)msg->payloads), 8, altitude);
    _mav_put_float(((char*)msg->payloads), 12, x);
    _mav_put_float(((char*)msg->payloads), 16, y);
    _mav_put_float(((char*)msg->payloads), 20, z);
    _mav_put_float(((char*)msg->payloads), 40, approach_x);
    _mav_put_float(((char*)msg->payloads), 44, approach_y);
    _mav_put_float(((char*)msg->payloads), 48, approach_z);
    _mav_put_uint64_t(((char*)msg->payloads), 52, time_usec);
    _mav_put_float_array(((char*)msg->payloads), 24, q, 4);

    msg->msgid = MAVLINK_MSG_ID_HOME_POSITION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HOME_POSITION_MIN_LEN, MAVLINK_MSG_ID_HOME_POSITION_LEN, MAVLINK_MSG_ID_HOME_POSITION_CRC);
}

/**
 * @brief Encode a home_position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param home_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_home_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_home_position_t* home_position)
{
    return mavlink_msg_home_position_pack(system_id, component_id, msg, home_position->latitude, home_position->longitude, home_position->altitude, home_position->x, home_position->y, home_position->z, home_position->q, home_position->approach_x, home_position->approach_y, home_position->approach_z, home_position->time_usec);
}

/**
 * @brief Encode a home_position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param home_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_home_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_home_position_t* home_position)
{
    return mavlink_msg_home_position_pack_chan(system_id, component_id, chan, msg, home_position->latitude, home_position->longitude, home_position->altitude, home_position->x, home_position->y, home_position->z, home_position->q, home_position->approach_x, home_position->approach_y, home_position->approach_z, home_position->time_usec);
}

// MESSAGE HOME_POSITION UNPACKING


/**
 * @brief Get field latitude from home_position message
 *
 * @return [degE7] Latitude (WGS84)
 */
static inline int32_t mavlink_msg_home_position_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from home_position message
 *
 * @return [degE7] Longitude (WGS84)
 */
static inline int32_t mavlink_msg_home_position_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field altitude from home_position message
 *
 * @return [mm] Altitude (MSL). Positive for up.
 */
static inline int32_t mavlink_msg_home_position_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field x from home_position message
 *
 * @return [m] Local X position of this position in the local coordinate frame
 */
static inline float mavlink_msg_home_position_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field y from home_position message
 *
 * @return [m] Local Y position of this position in the local coordinate frame
 */
static inline float mavlink_msg_home_position_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field z from home_position message
 *
 * @return [m] Local Z position of this position in the local coordinate frame
 */
static inline float mavlink_msg_home_position_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field q from home_position message
 *
 * @return  World to surface normal and heading transformation of the takeoff position. Used to indicate the heading and slope of the ground
 */
static inline uint16_t mavlink_msg_home_position_get_q(const mavlink_message_t* msg, float *q)
{
    return _MAV_RETURN_float_array(msg, q, 4,  24);
}

/**
 * @brief Get field approach_x from home_position message
 *
 * @return [m] Local X position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
 */
static inline float mavlink_msg_home_position_get_approach_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field approach_y from home_position message
 *
 * @return [m] Local Y position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
 */
static inline float mavlink_msg_home_position_get_approach_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field approach_z from home_position message
 *
 * @return [m] Local Z position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
 */
static inline float mavlink_msg_home_position_get_approach_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field time_usec from home_position message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_home_position_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  52);
}

/**
 * @brief Decode a home_position message into a struct
 *
 * @param msg The message to decode
 * @param home_position C-struct to decode the message contents into
 */
static inline void mavlink_msg_home_position_decode(const mavlink_message_t* msg, mavlink_home_position_t* home_position)
{
    home_position->latitude = mavlink_msg_home_position_get_latitude(msg);
    home_position->longitude = mavlink_msg_home_position_get_longitude(msg);
    home_position->altitude = mavlink_msg_home_position_get_altitude(msg);
    home_position->x = mavlink_msg_home_position_get_x(msg);
    home_position->y = mavlink_msg_home_position_get_y(msg);
    home_position->z = mavlink_msg_home_position_get_z(msg);
    mavlink_msg_home_position_get_q(msg, home_position->q);
    home_position->approach_x = mavlink_msg_home_position_get_approach_x(msg);
    home_position->approach_y = mavlink_msg_home_position_get_approach_y(msg);
    home_position->approach_z = mavlink_msg_home_position_get_approach_z(msg);
    home_position->time_usec = mavlink_msg_home_position_get_time_usec(msg);
}
#endif
