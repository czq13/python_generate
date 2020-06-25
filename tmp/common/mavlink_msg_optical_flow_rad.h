#pragma once
// MESSAGE OPTICAL_FLOW_RAD PACKING

#define MAVLINK_MSG_ID_OPTICAL_FLOW_RAD 106

typedef struct __mavlink_optical_flow_rad_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint32_t integration_time_us; /*< [us] Integration time. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the.*/
 float integrated_x; /*< [rad] Flow around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion along the positive Y axis induces a negative flow.)*/
 float integrated_y; /*< [rad] Flow around Y axis (Sensor RH rotation about the Y axis induces a positive flow. Sensor linear motion along the positive X axis induces a positive flow.)*/
 float integrated_xgyro; /*< [rad] RH rotation around X axis*/
 float integrated_ygyro; /*< [rad] RH rotation around Y axis*/
 float integrated_zgyro; /*< [rad] RH rotation around Z axis*/
 uint32_t time_delta_distance_us; /*< [us] Time since the distance was sampled.*/
 float distance; /*< [m] Distance to the center of the flow field. Positive value (including zero): distance known. Negative value: Unknown distance.*/
 int16_t temperature; /*< [cdegC] Temperature*/
 uint8_t sensor_id; /*<  Sensor ID*/
 uint8_t quality; /*<  Optical flow quality / confidence. 0: no valid flow, 255: maximum quality*/
} mavlink_optical_flow_rad_t;

#define MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_LEN 44
#define MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_MIN_LEN 44
#define MAVLINK_MSG_ID_106_LEN 44
#define MAVLINK_MSG_ID_106_MIN_LEN 44

#define MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_CRC 138
#define MAVLINK_MSG_ID_106_CRC 138



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OPTICAL_FLOW_RAD { \
    106, \
    "OPTICAL_FLOW_RAD", \
    12, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_optical_flow_rad_t, time_usec) }, \
         { "sensor_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_optical_flow_rad_t, sensor_id) }, \
         { "integration_time_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_optical_flow_rad_t, integration_time_us) }, \
         { "integrated_x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_optical_flow_rad_t, integrated_x) }, \
         { "integrated_y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_optical_flow_rad_t, integrated_y) }, \
         { "integrated_xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_optical_flow_rad_t, integrated_xgyro) }, \
         { "integrated_ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_optical_flow_rad_t, integrated_ygyro) }, \
         { "integrated_zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_optical_flow_rad_t, integrated_zgyro) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_optical_flow_rad_t, temperature) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_optical_flow_rad_t, quality) }, \
         { "time_delta_distance_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_optical_flow_rad_t, time_delta_distance_us) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_optical_flow_rad_t, distance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OPTICAL_FLOW_RAD { \
    "OPTICAL_FLOW_RAD", \
    12, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_optical_flow_rad_t, time_usec) }, \
         { "sensor_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_optical_flow_rad_t, sensor_id) }, \
         { "integration_time_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_optical_flow_rad_t, integration_time_us) }, \
         { "integrated_x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_optical_flow_rad_t, integrated_x) }, \
         { "integrated_y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_optical_flow_rad_t, integrated_y) }, \
         { "integrated_xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_optical_flow_rad_t, integrated_xgyro) }, \
         { "integrated_ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_optical_flow_rad_t, integrated_ygyro) }, \
         { "integrated_zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_optical_flow_rad_t, integrated_zgyro) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_optical_flow_rad_t, temperature) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_optical_flow_rad_t, quality) }, \
         { "time_delta_distance_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_optical_flow_rad_t, time_delta_distance_us) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_optical_flow_rad_t, distance) }, \
         } \
}
#endif

/**
 * @brief Pack a optical_flow_rad message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param sensor_id  Sensor ID
 * @param integration_time_us [us] Integration time. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the.
 * @param integrated_x [rad] Flow around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion along the positive Y axis induces a negative flow.)
 * @param integrated_y [rad] Flow around Y axis (Sensor RH rotation about the Y axis induces a positive flow. Sensor linear motion along the positive X axis induces a positive flow.)
 * @param integrated_xgyro [rad] RH rotation around X axis
 * @param integrated_ygyro [rad] RH rotation around Y axis
 * @param integrated_zgyro [rad] RH rotation around Z axis
 * @param temperature [cdegC] Temperature
 * @param quality  Optical flow quality / confidence. 0: no valid flow, 255: maximum quality
 * @param time_delta_distance_us [us] Time since the distance was sampled.
 * @param distance [m] Distance to the center of the flow field. Positive value (including zero): distance known. Negative value: Unknown distance.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_optical_flow_rad_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t sensor_id, uint32_t integration_time_us, float integrated_x, float integrated_y, float integrated_xgyro, float integrated_ygyro, float integrated_zgyro, int16_t temperature, uint8_t quality, uint32_t time_delta_distance_us, float distance)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint32_t(msg->payloads, 8, integration_time_us);
    _mav_put_float(msg->payloads, 12, integrated_x);
    _mav_put_float(msg->payloads, 16, integrated_y);
    _mav_put_float(msg->payloads, 20, integrated_xgyro);
    _mav_put_float(msg->payloads, 24, integrated_ygyro);
    _mav_put_float(msg->payloads, 28, integrated_zgyro);
    _mav_put_uint32_t(msg->payloads, 32, time_delta_distance_us);
    _mav_put_float(msg->payloads, 36, distance);
    _mav_put_int16_t(msg->payloads, 40, temperature);
    _mav_put_uint8_t(msg->payloads, 42, sensor_id);
    _mav_put_uint8_t(msg->payloads, 43, quality);

    msg->msgid = MAVLINK_MSG_ID_OPTICAL_FLOW_RAD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_MIN_LEN, MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_LEN, MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_CRC);
}

/**
 * @brief Pack a optical_flow_rad message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param sensor_id  Sensor ID
 * @param integration_time_us [us] Integration time. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the.
 * @param integrated_x [rad] Flow around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion along the positive Y axis induces a negative flow.)
 * @param integrated_y [rad] Flow around Y axis (Sensor RH rotation about the Y axis induces a positive flow. Sensor linear motion along the positive X axis induces a positive flow.)
 * @param integrated_xgyro [rad] RH rotation around X axis
 * @param integrated_ygyro [rad] RH rotation around Y axis
 * @param integrated_zgyro [rad] RH rotation around Z axis
 * @param temperature [cdegC] Temperature
 * @param quality  Optical flow quality / confidence. 0: no valid flow, 255: maximum quality
 * @param time_delta_distance_us [us] Time since the distance was sampled.
 * @param distance [m] Distance to the center of the flow field. Positive value (including zero): distance known. Negative value: Unknown distance.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_optical_flow_rad_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t sensor_id,uint32_t integration_time_us,float integrated_x,float integrated_y,float integrated_xgyro,float integrated_ygyro,float integrated_zgyro,int16_t temperature,uint8_t quality,uint32_t time_delta_distance_us,float distance)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint32_t(msg->payloads, 8, integration_time_us);
    _mav_put_float(msg->payloads, 12, integrated_x);
    _mav_put_float(msg->payloads, 16, integrated_y);
    _mav_put_float(msg->payloads, 20, integrated_xgyro);
    _mav_put_float(msg->payloads, 24, integrated_ygyro);
    _mav_put_float(msg->payloads, 28, integrated_zgyro);
    _mav_put_uint32_t(msg->payloads, 32, time_delta_distance_us);
    _mav_put_float(msg->payloads, 36, distance);
    _mav_put_int16_t(msg->payloads, 40, temperature);
    _mav_put_uint8_t(msg->payloads, 42, sensor_id);
    _mav_put_uint8_t(msg->payloads, 43, quality);


    msg->msgid = MAVLINK_MSG_ID_OPTICAL_FLOW_RAD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_MIN_LEN, MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_LEN, MAVLINK_MSG_ID_OPTICAL_FLOW_RAD_CRC);
}

/**
 * @brief Encode a optical_flow_rad struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param optical_flow_rad C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_optical_flow_rad_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_optical_flow_rad_t* optical_flow_rad)
{
    return mavlink_msg_optical_flow_rad_pack(system_id, component_id, msg, optical_flow_rad->time_usec, optical_flow_rad->sensor_id, optical_flow_rad->integration_time_us, optical_flow_rad->integrated_x, optical_flow_rad->integrated_y, optical_flow_rad->integrated_xgyro, optical_flow_rad->integrated_ygyro, optical_flow_rad->integrated_zgyro, optical_flow_rad->temperature, optical_flow_rad->quality, optical_flow_rad->time_delta_distance_us, optical_flow_rad->distance);
}

/**
 * @brief Encode a optical_flow_rad struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param optical_flow_rad C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_optical_flow_rad_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_optical_flow_rad_t* optical_flow_rad)
{
    return mavlink_msg_optical_flow_rad_pack_chan(system_id, component_id, chan, msg, optical_flow_rad->time_usec, optical_flow_rad->sensor_id, optical_flow_rad->integration_time_us, optical_flow_rad->integrated_x, optical_flow_rad->integrated_y, optical_flow_rad->integrated_xgyro, optical_flow_rad->integrated_ygyro, optical_flow_rad->integrated_zgyro, optical_flow_rad->temperature, optical_flow_rad->quality, optical_flow_rad->time_delta_distance_us, optical_flow_rad->distance);
}

// MESSAGE OPTICAL_FLOW_RAD UNPACKING


/**
 * @brief Get field time_usec from optical_flow_rad message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_optical_flow_rad_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field sensor_id from optical_flow_rad message
 *
 * @return  Sensor ID
 */
static inline uint8_t mavlink_msg_optical_flow_rad_get_sensor_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  42);
}

/**
 * @brief Get field integration_time_us from optical_flow_rad message
 *
 * @return [us] Integration time. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the.
 */
static inline uint32_t mavlink_msg_optical_flow_rad_get_integration_time_us(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field integrated_x from optical_flow_rad message
 *
 * @return [rad] Flow around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion along the positive Y axis induces a negative flow.)
 */
static inline float mavlink_msg_optical_flow_rad_get_integrated_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field integrated_y from optical_flow_rad message
 *
 * @return [rad] Flow around Y axis (Sensor RH rotation about the Y axis induces a positive flow. Sensor linear motion along the positive X axis induces a positive flow.)
 */
static inline float mavlink_msg_optical_flow_rad_get_integrated_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field integrated_xgyro from optical_flow_rad message
 *
 * @return [rad] RH rotation around X axis
 */
static inline float mavlink_msg_optical_flow_rad_get_integrated_xgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field integrated_ygyro from optical_flow_rad message
 *
 * @return [rad] RH rotation around Y axis
 */
static inline float mavlink_msg_optical_flow_rad_get_integrated_ygyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field integrated_zgyro from optical_flow_rad message
 *
 * @return [rad] RH rotation around Z axis
 */
static inline float mavlink_msg_optical_flow_rad_get_integrated_zgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field temperature from optical_flow_rad message
 *
 * @return [cdegC] Temperature
 */
static inline int16_t mavlink_msg_optical_flow_rad_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field quality from optical_flow_rad message
 *
 * @return  Optical flow quality / confidence. 0: no valid flow, 255: maximum quality
 */
static inline uint8_t mavlink_msg_optical_flow_rad_get_quality(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  43);
}

/**
 * @brief Get field time_delta_distance_us from optical_flow_rad message
 *
 * @return [us] Time since the distance was sampled.
 */
static inline uint32_t mavlink_msg_optical_flow_rad_get_time_delta_distance_us(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  32);
}

/**
 * @brief Get field distance from optical_flow_rad message
 *
 * @return [m] Distance to the center of the flow field. Positive value (including zero): distance known. Negative value: Unknown distance.
 */
static inline float mavlink_msg_optical_flow_rad_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a optical_flow_rad message into a struct
 *
 * @param msg The message to decode
 * @param optical_flow_rad C-struct to decode the message contents into
 */
static inline void mavlink_msg_optical_flow_rad_decode(const mavlink_message_t* msg, mavlink_optical_flow_rad_t* optical_flow_rad)
{
    optical_flow_rad->time_usec = mavlink_msg_optical_flow_rad_get_time_usec(msg);
    optical_flow_rad->integration_time_us = mavlink_msg_optical_flow_rad_get_integration_time_us(msg);
    optical_flow_rad->integrated_x = mavlink_msg_optical_flow_rad_get_integrated_x(msg);
    optical_flow_rad->integrated_y = mavlink_msg_optical_flow_rad_get_integrated_y(msg);
    optical_flow_rad->integrated_xgyro = mavlink_msg_optical_flow_rad_get_integrated_xgyro(msg);
    optical_flow_rad->integrated_ygyro = mavlink_msg_optical_flow_rad_get_integrated_ygyro(msg);
    optical_flow_rad->integrated_zgyro = mavlink_msg_optical_flow_rad_get_integrated_zgyro(msg);
    optical_flow_rad->time_delta_distance_us = mavlink_msg_optical_flow_rad_get_time_delta_distance_us(msg);
    optical_flow_rad->distance = mavlink_msg_optical_flow_rad_get_distance(msg);
    optical_flow_rad->temperature = mavlink_msg_optical_flow_rad_get_temperature(msg);
    optical_flow_rad->sensor_id = mavlink_msg_optical_flow_rad_get_sensor_id(msg);
    optical_flow_rad->quality = mavlink_msg_optical_flow_rad_get_quality(msg);
}
