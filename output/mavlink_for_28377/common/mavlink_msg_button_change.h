#pragma once
// MESSAGE BUTTON_CHANGE PACKING

#define MAVLINK_MSG_ID_BUTTON_CHANGE 257

typedef struct __mavlink_button_change_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 uint32_t last_change_ms; /*< [ms] Time of last change of button state.*/
 uint8_t state; /*<  Bitmap for state of buttons.*/
} mavlink_button_change_t;

#define MAVLINK_MSG_ID_BUTTON_CHANGE_LEN 9
#define MAVLINK_MSG_ID_BUTTON_CHANGE_MIN_LEN 9
#define MAVLINK_MSG_ID_257_LEN 9
#define MAVLINK_MSG_ID_257_MIN_LEN 9

#define MAVLINK_MSG_ID_BUTTON_CHANGE_CRC 131
#define MAVLINK_MSG_ID_257_CRC 131



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BUTTON_CHANGE { \
    257, \
    "BUTTON_CHANGE", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_button_change_t, time_boot_ms) }, \
         { "last_change_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_button_change_t, last_change_ms) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_button_change_t, state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BUTTON_CHANGE { \
    "BUTTON_CHANGE", \
    3, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_button_change_t, time_boot_ms) }, \
         { "last_change_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_button_change_t, last_change_ms) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_button_change_t, state) }, \
         } \
}
#endif

/**
 * @brief Pack a button_change message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param last_change_ms [ms] Time of last change of button state.
 * @param state  Bitmap for state of buttons.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_button_change_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t last_change_ms, uint8_t state)
{
    _mav_put_uint32_t(msg->payloads, 0, time_boot_ms);
    _mav_put_uint32_t(msg->payloads, 4, last_change_ms);
    _mav_put_uint8_t(msg->payloads, 8, state);

    msg->msgid = MAVLINK_MSG_ID_BUTTON_CHANGE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BUTTON_CHANGE_MIN_LEN, MAVLINK_MSG_ID_BUTTON_CHANGE_LEN, MAVLINK_MSG_ID_BUTTON_CHANGE_CRC);
}

/**
 * @brief Pack a button_change message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param last_change_ms [ms] Time of last change of button state.
 * @param state  Bitmap for state of buttons.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_button_change_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t last_change_ms,uint8_t state)
{
    _mav_put_uint32_t(msg->payloads, 0, time_boot_ms);
    _mav_put_uint32_t(msg->payloads, 4, last_change_ms);
    _mav_put_uint8_t(msg->payloads, 8, state);


    msg->msgid = MAVLINK_MSG_ID_BUTTON_CHANGE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BUTTON_CHANGE_MIN_LEN, MAVLINK_MSG_ID_BUTTON_CHANGE_LEN, MAVLINK_MSG_ID_BUTTON_CHANGE_CRC);
}

/**
 * @brief Encode a button_change struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param button_change C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_button_change_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_button_change_t* button_change)
{
    return mavlink_msg_button_change_pack(system_id, component_id, msg, button_change->time_boot_ms, button_change->last_change_ms, button_change->state);
}

/**
 * @brief Encode a button_change struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param button_change C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_button_change_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_button_change_t* button_change)
{
    return mavlink_msg_button_change_pack_chan(system_id, component_id, chan, msg, button_change->time_boot_ms, button_change->last_change_ms, button_change->state);
}

// MESSAGE BUTTON_CHANGE UNPACKING


/**
 * @brief Get field time_boot_ms from button_change message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_button_change_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field last_change_ms from button_change message
 *
 * @return [ms] Time of last change of button state.
 */
static inline uint32_t mavlink_msg_button_change_get_last_change_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field state from button_change message
 *
 * @return  Bitmap for state of buttons.
 */
static inline uint8_t mavlink_msg_button_change_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a button_change message into a struct
 *
 * @param msg The message to decode
 * @param button_change C-struct to decode the message contents into
 */
static inline void mavlink_msg_button_change_decode(const mavlink_message_t* msg, mavlink_button_change_t* button_change)
{
    button_change->time_boot_ms = mavlink_msg_button_change_get_time_boot_ms(msg);
    button_change->last_change_ms = mavlink_msg_button_change_get_last_change_ms(msg);
    button_change->state = mavlink_msg_button_change_get_state(msg);
}
