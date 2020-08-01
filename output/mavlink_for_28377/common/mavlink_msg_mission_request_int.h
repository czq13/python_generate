#ifndef MAVLINK_MSG_mission_request_int
#define MAVLINK_MSG_mission_request_int
// MESSAGE MISSION_REQUEST_INT PACKING

#define MAVLINK_MSG_ID_MISSION_REQUEST_INT 51

typedef struct __mavlink_mission_request_int_t {
 uint16_t seq; /*<  Sequence*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t mission_type; /*<  Mission type.*/
} mavlink_mission_request_int_t;

#define MAVLINK_MSG_ID_MISSION_REQUEST_INT_LEN 5
#define MAVLINK_MSG_ID_MISSION_REQUEST_INT_MIN_LEN 4
#define MAVLINK_MSG_ID_51_LEN 5
#define MAVLINK_MSG_ID_51_MIN_LEN 4

#define MAVLINK_MSG_ID_MISSION_REQUEST_INT_CRC 196
#define MAVLINK_MSG_ID_51_CRC 196



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_REQUEST_INT { \
    51, \
    "MISSION_REQUEST_INT", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_request_int_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mission_request_int_t, target_component) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_request_int_t, seq) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mission_request_int_t, mission_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_REQUEST_INT { \
    "MISSION_REQUEST_INT", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_request_int_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mission_request_int_t, target_component) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_request_int_t, seq) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mission_request_int_t, mission_type) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_request_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param seq  Sequence
 * @param mission_type  Mission type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_request_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t mission_type)
{
    _mav_put_uint16_t(((char*)msg->payloads), 0, seq);
    _mav_put_uint8_t(((char*)msg->payloads), 2, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 3, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 4, mission_type);

    msg->msgid = MAVLINK_MSG_ID_MISSION_REQUEST_INT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_REQUEST_INT_MIN_LEN, MAVLINK_MSG_ID_MISSION_REQUEST_INT_LEN, MAVLINK_MSG_ID_MISSION_REQUEST_INT_CRC);
}

/**
 * @brief Pack a mission_request_int message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param seq  Sequence
 * @param mission_type  Mission type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_request_int_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint16_t seq,uint8_t mission_type)
{
    _mav_put_uint16_t(((char*)msg->payloads), 0, seq);
    _mav_put_uint8_t(((char*)msg->payloads), 2, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 3, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 4, mission_type);


    msg->msgid = MAVLINK_MSG_ID_MISSION_REQUEST_INT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_REQUEST_INT_MIN_LEN, MAVLINK_MSG_ID_MISSION_REQUEST_INT_LEN, MAVLINK_MSG_ID_MISSION_REQUEST_INT_CRC);
}

/**
 * @brief Encode a mission_request_int struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_request_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_request_int_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_request_int_t* mission_request_int)
{
    return mavlink_msg_mission_request_int_pack(system_id, component_id, msg, mission_request_int->target_system, mission_request_int->target_component, mission_request_int->seq, mission_request_int->mission_type);
}

/**
 * @brief Encode a mission_request_int struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_request_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_request_int_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mission_request_int_t* mission_request_int)
{
    return mavlink_msg_mission_request_int_pack_chan(system_id, component_id, chan, msg, mission_request_int->target_system, mission_request_int->target_component, mission_request_int->seq, mission_request_int->mission_type);
}

// MESSAGE MISSION_REQUEST_INT UNPACKING


/**
 * @brief Get field target_system from mission_request_int message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_mission_request_int_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field target_component from mission_request_int message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_mission_request_int_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field seq from mission_request_int message
 *
 * @return  Sequence
 */
static inline uint16_t mavlink_msg_mission_request_int_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field mission_type from mission_request_int message
 *
 * @return  Mission type.
 */
static inline uint8_t mavlink_msg_mission_request_int_get_mission_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a mission_request_int message into a struct
 *
 * @param msg The message to decode
 * @param mission_request_int C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_request_int_decode(const mavlink_message_t* msg, mavlink_mission_request_int_t* mission_request_int)
{
    mission_request_int->seq = mavlink_msg_mission_request_int_get_seq(msg);
    mission_request_int->target_system = mavlink_msg_mission_request_int_get_target_system(msg);
    mission_request_int->target_component = mavlink_msg_mission_request_int_get_target_component(msg);
    mission_request_int->mission_type = mavlink_msg_mission_request_int_get_mission_type(msg);
}
#endif
