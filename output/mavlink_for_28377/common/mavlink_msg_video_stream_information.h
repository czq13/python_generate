#ifndef MAVLINK_MSG_video_stream_information
#define MAVLINK_MSG_video_stream_information
// MESSAGE VIDEO_STREAM_INFORMATION PACKING

#define MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION 269

typedef struct __mavlink_video_stream_information_t {
 float framerate; /*< [Hz] Frame rate.*/
 uint32_t bitrate; /*< [bits/s] Bit rate.*/
 uint16_t flags; /*<  Bitmap of stream status flags.*/
 uint16_t resolution_h; /*< [pix] Horizontal resolution.*/
 uint16_t resolution_v; /*< [pix] Vertical resolution.*/
 uint16_t rotation; /*< [deg] Video image rotation clockwise.*/
 uint16_t hfov; /*< [deg] Horizontal Field of view.*/
 uint8_t stream_id; /*<  Video Stream ID (1 for first, 2 for second, etc.)*/
 uint8_t count; /*<  Number of streams available.*/
 uint8_t type; /*<  Type of stream.*/
 char name[32]; /*<  Stream name.*/
 char uri[160]; /*<  Video stream URI (TCP or RTSP URI ground station should connect to) or port number (UDP port ground station should listen to).*/
} mavlink_video_stream_information_t;

#define MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_LEN 213
#define MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_MIN_LEN 213
#define MAVLINK_MSG_ID_269_LEN 213
#define MAVLINK_MSG_ID_269_MIN_LEN 213

#define MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_CRC 109
#define MAVLINK_MSG_ID_269_CRC 109

#define MAVLINK_MSG_VIDEO_STREAM_INFORMATION_FIELD_NAME_LEN 32
#define MAVLINK_MSG_VIDEO_STREAM_INFORMATION_FIELD_URI_LEN 160

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_INFORMATION { \
    269, \
    "VIDEO_STREAM_INFORMATION", \
    12, \
    {  { "stream_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_video_stream_information_t, stream_id) }, \
         { "count", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_video_stream_information_t, count) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_video_stream_information_t, type) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_video_stream_information_t, flags) }, \
         { "framerate", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_video_stream_information_t, framerate) }, \
         { "resolution_h", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_video_stream_information_t, resolution_h) }, \
         { "resolution_v", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_video_stream_information_t, resolution_v) }, \
         { "bitrate", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_video_stream_information_t, bitrate) }, \
         { "rotation", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_video_stream_information_t, rotation) }, \
         { "hfov", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_video_stream_information_t, hfov) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 32, 21, offsetof(mavlink_video_stream_information_t, name) }, \
         { "uri", NULL, MAVLINK_TYPE_CHAR, 160, 53, offsetof(mavlink_video_stream_information_t, uri) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_INFORMATION { \
    "VIDEO_STREAM_INFORMATION", \
    12, \
    {  { "stream_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_video_stream_information_t, stream_id) }, \
         { "count", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_video_stream_information_t, count) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_video_stream_information_t, type) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_video_stream_information_t, flags) }, \
         { "framerate", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_video_stream_information_t, framerate) }, \
         { "resolution_h", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_video_stream_information_t, resolution_h) }, \
         { "resolution_v", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_video_stream_information_t, resolution_v) }, \
         { "bitrate", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_video_stream_information_t, bitrate) }, \
         { "rotation", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_video_stream_information_t, rotation) }, \
         { "hfov", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_video_stream_information_t, hfov) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 32, 21, offsetof(mavlink_video_stream_information_t, name) }, \
         { "uri", NULL, MAVLINK_TYPE_CHAR, 160, 53, offsetof(mavlink_video_stream_information_t, uri) }, \
         } \
}
#endif

/**
 * @brief Pack a video_stream_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param stream_id  Video Stream ID (1 for first, 2 for second, etc.)
 * @param count  Number of streams available.
 * @param type  Type of stream.
 * @param flags  Bitmap of stream status flags.
 * @param framerate [Hz] Frame rate.
 * @param resolution_h [pix] Horizontal resolution.
 * @param resolution_v [pix] Vertical resolution.
 * @param bitrate [bits/s] Bit rate.
 * @param rotation [deg] Video image rotation clockwise.
 * @param hfov [deg] Horizontal Field of view.
 * @param name  Stream name.
 * @param uri  Video stream URI (TCP or RTSP URI ground station should connect to) or port number (UDP port ground station should listen to).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t stream_id, uint8_t count, uint8_t type, uint16_t flags, float framerate, uint16_t resolution_h, uint16_t resolution_v, uint32_t bitrate, uint16_t rotation, uint16_t hfov, const char *name, const char *uri)
{
    _mav_put_float(((char*)msg->payloads), 0, framerate);
    _mav_put_uint32_t(((char*)msg->payloads), 4, bitrate);
    _mav_put_uint16_t(((char*)msg->payloads), 8, flags);
    _mav_put_uint16_t(((char*)msg->payloads), 10, resolution_h);
    _mav_put_uint16_t(((char*)msg->payloads), 12, resolution_v);
    _mav_put_uint16_t(((char*)msg->payloads), 14, rotation);
    _mav_put_uint16_t(((char*)msg->payloads), 16, hfov);
    _mav_put_uint8_t(((char*)msg->payloads), 18, stream_id);
    _mav_put_uint8_t(((char*)msg->payloads), 19, count);
    _mav_put_uint8_t(((char*)msg->payloads), 20, type);
    _mav_put_char_array(((char*)msg->payloads), 21, name, 32);
    _mav_put_char_array(((char*)msg->payloads), 53, uri, 160);
    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_CRC);
}

/**
 * @brief Pack a video_stream_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param stream_id  Video Stream ID (1 for first, 2 for second, etc.)
 * @param count  Number of streams available.
 * @param type  Type of stream.
 * @param flags  Bitmap of stream status flags.
 * @param framerate [Hz] Frame rate.
 * @param resolution_h [pix] Horizontal resolution.
 * @param resolution_v [pix] Vertical resolution.
 * @param bitrate [bits/s] Bit rate.
 * @param rotation [deg] Video image rotation clockwise.
 * @param hfov [deg] Horizontal Field of view.
 * @param name  Stream name.
 * @param uri  Video stream URI (TCP or RTSP URI ground station should connect to) or port number (UDP port ground station should listen to).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t stream_id,uint8_t count,uint8_t type,uint16_t flags,float framerate,uint16_t resolution_h,uint16_t resolution_v,uint32_t bitrate,uint16_t rotation,uint16_t hfov,const char *name,const char *uri)
{
    _mav_put_float(((char*)msg->payloads), 0, framerate);
    _mav_put_uint32_t(((char*)msg->payloads), 4, bitrate);
    _mav_put_uint16_t(((char*)msg->payloads), 8, flags);
    _mav_put_uint16_t(((char*)msg->payloads), 10, resolution_h);
    _mav_put_uint16_t(((char*)msg->payloads), 12, resolution_v);
    _mav_put_uint16_t(((char*)msg->payloads), 14, rotation);
    _mav_put_uint16_t(((char*)msg->payloads), 16, hfov);
    _mav_put_uint8_t(((char*)msg->payloads), 18, stream_id);
    _mav_put_uint8_t(((char*)msg->payloads), 19, count);
    _mav_put_uint8_t(((char*)msg->payloads), 20, type);
    _mav_put_char_array(((char*)msg->payloads), 21, name, 32);
    _mav_put_char_array(((char*)msg->payloads), 53, uri, 160);

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION_CRC);
}

/**
 * @brief Encode a video_stream_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_video_stream_information_t* video_stream_information)
{
    return mavlink_msg_video_stream_information_pack(system_id, component_id, msg, video_stream_information->stream_id, video_stream_information->count, video_stream_information->type, video_stream_information->flags, video_stream_information->framerate, video_stream_information->resolution_h, video_stream_information->resolution_v, video_stream_information->bitrate, video_stream_information->rotation, video_stream_information->hfov, video_stream_information->name, video_stream_information->uri);
}

/**
 * @brief Encode a video_stream_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_video_stream_information_t* video_stream_information)
{
    return mavlink_msg_video_stream_information_pack_chan(system_id, component_id, chan, msg, video_stream_information->stream_id, video_stream_information->count, video_stream_information->type, video_stream_information->flags, video_stream_information->framerate, video_stream_information->resolution_h, video_stream_information->resolution_v, video_stream_information->bitrate, video_stream_information->rotation, video_stream_information->hfov, video_stream_information->name, video_stream_information->uri);
}

// MESSAGE VIDEO_STREAM_INFORMATION UNPACKING


/**
 * @brief Get field stream_id from video_stream_information message
 *
 * @return  Video Stream ID (1 for first, 2 for second, etc.)
 */
static inline uint8_t mavlink_msg_video_stream_information_get_stream_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field count from video_stream_information message
 *
 * @return  Number of streams available.
 */
static inline uint8_t mavlink_msg_video_stream_information_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field type from video_stream_information message
 *
 * @return  Type of stream.
 */
static inline uint8_t mavlink_msg_video_stream_information_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field flags from video_stream_information message
 *
 * @return  Bitmap of stream status flags.
 */
static inline uint16_t mavlink_msg_video_stream_information_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field framerate from video_stream_information message
 *
 * @return [Hz] Frame rate.
 */
static inline float mavlink_msg_video_stream_information_get_framerate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field resolution_h from video_stream_information message
 *
 * @return [pix] Horizontal resolution.
 */
static inline uint16_t mavlink_msg_video_stream_information_get_resolution_h(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field resolution_v from video_stream_information message
 *
 * @return [pix] Vertical resolution.
 */
static inline uint16_t mavlink_msg_video_stream_information_get_resolution_v(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field bitrate from video_stream_information message
 *
 * @return [bits/s] Bit rate.
 */
static inline uint32_t mavlink_msg_video_stream_information_get_bitrate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field rotation from video_stream_information message
 *
 * @return [deg] Video image rotation clockwise.
 */
static inline uint16_t mavlink_msg_video_stream_information_get_rotation(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field hfov from video_stream_information message
 *
 * @return [deg] Horizontal Field of view.
 */
static inline uint16_t mavlink_msg_video_stream_information_get_hfov(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field name from video_stream_information message
 *
 * @return  Stream name.
 */
static inline uint16_t mavlink_msg_video_stream_information_get_name(const mavlink_message_t* msg, char *name)
{
    return _MAV_RETURN_char_array(msg, name, 32,  21);
}

/**
 * @brief Get field uri from video_stream_information message
 *
 * @return  Video stream URI (TCP or RTSP URI ground station should connect to) or port number (UDP port ground station should listen to).
 */
static inline uint16_t mavlink_msg_video_stream_information_get_uri(const mavlink_message_t* msg, char *uri)
{
    return _MAV_RETURN_char_array(msg, uri, 160,  53);
}

/**
 * @brief Decode a video_stream_information message into a struct
 *
 * @param msg The message to decode
 * @param video_stream_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_video_stream_information_decode(const mavlink_message_t* msg, mavlink_video_stream_information_t* video_stream_information)
{
    video_stream_information->framerate = mavlink_msg_video_stream_information_get_framerate(msg);
    video_stream_information->bitrate = mavlink_msg_video_stream_information_get_bitrate(msg);
    video_stream_information->flags = mavlink_msg_video_stream_information_get_flags(msg);
    video_stream_information->resolution_h = mavlink_msg_video_stream_information_get_resolution_h(msg);
    video_stream_information->resolution_v = mavlink_msg_video_stream_information_get_resolution_v(msg);
    video_stream_information->rotation = mavlink_msg_video_stream_information_get_rotation(msg);
    video_stream_information->hfov = mavlink_msg_video_stream_information_get_hfov(msg);
    video_stream_information->stream_id = mavlink_msg_video_stream_information_get_stream_id(msg);
    video_stream_information->count = mavlink_msg_video_stream_information_get_count(msg);
    video_stream_information->type = mavlink_msg_video_stream_information_get_type(msg);
    mavlink_msg_video_stream_information_get_name(msg, video_stream_information->name);
    mavlink_msg_video_stream_information_get_uri(msg, video_stream_information->uri);
}
#endif
