#pragma once
// MESSAGE RADIO_STATUS PACKING

#define MAVLINK_MSG_ID_RADIO_STATUS 109

typedef struct __mavlink_radio_status_t {
 uint16_t rxerrors; /*<  Count of radio packet receive errors (since boot).*/
 uint16_t fixed; /*<  Count of error corrected radio packets (since boot).*/
 uint8_t rssi; /*<  Local (message sender) recieved signal strength indication in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.*/
 uint8_t remrssi; /*<  Remote (message receiver) signal strength indication in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.*/
 uint8_t txbuf; /*< [%] Remaining free transmitter buffer space.*/
 uint8_t noise; /*<  Local background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], 255: invalid/unknown.*/
 uint8_t remnoise; /*<  Remote background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], 255: invalid/unknown.*/
} mavlink_radio_status_t;

#define MAVLINK_MSG_ID_RADIO_STATUS_LEN 9
#define MAVLINK_MSG_ID_RADIO_STATUS_MIN_LEN 9
#define MAVLINK_MSG_ID_109_LEN 9
#define MAVLINK_MSG_ID_109_MIN_LEN 9

#define MAVLINK_MSG_ID_RADIO_STATUS_CRC 185
#define MAVLINK_MSG_ID_109_CRC 185



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RADIO_STATUS { \
    109, \
    "RADIO_STATUS", \
    7, \
    {  { "rssi", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_radio_status_t, rssi) }, \
         { "remrssi", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_radio_status_t, remrssi) }, \
         { "txbuf", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_radio_status_t, txbuf) }, \
         { "noise", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_radio_status_t, noise) }, \
         { "remnoise", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_radio_status_t, remnoise) }, \
         { "rxerrors", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_radio_status_t, rxerrors) }, \
         { "fixed", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_radio_status_t, fixed) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RADIO_STATUS { \
    "RADIO_STATUS", \
    7, \
    {  { "rssi", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_radio_status_t, rssi) }, \
         { "remrssi", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_radio_status_t, remrssi) }, \
         { "txbuf", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_radio_status_t, txbuf) }, \
         { "noise", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_radio_status_t, noise) }, \
         { "remnoise", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_radio_status_t, remnoise) }, \
         { "rxerrors", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_radio_status_t, rxerrors) }, \
         { "fixed", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_radio_status_t, fixed) }, \
         } \
}
#endif

/**
 * @brief Pack a radio_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param rssi  Local (message sender) recieved signal strength indication in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.
 * @param remrssi  Remote (message receiver) signal strength indication in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.
 * @param txbuf [%] Remaining free transmitter buffer space.
 * @param noise  Local background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], 255: invalid/unknown.
 * @param remnoise  Remote background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], 255: invalid/unknown.
 * @param rxerrors  Count of radio packet receive errors (since boot).
 * @param fixed  Count of error corrected radio packets (since boot).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radio_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t rssi, uint8_t remrssi, uint8_t txbuf, uint8_t noise, uint8_t remnoise, uint16_t rxerrors, uint16_t fixed)
{
    _mav_put_uint16_t(msg->payloads, 0, rxerrors);
    _mav_put_uint16_t(msg->payloads, 2, fixed);
    _mav_put_uint8_t(msg->payloads, 4, rssi);
    _mav_put_uint8_t(msg->payloads, 5, remrssi);
    _mav_put_uint8_t(msg->payloads, 6, txbuf);
    _mav_put_uint8_t(msg->payloads, 7, noise);
    _mav_put_uint8_t(msg->payloads, 8, remnoise);

    msg->msgid = MAVLINK_MSG_ID_RADIO_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADIO_STATUS_MIN_LEN, MAVLINK_MSG_ID_RADIO_STATUS_LEN, MAVLINK_MSG_ID_RADIO_STATUS_CRC);
}

/**
 * @brief Pack a radio_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rssi  Local (message sender) recieved signal strength indication in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.
 * @param remrssi  Remote (message receiver) signal strength indication in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.
 * @param txbuf [%] Remaining free transmitter buffer space.
 * @param noise  Local background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], 255: invalid/unknown.
 * @param remnoise  Remote background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], 255: invalid/unknown.
 * @param rxerrors  Count of radio packet receive errors (since boot).
 * @param fixed  Count of error corrected radio packets (since boot).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radio_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t rssi,uint8_t remrssi,uint8_t txbuf,uint8_t noise,uint8_t remnoise,uint16_t rxerrors,uint16_t fixed)
{
    _mav_put_uint16_t(msg->payloads, 0, rxerrors);
    _mav_put_uint16_t(msg->payloads, 2, fixed);
    _mav_put_uint8_t(msg->payloads, 4, rssi);
    _mav_put_uint8_t(msg->payloads, 5, remrssi);
    _mav_put_uint8_t(msg->payloads, 6, txbuf);
    _mav_put_uint8_t(msg->payloads, 7, noise);
    _mav_put_uint8_t(msg->payloads, 8, remnoise);


    msg->msgid = MAVLINK_MSG_ID_RADIO_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADIO_STATUS_MIN_LEN, MAVLINK_MSG_ID_RADIO_STATUS_LEN, MAVLINK_MSG_ID_RADIO_STATUS_CRC);
}

/**
 * @brief Encode a radio_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param radio_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radio_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_radio_status_t* radio_status)
{
    return mavlink_msg_radio_status_pack(system_id, component_id, msg, radio_status->rssi, radio_status->remrssi, radio_status->txbuf, radio_status->noise, radio_status->remnoise, radio_status->rxerrors, radio_status->fixed);
}

/**
 * @brief Encode a radio_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param radio_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radio_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_radio_status_t* radio_status)
{
    return mavlink_msg_radio_status_pack_chan(system_id, component_id, chan, msg, radio_status->rssi, radio_status->remrssi, radio_status->txbuf, radio_status->noise, radio_status->remnoise, radio_status->rxerrors, radio_status->fixed);
}

// MESSAGE RADIO_STATUS UNPACKING


/**
 * @brief Get field rssi from radio_status message
 *
 * @return  Local (message sender) recieved signal strength indication in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.
 */
static inline uint8_t mavlink_msg_radio_status_get_rssi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field remrssi from radio_status message
 *
 * @return  Remote (message receiver) signal strength indication in device-dependent units/scale. Values: [0-254], 255: invalid/unknown.
 */
static inline uint8_t mavlink_msg_radio_status_get_remrssi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field txbuf from radio_status message
 *
 * @return [%] Remaining free transmitter buffer space.
 */
static inline uint8_t mavlink_msg_radio_status_get_txbuf(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field noise from radio_status message
 *
 * @return  Local background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], 255: invalid/unknown.
 */
static inline uint8_t mavlink_msg_radio_status_get_noise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field remnoise from radio_status message
 *
 * @return  Remote background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], 255: invalid/unknown.
 */
static inline uint8_t mavlink_msg_radio_status_get_remnoise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field rxerrors from radio_status message
 *
 * @return  Count of radio packet receive errors (since boot).
 */
static inline uint16_t mavlink_msg_radio_status_get_rxerrors(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field fixed from radio_status message
 *
 * @return  Count of error corrected radio packets (since boot).
 */
static inline uint16_t mavlink_msg_radio_status_get_fixed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Decode a radio_status message into a struct
 *
 * @param msg The message to decode
 * @param radio_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_radio_status_decode(const mavlink_message_t* msg, mavlink_radio_status_t* radio_status)
{
    radio_status->rxerrors = mavlink_msg_radio_status_get_rxerrors(msg);
    radio_status->fixed = mavlink_msg_radio_status_get_fixed(msg);
    radio_status->rssi = mavlink_msg_radio_status_get_rssi(msg);
    radio_status->remrssi = mavlink_msg_radio_status_get_remrssi(msg);
    radio_status->txbuf = mavlink_msg_radio_status_get_txbuf(msg);
    radio_status->noise = mavlink_msg_radio_status_get_noise(msg);
    radio_status->remnoise = mavlink_msg_radio_status_get_remnoise(msg);
}
