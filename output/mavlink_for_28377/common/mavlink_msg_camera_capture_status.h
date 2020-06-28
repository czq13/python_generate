#ifndef MAVLINK_MSG_camera_capture_status
#define MAVLINK_MSG_camera_capture_status
// MESSAGE CAMERA_CAPTURE_STATUS PACKING

#define MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS 262

typedef struct __mavlink_camera_capture_status_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float image_interval; /*< [s] Image capture interval*/
 uint32_t recording_time_ms; /*< [ms] Time since recording started*/
 float available_capacity; /*< [MiB] Available storage capacity.*/
 uint8_t image_status; /*<  Current status of image capturing (0: idle, 1: capture in progress, 2: interval set but idle, 3: interval set and capture in progress)*/
 uint8_t video_status; /*<  Current status of video capturing (0: idle, 1: capture in progress)*/
 int32_t image_count; /*<  Total number of images captured ('forever', or until reset using MAV_CMD_STORAGE_FORMAT).*/
} mavlink_camera_capture_status_t;

#define MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_LEN 22
#define MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_MIN_LEN 18
#define MAVLINK_MSG_ID_262_LEN 22
#define MAVLINK_MSG_ID_262_MIN_LEN 18

#define MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_CRC 12
#define MAVLINK_MSG_ID_262_CRC 12



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CAMERA_CAPTURE_STATUS { \
    262, \
    "CAMERA_CAPTURE_STATUS", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_camera_capture_status_t, time_boot_ms) }, \
         { "image_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_camera_capture_status_t, image_status) }, \
         { "video_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_camera_capture_status_t, video_status) }, \
         { "image_interval", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_camera_capture_status_t, image_interval) }, \
         { "recording_time_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_camera_capture_status_t, recording_time_ms) }, \
         { "available_capacity", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_camera_capture_status_t, available_capacity) }, \
         { "image_count", NULL, MAVLINK_TYPE_INT32_T, 0, 18, offsetof(mavlink_camera_capture_status_t, image_count) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CAMERA_CAPTURE_STATUS { \
    "CAMERA_CAPTURE_STATUS", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_camera_capture_status_t, time_boot_ms) }, \
         { "image_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_camera_capture_status_t, image_status) }, \
         { "video_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_camera_capture_status_t, video_status) }, \
         { "image_interval", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_camera_capture_status_t, image_interval) }, \
         { "recording_time_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_camera_capture_status_t, recording_time_ms) }, \
         { "available_capacity", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_camera_capture_status_t, available_capacity) }, \
         { "image_count", NULL, MAVLINK_TYPE_INT32_T, 0, 18, offsetof(mavlink_camera_capture_status_t, image_count) }, \
         } \
}
#endif

/**
 * @brief Pack a camera_capture_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param image_status  Current status of image capturing (0: idle, 1: capture in progress, 2: interval set but idle, 3: interval set and capture in progress)
 * @param video_status  Current status of video capturing (0: idle, 1: capture in progress)
 * @param image_interval [s] Image capture interval
 * @param recording_time_ms [ms] Time since recording started
 * @param available_capacity [MiB] Available storage capacity.
 * @param image_count  Total number of images captured ('forever', or until reset using MAV_CMD_STORAGE_FORMAT).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_camera_capture_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t image_status, uint8_t video_status, float image_interval, uint32_t recording_time_ms, float available_capacity, int32_t image_count)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_float(((char*)msg->payloads), 4, image_interval);
    _mav_put_uint32_t(((char*)msg->payloads), 8, recording_time_ms);
    _mav_put_float(((char*)msg->payloads), 12, available_capacity);
    _mav_put_uint8_t(((char*)msg->payloads), 16, image_status);
    _mav_put_uint8_t(((char*)msg->payloads), 17, video_status);
    _mav_put_int32_t(((char*)msg->payloads), 18, image_count);

    msg->msgid = MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_LEN, MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_CRC);
}

/**
 * @brief Pack a camera_capture_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param image_status  Current status of image capturing (0: idle, 1: capture in progress, 2: interval set but idle, 3: interval set and capture in progress)
 * @param video_status  Current status of video capturing (0: idle, 1: capture in progress)
 * @param image_interval [s] Image capture interval
 * @param recording_time_ms [ms] Time since recording started
 * @param available_capacity [MiB] Available storage capacity.
 * @param image_count  Total number of images captured ('forever', or until reset using MAV_CMD_STORAGE_FORMAT).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_camera_capture_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t image_status,uint8_t video_status,float image_interval,uint32_t recording_time_ms,float available_capacity,int32_t image_count)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_float(((char*)msg->payloads), 4, image_interval);
    _mav_put_uint32_t(((char*)msg->payloads), 8, recording_time_ms);
    _mav_put_float(((char*)msg->payloads), 12, available_capacity);
    _mav_put_uint8_t(((char*)msg->payloads), 16, image_status);
    _mav_put_uint8_t(((char*)msg->payloads), 17, video_status);
    _mav_put_int32_t(((char*)msg->payloads), 18, image_count);


    msg->msgid = MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_MIN_LEN, MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_LEN, MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS_CRC);
}

/**
 * @brief Encode a camera_capture_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param camera_capture_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_camera_capture_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_camera_capture_status_t* camera_capture_status)
{
    return mavlink_msg_camera_capture_status_pack(system_id, component_id, msg, camera_capture_status->time_boot_ms, camera_capture_status->image_status, camera_capture_status->video_status, camera_capture_status->image_interval, camera_capture_status->recording_time_ms, camera_capture_status->available_capacity, camera_capture_status->image_count);
}

/**
 * @brief Encode a camera_capture_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param camera_capture_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_camera_capture_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_camera_capture_status_t* camera_capture_status)
{
    return mavlink_msg_camera_capture_status_pack_chan(system_id, component_id, chan, msg, camera_capture_status->time_boot_ms, camera_capture_status->image_status, camera_capture_status->video_status, camera_capture_status->image_interval, camera_capture_status->recording_time_ms, camera_capture_status->available_capacity, camera_capture_status->image_count);
}

// MESSAGE CAMERA_CAPTURE_STATUS UNPACKING


/**
 * @brief Get field time_boot_ms from camera_capture_status message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_camera_capture_status_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field image_status from camera_capture_status message
 *
 * @return  Current status of image capturing (0: idle, 1: capture in progress, 2: interval set but idle, 3: interval set and capture in progress)
 */
static inline uint8_t mavlink_msg_camera_capture_status_get_image_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field video_status from camera_capture_status message
 *
 * @return  Current status of video capturing (0: idle, 1: capture in progress)
 */
static inline uint8_t mavlink_msg_camera_capture_status_get_video_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field image_interval from camera_capture_status message
 *
 * @return [s] Image capture interval
 */
static inline float mavlink_msg_camera_capture_status_get_image_interval(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field recording_time_ms from camera_capture_status message
 *
 * @return [ms] Time since recording started
 */
static inline uint32_t mavlink_msg_camera_capture_status_get_recording_time_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field available_capacity from camera_capture_status message
 *
 * @return [MiB] Available storage capacity.
 */
static inline float mavlink_msg_camera_capture_status_get_available_capacity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field image_count from camera_capture_status message
 *
 * @return  Total number of images captured ('forever', or until reset using MAV_CMD_STORAGE_FORMAT).
 */
static inline int32_t mavlink_msg_camera_capture_status_get_image_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  18);
}

/**
 * @brief Decode a camera_capture_status message into a struct
 *
 * @param msg The message to decode
 * @param camera_capture_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_camera_capture_status_decode(const mavlink_message_t* msg, mavlink_camera_capture_status_t* camera_capture_status)
{
    camera_capture_status->time_boot_ms = mavlink_msg_camera_capture_status_get_time_boot_ms(msg);
    camera_capture_status->image_interval = mavlink_msg_camera_capture_status_get_image_interval(msg);
    camera_capture_status->recording_time_ms = mavlink_msg_camera_capture_status_get_recording_time_ms(msg);
    camera_capture_status->available_capacity = mavlink_msg_camera_capture_status_get_available_capacity(msg);
    camera_capture_status->image_status = mavlink_msg_camera_capture_status_get_image_status(msg);
    camera_capture_status->video_status = mavlink_msg_camera_capture_status_get_video_status(msg);
    camera_capture_status->image_count = mavlink_msg_camera_capture_status_get_image_count(msg);
}
#endif
