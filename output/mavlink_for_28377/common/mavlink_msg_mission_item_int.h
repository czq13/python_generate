#pragma once
// MESSAGE MISSION_ITEM_INT PACKING

#define MAVLINK_MSG_ID_MISSION_ITEM_INT 73

typedef struct __mavlink_mission_item_int_t {
 float param1; /*<  PARAM1, see MAV_CMD enum*/
 float param2; /*<  PARAM2, see MAV_CMD enum*/
 float param3; /*<  PARAM3, see MAV_CMD enum*/
 float param4; /*<  PARAM4, see MAV_CMD enum*/
 int32_t x; /*<  PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7*/
 int32_t y; /*<  PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7*/
 float z; /*<  PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.*/
 uint16_t seq; /*<  Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).*/
 uint16_t command; /*<  The scheduled action for the waypoint.*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t frame; /*<  The coordinate system of the waypoint.*/
 uint8_t current; /*<  false:0, true:1*/
 uint8_t autocontinue; /*<  Autocontinue to next waypoint*/
 uint8_t mission_type; /*<  Mission type.*/
} mavlink_mission_item_int_t;

#define MAVLINK_MSG_ID_MISSION_ITEM_INT_LEN 38
#define MAVLINK_MSG_ID_MISSION_ITEM_INT_MIN_LEN 37
#define MAVLINK_MSG_ID_73_LEN 38
#define MAVLINK_MSG_ID_73_MIN_LEN 37

#define MAVLINK_MSG_ID_MISSION_ITEM_INT_CRC 38
#define MAVLINK_MSG_ID_73_CRC 38



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_ITEM_INT { \
    73, \
    "MISSION_ITEM_INT", \
    15, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_mission_item_int_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_mission_item_int_t, target_component) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_mission_item_int_t, seq) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_mission_item_int_t, frame) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_mission_item_int_t, command) }, \
         { "current", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_mission_item_int_t, current) }, \
         { "autocontinue", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_mission_item_int_t, autocontinue) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mission_item_int_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mission_item_int_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mission_item_int_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mission_item_int_t, param4) }, \
         { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_mission_item_int_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_mission_item_int_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_mission_item_int_t, z) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_mission_item_int_t, mission_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_ITEM_INT { \
    "MISSION_ITEM_INT", \
    15, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_mission_item_int_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_mission_item_int_t, target_component) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_mission_item_int_t, seq) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_mission_item_int_t, frame) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_mission_item_int_t, command) }, \
         { "current", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_mission_item_int_t, current) }, \
         { "autocontinue", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_mission_item_int_t, autocontinue) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mission_item_int_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mission_item_int_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mission_item_int_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mission_item_int_t, param4) }, \
         { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_mission_item_int_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_mission_item_int_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_mission_item_int_t, z) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_mission_item_int_t, mission_type) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_item_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param seq  Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).
 * @param frame  The coordinate system of the waypoint.
 * @param command  The scheduled action for the waypoint.
 * @param current  false:0, true:1
 * @param autocontinue  Autocontinue to next waypoint
 * @param param1  PARAM1, see MAV_CMD enum
 * @param param2  PARAM2, see MAV_CMD enum
 * @param param3  PARAM3, see MAV_CMD enum
 * @param param4  PARAM4, see MAV_CMD enum
 * @param x  PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7
 * @param y  PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7
 * @param z  PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.
 * @param mission_type  Mission type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_item_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t frame, uint16_t command, uint8_t current, uint8_t autocontinue, float param1, float param2, float param3, float param4, int32_t x, int32_t y, float z, uint8_t mission_type)
{
    _mav_put_float(msg->payloads, 0, param1);
    _mav_put_float(msg->payloads, 4, param2);
    _mav_put_float(msg->payloads, 8, param3);
    _mav_put_float(msg->payloads, 12, param4);
    _mav_put_int32_t(msg->payloads, 16, x);
    _mav_put_int32_t(msg->payloads, 20, y);
    _mav_put_float(msg->payloads, 24, z);
    _mav_put_uint16_t(msg->payloads, 28, seq);
    _mav_put_uint16_t(msg->payloads, 30, command);
    _mav_put_uint8_t(msg->payloads, 32, target_system);
    _mav_put_uint8_t(msg->payloads, 33, target_component);
    _mav_put_uint8_t(msg->payloads, 34, frame);
    _mav_put_uint8_t(msg->payloads, 35, current);
    _mav_put_uint8_t(msg->payloads, 36, autocontinue);
    _mav_put_uint8_t(msg->payloads, 37, mission_type);

    msg->msgid = MAVLINK_MSG_ID_MISSION_ITEM_INT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_ITEM_INT_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_CRC);
}

/**
 * @brief Pack a mission_item_int message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param seq  Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).
 * @param frame  The coordinate system of the waypoint.
 * @param command  The scheduled action for the waypoint.
 * @param current  false:0, true:1
 * @param autocontinue  Autocontinue to next waypoint
 * @param param1  PARAM1, see MAV_CMD enum
 * @param param2  PARAM2, see MAV_CMD enum
 * @param param3  PARAM3, see MAV_CMD enum
 * @param param4  PARAM4, see MAV_CMD enum
 * @param x  PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7
 * @param y  PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7
 * @param z  PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.
 * @param mission_type  Mission type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_item_int_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint16_t seq,uint8_t frame,uint16_t command,uint8_t current,uint8_t autocontinue,float param1,float param2,float param3,float param4,int32_t x,int32_t y,float z,uint8_t mission_type)
{
    _mav_put_float(msg->payloads, 0, param1);
    _mav_put_float(msg->payloads, 4, param2);
    _mav_put_float(msg->payloads, 8, param3);
    _mav_put_float(msg->payloads, 12, param4);
    _mav_put_int32_t(msg->payloads, 16, x);
    _mav_put_int32_t(msg->payloads, 20, y);
    _mav_put_float(msg->payloads, 24, z);
    _mav_put_uint16_t(msg->payloads, 28, seq);
    _mav_put_uint16_t(msg->payloads, 30, command);
    _mav_put_uint8_t(msg->payloads, 32, target_system);
    _mav_put_uint8_t(msg->payloads, 33, target_component);
    _mav_put_uint8_t(msg->payloads, 34, frame);
    _mav_put_uint8_t(msg->payloads, 35, current);
    _mav_put_uint8_t(msg->payloads, 36, autocontinue);
    _mav_put_uint8_t(msg->payloads, 37, mission_type);


    msg->msgid = MAVLINK_MSG_ID_MISSION_ITEM_INT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_ITEM_INT_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_CRC);
}

/**
 * @brief Encode a mission_item_int struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_item_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_item_int_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_item_int_t* mission_item_int)
{
    return mavlink_msg_mission_item_int_pack(system_id, component_id, msg, mission_item_int->target_system, mission_item_int->target_component, mission_item_int->seq, mission_item_int->frame, mission_item_int->command, mission_item_int->current, mission_item_int->autocontinue, mission_item_int->param1, mission_item_int->param2, mission_item_int->param3, mission_item_int->param4, mission_item_int->x, mission_item_int->y, mission_item_int->z, mission_item_int->mission_type);
}

/**
 * @brief Encode a mission_item_int struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_item_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_item_int_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mission_item_int_t* mission_item_int)
{
    return mavlink_msg_mission_item_int_pack_chan(system_id, component_id, chan, msg, mission_item_int->target_system, mission_item_int->target_component, mission_item_int->seq, mission_item_int->frame, mission_item_int->command, mission_item_int->current, mission_item_int->autocontinue, mission_item_int->param1, mission_item_int->param2, mission_item_int->param3, mission_item_int->param4, mission_item_int->x, mission_item_int->y, mission_item_int->z, mission_item_int->mission_type);
}

// MESSAGE MISSION_ITEM_INT UNPACKING


/**
 * @brief Get field target_system from mission_item_int message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_mission_item_int_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field target_component from mission_item_int message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_mission_item_int_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Get field seq from mission_item_int message
 *
 * @return  Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).
 */
static inline uint16_t mavlink_msg_mission_item_int_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field frame from mission_item_int message
 *
 * @return  The coordinate system of the waypoint.
 */
static inline uint8_t mavlink_msg_mission_item_int_get_frame(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field command from mission_item_int message
 *
 * @return  The scheduled action for the waypoint.
 */
static inline uint16_t mavlink_msg_mission_item_int_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field current from mission_item_int message
 *
 * @return  false:0, true:1
 */
static inline uint8_t mavlink_msg_mission_item_int_get_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  35);
}

/**
 * @brief Get field autocontinue from mission_item_int message
 *
 * @return  Autocontinue to next waypoint
 */
static inline uint8_t mavlink_msg_mission_item_int_get_autocontinue(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field param1 from mission_item_int message
 *
 * @return  PARAM1, see MAV_CMD enum
 */
static inline float mavlink_msg_mission_item_int_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param2 from mission_item_int message
 *
 * @return  PARAM2, see MAV_CMD enum
 */
static inline float mavlink_msg_mission_item_int_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param3 from mission_item_int message
 *
 * @return  PARAM3, see MAV_CMD enum
 */
static inline float mavlink_msg_mission_item_int_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param4 from mission_item_int message
 *
 * @return  PARAM4, see MAV_CMD enum
 */
static inline float mavlink_msg_mission_item_int_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field x from mission_item_int message
 *
 * @return  PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7
 */
static inline int32_t mavlink_msg_mission_item_int_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field y from mission_item_int message
 *
 * @return  PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7
 */
static inline int32_t mavlink_msg_mission_item_int_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field z from mission_item_int message
 *
 * @return  PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.
 */
static inline float mavlink_msg_mission_item_int_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field mission_type from mission_item_int message
 *
 * @return  Mission type.
 */
static inline uint8_t mavlink_msg_mission_item_int_get_mission_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Decode a mission_item_int message into a struct
 *
 * @param msg The message to decode
 * @param mission_item_int C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_item_int_decode(const mavlink_message_t* msg, mavlink_mission_item_int_t* mission_item_int)
{
    mission_item_int->param1 = mavlink_msg_mission_item_int_get_param1(msg);
    mission_item_int->param2 = mavlink_msg_mission_item_int_get_param2(msg);
    mission_item_int->param3 = mavlink_msg_mission_item_int_get_param3(msg);
    mission_item_int->param4 = mavlink_msg_mission_item_int_get_param4(msg);
    mission_item_int->x = mavlink_msg_mission_item_int_get_x(msg);
    mission_item_int->y = mavlink_msg_mission_item_int_get_y(msg);
    mission_item_int->z = mavlink_msg_mission_item_int_get_z(msg);
    mission_item_int->seq = mavlink_msg_mission_item_int_get_seq(msg);
    mission_item_int->command = mavlink_msg_mission_item_int_get_command(msg);
    mission_item_int->target_system = mavlink_msg_mission_item_int_get_target_system(msg);
    mission_item_int->target_component = mavlink_msg_mission_item_int_get_target_component(msg);
    mission_item_int->frame = mavlink_msg_mission_item_int_get_frame(msg);
    mission_item_int->current = mavlink_msg_mission_item_int_get_current(msg);
    mission_item_int->autocontinue = mavlink_msg_mission_item_int_get_autocontinue(msg);
    mission_item_int->mission_type = mavlink_msg_mission_item_int_get_mission_type(msg);
}
