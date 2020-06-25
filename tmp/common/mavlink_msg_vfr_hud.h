#pragma once
// MESSAGE VFR_HUD PACKING

#define MAVLINK_MSG_ID_VFR_HUD 74

typedef struct __mavlink_vfr_hud_t {
 float airspeed; /*< [m/s] Vehicle speed in form appropriate for vehicle type. For standard aircraft this is typically calibrated airspeed (CAS) or indicated airspeed (IAS) - either of which can be used by a pilot to estimate stall speed.*/
 float groundspeed; /*< [m/s] Current ground speed.*/
 float alt; /*< [m] Current altitude (MSL).*/
 float climb; /*< [m/s] Current climb rate.*/
 int16_t heading; /*< [deg] Current heading in compass units (0-360, 0=north).*/
 uint16_t throttle; /*< [%] Current throttle setting (0 to 100).*/
} mavlink_vfr_hud_t;

#define MAVLINK_MSG_ID_VFR_HUD_LEN 20
#define MAVLINK_MSG_ID_VFR_HUD_MIN_LEN 20
#define MAVLINK_MSG_ID_74_LEN 20
#define MAVLINK_MSG_ID_74_MIN_LEN 20

#define MAVLINK_MSG_ID_VFR_HUD_CRC 20
#define MAVLINK_MSG_ID_74_CRC 20



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VFR_HUD { \
    74, \
    "VFR_HUD", \
    6, \
    {  { "airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vfr_hud_t, airspeed) }, \
         { "groundspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vfr_hud_t, groundspeed) }, \
         { "heading", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_vfr_hud_t, heading) }, \
         { "throttle", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_vfr_hud_t, throttle) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vfr_hud_t, alt) }, \
         { "climb", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vfr_hud_t, climb) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VFR_HUD { \
    "VFR_HUD", \
    6, \
    {  { "airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vfr_hud_t, airspeed) }, \
         { "groundspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vfr_hud_t, groundspeed) }, \
         { "heading", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_vfr_hud_t, heading) }, \
         { "throttle", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_vfr_hud_t, throttle) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vfr_hud_t, alt) }, \
         { "climb", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vfr_hud_t, climb) }, \
         } \
}
#endif

/**
 * @brief Pack a vfr_hud message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param airspeed [m/s] Vehicle speed in form appropriate for vehicle type. For standard aircraft this is typically calibrated airspeed (CAS) or indicated airspeed (IAS) - either of which can be used by a pilot to estimate stall speed.
 * @param groundspeed [m/s] Current ground speed.
 * @param heading [deg] Current heading in compass units (0-360, 0=north).
 * @param throttle [%] Current throttle setting (0 to 100).
 * @param alt [m] Current altitude (MSL).
 * @param climb [m/s] Current climb rate.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vfr_hud_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float airspeed, float groundspeed, int16_t heading, uint16_t throttle, float alt, float climb)
{
    _mav_put_float(msg->payloads, 0, airspeed);
    _mav_put_float(msg->payloads, 4, groundspeed);
    _mav_put_float(msg->payloads, 8, alt);
    _mav_put_float(msg->payloads, 12, climb);
    _mav_put_int16_t(msg->payloads, 16, heading);
    _mav_put_uint16_t(msg->payloads, 18, throttle);

    msg->msgid = MAVLINK_MSG_ID_VFR_HUD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VFR_HUD_MIN_LEN, MAVLINK_MSG_ID_VFR_HUD_LEN, MAVLINK_MSG_ID_VFR_HUD_CRC);
}

/**
 * @brief Pack a vfr_hud message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param airspeed [m/s] Vehicle speed in form appropriate for vehicle type. For standard aircraft this is typically calibrated airspeed (CAS) or indicated airspeed (IAS) - either of which can be used by a pilot to estimate stall speed.
 * @param groundspeed [m/s] Current ground speed.
 * @param heading [deg] Current heading in compass units (0-360, 0=north).
 * @param throttle [%] Current throttle setting (0 to 100).
 * @param alt [m] Current altitude (MSL).
 * @param climb [m/s] Current climb rate.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vfr_hud_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float airspeed,float groundspeed,int16_t heading,uint16_t throttle,float alt,float climb)
{
    _mav_put_float(msg->payloads, 0, airspeed);
    _mav_put_float(msg->payloads, 4, groundspeed);
    _mav_put_float(msg->payloads, 8, alt);
    _mav_put_float(msg->payloads, 12, climb);
    _mav_put_int16_t(msg->payloads, 16, heading);
    _mav_put_uint16_t(msg->payloads, 18, throttle);


    msg->msgid = MAVLINK_MSG_ID_VFR_HUD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VFR_HUD_MIN_LEN, MAVLINK_MSG_ID_VFR_HUD_LEN, MAVLINK_MSG_ID_VFR_HUD_CRC);
}

/**
 * @brief Encode a vfr_hud struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vfr_hud C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vfr_hud_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vfr_hud_t* vfr_hud)
{
    return mavlink_msg_vfr_hud_pack(system_id, component_id, msg, vfr_hud->airspeed, vfr_hud->groundspeed, vfr_hud->heading, vfr_hud->throttle, vfr_hud->alt, vfr_hud->climb);
}

/**
 * @brief Encode a vfr_hud struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vfr_hud C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vfr_hud_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vfr_hud_t* vfr_hud)
{
    return mavlink_msg_vfr_hud_pack_chan(system_id, component_id, chan, msg, vfr_hud->airspeed, vfr_hud->groundspeed, vfr_hud->heading, vfr_hud->throttle, vfr_hud->alt, vfr_hud->climb);
}

// MESSAGE VFR_HUD UNPACKING


/**
 * @brief Get field airspeed from vfr_hud message
 *
 * @return [m/s] Vehicle speed in form appropriate for vehicle type. For standard aircraft this is typically calibrated airspeed (CAS) or indicated airspeed (IAS) - either of which can be used by a pilot to estimate stall speed.
 */
static inline float mavlink_msg_vfr_hud_get_airspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field groundspeed from vfr_hud message
 *
 * @return [m/s] Current ground speed.
 */
static inline float mavlink_msg_vfr_hud_get_groundspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field heading from vfr_hud message
 *
 * @return [deg] Current heading in compass units (0-360, 0=north).
 */
static inline int16_t mavlink_msg_vfr_hud_get_heading(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field throttle from vfr_hud message
 *
 * @return [%] Current throttle setting (0 to 100).
 */
static inline uint16_t mavlink_msg_vfr_hud_get_throttle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field alt from vfr_hud message
 *
 * @return [m] Current altitude (MSL).
 */
static inline float mavlink_msg_vfr_hud_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field climb from vfr_hud message
 *
 * @return [m/s] Current climb rate.
 */
static inline float mavlink_msg_vfr_hud_get_climb(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a vfr_hud message into a struct
 *
 * @param msg The message to decode
 * @param vfr_hud C-struct to decode the message contents into
 */
static inline void mavlink_msg_vfr_hud_decode(const mavlink_message_t* msg, mavlink_vfr_hud_t* vfr_hud)
{
    vfr_hud->airspeed = mavlink_msg_vfr_hud_get_airspeed(msg);
    vfr_hud->groundspeed = mavlink_msg_vfr_hud_get_groundspeed(msg);
    vfr_hud->alt = mavlink_msg_vfr_hud_get_alt(msg);
    vfr_hud->climb = mavlink_msg_vfr_hud_get_climb(msg);
    vfr_hud->heading = mavlink_msg_vfr_hud_get_heading(msg);
    vfr_hud->throttle = mavlink_msg_vfr_hud_get_throttle(msg);
}
