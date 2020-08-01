#ifndef MAVLINK_MSG_ping
#define MAVLINK_MSG_ping
// MESSAGE PING PACKING

#define MAVLINK_MSG_ID_PING 4

typedef struct __mavlink_ping_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint32_t seq; /*<  PING sequence*/
 uint8_t target_system; /*<  0: request ping from all receiving systems. If greater than 0: message is a ping response and number is the system id of the requesting system*/
 uint8_t target_component; /*<  0: request ping from all receiving components. If greater than 0: message is a ping response and number is the component id of the requesting component.*/
} mavlink_ping_t;

#define MAVLINK_MSG_ID_PING_LEN 14
#define MAVLINK_MSG_ID_PING_MIN_LEN 14
#define MAVLINK_MSG_ID_4_LEN 14
#define MAVLINK_MSG_ID_4_MIN_LEN 14

#define MAVLINK_MSG_ID_PING_CRC 237
#define MAVLINK_MSG_ID_4_CRC 237



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PING { \
    4, \
    "PING", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ping_t, time_usec) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_ping_t, seq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_ping_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_ping_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PING { \
    "PING", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ping_t, time_usec) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_ping_t, seq) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_ping_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_ping_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a ping message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param seq  PING sequence
 * @param target_system  0: request ping from all receiving systems. If greater than 0: message is a ping response and number is the system id of the requesting system
 * @param target_component  0: request ping from all receiving components. If greater than 0: message is a ping response and number is the component id of the requesting component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ping_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint32_t seq, uint8_t target_system, uint8_t target_component)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_uint32_t(((char*)msg->payloads), 8, seq);
    _mav_put_uint8_t(((char*)msg->payloads), 12, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 13, target_component);

    msg->msgid = MAVLINK_MSG_ID_PING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PING_MIN_LEN, MAVLINK_MSG_ID_PING_LEN, MAVLINK_MSG_ID_PING_CRC);
}

/**
 * @brief Pack a ping message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param seq  PING sequence
 * @param target_system  0: request ping from all receiving systems. If greater than 0: message is a ping response and number is the system id of the requesting system
 * @param target_component  0: request ping from all receiving components. If greater than 0: message is a ping response and number is the component id of the requesting component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ping_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint32_t seq,uint8_t target_system,uint8_t target_component)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_uint32_t(((char*)msg->payloads), 8, seq);
    _mav_put_uint8_t(((char*)msg->payloads), 12, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 13, target_component);


    msg->msgid = MAVLINK_MSG_ID_PING;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PING_MIN_LEN, MAVLINK_MSG_ID_PING_LEN, MAVLINK_MSG_ID_PING_CRC);
}

/**
 * @brief Encode a ping struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ping C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ping_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ping_t* ping)
{
    return mavlink_msg_ping_pack(system_id, component_id, msg, ping->time_usec, ping->seq, ping->target_system, ping->target_component);
}

/**
 * @brief Encode a ping struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ping C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ping_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ping_t* ping)
{
    return mavlink_msg_ping_pack_chan(system_id, component_id, chan, msg, ping->time_usec, ping->seq, ping->target_system, ping->target_component);
}

// MESSAGE PING UNPACKING


/**
 * @brief Get field time_usec from ping message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_ping_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field seq from ping message
 *
 * @return  PING sequence
 */
static inline uint32_t mavlink_msg_ping_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field target_system from ping message
 *
 * @return  0: request ping from all receiving systems. If greater than 0: message is a ping response and number is the system id of the requesting system
 */
static inline uint8_t mavlink_msg_ping_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field target_component from ping message
 *
 * @return  0: request ping from all receiving components. If greater than 0: message is a ping response and number is the component id of the requesting component.
 */
static inline uint8_t mavlink_msg_ping_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Decode a ping message into a struct
 *
 * @param msg The message to decode
 * @param ping C-struct to decode the message contents into
 */
static inline void mavlink_msg_ping_decode(const mavlink_message_t* msg, mavlink_ping_t* ping)
{
    ping->time_usec = mavlink_msg_ping_get_time_usec(msg);
    ping->seq = mavlink_msg_ping_get_seq(msg);
    ping->target_system = mavlink_msg_ping_get_target_system(msg);
    ping->target_component = mavlink_msg_ping_get_target_component(msg);
}
#endif
