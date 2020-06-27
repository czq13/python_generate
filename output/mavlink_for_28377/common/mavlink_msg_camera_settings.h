#pragma once
// MESSAGE CAMERA_SETTINGS PACKING

#define MAVLINK_MSG_ID_CAMERA_SETTINGS 260

typedef struct __mavlink_camera_settings_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 uint8_t mode_id; /*<  Camera mode*/
 float zoomLevel; /*<  Current zoom level (0.0 to 100.0, NaN if not known)*/
 float focusLevel; /*<  Current focus level (0.0 to 100.0, NaN if not known)*/
} mavlink_camera_settings_t;

#define MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN 13
#define MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN 5
#define MAVLINK_MSG_ID_260_LEN 13
#define MAVLINK_MSG_ID_260_MIN_LEN 5

#define MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC 146
#define MAVLINK_MSG_ID_260_CRC 146



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CAMERA_SETTINGS { \
    260, \
    "CAMERA_SETTINGS", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_camera_settings_t, time_boot_ms) }, \
         { "mode_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_camera_settings_t, mode_id) }, \
         { "zoomLevel", NULL, MAVLINK_TYPE_FLOAT, 0, 5, offsetof(mavlink_camera_settings_t, zoomLevel) }, \
         { "focusLevel", NULL, MAVLINK_TYPE_FLOAT, 0, 9, offsetof(mavlink_camera_settings_t, focusLevel) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CAMERA_SETTINGS { \
    "CAMERA_SETTINGS", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_camera_settings_t, time_boot_ms) }, \
         { "mode_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_camera_settings_t, mode_id) }, \
         { "zoomLevel", NULL, MAVLINK_TYPE_FLOAT, 0, 5, offsetof(mavlink_camera_settings_t, zoomLevel) }, \
         { "focusLevel", NULL, MAVLINK_TYPE_FLOAT, 0, 9, offsetof(mavlink_camera_settings_t, focusLevel) }, \
         } \
}
#endif

/**
 * @brief Pack a camera_settings message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param mode_id  Camera mode
 * @param zoomLevel  Current zoom level (0.0 to 100.0, NaN if not known)
 * @param focusLevel  Current focus level (0.0 to 100.0, NaN if not known)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_camera_settings_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t mode_id, float zoomLevel, float focusLevel)
{
    _mav_put_uint32_t(msg->payloads, 0, time_boot_ms);
    _mav_put_uint8_t(msg->payloads, 4, mode_id);
    _mav_put_float(msg->payloads, 5, zoomLevel);
    _mav_put_float(msg->payloads, 9, focusLevel);

    msg->msgid = MAVLINK_MSG_ID_CAMERA_SETTINGS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC);
}

/**
 * @brief Pack a camera_settings message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param mode_id  Camera mode
 * @param zoomLevel  Current zoom level (0.0 to 100.0, NaN if not known)
 * @param focusLevel  Current focus level (0.0 to 100.0, NaN if not known)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_camera_settings_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t mode_id,float zoomLevel,float focusLevel)
{
    _mav_put_uint32_t(msg->payloads, 0, time_boot_ms);
    _mav_put_uint8_t(msg->payloads, 4, mode_id);
    _mav_put_float(msg->payloads, 5, zoomLevel);
    _mav_put_float(msg->payloads, 9, focusLevel);


    msg->msgid = MAVLINK_MSG_ID_CAMERA_SETTINGS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CAMERA_SETTINGS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_LEN, MAVLINK_MSG_ID_CAMERA_SETTINGS_CRC);
}

/**
 * @brief Encode a camera_settings struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param camera_settings C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_camera_settings_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_camera_settings_t* camera_settings)
{
    return mavlink_msg_camera_settings_pack(system_id, component_id, msg, camera_settings->time_boot_ms, camera_settings->mode_id, camera_settings->zoomLevel, camera_settings->focusLevel);
}

/**
 * @brief Encode a camera_settings struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param camera_settings C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_camera_settings_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_camera_settings_t* camera_settings)
{
    return mavlink_msg_camera_settings_pack_chan(system_id, component_id, chan, msg, camera_settings->time_boot_ms, camera_settings->mode_id, camera_settings->zoomLevel, camera_settings->focusLevel);
}

// MESSAGE CAMERA_SETTINGS UNPACKING


/**
 * @brief Get field time_boot_ms from camera_settings message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_camera_settings_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field mode_id from camera_settings message
 *
 * @return  Camera mode
 */
static inline uint8_t mavlink_msg_camera_settings_get_mode_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field zoomLevel from camera_settings message
 *
 * @return  Current zoom level (0.0 to 100.0, NaN if not known)
 */
static inline float mavlink_msg_camera_settings_get_zoomLevel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  5);
}

/**
 * @brief Get field focusLevel from camera_settings message
 *
 * @return  Current focus level (0.0 to 100.0, NaN if not known)
 */
static inline float mavlink_msg_camera_settings_get_focusLevel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  9);
}

/**
 * @brief Decode a camera_settings message into a struct
 *
 * @param msg The message to decode
 * @param camera_settings C-struct to decode the message contents into
 */
static inline void mavlink_msg_camera_settings_decode(const mavlink_message_t* msg, mavlink_camera_settings_t* camera_settings)
{
    camera_settings->time_boot_ms = mavlink_msg_camera_settings_get_time_boot_ms(msg);
    camera_settings->mode_id = mavlink_msg_camera_settings_get_mode_id(msg);
    camera_settings->zoomLevel = mavlink_msg_camera_settings_get_zoomLevel(msg);
    camera_settings->focusLevel = mavlink_msg_camera_settings_get_focusLevel(msg);
}
