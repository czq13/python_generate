#ifndef MAVLINK_MSG_hil_rc_inputs_raw
#define MAVLINK_MSG_hil_rc_inputs_raw
// MESSAGE HIL_RC_INPUTS_RAW PACKING

#define MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW 92

typedef struct __mavlink_hil_rc_inputs_raw_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint16_t chan1_raw; /*< [us] RC channel 1 value*/
 uint16_t chan2_raw; /*< [us] RC channel 2 value*/
 uint16_t chan3_raw; /*< [us] RC channel 3 value*/
 uint16_t chan4_raw; /*< [us] RC channel 4 value*/
 uint16_t chan5_raw; /*< [us] RC channel 5 value*/
 uint16_t chan6_raw; /*< [us] RC channel 6 value*/
 uint16_t chan7_raw; /*< [us] RC channel 7 value*/
 uint16_t chan8_raw; /*< [us] RC channel 8 value*/
 uint16_t chan9_raw; /*< [us] RC channel 9 value*/
 uint16_t chan10_raw; /*< [us] RC channel 10 value*/
 uint16_t chan11_raw; /*< [us] RC channel 11 value*/
 uint16_t chan12_raw; /*< [us] RC channel 12 value*/
 uint8_t rssi; /*<  Receive signal strength indicator in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.*/
} mavlink_hil_rc_inputs_raw_t;

#define MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_LEN 33
#define MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_MIN_LEN 33
#define MAVLINK_MSG_ID_92_LEN 33
#define MAVLINK_MSG_ID_92_MIN_LEN 33

#define MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_CRC 54
#define MAVLINK_MSG_ID_92_CRC 54



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HIL_RC_INPUTS_RAW { \
    92, \
    "HIL_RC_INPUTS_RAW", \
    14, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_rc_inputs_raw_t, time_usec) }, \
         { "chan1_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_hil_rc_inputs_raw_t, chan1_raw) }, \
         { "chan2_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_hil_rc_inputs_raw_t, chan2_raw) }, \
         { "chan3_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_hil_rc_inputs_raw_t, chan3_raw) }, \
         { "chan4_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_hil_rc_inputs_raw_t, chan4_raw) }, \
         { "chan5_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_hil_rc_inputs_raw_t, chan5_raw) }, \
         { "chan6_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_hil_rc_inputs_raw_t, chan6_raw) }, \
         { "chan7_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_hil_rc_inputs_raw_t, chan7_raw) }, \
         { "chan8_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_hil_rc_inputs_raw_t, chan8_raw) }, \
         { "chan9_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_hil_rc_inputs_raw_t, chan9_raw) }, \
         { "chan10_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_hil_rc_inputs_raw_t, chan10_raw) }, \
         { "chan11_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_hil_rc_inputs_raw_t, chan11_raw) }, \
         { "chan12_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_hil_rc_inputs_raw_t, chan12_raw) }, \
         { "rssi", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_hil_rc_inputs_raw_t, rssi) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HIL_RC_INPUTS_RAW { \
    "HIL_RC_INPUTS_RAW", \
    14, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_rc_inputs_raw_t, time_usec) }, \
         { "chan1_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_hil_rc_inputs_raw_t, chan1_raw) }, \
         { "chan2_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_hil_rc_inputs_raw_t, chan2_raw) }, \
         { "chan3_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_hil_rc_inputs_raw_t, chan3_raw) }, \
         { "chan4_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_hil_rc_inputs_raw_t, chan4_raw) }, \
         { "chan5_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_hil_rc_inputs_raw_t, chan5_raw) }, \
         { "chan6_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_hil_rc_inputs_raw_t, chan6_raw) }, \
         { "chan7_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_hil_rc_inputs_raw_t, chan7_raw) }, \
         { "chan8_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_hil_rc_inputs_raw_t, chan8_raw) }, \
         { "chan9_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_hil_rc_inputs_raw_t, chan9_raw) }, \
         { "chan10_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_hil_rc_inputs_raw_t, chan10_raw) }, \
         { "chan11_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_hil_rc_inputs_raw_t, chan11_raw) }, \
         { "chan12_raw", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_hil_rc_inputs_raw_t, chan12_raw) }, \
         { "rssi", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_hil_rc_inputs_raw_t, rssi) }, \
         } \
}
#endif

/**
 * @brief Pack a hil_rc_inputs_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param chan1_raw [us] RC channel 1 value
 * @param chan2_raw [us] RC channel 2 value
 * @param chan3_raw [us] RC channel 3 value
 * @param chan4_raw [us] RC channel 4 value
 * @param chan5_raw [us] RC channel 5 value
 * @param chan6_raw [us] RC channel 6 value
 * @param chan7_raw [us] RC channel 7 value
 * @param chan8_raw [us] RC channel 8 value
 * @param chan9_raw [us] RC channel 9 value
 * @param chan10_raw [us] RC channel 10 value
 * @param chan11_raw [us] RC channel 11 value
 * @param chan12_raw [us] RC channel 12 value
 * @param rssi  Receive signal strength indicator in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint16_t chan1_raw, uint16_t chan2_raw, uint16_t chan3_raw, uint16_t chan4_raw, uint16_t chan5_raw, uint16_t chan6_raw, uint16_t chan7_raw, uint16_t chan8_raw, uint16_t chan9_raw, uint16_t chan10_raw, uint16_t chan11_raw, uint16_t chan12_raw, uint8_t rssi)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_uint16_t(((char*)msg->payloads), 8, chan1_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 10, chan2_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 12, chan3_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 14, chan4_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 16, chan5_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 18, chan6_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 20, chan7_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 22, chan8_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 24, chan9_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 26, chan10_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 28, chan11_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 30, chan12_raw);
    _mav_put_uint8_t(((char*)msg->payloads), 32, rssi);

    msg->msgid = MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_MIN_LEN, MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_LEN, MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_CRC);
}

/**
 * @brief Pack a hil_rc_inputs_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param chan1_raw [us] RC channel 1 value
 * @param chan2_raw [us] RC channel 2 value
 * @param chan3_raw [us] RC channel 3 value
 * @param chan4_raw [us] RC channel 4 value
 * @param chan5_raw [us] RC channel 5 value
 * @param chan6_raw [us] RC channel 6 value
 * @param chan7_raw [us] RC channel 7 value
 * @param chan8_raw [us] RC channel 8 value
 * @param chan9_raw [us] RC channel 9 value
 * @param chan10_raw [us] RC channel 10 value
 * @param chan11_raw [us] RC channel 11 value
 * @param chan12_raw [us] RC channel 12 value
 * @param rssi  Receive signal strength indicator in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint16_t chan1_raw,uint16_t chan2_raw,uint16_t chan3_raw,uint16_t chan4_raw,uint16_t chan5_raw,uint16_t chan6_raw,uint16_t chan7_raw,uint16_t chan8_raw,uint16_t chan9_raw,uint16_t chan10_raw,uint16_t chan11_raw,uint16_t chan12_raw,uint8_t rssi)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_uint16_t(((char*)msg->payloads), 8, chan1_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 10, chan2_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 12, chan3_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 14, chan4_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 16, chan5_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 18, chan6_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 20, chan7_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 22, chan8_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 24, chan9_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 26, chan10_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 28, chan11_raw);
    _mav_put_uint16_t(((char*)msg->payloads), 30, chan12_raw);
    _mav_put_uint8_t(((char*)msg->payloads), 32, rssi);


    msg->msgid = MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_MIN_LEN, MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_LEN, MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW_CRC);
}

/**
 * @brief Encode a hil_rc_inputs_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hil_rc_inputs_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hil_rc_inputs_raw_t* hil_rc_inputs_raw)
{
    return mavlink_msg_hil_rc_inputs_raw_pack(system_id, component_id, msg, hil_rc_inputs_raw->time_usec, hil_rc_inputs_raw->chan1_raw, hil_rc_inputs_raw->chan2_raw, hil_rc_inputs_raw->chan3_raw, hil_rc_inputs_raw->chan4_raw, hil_rc_inputs_raw->chan5_raw, hil_rc_inputs_raw->chan6_raw, hil_rc_inputs_raw->chan7_raw, hil_rc_inputs_raw->chan8_raw, hil_rc_inputs_raw->chan9_raw, hil_rc_inputs_raw->chan10_raw, hil_rc_inputs_raw->chan11_raw, hil_rc_inputs_raw->chan12_raw, hil_rc_inputs_raw->rssi);
}

/**
 * @brief Encode a hil_rc_inputs_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hil_rc_inputs_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hil_rc_inputs_raw_t* hil_rc_inputs_raw)
{
    return mavlink_msg_hil_rc_inputs_raw_pack_chan(system_id, component_id, chan, msg, hil_rc_inputs_raw->time_usec, hil_rc_inputs_raw->chan1_raw, hil_rc_inputs_raw->chan2_raw, hil_rc_inputs_raw->chan3_raw, hil_rc_inputs_raw->chan4_raw, hil_rc_inputs_raw->chan5_raw, hil_rc_inputs_raw->chan6_raw, hil_rc_inputs_raw->chan7_raw, hil_rc_inputs_raw->chan8_raw, hil_rc_inputs_raw->chan9_raw, hil_rc_inputs_raw->chan10_raw, hil_rc_inputs_raw->chan11_raw, hil_rc_inputs_raw->chan12_raw, hil_rc_inputs_raw->rssi);
}

// MESSAGE HIL_RC_INPUTS_RAW UNPACKING


/**
 * @brief Get field time_usec from hil_rc_inputs_raw message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_hil_rc_inputs_raw_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field chan1_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 1 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan1_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field chan2_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 2 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan2_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field chan3_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 3 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan3_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field chan4_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 4 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan4_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field chan5_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 5 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan5_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field chan6_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 6 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan6_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field chan7_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 7 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan7_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field chan8_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 8 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan8_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field chan9_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 9 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan9_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field chan10_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 10 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan10_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field chan11_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 11 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan11_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field chan12_raw from hil_rc_inputs_raw message
 *
 * @return [us] RC channel 12 value
 */
static inline uint16_t mavlink_msg_hil_rc_inputs_raw_get_chan12_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field rssi from hil_rc_inputs_raw message
 *
 * @return  Receive signal strength indicator in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.
 */
static inline uint8_t mavlink_msg_hil_rc_inputs_raw_get_rssi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Decode a hil_rc_inputs_raw message into a struct
 *
 * @param msg The message to decode
 * @param hil_rc_inputs_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_hil_rc_inputs_raw_decode(const mavlink_message_t* msg, mavlink_hil_rc_inputs_raw_t* hil_rc_inputs_raw)
{
    hil_rc_inputs_raw->time_usec = mavlink_msg_hil_rc_inputs_raw_get_time_usec(msg);
    hil_rc_inputs_raw->chan1_raw = mavlink_msg_hil_rc_inputs_raw_get_chan1_raw(msg);
    hil_rc_inputs_raw->chan2_raw = mavlink_msg_hil_rc_inputs_raw_get_chan2_raw(msg);
    hil_rc_inputs_raw->chan3_raw = mavlink_msg_hil_rc_inputs_raw_get_chan3_raw(msg);
    hil_rc_inputs_raw->chan4_raw = mavlink_msg_hil_rc_inputs_raw_get_chan4_raw(msg);
    hil_rc_inputs_raw->chan5_raw = mavlink_msg_hil_rc_inputs_raw_get_chan5_raw(msg);
    hil_rc_inputs_raw->chan6_raw = mavlink_msg_hil_rc_inputs_raw_get_chan6_raw(msg);
    hil_rc_inputs_raw->chan7_raw = mavlink_msg_hil_rc_inputs_raw_get_chan7_raw(msg);
    hil_rc_inputs_raw->chan8_raw = mavlink_msg_hil_rc_inputs_raw_get_chan8_raw(msg);
    hil_rc_inputs_raw->chan9_raw = mavlink_msg_hil_rc_inputs_raw_get_chan9_raw(msg);
    hil_rc_inputs_raw->chan10_raw = mavlink_msg_hil_rc_inputs_raw_get_chan10_raw(msg);
    hil_rc_inputs_raw->chan11_raw = mavlink_msg_hil_rc_inputs_raw_get_chan11_raw(msg);
    hil_rc_inputs_raw->chan12_raw = mavlink_msg_hil_rc_inputs_raw_get_chan12_raw(msg);
    hil_rc_inputs_raw->rssi = mavlink_msg_hil_rc_inputs_raw_get_rssi(msg);
}
#endif
