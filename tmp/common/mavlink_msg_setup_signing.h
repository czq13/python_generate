#pragma once
// MESSAGE SETUP_SIGNING PACKING

#define MAVLINK_MSG_ID_SETUP_SIGNING 256

typedef struct __mavlink_setup_signing_t {
 uint64_t initial_timestamp; /*<  initial timestamp*/
 uint8_t target_system; /*<  system id of the target*/
 uint8_t target_component; /*<  component ID of the target*/
 uint8_t secret_key[32]; /*<  signing key*/
} mavlink_setup_signing_t;

#define MAVLINK_MSG_ID_SETUP_SIGNING_LEN 42
#define MAVLINK_MSG_ID_SETUP_SIGNING_MIN_LEN 42
#define MAVLINK_MSG_ID_256_LEN 42
#define MAVLINK_MSG_ID_256_MIN_LEN 42

#define MAVLINK_MSG_ID_SETUP_SIGNING_CRC 71
#define MAVLINK_MSG_ID_256_CRC 71

#define MAVLINK_MSG_SETUP_SIGNING_FIELD_SECRET_KEY_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SETUP_SIGNING { \
    256, \
    "SETUP_SIGNING", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_setup_signing_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_setup_signing_t, target_component) }, \
         { "secret_key", NULL, MAVLINK_TYPE_UINT8_T, 32, 10, offsetof(mavlink_setup_signing_t, secret_key) }, \
         { "initial_timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_setup_signing_t, initial_timestamp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SETUP_SIGNING { \
    "SETUP_SIGNING", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_setup_signing_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_setup_signing_t, target_component) }, \
         { "secret_key", NULL, MAVLINK_TYPE_UINT8_T, 32, 10, offsetof(mavlink_setup_signing_t, secret_key) }, \
         { "initial_timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_setup_signing_t, initial_timestamp) }, \
         } \
}
#endif

/**
 * @brief Pack a setup_signing message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  system id of the target
 * @param target_component  component ID of the target
 * @param secret_key  signing key
 * @param initial_timestamp  initial timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setup_signing_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const uint8_t *secret_key, uint64_t initial_timestamp)
{
    _mav_put_uint64_t(msg->payloads, 0, initial_timestamp);
    _mav_put_uint8_t(msg->payloads, 8, target_system);
    _mav_put_uint8_t(msg->payloads, 9, target_component);
    _mav_put_uint8_t_array(msg->payloads, 10, secret_key, 32);
    msg->msgid = MAVLINK_MSG_ID_SETUP_SIGNING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SETUP_SIGNING_MIN_LEN, MAVLINK_MSG_ID_SETUP_SIGNING_LEN, MAVLINK_MSG_ID_SETUP_SIGNING_CRC);
}

/**
 * @brief Pack a setup_signing message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  system id of the target
 * @param target_component  component ID of the target
 * @param secret_key  signing key
 * @param initial_timestamp  initial timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setup_signing_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const uint8_t *secret_key,uint64_t initial_timestamp)
{
    _mav_put_uint64_t(msg->payloads, 0, initial_timestamp);
    _mav_put_uint8_t(msg->payloads, 8, target_system);
    _mav_put_uint8_t(msg->payloads, 9, target_component);
    _mav_put_uint8_t_array(msg->payloads, 10, secret_key, 32);

    msg->msgid = MAVLINK_MSG_ID_SETUP_SIGNING;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SETUP_SIGNING_MIN_LEN, MAVLINK_MSG_ID_SETUP_SIGNING_LEN, MAVLINK_MSG_ID_SETUP_SIGNING_CRC);
}

/**
 * @brief Encode a setup_signing struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param setup_signing C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_setup_signing_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_setup_signing_t* setup_signing)
{
    return mavlink_msg_setup_signing_pack(system_id, component_id, msg, setup_signing->target_system, setup_signing->target_component, setup_signing->secret_key, setup_signing->initial_timestamp);
}

/**
 * @brief Encode a setup_signing struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param setup_signing C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_setup_signing_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_setup_signing_t* setup_signing)
{
    return mavlink_msg_setup_signing_pack_chan(system_id, component_id, chan, msg, setup_signing->target_system, setup_signing->target_component, setup_signing->secret_key, setup_signing->initial_timestamp);
}

// MESSAGE SETUP_SIGNING UNPACKING


/**
 * @brief Get field target_system from setup_signing message
 *
 * @return  system id of the target
 */
static inline uint8_t mavlink_msg_setup_signing_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field target_component from setup_signing message
 *
 * @return  component ID of the target
 */
static inline uint8_t mavlink_msg_setup_signing_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field secret_key from setup_signing message
 *
 * @return  signing key
 */
static inline uint16_t mavlink_msg_setup_signing_get_secret_key(const mavlink_message_t* msg, uint8_t *secret_key)
{
    return _MAV_RETURN_uint8_t_array(msg, secret_key, 32,  10);
}

/**
 * @brief Get field initial_timestamp from setup_signing message
 *
 * @return  initial timestamp
 */
static inline uint64_t mavlink_msg_setup_signing_get_initial_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a setup_signing message into a struct
 *
 * @param msg The message to decode
 * @param setup_signing C-struct to decode the message contents into
 */
static inline void mavlink_msg_setup_signing_decode(const mavlink_message_t* msg, mavlink_setup_signing_t* setup_signing)
{
    setup_signing->initial_timestamp = mavlink_msg_setup_signing_get_initial_timestamp(msg);
    setup_signing->target_system = mavlink_msg_setup_signing_get_target_system(msg);
    setup_signing->target_component = mavlink_msg_setup_signing_get_target_component(msg);
    mavlink_msg_setup_signing_get_secret_key(msg, setup_signing->secret_key);
}
