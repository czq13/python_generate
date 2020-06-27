#pragma once
// MESSAGE ACTUATOR_CONTROL_TARGET PACKING

#define MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET 140

typedef struct __mavlink_actuator_control_target_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float controls[8]; /*<  Actuator controls. Normed to -1..+1 where 0 is neutral position. Throttle for single rotation direction motors is 0..1, negative range for reverse direction. Standard mapping for attitude controls (group 0): (index 0-7): roll, pitch, yaw, throttle, flaps, spoilers, airbrakes, landing gear. Load a pass-through mixer to repurpose them as generic outputs.*/
 uint8_t group_mlx; /*<  Actuator group. The "_mlx" indicates this is a multi-instance message and a MAVLink parser should use this field to difference between instances.*/
} mavlink_actuator_control_target_t;

#define MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_LEN 41
#define MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_MIN_LEN 41
#define MAVLINK_MSG_ID_140_LEN 41
#define MAVLINK_MSG_ID_140_MIN_LEN 41

#define MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_CRC 181
#define MAVLINK_MSG_ID_140_CRC 181

#define MAVLINK_MSG_ACTUATOR_CONTROL_TARGET_FIELD_CONTROLS_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ACTUATOR_CONTROL_TARGET { \
    140, \
    "ACTUATOR_CONTROL_TARGET", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_actuator_control_target_t, time_usec) }, \
         { "group_mlx", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_actuator_control_target_t, group_mlx) }, \
         { "controls", NULL, MAVLINK_TYPE_FLOAT, 8, 8, offsetof(mavlink_actuator_control_target_t, controls) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ACTUATOR_CONTROL_TARGET { \
    "ACTUATOR_CONTROL_TARGET", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_actuator_control_target_t, time_usec) }, \
         { "group_mlx", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_actuator_control_target_t, group_mlx) }, \
         { "controls", NULL, MAVLINK_TYPE_FLOAT, 8, 8, offsetof(mavlink_actuator_control_target_t, controls) }, \
         } \
}
#endif

/**
 * @brief Pack a actuator_control_target message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param group_mlx  Actuator group. The "_mlx" indicates this is a multi-instance message and a MAVLink parser should use this field to difference between instances.
 * @param controls  Actuator controls. Normed to -1..+1 where 0 is neutral position. Throttle for single rotation direction motors is 0..1, negative range for reverse direction. Standard mapping for attitude controls (group 0): (index 0-7): roll, pitch, yaw, throttle, flaps, spoilers, airbrakes, landing gear. Load a pass-through mixer to repurpose them as generic outputs.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_actuator_control_target_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t group_mlx, const float *controls)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint8_t(msg->payloads, 40, group_mlx);
    _mav_put_float_array(msg->payloads, 8, controls, 8);
    msg->msgid = MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_LEN, MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_CRC);
}

/**
 * @brief Pack a actuator_control_target message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param group_mlx  Actuator group. The "_mlx" indicates this is a multi-instance message and a MAVLink parser should use this field to difference between instances.
 * @param controls  Actuator controls. Normed to -1..+1 where 0 is neutral position. Throttle for single rotation direction motors is 0..1, negative range for reverse direction. Standard mapping for attitude controls (group 0): (index 0-7): roll, pitch, yaw, throttle, flaps, spoilers, airbrakes, landing gear. Load a pass-through mixer to repurpose them as generic outputs.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_actuator_control_target_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t group_mlx,const float *controls)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint8_t(msg->payloads, 40, group_mlx);
    _mav_put_float_array(msg->payloads, 8, controls, 8);

    msg->msgid = MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_LEN, MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET_CRC);
}

/**
 * @brief Encode a actuator_control_target struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param actuator_control_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_actuator_control_target_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_actuator_control_target_t* actuator_control_target)
{
    return mavlink_msg_actuator_control_target_pack(system_id, component_id, msg, actuator_control_target->time_usec, actuator_control_target->group_mlx, actuator_control_target->controls);
}

/**
 * @brief Encode a actuator_control_target struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param actuator_control_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_actuator_control_target_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_actuator_control_target_t* actuator_control_target)
{
    return mavlink_msg_actuator_control_target_pack_chan(system_id, component_id, chan, msg, actuator_control_target->time_usec, actuator_control_target->group_mlx, actuator_control_target->controls);
}

// MESSAGE ACTUATOR_CONTROL_TARGET UNPACKING


/**
 * @brief Get field time_usec from actuator_control_target message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_actuator_control_target_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field group_mlx from actuator_control_target message
 *
 * @return  Actuator group. The "_mlx" indicates this is a multi-instance message and a MAVLink parser should use this field to difference between instances.
 */
static inline uint8_t mavlink_msg_actuator_control_target_get_group_mlx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field controls from actuator_control_target message
 *
 * @return  Actuator controls. Normed to -1..+1 where 0 is neutral position. Throttle for single rotation direction motors is 0..1, negative range for reverse direction. Standard mapping for attitude controls (group 0): (index 0-7): roll, pitch, yaw, throttle, flaps, spoilers, airbrakes, landing gear. Load a pass-through mixer to repurpose them as generic outputs.
 */
static inline uint16_t mavlink_msg_actuator_control_target_get_controls(const mavlink_message_t* msg, float *controls)
{
    return _MAV_RETURN_float_array(msg, controls, 8,  8);
}

/**
 * @brief Decode a actuator_control_target message into a struct
 *
 * @param msg The message to decode
 * @param actuator_control_target C-struct to decode the message contents into
 */
static inline void mavlink_msg_actuator_control_target_decode(const mavlink_message_t* msg, mavlink_actuator_control_target_t* actuator_control_target)
{
    actuator_control_target->time_usec = mavlink_msg_actuator_control_target_get_time_usec(msg);
    mavlink_msg_actuator_control_target_get_controls(msg, actuator_control_target->controls);
    actuator_control_target->group_mlx = mavlink_msg_actuator_control_target_get_group_mlx(msg);
}
