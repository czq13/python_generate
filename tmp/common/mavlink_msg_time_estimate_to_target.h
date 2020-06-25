#pragma once
// MESSAGE TIME_ESTIMATE_TO_TARGET PACKING

#define MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET 380

typedef struct __mavlink_time_estimate_to_target_t {
 int32_t safe_return; /*< [s] Estimated time to complete the vehicle's configured "safe return" action from its current position (e.g. RTL, Smart RTL, etc.). -1 indicates that the vehicle is landed, or that no time estimate available.*/
 int32_t land; /*< [s] Estimated time for vehicle to complete the LAND action from its current position. -1 indicates that the vehicle is landed, or that no time estimate available.*/
 int32_t mission_next_item; /*< [s] Estimated time for reaching/completing the currently active mission item. -1 means no time estimate available.*/
 int32_t mission_end; /*< [s] Estimated time for completing the current mission. -1 means no mission active and/or no estimate available.*/
 int32_t commanded_action; /*< [s] Estimated time for completing the current commanded action (i.e. Go To, Takeoff, Land, etc.). -1 means no action active and/or no estimate available.*/
} mavlink_time_estimate_to_target_t;

#define MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET_LEN 20
#define MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET_MIN_LEN 20
#define MAVLINK_MSG_ID_380_LEN 20
#define MAVLINK_MSG_ID_380_MIN_LEN 20

#define MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET_CRC 232
#define MAVLINK_MSG_ID_380_CRC 232



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TIME_ESTIMATE_TO_TARGET { \
    380, \
    "TIME_ESTIMATE_TO_TARGET", \
    5, \
    {  { "safe_return", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_time_estimate_to_target_t, safe_return) }, \
         { "land", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_time_estimate_to_target_t, land) }, \
         { "mission_next_item", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_time_estimate_to_target_t, mission_next_item) }, \
         { "mission_end", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_time_estimate_to_target_t, mission_end) }, \
         { "commanded_action", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_time_estimate_to_target_t, commanded_action) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TIME_ESTIMATE_TO_TARGET { \
    "TIME_ESTIMATE_TO_TARGET", \
    5, \
    {  { "safe_return", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_time_estimate_to_target_t, safe_return) }, \
         { "land", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_time_estimate_to_target_t, land) }, \
         { "mission_next_item", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_time_estimate_to_target_t, mission_next_item) }, \
         { "mission_end", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_time_estimate_to_target_t, mission_end) }, \
         { "commanded_action", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_time_estimate_to_target_t, commanded_action) }, \
         } \
}
#endif

/**
 * @brief Pack a time_estimate_to_target message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param safe_return [s] Estimated time to complete the vehicle's configured "safe return" action from its current position (e.g. RTL, Smart RTL, etc.). -1 indicates that the vehicle is landed, or that no time estimate available.
 * @param land [s] Estimated time for vehicle to complete the LAND action from its current position. -1 indicates that the vehicle is landed, or that no time estimate available.
 * @param mission_next_item [s] Estimated time for reaching/completing the currently active mission item. -1 means no time estimate available.
 * @param mission_end [s] Estimated time for completing the current mission. -1 means no mission active and/or no estimate available.
 * @param commanded_action [s] Estimated time for completing the current commanded action (i.e. Go To, Takeoff, Land, etc.). -1 means no action active and/or no estimate available.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_time_estimate_to_target_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t safe_return, int32_t land, int32_t mission_next_item, int32_t mission_end, int32_t commanded_action)
{
    _mav_put_int32_t(msg->payloads, 0, safe_return);
    _mav_put_int32_t(msg->payloads, 4, land);
    _mav_put_int32_t(msg->payloads, 8, mission_next_item);
    _mav_put_int32_t(msg->payloads, 12, mission_end);
    _mav_put_int32_t(msg->payloads, 16, commanded_action);

    msg->msgid = MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET_MIN_LEN, MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET_LEN, MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET_CRC);
}

/**
 * @brief Pack a time_estimate_to_target message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param safe_return [s] Estimated time to complete the vehicle's configured "safe return" action from its current position (e.g. RTL, Smart RTL, etc.). -1 indicates that the vehicle is landed, or that no time estimate available.
 * @param land [s] Estimated time for vehicle to complete the LAND action from its current position. -1 indicates that the vehicle is landed, or that no time estimate available.
 * @param mission_next_item [s] Estimated time for reaching/completing the currently active mission item. -1 means no time estimate available.
 * @param mission_end [s] Estimated time for completing the current mission. -1 means no mission active and/or no estimate available.
 * @param commanded_action [s] Estimated time for completing the current commanded action (i.e. Go To, Takeoff, Land, etc.). -1 means no action active and/or no estimate available.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_time_estimate_to_target_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t safe_return,int32_t land,int32_t mission_next_item,int32_t mission_end,int32_t commanded_action)
{
    _mav_put_int32_t(msg->payloads, 0, safe_return);
    _mav_put_int32_t(msg->payloads, 4, land);
    _mav_put_int32_t(msg->payloads, 8, mission_next_item);
    _mav_put_int32_t(msg->payloads, 12, mission_end);
    _mav_put_int32_t(msg->payloads, 16, commanded_action);


    msg->msgid = MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET_MIN_LEN, MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET_LEN, MAVLINK_MSG_ID_TIME_ESTIMATE_TO_TARGET_CRC);
}

/**
 * @brief Encode a time_estimate_to_target struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param time_estimate_to_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_time_estimate_to_target_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_time_estimate_to_target_t* time_estimate_to_target)
{
    return mavlink_msg_time_estimate_to_target_pack(system_id, component_id, msg, time_estimate_to_target->safe_return, time_estimate_to_target->land, time_estimate_to_target->mission_next_item, time_estimate_to_target->mission_end, time_estimate_to_target->commanded_action);
}

/**
 * @brief Encode a time_estimate_to_target struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_estimate_to_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_time_estimate_to_target_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_time_estimate_to_target_t* time_estimate_to_target)
{
    return mavlink_msg_time_estimate_to_target_pack_chan(system_id, component_id, chan, msg, time_estimate_to_target->safe_return, time_estimate_to_target->land, time_estimate_to_target->mission_next_item, time_estimate_to_target->mission_end, time_estimate_to_target->commanded_action);
}

// MESSAGE TIME_ESTIMATE_TO_TARGET UNPACKING


/**
 * @brief Get field safe_return from time_estimate_to_target message
 *
 * @return [s] Estimated time to complete the vehicle's configured "safe return" action from its current position (e.g. RTL, Smart RTL, etc.). -1 indicates that the vehicle is landed, or that no time estimate available.
 */
static inline int32_t mavlink_msg_time_estimate_to_target_get_safe_return(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field land from time_estimate_to_target message
 *
 * @return [s] Estimated time for vehicle to complete the LAND action from its current position. -1 indicates that the vehicle is landed, or that no time estimate available.
 */
static inline int32_t mavlink_msg_time_estimate_to_target_get_land(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field mission_next_item from time_estimate_to_target message
 *
 * @return [s] Estimated time for reaching/completing the currently active mission item. -1 means no time estimate available.
 */
static inline int32_t mavlink_msg_time_estimate_to_target_get_mission_next_item(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field mission_end from time_estimate_to_target message
 *
 * @return [s] Estimated time for completing the current mission. -1 means no mission active and/or no estimate available.
 */
static inline int32_t mavlink_msg_time_estimate_to_target_get_mission_end(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field commanded_action from time_estimate_to_target message
 *
 * @return [s] Estimated time for completing the current commanded action (i.e. Go To, Takeoff, Land, etc.). -1 means no action active and/or no estimate available.
 */
static inline int32_t mavlink_msg_time_estimate_to_target_get_commanded_action(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Decode a time_estimate_to_target message into a struct
 *
 * @param msg The message to decode
 * @param time_estimate_to_target C-struct to decode the message contents into
 */
static inline void mavlink_msg_time_estimate_to_target_decode(const mavlink_message_t* msg, mavlink_time_estimate_to_target_t* time_estimate_to_target)
{
    time_estimate_to_target->safe_return = mavlink_msg_time_estimate_to_target_get_safe_return(msg);
    time_estimate_to_target->land = mavlink_msg_time_estimate_to_target_get_land(msg);
    time_estimate_to_target->mission_next_item = mavlink_msg_time_estimate_to_target_get_mission_next_item(msg);
    time_estimate_to_target->mission_end = mavlink_msg_time_estimate_to_target_get_mission_end(msg);
    time_estimate_to_target->commanded_action = mavlink_msg_time_estimate_to_target_get_commanded_action(msg);
}
