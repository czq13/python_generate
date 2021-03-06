#ifndef MAVLINK_MSG_gimbal_device_information
#define MAVLINK_MSG_gimbal_device_information
// MESSAGE GIMBAL_DEVICE_INFORMATION PACKING

#define MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION 283

typedef struct __mavlink_gimbal_device_information_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 uint32_t firmware_version; /*<  Version of the gimbal firmware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff)*/
 float tilt_max; /*< [rad] Maximum tilt/pitch angle (positive: up, negative: down)*/
 float tilt_min; /*< [rad] Minimum tilt/pitch angle (positive: up, negative: down)*/
 float tilt_rate_max; /*< [rad/s] Maximum tilt/pitch angular rate (positive: up, negative: down)*/
 float pan_max; /*< [rad] Maximum pan/yaw angle (positive: to the right, negative: to the left)*/
 float pan_min; /*< [rad] Minimum pan/yaw angle (positive: to the right, negative: to the left)*/
 float pan_rate_max; /*< [rad/s] Minimum pan/yaw angular rate (positive: to the right, negative: to the left)*/
 uint16_t cap_flags; /*<  Bitmap of gimbal capability flags.*/
 uint8_t vendor_name[32]; /*<  Name of the gimbal vendor*/
 uint8_t model_name[32]; /*<  Name of the gimbal model*/
} mavlink_gimbal_device_information_t;

#define MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION_LEN 98
#define MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION_MIN_LEN 98
#define MAVLINK_MSG_ID_283_LEN 98
#define MAVLINK_MSG_ID_283_MIN_LEN 98

#define MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION_CRC 247
#define MAVLINK_MSG_ID_283_CRC 247

#define MAVLINK_MSG_GIMBAL_DEVICE_INFORMATION_FIELD_VENDOR_NAME_LEN 32
#define MAVLINK_MSG_GIMBAL_DEVICE_INFORMATION_FIELD_MODEL_NAME_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GIMBAL_DEVICE_INFORMATION { \
    283, \
    "GIMBAL_DEVICE_INFORMATION", \
    11, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gimbal_device_information_t, time_boot_ms) }, \
         { "vendor_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 34, offsetof(mavlink_gimbal_device_information_t, vendor_name) }, \
         { "model_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 66, offsetof(mavlink_gimbal_device_information_t, model_name) }, \
         { "firmware_version", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_gimbal_device_information_t, firmware_version) }, \
         { "cap_flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_gimbal_device_information_t, cap_flags) }, \
         { "tilt_max", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gimbal_device_information_t, tilt_max) }, \
         { "tilt_min", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gimbal_device_information_t, tilt_min) }, \
         { "tilt_rate_max", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gimbal_device_information_t, tilt_rate_max) }, \
         { "pan_max", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gimbal_device_information_t, pan_max) }, \
         { "pan_min", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_gimbal_device_information_t, pan_min) }, \
         { "pan_rate_max", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_gimbal_device_information_t, pan_rate_max) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GIMBAL_DEVICE_INFORMATION { \
    "GIMBAL_DEVICE_INFORMATION", \
    11, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gimbal_device_information_t, time_boot_ms) }, \
         { "vendor_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 34, offsetof(mavlink_gimbal_device_information_t, vendor_name) }, \
         { "model_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 66, offsetof(mavlink_gimbal_device_information_t, model_name) }, \
         { "firmware_version", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_gimbal_device_information_t, firmware_version) }, \
         { "cap_flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_gimbal_device_information_t, cap_flags) }, \
         { "tilt_max", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gimbal_device_information_t, tilt_max) }, \
         { "tilt_min", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gimbal_device_information_t, tilt_min) }, \
         { "tilt_rate_max", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gimbal_device_information_t, tilt_rate_max) }, \
         { "pan_max", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gimbal_device_information_t, pan_max) }, \
         { "pan_min", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_gimbal_device_information_t, pan_min) }, \
         { "pan_rate_max", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_gimbal_device_information_t, pan_rate_max) }, \
         } \
}
#endif

/**
 * @brief Pack a gimbal_device_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param vendor_name  Name of the gimbal vendor
 * @param model_name  Name of the gimbal model
 * @param firmware_version  Version of the gimbal firmware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff)
 * @param cap_flags  Bitmap of gimbal capability flags.
 * @param tilt_max [rad] Maximum tilt/pitch angle (positive: up, negative: down)
 * @param tilt_min [rad] Minimum tilt/pitch angle (positive: up, negative: down)
 * @param tilt_rate_max [rad/s] Maximum tilt/pitch angular rate (positive: up, negative: down)
 * @param pan_max [rad] Maximum pan/yaw angle (positive: to the right, negative: to the left)
 * @param pan_min [rad] Minimum pan/yaw angle (positive: to the right, negative: to the left)
 * @param pan_rate_max [rad/s] Minimum pan/yaw angular rate (positive: to the right, negative: to the left)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gimbal_device_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, const uint8_t *vendor_name, const uint8_t *model_name, uint32_t firmware_version, uint16_t cap_flags, float tilt_max, float tilt_min, float tilt_rate_max, float pan_max, float pan_min, float pan_rate_max)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_uint32_t(((char*)msg->payloads), 4, firmware_version);
    _mav_put_float(((char*)msg->payloads), 8, tilt_max);
    _mav_put_float(((char*)msg->payloads), 12, tilt_min);
    _mav_put_float(((char*)msg->payloads), 16, tilt_rate_max);
    _mav_put_float(((char*)msg->payloads), 20, pan_max);
    _mav_put_float(((char*)msg->payloads), 24, pan_min);
    _mav_put_float(((char*)msg->payloads), 28, pan_rate_max);
    _mav_put_uint16_t(((char*)msg->payloads), 32, cap_flags);
    _mav_put_uint8_t_array(((char*)msg->payloads), 34, vendor_name, 32);
    _mav_put_uint8_t_array(((char*)msg->payloads), 66, model_name, 32);
    msg->msgid = MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION_LEN, MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION_CRC);
}

/**
 * @brief Pack a gimbal_device_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param vendor_name  Name of the gimbal vendor
 * @param model_name  Name of the gimbal model
 * @param firmware_version  Version of the gimbal firmware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff)
 * @param cap_flags  Bitmap of gimbal capability flags.
 * @param tilt_max [rad] Maximum tilt/pitch angle (positive: up, negative: down)
 * @param tilt_min [rad] Minimum tilt/pitch angle (positive: up, negative: down)
 * @param tilt_rate_max [rad/s] Maximum tilt/pitch angular rate (positive: up, negative: down)
 * @param pan_max [rad] Maximum pan/yaw angle (positive: to the right, negative: to the left)
 * @param pan_min [rad] Minimum pan/yaw angle (positive: to the right, negative: to the left)
 * @param pan_rate_max [rad/s] Minimum pan/yaw angular rate (positive: to the right, negative: to the left)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gimbal_device_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,const uint8_t *vendor_name,const uint8_t *model_name,uint32_t firmware_version,uint16_t cap_flags,float tilt_max,float tilt_min,float tilt_rate_max,float pan_max,float pan_min,float pan_rate_max)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_uint32_t(((char*)msg->payloads), 4, firmware_version);
    _mav_put_float(((char*)msg->payloads), 8, tilt_max);
    _mav_put_float(((char*)msg->payloads), 12, tilt_min);
    _mav_put_float(((char*)msg->payloads), 16, tilt_rate_max);
    _mav_put_float(((char*)msg->payloads), 20, pan_max);
    _mav_put_float(((char*)msg->payloads), 24, pan_min);
    _mav_put_float(((char*)msg->payloads), 28, pan_rate_max);
    _mav_put_uint16_t(((char*)msg->payloads), 32, cap_flags);
    _mav_put_uint8_t_array(((char*)msg->payloads), 34, vendor_name, 32);
    _mav_put_uint8_t_array(((char*)msg->payloads), 66, model_name, 32);

    msg->msgid = MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION_LEN, MAVLINK_MSG_ID_GIMBAL_DEVICE_INFORMATION_CRC);
}

/**
 * @brief Encode a gimbal_device_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gimbal_device_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gimbal_device_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gimbal_device_information_t* gimbal_device_information)
{
    return mavlink_msg_gimbal_device_information_pack(system_id, component_id, msg, gimbal_device_information->time_boot_ms, gimbal_device_information->vendor_name, gimbal_device_information->model_name, gimbal_device_information->firmware_version, gimbal_device_information->cap_flags, gimbal_device_information->tilt_max, gimbal_device_information->tilt_min, gimbal_device_information->tilt_rate_max, gimbal_device_information->pan_max, gimbal_device_information->pan_min, gimbal_device_information->pan_rate_max);
}

/**
 * @brief Encode a gimbal_device_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gimbal_device_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gimbal_device_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gimbal_device_information_t* gimbal_device_information)
{
    return mavlink_msg_gimbal_device_information_pack_chan(system_id, component_id, chan, msg, gimbal_device_information->time_boot_ms, gimbal_device_information->vendor_name, gimbal_device_information->model_name, gimbal_device_information->firmware_version, gimbal_device_information->cap_flags, gimbal_device_information->tilt_max, gimbal_device_information->tilt_min, gimbal_device_information->tilt_rate_max, gimbal_device_information->pan_max, gimbal_device_information->pan_min, gimbal_device_information->pan_rate_max);
}

// MESSAGE GIMBAL_DEVICE_INFORMATION UNPACKING


/**
 * @brief Get field time_boot_ms from gimbal_device_information message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_gimbal_device_information_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field vendor_name from gimbal_device_information message
 *
 * @return  Name of the gimbal vendor
 */
static inline uint16_t mavlink_msg_gimbal_device_information_get_vendor_name(const mavlink_message_t* msg, uint8_t *vendor_name)
{
    return _MAV_RETURN_uint8_t_array(msg, vendor_name, 32,  34);
}

/**
 * @brief Get field model_name from gimbal_device_information message
 *
 * @return  Name of the gimbal model
 */
static inline uint16_t mavlink_msg_gimbal_device_information_get_model_name(const mavlink_message_t* msg, uint8_t *model_name)
{
    return _MAV_RETURN_uint8_t_array(msg, model_name, 32,  66);
}

/**
 * @brief Get field firmware_version from gimbal_device_information message
 *
 * @return  Version of the gimbal firmware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff)
 */
static inline uint32_t mavlink_msg_gimbal_device_information_get_firmware_version(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field cap_flags from gimbal_device_information message
 *
 * @return  Bitmap of gimbal capability flags.
 */
static inline uint16_t mavlink_msg_gimbal_device_information_get_cap_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field tilt_max from gimbal_device_information message
 *
 * @return [rad] Maximum tilt/pitch angle (positive: up, negative: down)
 */
static inline float mavlink_msg_gimbal_device_information_get_tilt_max(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field tilt_min from gimbal_device_information message
 *
 * @return [rad] Minimum tilt/pitch angle (positive: up, negative: down)
 */
static inline float mavlink_msg_gimbal_device_information_get_tilt_min(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field tilt_rate_max from gimbal_device_information message
 *
 * @return [rad/s] Maximum tilt/pitch angular rate (positive: up, negative: down)
 */
static inline float mavlink_msg_gimbal_device_information_get_tilt_rate_max(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pan_max from gimbal_device_information message
 *
 * @return [rad] Maximum pan/yaw angle (positive: to the right, negative: to the left)
 */
static inline float mavlink_msg_gimbal_device_information_get_pan_max(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field pan_min from gimbal_device_information message
 *
 * @return [rad] Minimum pan/yaw angle (positive: to the right, negative: to the left)
 */
static inline float mavlink_msg_gimbal_device_information_get_pan_min(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field pan_rate_max from gimbal_device_information message
 *
 * @return [rad/s] Minimum pan/yaw angular rate (positive: to the right, negative: to the left)
 */
static inline float mavlink_msg_gimbal_device_information_get_pan_rate_max(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a gimbal_device_information message into a struct
 *
 * @param msg The message to decode
 * @param gimbal_device_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_gimbal_device_information_decode(const mavlink_message_t* msg, mavlink_gimbal_device_information_t* gimbal_device_information)
{
    gimbal_device_information->time_boot_ms = mavlink_msg_gimbal_device_information_get_time_boot_ms(msg);
    gimbal_device_information->firmware_version = mavlink_msg_gimbal_device_information_get_firmware_version(msg);
    gimbal_device_information->tilt_max = mavlink_msg_gimbal_device_information_get_tilt_max(msg);
    gimbal_device_information->tilt_min = mavlink_msg_gimbal_device_information_get_tilt_min(msg);
    gimbal_device_information->tilt_rate_max = mavlink_msg_gimbal_device_information_get_tilt_rate_max(msg);
    gimbal_device_information->pan_max = mavlink_msg_gimbal_device_information_get_pan_max(msg);
    gimbal_device_information->pan_min = mavlink_msg_gimbal_device_information_get_pan_min(msg);
    gimbal_device_information->pan_rate_max = mavlink_msg_gimbal_device_information_get_pan_rate_max(msg);
    gimbal_device_information->cap_flags = mavlink_msg_gimbal_device_information_get_cap_flags(msg);
    mavlink_msg_gimbal_device_information_get_vendor_name(msg, gimbal_device_information->vendor_name);
    mavlink_msg_gimbal_device_information_get_model_name(msg, gimbal_device_information->model_name);
}
#endif
