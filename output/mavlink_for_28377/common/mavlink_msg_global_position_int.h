#ifndef MAVLINK_MSG_global_position_int
#define MAVLINK_MSG_global_position_int
// MESSAGE GLOBAL_POSITION_INT PACKING

#define MAVLINK_MSG_ID_GLOBAL_POSITION_INT 33

typedef struct __mavlink_global_position_int_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 int32_t lat; /*< [degE7] Latitude, expressed*/
 int32_t lon; /*< [degE7] Longitude, expressed*/
 int32_t alt; /*< [mm] Altitude (MSL). Note that virtually all GPS modules provide both WGS84 and MSL.*/
 int32_t relative_alt; /*< [mm] Altitude above ground*/
 int16_t vx; /*< [cm/s] Ground X Speed (Latitude, positive north)*/
 int16_t vy; /*< [cm/s] Ground Y Speed (Longitude, positive east)*/
 int16_t vz; /*< [cm/s] Ground Z Speed (Altitude, positive down)*/
 uint16_t hdg; /*< [cdeg] Vehicle heading (yaw angle), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX*/
} mavlink_global_position_int_t;

#define MAVLINK_MSG_ID_GLOBAL_POSITION_INT_LEN 28
#define MAVLINK_MSG_ID_GLOBAL_POSITION_INT_MIN_LEN 28
#define MAVLINK_MSG_ID_33_LEN 28
#define MAVLINK_MSG_ID_33_MIN_LEN 28

#define MAVLINK_MSG_ID_GLOBAL_POSITION_INT_CRC 104
#define MAVLINK_MSG_ID_33_CRC 104



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GLOBAL_POSITION_INT { \
    33, \
    "GLOBAL_POSITION_INT", \
    9, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_global_position_int_t, time_boot_ms) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_global_position_int_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_global_position_int_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_global_position_int_t, alt) }, \
         { "relative_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_global_position_int_t, relative_alt) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_global_position_int_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_global_position_int_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_global_position_int_t, vz) }, \
         { "hdg", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_global_position_int_t, hdg) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GLOBAL_POSITION_INT { \
    "GLOBAL_POSITION_INT", \
    9, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_global_position_int_t, time_boot_ms) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_global_position_int_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_global_position_int_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_global_position_int_t, alt) }, \
         { "relative_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_global_position_int_t, relative_alt) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_global_position_int_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_global_position_int_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_global_position_int_t, vz) }, \
         { "hdg", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_global_position_int_t, hdg) }, \
         } \
}
#endif

/**
 * @brief Pack a global_position_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param lat [degE7] Latitude, expressed
 * @param lon [degE7] Longitude, expressed
 * @param alt [mm] Altitude (MSL). Note that virtually all GPS modules provide both WGS84 and MSL.
 * @param relative_alt [mm] Altitude above ground
 * @param vx [cm/s] Ground X Speed (Latitude, positive north)
 * @param vy [cm/s] Ground Y Speed (Longitude, positive east)
 * @param vz [cm/s] Ground Z Speed (Altitude, positive down)
 * @param hdg [cdeg] Vehicle heading (yaw angle), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_global_position_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, int32_t lat, int32_t lon, int32_t alt, int32_t relative_alt, int16_t vx, int16_t vy, int16_t vz, uint16_t hdg)
{
    _mav_put_uint32_t(msg->payloads, 0, time_boot_ms);
    _mav_put_int32_t(msg->payloads, 4, lat);
    _mav_put_int32_t(msg->payloads, 8, lon);
    _mav_put_int32_t(msg->payloads, 12, alt);
    _mav_put_int32_t(msg->payloads, 16, relative_alt);
    _mav_put_int16_t(msg->payloads, 20, vx);
    _mav_put_int16_t(msg->payloads, 22, vy);
    _mav_put_int16_t(msg->payloads, 24, vz);
    _mav_put_uint16_t(msg->payloads, 26, hdg);

    msg->msgid = MAVLINK_MSG_ID_GLOBAL_POSITION_INT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GLOBAL_POSITION_INT_MIN_LEN, MAVLINK_MSG_ID_GLOBAL_POSITION_INT_LEN, MAVLINK_MSG_ID_GLOBAL_POSITION_INT_CRC);
}

/**
 * @brief Pack a global_position_int message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param lat [degE7] Latitude, expressed
 * @param lon [degE7] Longitude, expressed
 * @param alt [mm] Altitude (MSL). Note that virtually all GPS modules provide both WGS84 and MSL.
 * @param relative_alt [mm] Altitude above ground
 * @param vx [cm/s] Ground X Speed (Latitude, positive north)
 * @param vy [cm/s] Ground Y Speed (Longitude, positive east)
 * @param vz [cm/s] Ground Z Speed (Altitude, positive down)
 * @param hdg [cdeg] Vehicle heading (yaw angle), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_global_position_int_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,int32_t lat,int32_t lon,int32_t alt,int32_t relative_alt,int16_t vx,int16_t vy,int16_t vz,uint16_t hdg)
{
    _mav_put_uint32_t(msg->payloads, 0, time_boot_ms);
    _mav_put_int32_t(msg->payloads, 4, lat);
    _mav_put_int32_t(msg->payloads, 8, lon);
    _mav_put_int32_t(msg->payloads, 12, alt);
    _mav_put_int32_t(msg->payloads, 16, relative_alt);
    _mav_put_int16_t(msg->payloads, 20, vx);
    _mav_put_int16_t(msg->payloads, 22, vy);
    _mav_put_int16_t(msg->payloads, 24, vz);
    _mav_put_uint16_t(msg->payloads, 26, hdg);


    msg->msgid = MAVLINK_MSG_ID_GLOBAL_POSITION_INT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GLOBAL_POSITION_INT_MIN_LEN, MAVLINK_MSG_ID_GLOBAL_POSITION_INT_LEN, MAVLINK_MSG_ID_GLOBAL_POSITION_INT_CRC);
}

/**
 * @brief Encode a global_position_int struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param global_position_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_global_position_int_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_global_position_int_t* global_position_int)
{
    return mavlink_msg_global_position_int_pack(system_id, component_id, msg, global_position_int->time_boot_ms, global_position_int->lat, global_position_int->lon, global_position_int->alt, global_position_int->relative_alt, global_position_int->vx, global_position_int->vy, global_position_int->vz, global_position_int->hdg);
}

/**
 * @brief Encode a global_position_int struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param global_position_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_global_position_int_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_global_position_int_t* global_position_int)
{
    return mavlink_msg_global_position_int_pack_chan(system_id, component_id, chan, msg, global_position_int->time_boot_ms, global_position_int->lat, global_position_int->lon, global_position_int->alt, global_position_int->relative_alt, global_position_int->vx, global_position_int->vy, global_position_int->vz, global_position_int->hdg);
}

// MESSAGE GLOBAL_POSITION_INT UNPACKING


/**
 * @brief Get field time_boot_ms from global_position_int message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_global_position_int_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field lat from global_position_int message
 *
 * @return [degE7] Latitude, expressed
 */
static inline int32_t mavlink_msg_global_position_int_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field lon from global_position_int message
 *
 * @return [degE7] Longitude, expressed
 */
static inline int32_t mavlink_msg_global_position_int_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field alt from global_position_int message
 *
 * @return [mm] Altitude (MSL). Note that virtually all GPS modules provide both WGS84 and MSL.
 */
static inline int32_t mavlink_msg_global_position_int_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field relative_alt from global_position_int message
 *
 * @return [mm] Altitude above ground
 */
static inline int32_t mavlink_msg_global_position_int_get_relative_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field vx from global_position_int message
 *
 * @return [cm/s] Ground X Speed (Latitude, positive north)
 */
static inline int16_t mavlink_msg_global_position_int_get_vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field vy from global_position_int message
 *
 * @return [cm/s] Ground Y Speed (Longitude, positive east)
 */
static inline int16_t mavlink_msg_global_position_int_get_vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field vz from global_position_int message
 *
 * @return [cm/s] Ground Z Speed (Altitude, positive down)
 */
static inline int16_t mavlink_msg_global_position_int_get_vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field hdg from global_position_int message
 *
 * @return [cdeg] Vehicle heading (yaw angle), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
 */
static inline uint16_t mavlink_msg_global_position_int_get_hdg(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Decode a global_position_int message into a struct
 *
 * @param msg The message to decode
 * @param global_position_int C-struct to decode the message contents into
 */
static inline void mavlink_msg_global_position_int_decode(const mavlink_message_t* msg, mavlink_global_position_int_t* global_position_int)
{
    global_position_int->time_boot_ms = mavlink_msg_global_position_int_get_time_boot_ms(msg);
    global_position_int->lat = mavlink_msg_global_position_int_get_lat(msg);
    global_position_int->lon = mavlink_msg_global_position_int_get_lon(msg);
    global_position_int->alt = mavlink_msg_global_position_int_get_alt(msg);
    global_position_int->relative_alt = mavlink_msg_global_position_int_get_relative_alt(msg);
    global_position_int->vx = mavlink_msg_global_position_int_get_vx(msg);
    global_position_int->vy = mavlink_msg_global_position_int_get_vy(msg);
    global_position_int->vz = mavlink_msg_global_position_int_get_vz(msg);
    global_position_int->hdg = mavlink_msg_global_position_int_get_hdg(msg);
}
#endif
