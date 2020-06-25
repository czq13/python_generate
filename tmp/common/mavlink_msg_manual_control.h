#pragma once
// MESSAGE MANUAL_CONTROL PACKING

#define MAVLINK_MSG_ID_MANUAL_CONTROL 69

typedef struct __mavlink_manual_control_t {
 int16_t x; /*<  X-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to forward(1000)-backward(-1000) movement on a joystick and the pitch of a vehicle.*/
 int16_t y; /*<  Y-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to left(-1000)-right(1000) movement on a joystick and the roll of a vehicle.*/
 int16_t z; /*<  Z-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a separate slider movement with maximum being 1000 and minimum being -1000 on a joystick and the thrust of a vehicle. Positive values are positive thrust, negative values are negative thrust.*/
 int16_t r; /*<  R-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a twisting of the joystick, with counter-clockwise being 1000 and clockwise being -1000, and the yaw of a vehicle.*/
 uint16_t buttons; /*<  A bitfield corresponding to the joystick buttons' current state, 1 for pressed, 0 for released. The lowest bit corresponds to Button 1.*/
 uint8_t target; /*<  The system to be controlled.*/
} mavlink_manual_control_t;

#define MAVLINK_MSG_ID_MANUAL_CONTROL_LEN 11
#define MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN 11
#define MAVLINK_MSG_ID_69_LEN 11
#define MAVLINK_MSG_ID_69_MIN_LEN 11

#define MAVLINK_MSG_ID_MANUAL_CONTROL_CRC 243
#define MAVLINK_MSG_ID_69_CRC 243



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MANUAL_CONTROL { \
    69, \
    "MANUAL_CONTROL", \
    6, \
    {  { "target", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_manual_control_t, target) }, \
         { "x", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_manual_control_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_manual_control_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_manual_control_t, z) }, \
         { "r", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_manual_control_t, r) }, \
         { "buttons", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_manual_control_t, buttons) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MANUAL_CONTROL { \
    "MANUAL_CONTROL", \
    6, \
    {  { "target", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_manual_control_t, target) }, \
         { "x", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_manual_control_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_manual_control_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_manual_control_t, z) }, \
         { "r", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_manual_control_t, r) }, \
         { "buttons", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_manual_control_t, buttons) }, \
         } \
}
#endif

/**
 * @brief Pack a manual_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target  The system to be controlled.
 * @param x  X-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to forward(1000)-backward(-1000) movement on a joystick and the pitch of a vehicle.
 * @param y  Y-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to left(-1000)-right(1000) movement on a joystick and the roll of a vehicle.
 * @param z  Z-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a separate slider movement with maximum being 1000 and minimum being -1000 on a joystick and the thrust of a vehicle. Positive values are positive thrust, negative values are negative thrust.
 * @param r  R-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a twisting of the joystick, with counter-clockwise being 1000 and clockwise being -1000, and the yaw of a vehicle.
 * @param buttons  A bitfield corresponding to the joystick buttons' current state, 1 for pressed, 0 for released. The lowest bit corresponds to Button 1.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_manual_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target, int16_t x, int16_t y, int16_t z, int16_t r, uint16_t buttons)
{
    _mav_put_int16_t(msg->payloads, 0, x);
    _mav_put_int16_t(msg->payloads, 2, y);
    _mav_put_int16_t(msg->payloads, 4, z);
    _mav_put_int16_t(msg->payloads, 6, r);
    _mav_put_uint16_t(msg->payloads, 8, buttons);
    _mav_put_uint8_t(msg->payloads, 10, target);

    msg->msgid = MAVLINK_MSG_ID_MANUAL_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_CRC);
}

/**
 * @brief Pack a manual_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target  The system to be controlled.
 * @param x  X-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to forward(1000)-backward(-1000) movement on a joystick and the pitch of a vehicle.
 * @param y  Y-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to left(-1000)-right(1000) movement on a joystick and the roll of a vehicle.
 * @param z  Z-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a separate slider movement with maximum being 1000 and minimum being -1000 on a joystick and the thrust of a vehicle. Positive values are positive thrust, negative values are negative thrust.
 * @param r  R-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a twisting of the joystick, with counter-clockwise being 1000 and clockwise being -1000, and the yaw of a vehicle.
 * @param buttons  A bitfield corresponding to the joystick buttons' current state, 1 for pressed, 0 for released. The lowest bit corresponds to Button 1.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_manual_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target,int16_t x,int16_t y,int16_t z,int16_t r,uint16_t buttons)
{
    _mav_put_int16_t(msg->payloads, 0, x);
    _mav_put_int16_t(msg->payloads, 2, y);
    _mav_put_int16_t(msg->payloads, 4, z);
    _mav_put_int16_t(msg->payloads, 6, r);
    _mav_put_uint16_t(msg->payloads, 8, buttons);
    _mav_put_uint8_t(msg->payloads, 10, target);


    msg->msgid = MAVLINK_MSG_ID_MANUAL_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MANUAL_CONTROL_MIN_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_LEN, MAVLINK_MSG_ID_MANUAL_CONTROL_CRC);
}

/**
 * @brief Encode a manual_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param manual_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_manual_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_manual_control_t* manual_control)
{
    return mavlink_msg_manual_control_pack(system_id, component_id, msg, manual_control->target, manual_control->x, manual_control->y, manual_control->z, manual_control->r, manual_control->buttons);
}

/**
 * @brief Encode a manual_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param manual_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_manual_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_manual_control_t* manual_control)
{
    return mavlink_msg_manual_control_pack_chan(system_id, component_id, chan, msg, manual_control->target, manual_control->x, manual_control->y, manual_control->z, manual_control->r, manual_control->buttons);
}

// MESSAGE MANUAL_CONTROL UNPACKING


/**
 * @brief Get field target from manual_control message
 *
 * @return  The system to be controlled.
 */
static inline uint8_t mavlink_msg_manual_control_get_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field x from manual_control message
 *
 * @return  X-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to forward(1000)-backward(-1000) movement on a joystick and the pitch of a vehicle.
 */
static inline int16_t mavlink_msg_manual_control_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field y from manual_control message
 *
 * @return  Y-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to left(-1000)-right(1000) movement on a joystick and the roll of a vehicle.
 */
static inline int16_t mavlink_msg_manual_control_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field z from manual_control message
 *
 * @return  Z-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a separate slider movement with maximum being 1000 and minimum being -1000 on a joystick and the thrust of a vehicle. Positive values are positive thrust, negative values are negative thrust.
 */
static inline int16_t mavlink_msg_manual_control_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field r from manual_control message
 *
 * @return  R-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a twisting of the joystick, with counter-clockwise being 1000 and clockwise being -1000, and the yaw of a vehicle.
 */
static inline int16_t mavlink_msg_manual_control_get_r(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field buttons from manual_control message
 *
 * @return  A bitfield corresponding to the joystick buttons' current state, 1 for pressed, 0 for released. The lowest bit corresponds to Button 1.
 */
static inline uint16_t mavlink_msg_manual_control_get_buttons(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Decode a manual_control message into a struct
 *
 * @param msg The message to decode
 * @param manual_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_manual_control_decode(const mavlink_message_t* msg, mavlink_manual_control_t* manual_control)
{
    manual_control->x = mavlink_msg_manual_control_get_x(msg);
    manual_control->y = mavlink_msg_manual_control_get_y(msg);
    manual_control->z = mavlink_msg_manual_control_get_z(msg);
    manual_control->r = mavlink_msg_manual_control_get_r(msg);
    manual_control->buttons = mavlink_msg_manual_control_get_buttons(msg);
    manual_control->target = mavlink_msg_manual_control_get_target(msg);
}