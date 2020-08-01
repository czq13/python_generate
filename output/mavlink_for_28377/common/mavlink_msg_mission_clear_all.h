#ifndef MAVLINK_MSG_mission_clear_all
#define MAVLINK_MSG_mission_clear_all
// MESSAGE MISSION_CLEAR_ALL PACKING

#define MAVLINK_MSG_ID_MISSION_CLEAR_ALL 45

typedef struct __mavlink_mission_clear_all_t {
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t mission_type; /*<  Mission type.*/
} mavlink_mission_clear_all_t;

#define MAVLINK_MSG_ID_MISSION_CLEAR_ALL_LEN 3
#define MAVLINK_MSG_ID_MISSION_CLEAR_ALL_MIN_LEN 2
#define MAVLINK_MSG_ID_45_LEN 3
#define MAVLINK_MSG_ID_45_MIN_LEN 2

#define MAVLINK_MSG_ID_MISSION_CLEAR_ALL_CRC 232
#define MAVLINK_MSG_ID_45_CRC 232



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_CLEAR_ALL { \
    45, \
    "MISSION_CLEAR_ALL", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mission_clear_all_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mission_clear_all_t, target_component) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_clear_all_t, mission_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_CLEAR_ALL { \
    "MISSION_CLEAR_ALL", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mission_clear_all_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mission_clear_all_t, target_component) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_clear_all_t, mission_type) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_clear_all message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param mission_type  Mission type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_clear_all_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t mission_type)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 1, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 2, mission_type);

    msg->msgid = MAVLINK_MSG_ID_MISSION_CLEAR_ALL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_CLEAR_ALL_MIN_LEN, MAVLINK_MSG_ID_MISSION_CLEAR_ALL_LEN, MAVLINK_MSG_ID_MISSION_CLEAR_ALL_CRC);
}

/**
 * @brief Pack a mission_clear_all message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param mission_type  Mission type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_clear_all_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t mission_type)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 1, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 2, mission_type);


    msg->msgid = MAVLINK_MSG_ID_MISSION_CLEAR_ALL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_CLEAR_ALL_MIN_LEN, MAVLINK_MSG_ID_MISSION_CLEAR_ALL_LEN, MAVLINK_MSG_ID_MISSION_CLEAR_ALL_CRC);
}

/**
 * @brief Encode a mission_clear_all struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_clear_all C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_clear_all_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_clear_all_t* mission_clear_all)
{
    return mavlink_msg_mission_clear_all_pack(system_id, component_id, msg, mission_clear_all->target_system, mission_clear_all->target_component, mission_clear_all->mission_type);
}

/**
 * @brief Encode a mission_clear_all struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_clear_all C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_clear_all_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mission_clear_all_t* mission_clear_all)
{
    return mavlink_msg_mission_clear_all_pack_chan(system_id, component_id, chan, msg, mission_clear_all->target_system, mission_clear_all->target_component, mission_clear_all->mission_type);
}

// MESSAGE MISSION_CLEAR_ALL UNPACKING


/**
 * @brief Get field target_system from mission_clear_all message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_mission_clear_all_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from mission_clear_all message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_mission_clear_all_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field mission_type from mission_clear_all message
 *
 * @return  Mission type.
 */
static inline uint8_t mavlink_msg_mission_clear_all_get_mission_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a mission_clear_all message into a struct
 *
 * @param msg The message to decode
 * @param mission_clear_all C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_clear_all_decode(const mavlink_message_t* msg, mavlink_mission_clear_all_t* mission_clear_all)
{
    mission_clear_all->target_system = mavlink_msg_mission_clear_all_get_target_system(msg);
    mission_clear_all->target_component = mavlink_msg_mission_clear_all_get_target_component(msg);
    mission_clear_all->mission_type = mavlink_msg_mission_clear_all_get_mission_type(msg);
}
#endif
