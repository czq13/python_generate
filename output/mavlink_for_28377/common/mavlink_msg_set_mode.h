#ifndef MAVLINK_MSG_set_mode
#define MAVLINK_MSG_set_mode
// MESSAGE SET_MODE PACKING

#define MAVLINK_MSG_ID_SET_MODE 11

typedef struct __mavlink_set_mode_t {
 uint32_t custom_mode; /*<  The new autopilot-specific mode. This field can be ignored by an autopilot.*/
 uint8_t target_system; /*<  The system setting the mode*/
 uint8_t base_mode; /*<  The new base mode.*/
} mavlink_set_mode_t;

#define MAVLINK_MSG_ID_SET_MODE_LEN 6
#define MAVLINK_MSG_ID_SET_MODE_MIN_LEN 6
#define MAVLINK_MSG_ID_11_LEN 6
#define MAVLINK_MSG_ID_11_MIN_LEN 6

#define MAVLINK_MSG_ID_SET_MODE_CRC 89
#define MAVLINK_MSG_ID_11_CRC 89



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_MODE { \
    11, \
    "SET_MODE", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_set_mode_t, target_system) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_set_mode_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_mode_t, custom_mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_MODE { \
    "SET_MODE", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_set_mode_t, target_system) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_set_mode_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_mode_t, custom_mode) }, \
         } \
}
#endif

/**
 * @brief Pack a set_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  The system setting the mode
 * @param base_mode  The new base mode.
 * @param custom_mode  The new autopilot-specific mode. This field can be ignored by an autopilot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t base_mode, uint32_t custom_mode)
{
    _mav_put_uint32_t(msg->payloads, 0, custom_mode);
    _mav_put_uint8_t(msg->payloads, 4, target_system);
    _mav_put_uint8_t(msg->payloads, 5, base_mode);

    msg->msgid = MAVLINK_MSG_ID_SET_MODE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
}

/**
 * @brief Pack a set_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  The system setting the mode
 * @param base_mode  The new base mode.
 * @param custom_mode  The new autopilot-specific mode. This field can be ignored by an autopilot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t base_mode,uint32_t custom_mode)
{
    _mav_put_uint32_t(msg->payloads, 0, custom_mode);
    _mav_put_uint8_t(msg->payloads, 4, target_system);
    _mav_put_uint8_t(msg->payloads, 5, base_mode);


    msg->msgid = MAVLINK_MSG_ID_SET_MODE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
}

/**
 * @brief Encode a set_mode struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_mode_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_mode_t* set_mode)
{
    return mavlink_msg_set_mode_pack(system_id, component_id, msg, set_mode->target_system, set_mode->base_mode, set_mode->custom_mode);
}

/**
 * @brief Encode a set_mode struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_mode_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_mode_t* set_mode)
{
    return mavlink_msg_set_mode_pack_chan(system_id, component_id, chan, msg, set_mode->target_system, set_mode->base_mode, set_mode->custom_mode);
}

// MESSAGE SET_MODE UNPACKING


/**
 * @brief Get field target_system from set_mode message
 *
 * @return  The system setting the mode
 */
static inline uint8_t mavlink_msg_set_mode_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field base_mode from set_mode message
 *
 * @return  The new base mode.
 */
static inline uint8_t mavlink_msg_set_mode_get_base_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field custom_mode from set_mode message
 *
 * @return  The new autopilot-specific mode. This field can be ignored by an autopilot.
 */
static inline uint32_t mavlink_msg_set_mode_get_custom_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a set_mode message into a struct
 *
 * @param msg The message to decode
 * @param set_mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_mode_decode(const mavlink_message_t* msg, mavlink_set_mode_t* set_mode)
{
    set_mode->custom_mode = mavlink_msg_set_mode_get_custom_mode(msg);
    set_mode->target_system = mavlink_msg_set_mode_get_target_system(msg);
    set_mode->base_mode = mavlink_msg_set_mode_get_base_mode(msg);
}
#endif
