#ifndef MAVLINK_MSG_open_drone_id_message_pack
#define MAVLINK_MSG_open_drone_id_message_pack
// MESSAGE OPEN_DRONE_ID_MESSAGE_PACK PACKING

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK 12915

typedef struct __mavlink_open_drone_id_message_pack_t {
 uint8_t target_system; /*<  System ID (0 for broadcast).*/
 uint8_t target_component; /*<  Component ID (0 for broadcast).*/
 uint8_t single_message_size; /*< [bytes] This field must currently always be equal to 25 (bytes), since all encoded OpenDroneID messages are specificed to have this length.*/
 uint8_t msg_pack_size; /*<  Number of encoded messages in the pack (not the number of bytes). Allowed range is 1 - 10.*/
 uint8_t messages[250]; /*<  Concatenation of encoded OpenDroneID messages. Shall be filled with nulls in the unused portion of the field.*/
} mavlink_open_drone_id_message_pack_t;

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_LEN 254
#define MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_MIN_LEN 254
#define MAVLINK_MSG_ID_12915_LEN 254
#define MAVLINK_MSG_ID_12915_MIN_LEN 254

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_CRC 62
#define MAVLINK_MSG_ID_12915_CRC 62

#define MAVLINK_MSG_OPEN_DRONE_ID_MESSAGE_PACK_FIELD_MESSAGES_LEN 250

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_MESSAGE_PACK { \
    12915, \
    "OPEN_DRONE_ID_MESSAGE_PACK", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_open_drone_id_message_pack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_open_drone_id_message_pack_t, target_component) }, \
         { "single_message_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_open_drone_id_message_pack_t, single_message_size) }, \
         { "msg_pack_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_open_drone_id_message_pack_t, msg_pack_size) }, \
         { "messages", NULL, MAVLINK_TYPE_UINT8_T, 250, 4, offsetof(mavlink_open_drone_id_message_pack_t, messages) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_MESSAGE_PACK { \
    "OPEN_DRONE_ID_MESSAGE_PACK", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_open_drone_id_message_pack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_open_drone_id_message_pack_t, target_component) }, \
         { "single_message_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_open_drone_id_message_pack_t, single_message_size) }, \
         { "msg_pack_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_open_drone_id_message_pack_t, msg_pack_size) }, \
         { "messages", NULL, MAVLINK_TYPE_UINT8_T, 250, 4, offsetof(mavlink_open_drone_id_message_pack_t, messages) }, \
         } \
}
#endif

/**
 * @brief Pack a open_drone_id_message_pack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID (0 for broadcast).
 * @param target_component  Component ID (0 for broadcast).
 * @param single_message_size [bytes] This field must currently always be equal to 25 (bytes), since all encoded OpenDroneID messages are specificed to have this length.
 * @param msg_pack_size  Number of encoded messages in the pack (not the number of bytes). Allowed range is 1 - 10.
 * @param messages  Concatenation of encoded OpenDroneID messages. Shall be filled with nulls in the unused portion of the field.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_open_drone_id_message_pack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t single_message_size, uint8_t msg_pack_size, const uint8_t *messages)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 1, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 2, single_message_size);
    _mav_put_uint8_t(((char*)msg->payloads), 3, msg_pack_size);
    _mav_put_uint8_t_array(((char*)msg->payloads), 4, messages, 250);
    msg->msgid = MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_CRC);
}

/**
 * @brief Pack a open_drone_id_message_pack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID (0 for broadcast).
 * @param target_component  Component ID (0 for broadcast).
 * @param single_message_size [bytes] This field must currently always be equal to 25 (bytes), since all encoded OpenDroneID messages are specificed to have this length.
 * @param msg_pack_size  Number of encoded messages in the pack (not the number of bytes). Allowed range is 1 - 10.
 * @param messages  Concatenation of encoded OpenDroneID messages. Shall be filled with nulls in the unused portion of the field.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_open_drone_id_message_pack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t single_message_size,uint8_t msg_pack_size,const uint8_t *messages)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 1, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 2, single_message_size);
    _mav_put_uint8_t(((char*)msg->payloads), 3, msg_pack_size);
    _mav_put_uint8_t_array(((char*)msg->payloads), 4, messages, 250);

    msg->msgid = MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_MESSAGE_PACK_CRC);
}

/**
 * @brief Encode a open_drone_id_message_pack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param open_drone_id_message_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_open_drone_id_message_pack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_open_drone_id_message_pack_t* open_drone_id_message_pack)
{
    return mavlink_msg_open_drone_id_message_pack_pack(system_id, component_id, msg, open_drone_id_message_pack->target_system, open_drone_id_message_pack->target_component, open_drone_id_message_pack->single_message_size, open_drone_id_message_pack->msg_pack_size, open_drone_id_message_pack->messages);
}

/**
 * @brief Encode a open_drone_id_message_pack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param open_drone_id_message_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_open_drone_id_message_pack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_open_drone_id_message_pack_t* open_drone_id_message_pack)
{
    return mavlink_msg_open_drone_id_message_pack_pack_chan(system_id, component_id, chan, msg, open_drone_id_message_pack->target_system, open_drone_id_message_pack->target_component, open_drone_id_message_pack->single_message_size, open_drone_id_message_pack->msg_pack_size, open_drone_id_message_pack->messages);
}

// MESSAGE OPEN_DRONE_ID_MESSAGE_PACK UNPACKING


/**
 * @brief Get field target_system from open_drone_id_message_pack message
 *
 * @return  System ID (0 for broadcast).
 */
static inline uint8_t mavlink_msg_open_drone_id_message_pack_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from open_drone_id_message_pack message
 *
 * @return  Component ID (0 for broadcast).
 */
static inline uint8_t mavlink_msg_open_drone_id_message_pack_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field single_message_size from open_drone_id_message_pack message
 *
 * @return [bytes] This field must currently always be equal to 25 (bytes), since all encoded OpenDroneID messages are specificed to have this length.
 */
static inline uint8_t mavlink_msg_open_drone_id_message_pack_get_single_message_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field msg_pack_size from open_drone_id_message_pack message
 *
 * @return  Number of encoded messages in the pack (not the number of bytes). Allowed range is 1 - 10.
 */
static inline uint8_t mavlink_msg_open_drone_id_message_pack_get_msg_pack_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field messages from open_drone_id_message_pack message
 *
 * @return  Concatenation of encoded OpenDroneID messages. Shall be filled with nulls in the unused portion of the field.
 */
static inline uint16_t mavlink_msg_open_drone_id_message_pack_get_messages(const mavlink_message_t* msg, uint8_t *messages)
{
    return _MAV_RETURN_uint8_t_array(msg, messages, 250,  4);
}

/**
 * @brief Decode a open_drone_id_message_pack message into a struct
 *
 * @param msg The message to decode
 * @param open_drone_id_message_pack C-struct to decode the message contents into
 */
static inline void mavlink_msg_open_drone_id_message_pack_decode(const mavlink_message_t* msg, mavlink_open_drone_id_message_pack_t* open_drone_id_message_pack)
{
    open_drone_id_message_pack->target_system = mavlink_msg_open_drone_id_message_pack_get_target_system(msg);
    open_drone_id_message_pack->target_component = mavlink_msg_open_drone_id_message_pack_get_target_component(msg);
    open_drone_id_message_pack->single_message_size = mavlink_msg_open_drone_id_message_pack_get_single_message_size(msg);
    open_drone_id_message_pack->msg_pack_size = mavlink_msg_open_drone_id_message_pack_get_msg_pack_size(msg);
    mavlink_msg_open_drone_id_message_pack_get_messages(msg, open_drone_id_message_pack->messages);
}
#endif
