#pragma once
// MESSAGE WIFI_CONFIG_AP PACKING

#define MAVLINK_MSG_ID_WIFI_CONFIG_AP 299

typedef struct __mavlink_wifi_config_ap_t {
 char ssid[32]; /*<  Name of Wi-Fi network (SSID). Blank to leave it unchanged when setting. Current SSID when sent back as a response.*/
 char password[64]; /*<  Password. Blank for an open AP. MD5 hash when message is sent back as a response.*/
 int8_t mode; /*<  WiFi Mode.*/
 int8_t response; /*<  Message acceptance response (sent back to GS).*/
} mavlink_wifi_config_ap_t;

#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN 98
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_MIN_LEN 96
#define MAVLINK_MSG_ID_299_LEN 98
#define MAVLINK_MSG_ID_299_MIN_LEN 96

#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC 19
#define MAVLINK_MSG_ID_299_CRC 19

#define MAVLINK_MSG_WIFI_CONFIG_AP_FIELD_SSID_LEN 32
#define MAVLINK_MSG_WIFI_CONFIG_AP_FIELD_PASSWORD_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIFI_CONFIG_AP { \
    299, \
    "WIFI_CONFIG_AP", \
    4, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_config_ap_t, ssid) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 64, 32, offsetof(mavlink_wifi_config_ap_t, password) }, \
         { "mode", NULL, MAVLINK_TYPE_INT8_T, 0, 96, offsetof(mavlink_wifi_config_ap_t, mode) }, \
         { "response", NULL, MAVLINK_TYPE_INT8_T, 0, 97, offsetof(mavlink_wifi_config_ap_t, response) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIFI_CONFIG_AP { \
    "WIFI_CONFIG_AP", \
    4, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_config_ap_t, ssid) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 64, 32, offsetof(mavlink_wifi_config_ap_t, password) }, \
         { "mode", NULL, MAVLINK_TYPE_INT8_T, 0, 96, offsetof(mavlink_wifi_config_ap_t, mode) }, \
         { "response", NULL, MAVLINK_TYPE_INT8_T, 0, 97, offsetof(mavlink_wifi_config_ap_t, response) }, \
         } \
}
#endif

/**
 * @brief Pack a wifi_config_ap message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ssid  Name of Wi-Fi network (SSID). Blank to leave it unchanged when setting. Current SSID when sent back as a response.
 * @param password  Password. Blank for an open AP. MD5 hash when message is sent back as a response.
 * @param mode  WiFi Mode.
 * @param response  Message acceptance response (sent back to GS).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_config_ap_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *ssid, const char *password, int8_t mode, int8_t response)
{
    _mav_put_int8_t(msg->payloads, 96, mode);
    _mav_put_int8_t(msg->payloads, 97, response);
    _mav_put_char_array(msg->payloads, 0, ssid, 32);
    _mav_put_char_array(msg->payloads, 32, password, 64);
    msg->msgid = MAVLINK_MSG_ID_WIFI_CONFIG_AP;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIFI_CONFIG_AP_MIN_LEN, MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN, MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC);
}

/**
 * @brief Pack a wifi_config_ap message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ssid  Name of Wi-Fi network (SSID). Blank to leave it unchanged when setting. Current SSID when sent back as a response.
 * @param password  Password. Blank for an open AP. MD5 hash when message is sent back as a response.
 * @param mode  WiFi Mode.
 * @param response  Message acceptance response (sent back to GS).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_config_ap_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *ssid,const char *password,int8_t mode,int8_t response)
{
    _mav_put_int8_t(msg->payloads, 96, mode);
    _mav_put_int8_t(msg->payloads, 97, response);
    _mav_put_char_array(msg->payloads, 0, ssid, 32);
    _mav_put_char_array(msg->payloads, 32, password, 64);

    msg->msgid = MAVLINK_MSG_ID_WIFI_CONFIG_AP;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIFI_CONFIG_AP_MIN_LEN, MAVLINK_MSG_ID_WIFI_CONFIG_AP_LEN, MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC);
}

/**
 * @brief Encode a wifi_config_ap struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wifi_config_ap C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_config_ap_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wifi_config_ap_t* wifi_config_ap)
{
    return mavlink_msg_wifi_config_ap_pack(system_id, component_id, msg, wifi_config_ap->ssid, wifi_config_ap->password, wifi_config_ap->mode, wifi_config_ap->response);
}

/**
 * @brief Encode a wifi_config_ap struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wifi_config_ap C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_config_ap_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wifi_config_ap_t* wifi_config_ap)
{
    return mavlink_msg_wifi_config_ap_pack_chan(system_id, component_id, chan, msg, wifi_config_ap->ssid, wifi_config_ap->password, wifi_config_ap->mode, wifi_config_ap->response);
}

// MESSAGE WIFI_CONFIG_AP UNPACKING


/**
 * @brief Get field ssid from wifi_config_ap message
 *
 * @return  Name of Wi-Fi network (SSID). Blank to leave it unchanged when setting. Current SSID when sent back as a response.
 */
static inline uint16_t mavlink_msg_wifi_config_ap_get_ssid(const mavlink_message_t* msg, char *ssid)
{
    return _MAV_RETURN_char_array(msg, ssid, 32,  0);
}

/**
 * @brief Get field password from wifi_config_ap message
 *
 * @return  Password. Blank for an open AP. MD5 hash when message is sent back as a response.
 */
static inline uint16_t mavlink_msg_wifi_config_ap_get_password(const mavlink_message_t* msg, char *password)
{
    return _MAV_RETURN_char_array(msg, password, 64,  32);
}

/**
 * @brief Get field mode from wifi_config_ap message
 *
 * @return  WiFi Mode.
 */
static inline int8_t mavlink_msg_wifi_config_ap_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  96);
}

/**
 * @brief Get field response from wifi_config_ap message
 *
 * @return  Message acceptance response (sent back to GS).
 */
static inline int8_t mavlink_msg_wifi_config_ap_get_response(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  97);
}

/**
 * @brief Decode a wifi_config_ap message into a struct
 *
 * @param msg The message to decode
 * @param wifi_config_ap C-struct to decode the message contents into
 */
static inline void mavlink_msg_wifi_config_ap_decode(const mavlink_message_t* msg, mavlink_wifi_config_ap_t* wifi_config_ap)
{
    mavlink_msg_wifi_config_ap_get_ssid(msg, wifi_config_ap->ssid);
    mavlink_msg_wifi_config_ap_get_password(msg, wifi_config_ap->password);
    wifi_config_ap->mode = mavlink_msg_wifi_config_ap_get_mode(msg);
    wifi_config_ap->response = mavlink_msg_wifi_config_ap_get_response(msg);
}