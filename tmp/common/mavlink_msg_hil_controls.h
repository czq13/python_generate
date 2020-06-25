#pragma once
// MESSAGE HIL_CONTROLS PACKING

#define MAVLINK_MSG_ID_HIL_CONTROLS 91

typedef struct __mavlink_hil_controls_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float roll_ailerons; /*<  Control output -1 .. 1*/
 float pitch_elevator; /*<  Control output -1 .. 1*/
 float yaw_rudder; /*<  Control output -1 .. 1*/
 float throttle; /*<  Throttle 0 .. 1*/
 float aux1; /*<  Aux 1, -1 .. 1*/
 float aux2; /*<  Aux 2, -1 .. 1*/
 float aux3; /*<  Aux 3, -1 .. 1*/
 float aux4; /*<  Aux 4, -1 .. 1*/
 uint8_t mode; /*<  System mode.*/
 uint8_t nav_mode; /*<  Navigation mode (MAV_NAV_MODE)*/
} mavlink_hil_controls_t;

#define MAVLINK_MSG_ID_HIL_CONTROLS_LEN 42
#define MAVLINK_MSG_ID_HIL_CONTROLS_MIN_LEN 42
#define MAVLINK_MSG_ID_91_LEN 42
#define MAVLINK_MSG_ID_91_MIN_LEN 42

#define MAVLINK_MSG_ID_HIL_CONTROLS_CRC 63
#define MAVLINK_MSG_ID_91_CRC 63



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HIL_CONTROLS { \
    91, \
    "HIL_CONTROLS", \
    11, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_controls_t, time_usec) }, \
         { "roll_ailerons", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_hil_controls_t, roll_ailerons) }, \
         { "pitch_elevator", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_hil_controls_t, pitch_elevator) }, \
         { "yaw_rudder", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_hil_controls_t, yaw_rudder) }, \
         { "throttle", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_hil_controls_t, throttle) }, \
         { "aux1", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_hil_controls_t, aux1) }, \
         { "aux2", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_hil_controls_t, aux2) }, \
         { "aux3", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_hil_controls_t, aux3) }, \
         { "aux4", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_hil_controls_t, aux4) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_hil_controls_t, mode) }, \
         { "nav_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_hil_controls_t, nav_mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HIL_CONTROLS { \
    "HIL_CONTROLS", \
    11, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_controls_t, time_usec) }, \
         { "roll_ailerons", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_hil_controls_t, roll_ailerons) }, \
         { "pitch_elevator", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_hil_controls_t, pitch_elevator) }, \
         { "yaw_rudder", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_hil_controls_t, yaw_rudder) }, \
         { "throttle", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_hil_controls_t, throttle) }, \
         { "aux1", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_hil_controls_t, aux1) }, \
         { "aux2", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_hil_controls_t, aux2) }, \
         { "aux3", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_hil_controls_t, aux3) }, \
         { "aux4", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_hil_controls_t, aux4) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_hil_controls_t, mode) }, \
         { "nav_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_hil_controls_t, nav_mode) }, \
         } \
}
#endif

/**
 * @brief Pack a hil_controls message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param roll_ailerons  Control output -1 .. 1
 * @param pitch_elevator  Control output -1 .. 1
 * @param yaw_rudder  Control output -1 .. 1
 * @param throttle  Throttle 0 .. 1
 * @param aux1  Aux 1, -1 .. 1
 * @param aux2  Aux 2, -1 .. 1
 * @param aux3  Aux 3, -1 .. 1
 * @param aux4  Aux 4, -1 .. 1
 * @param mode  System mode.
 * @param nav_mode  Navigation mode (MAV_NAV_MODE)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_controls_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, float roll_ailerons, float pitch_elevator, float yaw_rudder, float throttle, float aux1, float aux2, float aux3, float aux4, uint8_t mode, uint8_t nav_mode)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_float(msg->payloads, 8, roll_ailerons);
    _mav_put_float(msg->payloads, 12, pitch_elevator);
    _mav_put_float(msg->payloads, 16, yaw_rudder);
    _mav_put_float(msg->payloads, 20, throttle);
    _mav_put_float(msg->payloads, 24, aux1);
    _mav_put_float(msg->payloads, 28, aux2);
    _mav_put_float(msg->payloads, 32, aux3);
    _mav_put_float(msg->payloads, 36, aux4);
    _mav_put_uint8_t(msg->payloads, 40, mode);
    _mav_put_uint8_t(msg->payloads, 41, nav_mode);

    msg->msgid = MAVLINK_MSG_ID_HIL_CONTROLS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HIL_CONTROLS_MIN_LEN, MAVLINK_MSG_ID_HIL_CONTROLS_LEN, MAVLINK_MSG_ID_HIL_CONTROLS_CRC);
}

/**
 * @brief Pack a hil_controls message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param roll_ailerons  Control output -1 .. 1
 * @param pitch_elevator  Control output -1 .. 1
 * @param yaw_rudder  Control output -1 .. 1
 * @param throttle  Throttle 0 .. 1
 * @param aux1  Aux 1, -1 .. 1
 * @param aux2  Aux 2, -1 .. 1
 * @param aux3  Aux 3, -1 .. 1
 * @param aux4  Aux 4, -1 .. 1
 * @param mode  System mode.
 * @param nav_mode  Navigation mode (MAV_NAV_MODE)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_controls_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,float roll_ailerons,float pitch_elevator,float yaw_rudder,float throttle,float aux1,float aux2,float aux3,float aux4,uint8_t mode,uint8_t nav_mode)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_float(msg->payloads, 8, roll_ailerons);
    _mav_put_float(msg->payloads, 12, pitch_elevator);
    _mav_put_float(msg->payloads, 16, yaw_rudder);
    _mav_put_float(msg->payloads, 20, throttle);
    _mav_put_float(msg->payloads, 24, aux1);
    _mav_put_float(msg->payloads, 28, aux2);
    _mav_put_float(msg->payloads, 32, aux3);
    _mav_put_float(msg->payloads, 36, aux4);
    _mav_put_uint8_t(msg->payloads, 40, mode);
    _mav_put_uint8_t(msg->payloads, 41, nav_mode);


    msg->msgid = MAVLINK_MSG_ID_HIL_CONTROLS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HIL_CONTROLS_MIN_LEN, MAVLINK_MSG_ID_HIL_CONTROLS_LEN, MAVLINK_MSG_ID_HIL_CONTROLS_CRC);
}

/**
 * @brief Encode a hil_controls struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hil_controls C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_controls_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hil_controls_t* hil_controls)
{
    return mavlink_msg_hil_controls_pack(system_id, component_id, msg, hil_controls->time_usec, hil_controls->roll_ailerons, hil_controls->pitch_elevator, hil_controls->yaw_rudder, hil_controls->throttle, hil_controls->aux1, hil_controls->aux2, hil_controls->aux3, hil_controls->aux4, hil_controls->mode, hil_controls->nav_mode);
}

/**
 * @brief Encode a hil_controls struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hil_controls C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_controls_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hil_controls_t* hil_controls)
{
    return mavlink_msg_hil_controls_pack_chan(system_id, component_id, chan, msg, hil_controls->time_usec, hil_controls->roll_ailerons, hil_controls->pitch_elevator, hil_controls->yaw_rudder, hil_controls->throttle, hil_controls->aux1, hil_controls->aux2, hil_controls->aux3, hil_controls->aux4, hil_controls->mode, hil_controls->nav_mode);
}

// MESSAGE HIL_CONTROLS UNPACKING


/**
 * @brief Get field time_usec from hil_controls message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_hil_controls_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field roll_ailerons from hil_controls message
 *
 * @return  Control output -1 .. 1
 */
static inline float mavlink_msg_hil_controls_get_roll_ailerons(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field pitch_elevator from hil_controls message
 *
 * @return  Control output -1 .. 1
 */
static inline float mavlink_msg_hil_controls_get_pitch_elevator(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yaw_rudder from hil_controls message
 *
 * @return  Control output -1 .. 1
 */
static inline float mavlink_msg_hil_controls_get_yaw_rudder(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field throttle from hil_controls message
 *
 * @return  Throttle 0 .. 1
 */
static inline float mavlink_msg_hil_controls_get_throttle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field aux1 from hil_controls message
 *
 * @return  Aux 1, -1 .. 1
 */
static inline float mavlink_msg_hil_controls_get_aux1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field aux2 from hil_controls message
 *
 * @return  Aux 2, -1 .. 1
 */
static inline float mavlink_msg_hil_controls_get_aux2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field aux3 from hil_controls message
 *
 * @return  Aux 3, -1 .. 1
 */
static inline float mavlink_msg_hil_controls_get_aux3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field aux4 from hil_controls message
 *
 * @return  Aux 4, -1 .. 1
 */
static inline float mavlink_msg_hil_controls_get_aux4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field mode from hil_controls message
 *
 * @return  System mode.
 */
static inline uint8_t mavlink_msg_hil_controls_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field nav_mode from hil_controls message
 *
 * @return  Navigation mode (MAV_NAV_MODE)
 */
static inline uint8_t mavlink_msg_hil_controls_get_nav_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  41);
}

/**
 * @brief Decode a hil_controls message into a struct
 *
 * @param msg The message to decode
 * @param hil_controls C-struct to decode the message contents into
 */
static inline void mavlink_msg_hil_controls_decode(const mavlink_message_t* msg, mavlink_hil_controls_t* hil_controls)
{
    hil_controls->time_usec = mavlink_msg_hil_controls_get_time_usec(msg);
    hil_controls->roll_ailerons = mavlink_msg_hil_controls_get_roll_ailerons(msg);
    hil_controls->pitch_elevator = mavlink_msg_hil_controls_get_pitch_elevator(msg);
    hil_controls->yaw_rudder = mavlink_msg_hil_controls_get_yaw_rudder(msg);
    hil_controls->throttle = mavlink_msg_hil_controls_get_throttle(msg);
    hil_controls->aux1 = mavlink_msg_hil_controls_get_aux1(msg);
    hil_controls->aux2 = mavlink_msg_hil_controls_get_aux2(msg);
    hil_controls->aux3 = mavlink_msg_hil_controls_get_aux3(msg);
    hil_controls->aux4 = mavlink_msg_hil_controls_get_aux4(msg);
    hil_controls->mode = mavlink_msg_hil_controls_get_mode(msg);
    hil_controls->nav_mode = mavlink_msg_hil_controls_get_nav_mode(msg);
}
