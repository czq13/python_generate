#ifndef MAVLINK_MSG_auth_key
#define MAVLINK_MSG_auth_key
// MESSAGE AUTH_KEY PACKING

#define MAVLINK_MSG_ID_AUTH_KEY 7

typedef struct __mavlink_auth_key_t {
 char key[32]; /*<  key*/
} mavlink_auth_key_t;

#define MAVLINK_MSG_ID_AUTH_KEY_LEN 32
#define MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN 32
#define MAVLINK_MSG_ID_7_LEN 32
#define MAVLINK_MSG_ID_7_MIN_LEN 32

#define MAVLINK_MSG_ID_AUTH_KEY_CRC 119
#define MAVLINK_MSG_ID_7_CRC 119

#define MAVLINK_MSG_AUTH_KEY_FIELD_KEY_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUTH_KEY { \
    7, \
    "AUTH_KEY", \
    1, \
    {  { "key", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_auth_key_t, key) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUTH_KEY { \
    "AUTH_KEY", \
    1, \
    {  { "key", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_auth_key_t, key) }, \
         } \
}
#endif

/**
 * @brief Pack a auth_key message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param key  key
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auth_key_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *key)
{

    _mav_put_char_array(((char*)msg->payloads), 0, key, 32);
    msg->msgid = MAVLINK_MSG_ID_AUTH_KEY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
}

/**
 * @brief Pack a auth_key message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param key  key
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auth_key_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *key)
{

    _mav_put_char_array(((char*)msg->payloads), 0, key, 32);

    msg->msgid = MAVLINK_MSG_ID_AUTH_KEY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
}

/**
 * @brief Encode a auth_key struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auth_key C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auth_key_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auth_key_t* auth_key)
{
    return mavlink_msg_auth_key_pack(system_id, component_id, msg, auth_key->key);
}

/**
 * @brief Encode a auth_key struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auth_key C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auth_key_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auth_key_t* auth_key)
{
    return mavlink_msg_auth_key_pack_chan(system_id, component_id, chan, msg, auth_key->key);
}

// MESSAGE AUTH_KEY UNPACKING


/**
 * @brief Get field key from auth_key message
 *
 * @return  key
 */
static inline uint16_t mavlink_msg_auth_key_get_key(const mavlink_message_t* msg, char *key)
{
    return _MAV_RETURN_char_array(msg, key, 32,  0);
}

/**
 * @brief Decode a auth_key message into a struct
 *
 * @param msg The message to decode
 * @param auth_key C-struct to decode the message contents into
 */
static inline void mavlink_msg_auth_key_decode(const mavlink_message_t* msg, mavlink_auth_key_t* auth_key)
{
    mavlink_msg_auth_key_get_key(msg, auth_key->key);
}
#endif
