#ifndef MAVLINK_MSG_extended_sys_state
#define MAVLINK_MSG_extended_sys_state
// MESSAGE EXTENDED_SYS_STATE PACKING

#define MAVLINK_MSG_ID_EXTENDED_SYS_STATE 245

typedef struct __mavlink_extended_sys_state_t {
 uint8_t vtol_state; /*<  The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration.*/
 uint8_t landed_state; /*<  The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown.*/
} mavlink_extended_sys_state_t;

#define MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN 2
#define MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN 2
#define MAVLINK_MSG_ID_245_LEN 2
#define MAVLINK_MSG_ID_245_MIN_LEN 2

#define MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC 130
#define MAVLINK_MSG_ID_245_CRC 130



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EXTENDED_SYS_STATE { \
    245, \
    "EXTENDED_SYS_STATE", \
    2, \
    {  { "vtol_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_extended_sys_state_t, vtol_state) }, \
         { "landed_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_extended_sys_state_t, landed_state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EXTENDED_SYS_STATE { \
    "EXTENDED_SYS_STATE", \
    2, \
    {  { "vtol_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_extended_sys_state_t, vtol_state) }, \
         { "landed_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_extended_sys_state_t, landed_state) }, \
         } \
}
#endif

/**
 * @brief Pack a extended_sys_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vtol_state  The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration.
 * @param landed_state  The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_extended_sys_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vtol_state, uint8_t landed_state)
{
    _mav_put_uint8_t(msg->payloads, 0, vtol_state);
    _mav_put_uint8_t(msg->payloads, 1, landed_state);

    msg->msgid = MAVLINK_MSG_ID_EXTENDED_SYS_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC);
}

/**
 * @brief Pack a extended_sys_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vtol_state  The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration.
 * @param landed_state  The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_extended_sys_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vtol_state,uint8_t landed_state)
{
    _mav_put_uint8_t(msg->payloads, 0, vtol_state);
    _mav_put_uint8_t(msg->payloads, 1, landed_state);


    msg->msgid = MAVLINK_MSG_ID_EXTENDED_SYS_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC);
}

/**
 * @brief Encode a extended_sys_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param extended_sys_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_extended_sys_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_extended_sys_state_t* extended_sys_state)
{
    return mavlink_msg_extended_sys_state_pack(system_id, component_id, msg, extended_sys_state->vtol_state, extended_sys_state->landed_state);
}

/**
 * @brief Encode a extended_sys_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param extended_sys_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_extended_sys_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_extended_sys_state_t* extended_sys_state)
{
    return mavlink_msg_extended_sys_state_pack_chan(system_id, component_id, chan, msg, extended_sys_state->vtol_state, extended_sys_state->landed_state);
}

// MESSAGE EXTENDED_SYS_STATE UNPACKING


/**
 * @brief Get field vtol_state from extended_sys_state message
 *
 * @return  The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration.
 */
static inline uint8_t mavlink_msg_extended_sys_state_get_vtol_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field landed_state from extended_sys_state message
 *
 * @return  The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown.
 */
static inline uint8_t mavlink_msg_extended_sys_state_get_landed_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a extended_sys_state message into a struct
 *
 * @param msg The message to decode
 * @param extended_sys_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_extended_sys_state_decode(const mavlink_message_t* msg, mavlink_extended_sys_state_t* extended_sys_state)
{
    extended_sys_state->vtol_state = mavlink_msg_extended_sys_state_get_vtol_state(msg);
    extended_sys_state->landed_state = mavlink_msg_extended_sys_state_get_landed_state(msg);
}
#endif
