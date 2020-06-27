#ifndef MAVLINK_MSG_open_drone_id_self_id
#define MAVLINK_MSG_open_drone_id_self_id
// MESSAGE OPEN_DRONE_ID_SELF_ID PACKING

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID 12903

typedef struct __mavlink_open_drone_id_self_id_t {
 uint8_t target_system; /*<  System ID (0 for broadcast).*/
 uint8_t target_component; /*<  Component ID (0 for broadcast).*/
 uint8_t id_or_mac[20]; /*<  Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html. */
 uint8_t description_type; /*<  Indicates the type of the description field.*/
 char description[23]; /*<  Text description or numeric value expressed as ASCII characters. Shall be filled with nulls in the unused portion of the field.*/
} mavlink_open_drone_id_self_id_t;

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID_LEN 46
#define MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID_MIN_LEN 46
#define MAVLINK_MSG_ID_12903_LEN 46
#define MAVLINK_MSG_ID_12903_MIN_LEN 46

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID_CRC 249
#define MAVLINK_MSG_ID_12903_CRC 249

#define MAVLINK_MSG_OPEN_DRONE_ID_SELF_ID_FIELD_ID_OR_MAC_LEN 20
#define MAVLINK_MSG_OPEN_DRONE_ID_SELF_ID_FIELD_DESCRIPTION_LEN 23

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_SELF_ID { \
    12903, \
    "OPEN_DRONE_ID_SELF_ID", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_open_drone_id_self_id_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_open_drone_id_self_id_t, target_component) }, \
         { "id_or_mac", NULL, MAVLINK_TYPE_UINT8_T, 20, 2, offsetof(mavlink_open_drone_id_self_id_t, id_or_mac) }, \
         { "description_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_open_drone_id_self_id_t, description_type) }, \
         { "description", NULL, MAVLINK_TYPE_CHAR, 23, 23, offsetof(mavlink_open_drone_id_self_id_t, description) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_SELF_ID { \
    "OPEN_DRONE_ID_SELF_ID", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_open_drone_id_self_id_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_open_drone_id_self_id_t, target_component) }, \
         { "id_or_mac", NULL, MAVLINK_TYPE_UINT8_T, 20, 2, offsetof(mavlink_open_drone_id_self_id_t, id_or_mac) }, \
         { "description_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_open_drone_id_self_id_t, description_type) }, \
         { "description", NULL, MAVLINK_TYPE_CHAR, 23, 23, offsetof(mavlink_open_drone_id_self_id_t, description) }, \
         } \
}
#endif

/**
 * @brief Pack a open_drone_id_self_id message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID (0 for broadcast).
 * @param target_component  Component ID (0 for broadcast).
 * @param id_or_mac  Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html. 
 * @param description_type  Indicates the type of the description field.
 * @param description  Text description or numeric value expressed as ASCII characters. Shall be filled with nulls in the unused portion of the field.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_open_drone_id_self_id_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const uint8_t *id_or_mac, uint8_t description_type, const char *description)
{
    _mav_put_uint8_t(msg->payloads, 0, target_system);
    _mav_put_uint8_t(msg->payloads, 1, target_component);
    _mav_put_uint8_t(msg->payloads, 22, description_type);
    _mav_put_uint8_t_array(msg->payloads, 2, id_or_mac, 20);
    _mav_put_char_array(msg->payloads, 23, description, 23);
    msg->msgid = MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID_CRC);
}

/**
 * @brief Pack a open_drone_id_self_id message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID (0 for broadcast).
 * @param target_component  Component ID (0 for broadcast).
 * @param id_or_mac  Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html. 
 * @param description_type  Indicates the type of the description field.
 * @param description  Text description or numeric value expressed as ASCII characters. Shall be filled with nulls in the unused portion of the field.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_open_drone_id_self_id_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const uint8_t *id_or_mac,uint8_t description_type,const char *description)
{
    _mav_put_uint8_t(msg->payloads, 0, target_system);
    _mav_put_uint8_t(msg->payloads, 1, target_component);
    _mav_put_uint8_t(msg->payloads, 22, description_type);
    _mav_put_uint8_t_array(msg->payloads, 2, id_or_mac, 20);
    _mav_put_char_array(msg->payloads, 23, description, 23);

    msg->msgid = MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_SELF_ID_CRC);
}

/**
 * @brief Encode a open_drone_id_self_id struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param open_drone_id_self_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_open_drone_id_self_id_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_open_drone_id_self_id_t* open_drone_id_self_id)
{
    return mavlink_msg_open_drone_id_self_id_pack(system_id, component_id, msg, open_drone_id_self_id->target_system, open_drone_id_self_id->target_component, open_drone_id_self_id->id_or_mac, open_drone_id_self_id->description_type, open_drone_id_self_id->description);
}

/**
 * @brief Encode a open_drone_id_self_id struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param open_drone_id_self_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_open_drone_id_self_id_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_open_drone_id_self_id_t* open_drone_id_self_id)
{
    return mavlink_msg_open_drone_id_self_id_pack_chan(system_id, component_id, chan, msg, open_drone_id_self_id->target_system, open_drone_id_self_id->target_component, open_drone_id_self_id->id_or_mac, open_drone_id_self_id->description_type, open_drone_id_self_id->description);
}

// MESSAGE OPEN_DRONE_ID_SELF_ID UNPACKING


/**
 * @brief Get field target_system from open_drone_id_self_id message
 *
 * @return  System ID (0 for broadcast).
 */
static inline uint8_t mavlink_msg_open_drone_id_self_id_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from open_drone_id_self_id message
 *
 * @return  Component ID (0 for broadcast).
 */
static inline uint8_t mavlink_msg_open_drone_id_self_id_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field id_or_mac from open_drone_id_self_id message
 *
 * @return  Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html. 
 */
static inline uint16_t mavlink_msg_open_drone_id_self_id_get_id_or_mac(const mavlink_message_t* msg, uint8_t *id_or_mac)
{
    return _MAV_RETURN_uint8_t_array(msg, id_or_mac, 20,  2);
}

/**
 * @brief Get field description_type from open_drone_id_self_id message
 *
 * @return  Indicates the type of the description field.
 */
static inline uint8_t mavlink_msg_open_drone_id_self_id_get_description_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field description from open_drone_id_self_id message
 *
 * @return  Text description or numeric value expressed as ASCII characters. Shall be filled with nulls in the unused portion of the field.
 */
static inline uint16_t mavlink_msg_open_drone_id_self_id_get_description(const mavlink_message_t* msg, char *description)
{
    return _MAV_RETURN_char_array(msg, description, 23,  23);
}

/**
 * @brief Decode a open_drone_id_self_id message into a struct
 *
 * @param msg The message to decode
 * @param open_drone_id_self_id C-struct to decode the message contents into
 */
static inline void mavlink_msg_open_drone_id_self_id_decode(const mavlink_message_t* msg, mavlink_open_drone_id_self_id_t* open_drone_id_self_id)
{
    open_drone_id_self_id->target_system = mavlink_msg_open_drone_id_self_id_get_target_system(msg);
    open_drone_id_self_id->target_component = mavlink_msg_open_drone_id_self_id_get_target_component(msg);
    mavlink_msg_open_drone_id_self_id_get_id_or_mac(msg, open_drone_id_self_id->id_or_mac);
    open_drone_id_self_id->description_type = mavlink_msg_open_drone_id_self_id_get_description_type(msg);
    mavlink_msg_open_drone_id_self_id_get_description(msg, open_drone_id_self_id->description);
}
#endif
