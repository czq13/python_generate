#pragma once
// MESSAGE POWER_STATUS PACKING

#define MAVLINK_MSG_ID_POWER_STATUS 125

typedef struct __mavlink_power_status_t {
 uint16_t Vcc; /*< [mV] 5V rail voltage.*/
 uint16_t Vservo; /*< [mV] Servo rail voltage.*/
 uint16_t flags; /*<  Bitmap of power supply status flags.*/
} mavlink_power_status_t;

#define MAVLINK_MSG_ID_POWER_STATUS_LEN 6
#define MAVLINK_MSG_ID_POWER_STATUS_MIN_LEN 6
#define MAVLINK_MSG_ID_125_LEN 6
#define MAVLINK_MSG_ID_125_MIN_LEN 6

#define MAVLINK_MSG_ID_POWER_STATUS_CRC 203
#define MAVLINK_MSG_ID_125_CRC 203



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_POWER_STATUS { \
    125, \
    "POWER_STATUS", \
    3, \
    {  { "Vcc", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_power_status_t, Vcc) }, \
         { "Vservo", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_power_status_t, Vservo) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_power_status_t, flags) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_POWER_STATUS { \
    "POWER_STATUS", \
    3, \
    {  { "Vcc", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_power_status_t, Vcc) }, \
         { "Vservo", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_power_status_t, Vservo) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_power_status_t, flags) }, \
         } \
}
#endif

/**
 * @brief Pack a power_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Vcc [mV] 5V rail voltage.
 * @param Vservo [mV] Servo rail voltage.
 * @param flags  Bitmap of power supply status flags.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_power_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t Vcc, uint16_t Vservo, uint16_t flags)
{
    _mav_put_uint16_t(msg->payloads, 0, Vcc);
    _mav_put_uint16_t(msg->payloads, 2, Vservo);
    _mav_put_uint16_t(msg->payloads, 4, flags);

    msg->msgid = MAVLINK_MSG_ID_POWER_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POWER_STATUS_MIN_LEN, MAVLINK_MSG_ID_POWER_STATUS_LEN, MAVLINK_MSG_ID_POWER_STATUS_CRC);
}

/**
 * @brief Pack a power_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Vcc [mV] 5V rail voltage.
 * @param Vservo [mV] Servo rail voltage.
 * @param flags  Bitmap of power supply status flags.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_power_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t Vcc,uint16_t Vservo,uint16_t flags)
{
    _mav_put_uint16_t(msg->payloads, 0, Vcc);
    _mav_put_uint16_t(msg->payloads, 2, Vservo);
    _mav_put_uint16_t(msg->payloads, 4, flags);


    msg->msgid = MAVLINK_MSG_ID_POWER_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POWER_STATUS_MIN_LEN, MAVLINK_MSG_ID_POWER_STATUS_LEN, MAVLINK_MSG_ID_POWER_STATUS_CRC);
}

/**
 * @brief Encode a power_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param power_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_power_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_power_status_t* power_status)
{
    return mavlink_msg_power_status_pack(system_id, component_id, msg, power_status->Vcc, power_status->Vservo, power_status->flags);
}

/**
 * @brief Encode a power_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param power_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_power_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_power_status_t* power_status)
{
    return mavlink_msg_power_status_pack_chan(system_id, component_id, chan, msg, power_status->Vcc, power_status->Vservo, power_status->flags);
}

// MESSAGE POWER_STATUS UNPACKING


/**
 * @brief Get field Vcc from power_status message
 *
 * @return [mV] 5V rail voltage.
 */
static inline uint16_t mavlink_msg_power_status_get_Vcc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field Vservo from power_status message
 *
 * @return [mV] Servo rail voltage.
 */
static inline uint16_t mavlink_msg_power_status_get_Vservo(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field flags from power_status message
 *
 * @return  Bitmap of power supply status flags.
 */
static inline uint16_t mavlink_msg_power_status_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Decode a power_status message into a struct
 *
 * @param msg The message to decode
 * @param power_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_power_status_decode(const mavlink_message_t* msg, mavlink_power_status_t* power_status)
{
    power_status->Vcc = mavlink_msg_power_status_get_Vcc(msg);
    power_status->Vservo = mavlink_msg_power_status_get_Vservo(msg);
    power_status->flags = mavlink_msg_power_status_get_flags(msg);
}