#ifndef MAVLINK_MSG_wind_cov
#define MAVLINK_MSG_wind_cov
// MESSAGE WIND_COV PACKING

#define MAVLINK_MSG_ID_WIND_COV 231

typedef struct __mavlink_wind_cov_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float wind_x; /*< [m/s] Wind in X (NED) direction*/
 float wind_y; /*< [m/s] Wind in Y (NED) direction*/
 float wind_z; /*< [m/s] Wind in Z (NED) direction*/
 float var_horiz; /*< [m/s] Variability of the wind in XY. RMS of a 1 Hz lowpassed wind estimate.*/
 float var_vert; /*< [m/s] Variability of the wind in Z. RMS of a 1 Hz lowpassed wind estimate.*/
 float wind_alt; /*< [m] Altitude (MSL) that this measurement was taken at*/
 float horiz_accuracy; /*< [m] Horizontal speed 1-STD accuracy*/
 float vert_accuracy; /*< [m] Vertical speed 1-STD accuracy*/
} mavlink_wind_cov_t;

#define MAVLINK_MSG_ID_WIND_COV_LEN 40
#define MAVLINK_MSG_ID_WIND_COV_MIN_LEN 40
#define MAVLINK_MSG_ID_231_LEN 40
#define MAVLINK_MSG_ID_231_MIN_LEN 40

#define MAVLINK_MSG_ID_WIND_COV_CRC 105
#define MAVLINK_MSG_ID_231_CRC 105



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIND_COV { \
    231, \
    "WIND_COV", \
    9, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wind_cov_t, time_usec) }, \
         { "wind_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wind_cov_t, wind_x) }, \
         { "wind_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wind_cov_t, wind_y) }, \
         { "wind_z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wind_cov_t, wind_z) }, \
         { "var_horiz", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wind_cov_t, var_horiz) }, \
         { "var_vert", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wind_cov_t, var_vert) }, \
         { "wind_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wind_cov_t, wind_alt) }, \
         { "horiz_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wind_cov_t, horiz_accuracy) }, \
         { "vert_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wind_cov_t, vert_accuracy) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIND_COV { \
    "WIND_COV", \
    9, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wind_cov_t, time_usec) }, \
         { "wind_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wind_cov_t, wind_x) }, \
         { "wind_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wind_cov_t, wind_y) }, \
         { "wind_z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wind_cov_t, wind_z) }, \
         { "var_horiz", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wind_cov_t, var_horiz) }, \
         { "var_vert", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wind_cov_t, var_vert) }, \
         { "wind_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wind_cov_t, wind_alt) }, \
         { "horiz_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wind_cov_t, horiz_accuracy) }, \
         { "vert_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wind_cov_t, vert_accuracy) }, \
         } \
}
#endif

/**
 * @brief Pack a wind_cov message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param wind_x [m/s] Wind in X (NED) direction
 * @param wind_y [m/s] Wind in Y (NED) direction
 * @param wind_z [m/s] Wind in Z (NED) direction
 * @param var_horiz [m/s] Variability of the wind in XY. RMS of a 1 Hz lowpassed wind estimate.
 * @param var_vert [m/s] Variability of the wind in Z. RMS of a 1 Hz lowpassed wind estimate.
 * @param wind_alt [m] Altitude (MSL) that this measurement was taken at
 * @param horiz_accuracy [m] Horizontal speed 1-STD accuracy
 * @param vert_accuracy [m] Vertical speed 1-STD accuracy
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wind_cov_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, float wind_x, float wind_y, float wind_z, float var_horiz, float var_vert, float wind_alt, float horiz_accuracy, float vert_accuracy)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_float(((char*)msg->payloads), 8, wind_x);
    _mav_put_float(((char*)msg->payloads), 12, wind_y);
    _mav_put_float(((char*)msg->payloads), 16, wind_z);
    _mav_put_float(((char*)msg->payloads), 20, var_horiz);
    _mav_put_float(((char*)msg->payloads), 24, var_vert);
    _mav_put_float(((char*)msg->payloads), 28, wind_alt);
    _mav_put_float(((char*)msg->payloads), 32, horiz_accuracy);
    _mav_put_float(((char*)msg->payloads), 36, vert_accuracy);

    msg->msgid = MAVLINK_MSG_ID_WIND_COV;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIND_COV_MIN_LEN, MAVLINK_MSG_ID_WIND_COV_LEN, MAVLINK_MSG_ID_WIND_COV_CRC);
}

/**
 * @brief Pack a wind_cov message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param wind_x [m/s] Wind in X (NED) direction
 * @param wind_y [m/s] Wind in Y (NED) direction
 * @param wind_z [m/s] Wind in Z (NED) direction
 * @param var_horiz [m/s] Variability of the wind in XY. RMS of a 1 Hz lowpassed wind estimate.
 * @param var_vert [m/s] Variability of the wind in Z. RMS of a 1 Hz lowpassed wind estimate.
 * @param wind_alt [m] Altitude (MSL) that this measurement was taken at
 * @param horiz_accuracy [m] Horizontal speed 1-STD accuracy
 * @param vert_accuracy [m] Vertical speed 1-STD accuracy
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wind_cov_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,float wind_x,float wind_y,float wind_z,float var_horiz,float var_vert,float wind_alt,float horiz_accuracy,float vert_accuracy)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_float(((char*)msg->payloads), 8, wind_x);
    _mav_put_float(((char*)msg->payloads), 12, wind_y);
    _mav_put_float(((char*)msg->payloads), 16, wind_z);
    _mav_put_float(((char*)msg->payloads), 20, var_horiz);
    _mav_put_float(((char*)msg->payloads), 24, var_vert);
    _mav_put_float(((char*)msg->payloads), 28, wind_alt);
    _mav_put_float(((char*)msg->payloads), 32, horiz_accuracy);
    _mav_put_float(((char*)msg->payloads), 36, vert_accuracy);


    msg->msgid = MAVLINK_MSG_ID_WIND_COV;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIND_COV_MIN_LEN, MAVLINK_MSG_ID_WIND_COV_LEN, MAVLINK_MSG_ID_WIND_COV_CRC);
}

/**
 * @brief Encode a wind_cov struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wind_cov C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wind_cov_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wind_cov_t* wind_cov)
{
    return mavlink_msg_wind_cov_pack(system_id, component_id, msg, wind_cov->time_usec, wind_cov->wind_x, wind_cov->wind_y, wind_cov->wind_z, wind_cov->var_horiz, wind_cov->var_vert, wind_cov->wind_alt, wind_cov->horiz_accuracy, wind_cov->vert_accuracy);
}

/**
 * @brief Encode a wind_cov struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wind_cov C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wind_cov_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wind_cov_t* wind_cov)
{
    return mavlink_msg_wind_cov_pack_chan(system_id, component_id, chan, msg, wind_cov->time_usec, wind_cov->wind_x, wind_cov->wind_y, wind_cov->wind_z, wind_cov->var_horiz, wind_cov->var_vert, wind_cov->wind_alt, wind_cov->horiz_accuracy, wind_cov->vert_accuracy);
}

// MESSAGE WIND_COV UNPACKING


/**
 * @brief Get field time_usec from wind_cov message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_wind_cov_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field wind_x from wind_cov message
 *
 * @return [m/s] Wind in X (NED) direction
 */
static inline float mavlink_msg_wind_cov_get_wind_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field wind_y from wind_cov message
 *
 * @return [m/s] Wind in Y (NED) direction
 */
static inline float mavlink_msg_wind_cov_get_wind_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field wind_z from wind_cov message
 *
 * @return [m/s] Wind in Z (NED) direction
 */
static inline float mavlink_msg_wind_cov_get_wind_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field var_horiz from wind_cov message
 *
 * @return [m/s] Variability of the wind in XY. RMS of a 1 Hz lowpassed wind estimate.
 */
static inline float mavlink_msg_wind_cov_get_var_horiz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field var_vert from wind_cov message
 *
 * @return [m/s] Variability of the wind in Z. RMS of a 1 Hz lowpassed wind estimate.
 */
static inline float mavlink_msg_wind_cov_get_var_vert(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field wind_alt from wind_cov message
 *
 * @return [m] Altitude (MSL) that this measurement was taken at
 */
static inline float mavlink_msg_wind_cov_get_wind_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field horiz_accuracy from wind_cov message
 *
 * @return [m] Horizontal speed 1-STD accuracy
 */
static inline float mavlink_msg_wind_cov_get_horiz_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field vert_accuracy from wind_cov message
 *
 * @return [m] Vertical speed 1-STD accuracy
 */
static inline float mavlink_msg_wind_cov_get_vert_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a wind_cov message into a struct
 *
 * @param msg The message to decode
 * @param wind_cov C-struct to decode the message contents into
 */
static inline void mavlink_msg_wind_cov_decode(const mavlink_message_t* msg, mavlink_wind_cov_t* wind_cov)
{
    wind_cov->time_usec = mavlink_msg_wind_cov_get_time_usec(msg);
    wind_cov->wind_x = mavlink_msg_wind_cov_get_wind_x(msg);
    wind_cov->wind_y = mavlink_msg_wind_cov_get_wind_y(msg);
    wind_cov->wind_z = mavlink_msg_wind_cov_get_wind_z(msg);
    wind_cov->var_horiz = mavlink_msg_wind_cov_get_var_horiz(msg);
    wind_cov->var_vert = mavlink_msg_wind_cov_get_var_vert(msg);
    wind_cov->wind_alt = mavlink_msg_wind_cov_get_wind_alt(msg);
    wind_cov->horiz_accuracy = mavlink_msg_wind_cov_get_horiz_accuracy(msg);
    wind_cov->vert_accuracy = mavlink_msg_wind_cov_get_vert_accuracy(msg);
}
#endif
