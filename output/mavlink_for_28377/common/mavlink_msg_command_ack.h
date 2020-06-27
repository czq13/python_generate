#pragma once
// MESSAGE COMMAND_ACK PACKING

#define MAVLINK_MSG_ID_COMMAND_ACK 77

typedef struct __mavlink_command_ack_t {
 uint16_t command; /*<  Command ID (of acknowledged command).*/
 uint8_t result; /*<  Result of command.*/
 uint8_t progress; /*<  WIP: Also used as result_param1, it can be set with a enum containing the errors reasons of why the command was denied or the progress percentage or 255 if unknown the progress when result is MAV_RESULT_IN_PROGRESS.*/
 int32_t result_param2; /*<  WIP: Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied.*/
 uint8_t target_system; /*<  WIP: System which requested the command to be executed*/
 uint8_t target_component; /*<  WIP: Component which requested the command to be executed*/
} mavlink_command_ack_t;

#define MAVLINK_MSG_ID_COMMAND_ACK_LEN 10
#define MAVLINK_MSG_ID_COMMAND_ACK_MIN_LEN 3
#define MAVLINK_MSG_ID_77_LEN 10
#define MAVLINK_MSG_ID_77_MIN_LEN 3

#define MAVLINK_MSG_ID_COMMAND_ACK_CRC 143
#define MAVLINK_MSG_ID_77_CRC 143



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMMAND_ACK { \
    77, \
    "COMMAND_ACK", \
    6, \
    {  { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_command_ack_t, command) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_command_ack_t, result) }, \
         { "progress", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_command_ack_t, progress) }, \
         { "result_param2", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_command_ack_t, result_param2) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_command_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_command_ack_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMMAND_ACK { \
    "COMMAND_ACK", \
    6, \
    {  { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_command_ack_t, command) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_command_ack_t, result) }, \
         { "progress", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_command_ack_t, progress) }, \
         { "result_param2", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_command_ack_t, result_param2) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_command_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_command_ack_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a command_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param command  Command ID (of acknowledged command).
 * @param result  Result of command.
 * @param progress  WIP: Also used as result_param1, it can be set with a enum containing the errors reasons of why the command was denied or the progress percentage or 255 if unknown the progress when result is MAV_RESULT_IN_PROGRESS.
 * @param result_param2  WIP: Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied.
 * @param target_system  WIP: System which requested the command to be executed
 * @param target_component  WIP: Component which requested the command to be executed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t command, uint8_t result, uint8_t progress, int32_t result_param2, uint8_t target_system, uint8_t target_component)
{
    _mav_put_uint16_t(msg->payloads, 0, command);
    _mav_put_uint8_t(msg->payloads, 2, result);
    _mav_put_uint8_t(msg->payloads, 3, progress);
    _mav_put_int32_t(msg->payloads, 4, result_param2);
    _mav_put_uint8_t(msg->payloads, 8, target_system);
    _mav_put_uint8_t(msg->payloads, 9, target_component);

    msg->msgid = MAVLINK_MSG_ID_COMMAND_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMMAND_ACK_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK_LEN, MAVLINK_MSG_ID_COMMAND_ACK_CRC);
}

/**
 * @brief Pack a command_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command  Command ID (of acknowledged command).
 * @param result  Result of command.
 * @param progress  WIP: Also used as result_param1, it can be set with a enum containing the errors reasons of why the command was denied or the progress percentage or 255 if unknown the progress when result is MAV_RESULT_IN_PROGRESS.
 * @param result_param2  WIP: Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied.
 * @param target_system  WIP: System which requested the command to be executed
 * @param target_component  WIP: Component which requested the command to be executed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t command,uint8_t result,uint8_t progress,int32_t result_param2,uint8_t target_system,uint8_t target_component)
{
    _mav_put_uint16_t(msg->payloads, 0, command);
    _mav_put_uint8_t(msg->payloads, 2, result);
    _mav_put_uint8_t(msg->payloads, 3, progress);
    _mav_put_int32_t(msg->payloads, 4, result_param2);
    _mav_put_uint8_t(msg->payloads, 8, target_system);
    _mav_put_uint8_t(msg->payloads, 9, target_component);


    msg->msgid = MAVLINK_MSG_ID_COMMAND_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMMAND_ACK_MIN_LEN, MAVLINK_MSG_ID_COMMAND_ACK_LEN, MAVLINK_MSG_ID_COMMAND_ACK_CRC);
}

/**
 * @brief Encode a command_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param command_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_command_ack_t* command_ack)
{
    return mavlink_msg_command_ack_pack(system_id, component_id, msg, command_ack->command, command_ack->result, command_ack->progress, command_ack->result_param2, command_ack->target_system, command_ack->target_component);
}

/**
 * @brief Encode a command_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_command_ack_t* command_ack)
{
    return mavlink_msg_command_ack_pack_chan(system_id, component_id, chan, msg, command_ack->command, command_ack->result, command_ack->progress, command_ack->result_param2, command_ack->target_system, command_ack->target_component);
}

// MESSAGE COMMAND_ACK UNPACKING


/**
 * @brief Get field command from command_ack message
 *
 * @return  Command ID (of acknowledged command).
 */
static inline uint16_t mavlink_msg_command_ack_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field result from command_ack message
 *
 * @return  Result of command.
 */
static inline uint8_t mavlink_msg_command_ack_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field progress from command_ack message
 *
 * @return  WIP: Also used as result_param1, it can be set with a enum containing the errors reasons of why the command was denied or the progress percentage or 255 if unknown the progress when result is MAV_RESULT_IN_PROGRESS.
 */
static inline uint8_t mavlink_msg_command_ack_get_progress(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field result_param2 from command_ack message
 *
 * @return  WIP: Additional parameter of the result, example: which parameter of MAV_CMD_NAV_WAYPOINT caused it to be denied.
 */
static inline int32_t mavlink_msg_command_ack_get_result_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field target_system from command_ack message
 *
 * @return  WIP: System which requested the command to be executed
 */
static inline uint8_t mavlink_msg_command_ack_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field target_component from command_ack message
 *
 * @return  WIP: Component which requested the command to be executed
 */
static inline uint8_t mavlink_msg_command_ack_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Decode a command_ack message into a struct
 *
 * @param msg The message to decode
 * @param command_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_command_ack_decode(const mavlink_message_t* msg, mavlink_command_ack_t* command_ack)
{
    command_ack->command = mavlink_msg_command_ack_get_command(msg);
    command_ack->result = mavlink_msg_command_ack_get_result(msg);
    command_ack->progress = mavlink_msg_command_ack_get_progress(msg);
    command_ack->result_param2 = mavlink_msg_command_ack_get_result_param2(msg);
    command_ack->target_system = mavlink_msg_command_ack_get_target_system(msg);
    command_ack->target_component = mavlink_msg_command_ack_get_target_component(msg);
}
