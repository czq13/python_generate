#pragma once
// MESSAGE SCALED_IMU2 PACKING

#define MAVLINK_MSG_ID_SCALED_IMU2 116

typedef struct __mavlink_scaled_imu2_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 int16_t xacc; /*< [mG] X acceleration*/
 int16_t yacc; /*< [mG] Y acceleration*/
 int16_t zacc; /*< [mG] Z acceleration*/
 int16_t xgyro; /*< [mrad/s] Angular speed around X axis*/
 int16_t ygyro; /*< [mrad/s] Angular speed around Y axis*/
 int16_t zgyro; /*< [mrad/s] Angular speed around Z axis*/
 int16_t xmag; /*< [mgauss] X Magnetic field*/
 int16_t ymag; /*< [mgauss] Y Magnetic field*/
 int16_t zmag; /*< [mgauss] Z Magnetic field*/
 int16_t temperature; /*< [cdegC] Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C).*/
} mavlink_scaled_imu2_t;

#define MAVLINK_MSG_ID_SCALED_IMU2_LEN 24
#define MAVLINK_MSG_ID_SCALED_IMU2_MIN_LEN 22
#define MAVLINK_MSG_ID_116_LEN 24
#define MAVLINK_MSG_ID_116_MIN_LEN 22

#define MAVLINK_MSG_ID_SCALED_IMU2_CRC 76
#define MAVLINK_MSG_ID_116_CRC 76



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SCALED_IMU2 { \
    116, \
    "SCALED_IMU2", \
    11, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_scaled_imu2_t, time_boot_ms) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_scaled_imu2_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_scaled_imu2_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_scaled_imu2_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_scaled_imu2_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_scaled_imu2_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_scaled_imu2_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_scaled_imu2_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_scaled_imu2_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_scaled_imu2_t, zmag) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_scaled_imu2_t, temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SCALED_IMU2 { \
    "SCALED_IMU2", \
    11, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_scaled_imu2_t, time_boot_ms) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_scaled_imu2_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_scaled_imu2_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_scaled_imu2_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_scaled_imu2_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_scaled_imu2_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_scaled_imu2_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_scaled_imu2_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_scaled_imu2_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_scaled_imu2_t, zmag) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_scaled_imu2_t, temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a scaled_imu2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param xacc [mG] X acceleration
 * @param yacc [mG] Y acceleration
 * @param zacc [mG] Z acceleration
 * @param xgyro [mrad/s] Angular speed around X axis
 * @param ygyro [mrad/s] Angular speed around Y axis
 * @param zgyro [mrad/s] Angular speed around Z axis
 * @param xmag [mgauss] X Magnetic field
 * @param ymag [mgauss] Y Magnetic field
 * @param zmag [mgauss] Z Magnetic field
 * @param temperature [cdegC] Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_scaled_imu2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag, int16_t temperature)
{
    _mav_put_uint32_t(msg->payloads, 0, time_boot_ms);
    _mav_put_int16_t(msg->payloads, 4, xacc);
    _mav_put_int16_t(msg->payloads, 6, yacc);
    _mav_put_int16_t(msg->payloads, 8, zacc);
    _mav_put_int16_t(msg->payloads, 10, xgyro);
    _mav_put_int16_t(msg->payloads, 12, ygyro);
    _mav_put_int16_t(msg->payloads, 14, zgyro);
    _mav_put_int16_t(msg->payloads, 16, xmag);
    _mav_put_int16_t(msg->payloads, 18, ymag);
    _mav_put_int16_t(msg->payloads, 20, zmag);
    _mav_put_int16_t(msg->payloads, 22, temperature);

    msg->msgid = MAVLINK_MSG_ID_SCALED_IMU2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SCALED_IMU2_MIN_LEN, MAVLINK_MSG_ID_SCALED_IMU2_LEN, MAVLINK_MSG_ID_SCALED_IMU2_CRC);
}

/**
 * @brief Pack a scaled_imu2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param xacc [mG] X acceleration
 * @param yacc [mG] Y acceleration
 * @param zacc [mG] Z acceleration
 * @param xgyro [mrad/s] Angular speed around X axis
 * @param ygyro [mrad/s] Angular speed around Y axis
 * @param zgyro [mrad/s] Angular speed around Z axis
 * @param xmag [mgauss] X Magnetic field
 * @param ymag [mgauss] Y Magnetic field
 * @param zmag [mgauss] Z Magnetic field
 * @param temperature [cdegC] Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_scaled_imu2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,int16_t xacc,int16_t yacc,int16_t zacc,int16_t xgyro,int16_t ygyro,int16_t zgyro,int16_t xmag,int16_t ymag,int16_t zmag,int16_t temperature)
{
    _mav_put_uint32_t(msg->payloads, 0, time_boot_ms);
    _mav_put_int16_t(msg->payloads, 4, xacc);
    _mav_put_int16_t(msg->payloads, 6, yacc);
    _mav_put_int16_t(msg->payloads, 8, zacc);
    _mav_put_int16_t(msg->payloads, 10, xgyro);
    _mav_put_int16_t(msg->payloads, 12, ygyro);
    _mav_put_int16_t(msg->payloads, 14, zgyro);
    _mav_put_int16_t(msg->payloads, 16, xmag);
    _mav_put_int16_t(msg->payloads, 18, ymag);
    _mav_put_int16_t(msg->payloads, 20, zmag);
    _mav_put_int16_t(msg->payloads, 22, temperature);


    msg->msgid = MAVLINK_MSG_ID_SCALED_IMU2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SCALED_IMU2_MIN_LEN, MAVLINK_MSG_ID_SCALED_IMU2_LEN, MAVLINK_MSG_ID_SCALED_IMU2_CRC);
}

/**
 * @brief Encode a scaled_imu2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param scaled_imu2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_scaled_imu2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_scaled_imu2_t* scaled_imu2)
{
    return mavlink_msg_scaled_imu2_pack(system_id, component_id, msg, scaled_imu2->time_boot_ms, scaled_imu2->xacc, scaled_imu2->yacc, scaled_imu2->zacc, scaled_imu2->xgyro, scaled_imu2->ygyro, scaled_imu2->zgyro, scaled_imu2->xmag, scaled_imu2->ymag, scaled_imu2->zmag, scaled_imu2->temperature);
}

/**
 * @brief Encode a scaled_imu2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param scaled_imu2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_scaled_imu2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_scaled_imu2_t* scaled_imu2)
{
    return mavlink_msg_scaled_imu2_pack_chan(system_id, component_id, chan, msg, scaled_imu2->time_boot_ms, scaled_imu2->xacc, scaled_imu2->yacc, scaled_imu2->zacc, scaled_imu2->xgyro, scaled_imu2->ygyro, scaled_imu2->zgyro, scaled_imu2->xmag, scaled_imu2->ymag, scaled_imu2->zmag, scaled_imu2->temperature);
}

// MESSAGE SCALED_IMU2 UNPACKING


/**
 * @brief Get field time_boot_ms from scaled_imu2 message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_scaled_imu2_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field xacc from scaled_imu2 message
 *
 * @return [mG] X acceleration
 */
static inline int16_t mavlink_msg_scaled_imu2_get_xacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field yacc from scaled_imu2 message
 *
 * @return [mG] Y acceleration
 */
static inline int16_t mavlink_msg_scaled_imu2_get_yacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field zacc from scaled_imu2 message
 *
 * @return [mG] Z acceleration
 */
static inline int16_t mavlink_msg_scaled_imu2_get_zacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field xgyro from scaled_imu2 message
 *
 * @return [mrad/s] Angular speed around X axis
 */
static inline int16_t mavlink_msg_scaled_imu2_get_xgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field ygyro from scaled_imu2 message
 *
 * @return [mrad/s] Angular speed around Y axis
 */
static inline int16_t mavlink_msg_scaled_imu2_get_ygyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field zgyro from scaled_imu2 message
 *
 * @return [mrad/s] Angular speed around Z axis
 */
static inline int16_t mavlink_msg_scaled_imu2_get_zgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field xmag from scaled_imu2 message
 *
 * @return [mgauss] X Magnetic field
 */
static inline int16_t mavlink_msg_scaled_imu2_get_xmag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field ymag from scaled_imu2 message
 *
 * @return [mgauss] Y Magnetic field
 */
static inline int16_t mavlink_msg_scaled_imu2_get_ymag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field zmag from scaled_imu2 message
 *
 * @return [mgauss] Z Magnetic field
 */
static inline int16_t mavlink_msg_scaled_imu2_get_zmag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field temperature from scaled_imu2 message
 *
 * @return [cdegC] Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C).
 */
static inline int16_t mavlink_msg_scaled_imu2_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Decode a scaled_imu2 message into a struct
 *
 * @param msg The message to decode
 * @param scaled_imu2 C-struct to decode the message contents into
 */
static inline void mavlink_msg_scaled_imu2_decode(const mavlink_message_t* msg, mavlink_scaled_imu2_t* scaled_imu2)
{
    scaled_imu2->time_boot_ms = mavlink_msg_scaled_imu2_get_time_boot_ms(msg);
    scaled_imu2->xacc = mavlink_msg_scaled_imu2_get_xacc(msg);
    scaled_imu2->yacc = mavlink_msg_scaled_imu2_get_yacc(msg);
    scaled_imu2->zacc = mavlink_msg_scaled_imu2_get_zacc(msg);
    scaled_imu2->xgyro = mavlink_msg_scaled_imu2_get_xgyro(msg);
    scaled_imu2->ygyro = mavlink_msg_scaled_imu2_get_ygyro(msg);
    scaled_imu2->zgyro = mavlink_msg_scaled_imu2_get_zgyro(msg);
    scaled_imu2->xmag = mavlink_msg_scaled_imu2_get_xmag(msg);
    scaled_imu2->ymag = mavlink_msg_scaled_imu2_get_ymag(msg);
    scaled_imu2->zmag = mavlink_msg_scaled_imu2_get_zmag(msg);
    scaled_imu2->temperature = mavlink_msg_scaled_imu2_get_temperature(msg);
}