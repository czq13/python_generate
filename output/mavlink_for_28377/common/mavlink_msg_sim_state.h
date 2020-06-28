#ifndef MAVLINK_MSG_sim_state
#define MAVLINK_MSG_sim_state
// MESSAGE SIM_STATE PACKING

#define MAVLINK_MSG_ID_SIM_STATE 108

typedef struct __mavlink_sim_state_t {
 float q1; /*<  True attitude quaternion component 1, w (1 in null-rotation)*/
 float q2; /*<  True attitude quaternion component 2, x (0 in null-rotation)*/
 float q3; /*<  True attitude quaternion component 3, y (0 in null-rotation)*/
 float q4; /*<  True attitude quaternion component 4, z (0 in null-rotation)*/
 float roll; /*<  Attitude roll expressed as Euler angles, not recommended except for human-readable outputs*/
 float pitch; /*<  Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs*/
 float yaw; /*<  Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs*/
 float xacc; /*< [m/s/s] X acceleration*/
 float yacc; /*< [m/s/s] Y acceleration*/
 float zacc; /*< [m/s/s] Z acceleration*/
 float xgyro; /*< [rad/s] Angular speed around X axis*/
 float ygyro; /*< [rad/s] Angular speed around Y axis*/
 float zgyro; /*< [rad/s] Angular speed around Z axis*/
 float lat; /*< [deg] Latitude*/
 float lon; /*< [deg] Longitude*/
 float alt; /*< [m] Altitude*/
 float std_dev_horz; /*<  Horizontal position standard deviation*/
 float std_dev_vert; /*<  Vertical position standard deviation*/
 float vn; /*< [m/s] True velocity in north direction in earth-fixed NED frame*/
 float ve; /*< [m/s] True velocity in east direction in earth-fixed NED frame*/
 float vd; /*< [m/s] True velocity in down direction in earth-fixed NED frame*/
} mavlink_sim_state_t;

#define MAVLINK_MSG_ID_SIM_STATE_LEN 84
#define MAVLINK_MSG_ID_SIM_STATE_MIN_LEN 84
#define MAVLINK_MSG_ID_108_LEN 84
#define MAVLINK_MSG_ID_108_MIN_LEN 84

#define MAVLINK_MSG_ID_SIM_STATE_CRC 32
#define MAVLINK_MSG_ID_108_CRC 32



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SIM_STATE { \
    108, \
    "SIM_STATE", \
    21, \
    {  { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_sim_state_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_sim_state_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_sim_state_t, q3) }, \
         { "q4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sim_state_t, q4) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sim_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_sim_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_sim_state_t, yaw) }, \
         { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sim_state_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sim_state_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_sim_state_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_sim_state_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_sim_state_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_sim_state_t, zgyro) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_sim_state_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_sim_state_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_sim_state_t, alt) }, \
         { "std_dev_horz", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_sim_state_t, std_dev_horz) }, \
         { "std_dev_vert", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_sim_state_t, std_dev_vert) }, \
         { "vn", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_sim_state_t, vn) }, \
         { "ve", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_sim_state_t, ve) }, \
         { "vd", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_sim_state_t, vd) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SIM_STATE { \
    "SIM_STATE", \
    21, \
    {  { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_sim_state_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_sim_state_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_sim_state_t, q3) }, \
         { "q4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sim_state_t, q4) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sim_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_sim_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_sim_state_t, yaw) }, \
         { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sim_state_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sim_state_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_sim_state_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_sim_state_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_sim_state_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_sim_state_t, zgyro) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_sim_state_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_sim_state_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_sim_state_t, alt) }, \
         { "std_dev_horz", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_sim_state_t, std_dev_horz) }, \
         { "std_dev_vert", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_sim_state_t, std_dev_vert) }, \
         { "vn", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_sim_state_t, vn) }, \
         { "ve", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_sim_state_t, ve) }, \
         { "vd", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_sim_state_t, vd) }, \
         } \
}
#endif

/**
 * @brief Pack a sim_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param q1  True attitude quaternion component 1, w (1 in null-rotation)
 * @param q2  True attitude quaternion component 2, x (0 in null-rotation)
 * @param q3  True attitude quaternion component 3, y (0 in null-rotation)
 * @param q4  True attitude quaternion component 4, z (0 in null-rotation)
 * @param roll  Attitude roll expressed as Euler angles, not recommended except for human-readable outputs
 * @param pitch  Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs
 * @param yaw  Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs
 * @param xacc [m/s/s] X acceleration
 * @param yacc [m/s/s] Y acceleration
 * @param zacc [m/s/s] Z acceleration
 * @param xgyro [rad/s] Angular speed around X axis
 * @param ygyro [rad/s] Angular speed around Y axis
 * @param zgyro [rad/s] Angular speed around Z axis
 * @param lat [deg] Latitude
 * @param lon [deg] Longitude
 * @param alt [m] Altitude
 * @param std_dev_horz  Horizontal position standard deviation
 * @param std_dev_vert  Vertical position standard deviation
 * @param vn [m/s] True velocity in north direction in earth-fixed NED frame
 * @param ve [m/s] True velocity in east direction in earth-fixed NED frame
 * @param vd [m/s] True velocity in down direction in earth-fixed NED frame
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sim_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float q1, float q2, float q3, float q4, float roll, float pitch, float yaw, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float lat, float lon, float alt, float std_dev_horz, float std_dev_vert, float vn, float ve, float vd)
{
    _mav_put_float(((char*)msg->payloads), 0, q1);
    _mav_put_float(((char*)msg->payloads), 4, q2);
    _mav_put_float(((char*)msg->payloads), 8, q3);
    _mav_put_float(((char*)msg->payloads), 12, q4);
    _mav_put_float(((char*)msg->payloads), 16, roll);
    _mav_put_float(((char*)msg->payloads), 20, pitch);
    _mav_put_float(((char*)msg->payloads), 24, yaw);
    _mav_put_float(((char*)msg->payloads), 28, xacc);
    _mav_put_float(((char*)msg->payloads), 32, yacc);
    _mav_put_float(((char*)msg->payloads), 36, zacc);
    _mav_put_float(((char*)msg->payloads), 40, xgyro);
    _mav_put_float(((char*)msg->payloads), 44, ygyro);
    _mav_put_float(((char*)msg->payloads), 48, zgyro);
    _mav_put_float(((char*)msg->payloads), 52, lat);
    _mav_put_float(((char*)msg->payloads), 56, lon);
    _mav_put_float(((char*)msg->payloads), 60, alt);
    _mav_put_float(((char*)msg->payloads), 64, std_dev_horz);
    _mav_put_float(((char*)msg->payloads), 68, std_dev_vert);
    _mav_put_float(((char*)msg->payloads), 72, vn);
    _mav_put_float(((char*)msg->payloads), 76, ve);
    _mav_put_float(((char*)msg->payloads), 80, vd);

    msg->msgid = MAVLINK_MSG_ID_SIM_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SIM_STATE_MIN_LEN, MAVLINK_MSG_ID_SIM_STATE_LEN, MAVLINK_MSG_ID_SIM_STATE_CRC);
}

/**
 * @brief Pack a sim_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param q1  True attitude quaternion component 1, w (1 in null-rotation)
 * @param q2  True attitude quaternion component 2, x (0 in null-rotation)
 * @param q3  True attitude quaternion component 3, y (0 in null-rotation)
 * @param q4  True attitude quaternion component 4, z (0 in null-rotation)
 * @param roll  Attitude roll expressed as Euler angles, not recommended except for human-readable outputs
 * @param pitch  Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs
 * @param yaw  Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs
 * @param xacc [m/s/s] X acceleration
 * @param yacc [m/s/s] Y acceleration
 * @param zacc [m/s/s] Z acceleration
 * @param xgyro [rad/s] Angular speed around X axis
 * @param ygyro [rad/s] Angular speed around Y axis
 * @param zgyro [rad/s] Angular speed around Z axis
 * @param lat [deg] Latitude
 * @param lon [deg] Longitude
 * @param alt [m] Altitude
 * @param std_dev_horz  Horizontal position standard deviation
 * @param std_dev_vert  Vertical position standard deviation
 * @param vn [m/s] True velocity in north direction in earth-fixed NED frame
 * @param ve [m/s] True velocity in east direction in earth-fixed NED frame
 * @param vd [m/s] True velocity in down direction in earth-fixed NED frame
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sim_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float q1,float q2,float q3,float q4,float roll,float pitch,float yaw,float xacc,float yacc,float zacc,float xgyro,float ygyro,float zgyro,float lat,float lon,float alt,float std_dev_horz,float std_dev_vert,float vn,float ve,float vd)
{
    _mav_put_float(((char*)msg->payloads), 0, q1);
    _mav_put_float(((char*)msg->payloads), 4, q2);
    _mav_put_float(((char*)msg->payloads), 8, q3);
    _mav_put_float(((char*)msg->payloads), 12, q4);
    _mav_put_float(((char*)msg->payloads), 16, roll);
    _mav_put_float(((char*)msg->payloads), 20, pitch);
    _mav_put_float(((char*)msg->payloads), 24, yaw);
    _mav_put_float(((char*)msg->payloads), 28, xacc);
    _mav_put_float(((char*)msg->payloads), 32, yacc);
    _mav_put_float(((char*)msg->payloads), 36, zacc);
    _mav_put_float(((char*)msg->payloads), 40, xgyro);
    _mav_put_float(((char*)msg->payloads), 44, ygyro);
    _mav_put_float(((char*)msg->payloads), 48, zgyro);
    _mav_put_float(((char*)msg->payloads), 52, lat);
    _mav_put_float(((char*)msg->payloads), 56, lon);
    _mav_put_float(((char*)msg->payloads), 60, alt);
    _mav_put_float(((char*)msg->payloads), 64, std_dev_horz);
    _mav_put_float(((char*)msg->payloads), 68, std_dev_vert);
    _mav_put_float(((char*)msg->payloads), 72, vn);
    _mav_put_float(((char*)msg->payloads), 76, ve);
    _mav_put_float(((char*)msg->payloads), 80, vd);


    msg->msgid = MAVLINK_MSG_ID_SIM_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SIM_STATE_MIN_LEN, MAVLINK_MSG_ID_SIM_STATE_LEN, MAVLINK_MSG_ID_SIM_STATE_CRC);
}

/**
 * @brief Encode a sim_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sim_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sim_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sim_state_t* sim_state)
{
    return mavlink_msg_sim_state_pack(system_id, component_id, msg, sim_state->q1, sim_state->q2, sim_state->q3, sim_state->q4, sim_state->roll, sim_state->pitch, sim_state->yaw, sim_state->xacc, sim_state->yacc, sim_state->zacc, sim_state->xgyro, sim_state->ygyro, sim_state->zgyro, sim_state->lat, sim_state->lon, sim_state->alt, sim_state->std_dev_horz, sim_state->std_dev_vert, sim_state->vn, sim_state->ve, sim_state->vd);
}

/**
 * @brief Encode a sim_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sim_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sim_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sim_state_t* sim_state)
{
    return mavlink_msg_sim_state_pack_chan(system_id, component_id, chan, msg, sim_state->q1, sim_state->q2, sim_state->q3, sim_state->q4, sim_state->roll, sim_state->pitch, sim_state->yaw, sim_state->xacc, sim_state->yacc, sim_state->zacc, sim_state->xgyro, sim_state->ygyro, sim_state->zgyro, sim_state->lat, sim_state->lon, sim_state->alt, sim_state->std_dev_horz, sim_state->std_dev_vert, sim_state->vn, sim_state->ve, sim_state->vd);
}

// MESSAGE SIM_STATE UNPACKING


/**
 * @brief Get field q1 from sim_state message
 *
 * @return  True attitude quaternion component 1, w (1 in null-rotation)
 */
static inline float mavlink_msg_sim_state_get_q1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field q2 from sim_state message
 *
 * @return  True attitude quaternion component 2, x (0 in null-rotation)
 */
static inline float mavlink_msg_sim_state_get_q2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field q3 from sim_state message
 *
 * @return  True attitude quaternion component 3, y (0 in null-rotation)
 */
static inline float mavlink_msg_sim_state_get_q3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field q4 from sim_state message
 *
 * @return  True attitude quaternion component 4, z (0 in null-rotation)
 */
static inline float mavlink_msg_sim_state_get_q4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field roll from sim_state message
 *
 * @return  Attitude roll expressed as Euler angles, not recommended except for human-readable outputs
 */
static inline float mavlink_msg_sim_state_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pitch from sim_state message
 *
 * @return  Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs
 */
static inline float mavlink_msg_sim_state_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field yaw from sim_state message
 *
 * @return  Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs
 */
static inline float mavlink_msg_sim_state_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field xacc from sim_state message
 *
 * @return [m/s/s] X acceleration
 */
static inline float mavlink_msg_sim_state_get_xacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field yacc from sim_state message
 *
 * @return [m/s/s] Y acceleration
 */
static inline float mavlink_msg_sim_state_get_yacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field zacc from sim_state message
 *
 * @return [m/s/s] Z acceleration
 */
static inline float mavlink_msg_sim_state_get_zacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field xgyro from sim_state message
 *
 * @return [rad/s] Angular speed around X axis
 */
static inline float mavlink_msg_sim_state_get_xgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field ygyro from sim_state message
 *
 * @return [rad/s] Angular speed around Y axis
 */
static inline float mavlink_msg_sim_state_get_ygyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field zgyro from sim_state message
 *
 * @return [rad/s] Angular speed around Z axis
 */
static inline float mavlink_msg_sim_state_get_zgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field lat from sim_state message
 *
 * @return [deg] Latitude
 */
static inline float mavlink_msg_sim_state_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field lon from sim_state message
 *
 * @return [deg] Longitude
 */
static inline float mavlink_msg_sim_state_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field alt from sim_state message
 *
 * @return [m] Altitude
 */
static inline float mavlink_msg_sim_state_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field std_dev_horz from sim_state message
 *
 * @return  Horizontal position standard deviation
 */
static inline float mavlink_msg_sim_state_get_std_dev_horz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field std_dev_vert from sim_state message
 *
 * @return  Vertical position standard deviation
 */
static inline float mavlink_msg_sim_state_get_std_dev_vert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field vn from sim_state message
 *
 * @return [m/s] True velocity in north direction in earth-fixed NED frame
 */
static inline float mavlink_msg_sim_state_get_vn(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field ve from sim_state message
 *
 * @return [m/s] True velocity in east direction in earth-fixed NED frame
 */
static inline float mavlink_msg_sim_state_get_ve(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field vd from sim_state message
 *
 * @return [m/s] True velocity in down direction in earth-fixed NED frame
 */
static inline float mavlink_msg_sim_state_get_vd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Decode a sim_state message into a struct
 *
 * @param msg The message to decode
 * @param sim_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_sim_state_decode(const mavlink_message_t* msg, mavlink_sim_state_t* sim_state)
{
    sim_state->q1 = mavlink_msg_sim_state_get_q1(msg);
    sim_state->q2 = mavlink_msg_sim_state_get_q2(msg);
    sim_state->q3 = mavlink_msg_sim_state_get_q3(msg);
    sim_state->q4 = mavlink_msg_sim_state_get_q4(msg);
    sim_state->roll = mavlink_msg_sim_state_get_roll(msg);
    sim_state->pitch = mavlink_msg_sim_state_get_pitch(msg);
    sim_state->yaw = mavlink_msg_sim_state_get_yaw(msg);
    sim_state->xacc = mavlink_msg_sim_state_get_xacc(msg);
    sim_state->yacc = mavlink_msg_sim_state_get_yacc(msg);
    sim_state->zacc = mavlink_msg_sim_state_get_zacc(msg);
    sim_state->xgyro = mavlink_msg_sim_state_get_xgyro(msg);
    sim_state->ygyro = mavlink_msg_sim_state_get_ygyro(msg);
    sim_state->zgyro = mavlink_msg_sim_state_get_zgyro(msg);
    sim_state->lat = mavlink_msg_sim_state_get_lat(msg);
    sim_state->lon = mavlink_msg_sim_state_get_lon(msg);
    sim_state->alt = mavlink_msg_sim_state_get_alt(msg);
    sim_state->std_dev_horz = mavlink_msg_sim_state_get_std_dev_horz(msg);
    sim_state->std_dev_vert = mavlink_msg_sim_state_get_std_dev_vert(msg);
    sim_state->vn = mavlink_msg_sim_state_get_vn(msg);
    sim_state->ve = mavlink_msg_sim_state_get_ve(msg);
    sim_state->vd = mavlink_msg_sim_state_get_vd(msg);
}
#endif
