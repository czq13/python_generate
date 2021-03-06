#ifndef MAVLINK_MSG_hil_actuator_controls
#define MAVLINK_MSG_hil_actuator_controls
// MESSAGE HIL_ACTUATOR_CONTROLS PACKING

#define MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS 93

typedef struct __mavlink_hil_actuator_controls_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint64_t flags; /*<  Flags as bitfield, 1: indicate simulation using lockstep.*/
 float controls[16]; /*<  Control outputs -1 .. 1. Channel assignment depends on the simulated hardware.*/
 uint8_t mode; /*<  System mode. Includes arming state.*/
} mavlink_hil_actuator_controls_t;

#define MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_LEN 81
#define MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_MIN_LEN 81
#define MAVLINK_MSG_ID_93_LEN 81
#define MAVLINK_MSG_ID_93_MIN_LEN 81

#define MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_CRC 47
#define MAVLINK_MSG_ID_93_CRC 47

#define MAVLINK_MSG_HIL_ACTUATOR_CONTROLS_FIELD_CONTROLS_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HIL_ACTUATOR_CONTROLS { \
    93, \
    "HIL_ACTUATOR_CONTROLS", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_actuator_controls_t, time_usec) }, \
         { "controls", NULL, MAVLINK_TYPE_FLOAT, 16, 16, offsetof(mavlink_hil_actuator_controls_t, controls) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 80, offsetof(mavlink_hil_actuator_controls_t, mode) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_hil_actuator_controls_t, flags) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HIL_ACTUATOR_CONTROLS { \
    "HIL_ACTUATOR_CONTROLS", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_actuator_controls_t, time_usec) }, \
         { "controls", NULL, MAVLINK_TYPE_FLOAT, 16, 16, offsetof(mavlink_hil_actuator_controls_t, controls) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 80, offsetof(mavlink_hil_actuator_controls_t, mode) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_hil_actuator_controls_t, flags) }, \
         } \
}
#endif

/**
 * @brief Pack a hil_actuator_controls message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param controls  Control outputs -1 .. 1. Channel assignment depends on the simulated hardware.
 * @param mode  System mode. Includes arming state.
 * @param flags  Flags as bitfield, 1: indicate simulation using lockstep.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_actuator_controls_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *controls, uint8_t mode, uint64_t flags)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_uint64_t(((char*)msg->payloads), 8, flags);
    _mav_put_uint8_t(((char*)msg->payloads), 80, mode);
    _mav_put_float_array(((char*)msg->payloads), 16, controls, 16);
    msg->msgid = MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_MIN_LEN, MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_LEN, MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_CRC);
}

/**
 * @brief Pack a hil_actuator_controls message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param controls  Control outputs -1 .. 1. Channel assignment depends on the simulated hardware.
 * @param mode  System mode. Includes arming state.
 * @param flags  Flags as bitfield, 1: indicate simulation using lockstep.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_actuator_controls_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *controls,uint8_t mode,uint64_t flags)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_uint64_t(((char*)msg->payloads), 8, flags);
    _mav_put_uint8_t(((char*)msg->payloads), 80, mode);
    _mav_put_float_array(((char*)msg->payloads), 16, controls, 16);

    msg->msgid = MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_MIN_LEN, MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_LEN, MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS_CRC);
}

/**
 * @brief Encode a hil_actuator_controls struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hil_actuator_controls C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_actuator_controls_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hil_actuator_controls_t* hil_actuator_controls)
{
    return mavlink_msg_hil_actuator_controls_pack(system_id, component_id, msg, hil_actuator_controls->time_usec, hil_actuator_controls->controls, hil_actuator_controls->mode, hil_actuator_controls->flags);
}

/**
 * @brief Encode a hil_actuator_controls struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hil_actuator_controls C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_actuator_controls_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hil_actuator_controls_t* hil_actuator_controls)
{
    return mavlink_msg_hil_actuator_controls_pack_chan(system_id, component_id, chan, msg, hil_actuator_controls->time_usec, hil_actuator_controls->controls, hil_actuator_controls->mode, hil_actuator_controls->flags);
}

// MESSAGE HIL_ACTUATOR_CONTROLS UNPACKING


/**
 * @brief Get field time_usec from hil_actuator_controls message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_hil_actuator_controls_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field controls from hil_actuator_controls message
 *
 * @return  Control outputs -1 .. 1. Channel assignment depends on the simulated hardware.
 */
static inline uint16_t mavlink_msg_hil_actuator_controls_get_controls(const mavlink_message_t* msg, float *controls)
{
    return _MAV_RETURN_float_array(msg, controls, 16,  16);
}

/**
 * @brief Get field mode from hil_actuator_controls message
 *
 * @return  System mode. Includes arming state.
 */
static inline uint8_t mavlink_msg_hil_actuator_controls_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  80);
}

/**
 * @brief Get field flags from hil_actuator_controls message
 *
 * @return  Flags as bitfield, 1: indicate simulation using lockstep.
 */
static inline uint64_t mavlink_msg_hil_actuator_controls_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Decode a hil_actuator_controls message into a struct
 *
 * @param msg The message to decode
 * @param hil_actuator_controls C-struct to decode the message contents into
 */
static inline void mavlink_msg_hil_actuator_controls_decode(const mavlink_message_t* msg, mavlink_hil_actuator_controls_t* hil_actuator_controls)
{
    hil_actuator_controls->time_usec = mavlink_msg_hil_actuator_controls_get_time_usec(msg);
    hil_actuator_controls->flags = mavlink_msg_hil_actuator_controls_get_flags(msg);
    mavlink_msg_hil_actuator_controls_get_controls(msg, hil_actuator_controls->controls);
    hil_actuator_controls->mode = mavlink_msg_hil_actuator_controls_get_mode(msg);
}
#endif
