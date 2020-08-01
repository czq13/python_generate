#ifndef MAVLINK_MSG_mission_current
#define MAVLINK_MSG_mission_current
// MESSAGE MISSION_CURRENT PACKING

#define MAVLINK_MSG_ID_MISSION_CURRENT 42

typedef struct __mavlink_mission_current_t {
 uint16_t seq; /*<  Sequence*/
} mavlink_mission_current_t;

#define MAVLINK_MSG_ID_MISSION_CURRENT_LEN 2
#define MAVLINK_MSG_ID_MISSION_CURRENT_MIN_LEN 2
#define MAVLINK_MSG_ID_42_LEN 2
#define MAVLINK_MSG_ID_42_MIN_LEN 2

#define MAVLINK_MSG_ID_MISSION_CURRENT_CRC 28
#define MAVLINK_MSG_ID_42_CRC 28



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_CURRENT { \
    42, \
    "MISSION_CURRENT", \
    1, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_current_t, seq) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_CURRENT { \
    "MISSION_CURRENT", \
    1, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_current_t, seq) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_current message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq  Sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_current_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t seq)
{
    _mav_put_uint16_t(((char*)msg->payloads), 0, seq);

    msg->msgid = MAVLINK_MSG_ID_MISSION_CURRENT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_CURRENT_MIN_LEN, MAVLINK_MSG_ID_MISSION_CURRENT_LEN, MAVLINK_MSG_ID_MISSION_CURRENT_CRC);
}

/**
 * @brief Pack a mission_current message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq  Sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_current_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t seq)
{
    _mav_put_uint16_t(((char*)msg->payloads), 0, seq);


    msg->msgid = MAVLINK_MSG_ID_MISSION_CURRENT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_CURRENT_MIN_LEN, MAVLINK_MSG_ID_MISSION_CURRENT_LEN, MAVLINK_MSG_ID_MISSION_CURRENT_CRC);
}

/**
 * @brief Encode a mission_current struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_current C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_current_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_current_t* mission_current)
{
    return mavlink_msg_mission_current_pack(system_id, component_id, msg, mission_current->seq);
}

/**
 * @brief Encode a mission_current struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_current C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_current_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mission_current_t* mission_current)
{
    return mavlink_msg_mission_current_pack_chan(system_id, component_id, chan, msg, mission_current->seq);
}

// MESSAGE MISSION_CURRENT UNPACKING


/**
 * @brief Get field seq from mission_current message
 *
 * @return  Sequence
 */
static inline uint16_t mavlink_msg_mission_current_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a mission_current message into a struct
 *
 * @param msg The message to decode
 * @param mission_current C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_current_decode(const mavlink_message_t* msg, mavlink_mission_current_t* mission_current)
{
    mission_current->seq = mavlink_msg_mission_current_get_seq(msg);
}
#endif
