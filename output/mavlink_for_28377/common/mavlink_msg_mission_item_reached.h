#ifndef MAVLINK_MSG_mission_item_reached
#define MAVLINK_MSG_mission_item_reached
// MESSAGE MISSION_ITEM_REACHED PACKING

#define MAVLINK_MSG_ID_MISSION_ITEM_REACHED 46

typedef struct __mavlink_mission_item_reached_t {
 uint16_t seq; /*<  Sequence*/
} mavlink_mission_item_reached_t;

#define MAVLINK_MSG_ID_MISSION_ITEM_REACHED_LEN 2
#define MAVLINK_MSG_ID_MISSION_ITEM_REACHED_MIN_LEN 2
#define MAVLINK_MSG_ID_46_LEN 2
#define MAVLINK_MSG_ID_46_MIN_LEN 2

#define MAVLINK_MSG_ID_MISSION_ITEM_REACHED_CRC 11
#define MAVLINK_MSG_ID_46_CRC 11



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_ITEM_REACHED { \
    46, \
    "MISSION_ITEM_REACHED", \
    1, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_item_reached_t, seq) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_ITEM_REACHED { \
    "MISSION_ITEM_REACHED", \
    1, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_item_reached_t, seq) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_item_reached message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq  Sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_item_reached_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t seq)
{
    _mav_put_uint16_t(((char*)msg->payloads), 0, seq);

    msg->msgid = MAVLINK_MSG_ID_MISSION_ITEM_REACHED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_ITEM_REACHED_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_REACHED_LEN, MAVLINK_MSG_ID_MISSION_ITEM_REACHED_CRC);
}

/**
 * @brief Pack a mission_item_reached message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq  Sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_item_reached_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t seq)
{
    _mav_put_uint16_t(((char*)msg->payloads), 0, seq);


    msg->msgid = MAVLINK_MSG_ID_MISSION_ITEM_REACHED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_ITEM_REACHED_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_REACHED_LEN, MAVLINK_MSG_ID_MISSION_ITEM_REACHED_CRC);
}

/**
 * @brief Encode a mission_item_reached struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_item_reached C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_item_reached_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_item_reached_t* mission_item_reached)
{
    return mavlink_msg_mission_item_reached_pack(system_id, component_id, msg, mission_item_reached->seq);
}

/**
 * @brief Encode a mission_item_reached struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_item_reached C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_item_reached_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mission_item_reached_t* mission_item_reached)
{
    return mavlink_msg_mission_item_reached_pack_chan(system_id, component_id, chan, msg, mission_item_reached->seq);
}

// MESSAGE MISSION_ITEM_REACHED UNPACKING


/**
 * @brief Get field seq from mission_item_reached message
 *
 * @return  Sequence
 */
static inline uint16_t mavlink_msg_mission_item_reached_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a mission_item_reached message into a struct
 *
 * @param msg The message to decode
 * @param mission_item_reached C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_item_reached_decode(const mavlink_message_t* msg, mavlink_mission_item_reached_t* mission_item_reached)
{
    mission_item_reached->seq = mavlink_msg_mission_item_reached_get_seq(msg);
}
#endif
