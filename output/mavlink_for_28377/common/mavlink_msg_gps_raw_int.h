#ifndef MAVLINK_MSG_gps_raw_int
#define MAVLINK_MSG_gps_raw_int
// MESSAGE GPS_RAW_INT PACKING

#define MAVLINK_MSG_ID_GPS_RAW_INT 24

typedef struct __mavlink_gps_raw_int_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 int32_t lat; /*< [degE7] Latitude (WGS84, EGM96 ellipsoid)*/
 int32_t lon; /*< [degE7] Longitude (WGS84, EGM96 ellipsoid)*/
 int32_t alt; /*< [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide the MSL altitude in addition to the WGS84 altitude.*/
 uint16_t eph; /*<  GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX*/
 uint16_t epv; /*<  GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX*/
 uint16_t vel; /*< [cm/s] GPS ground speed. If unknown, set to: UINT16_MAX*/
 uint16_t cog; /*< [cdeg] Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX*/
 uint8_t fix_type; /*<  GPS fix type.*/
 uint8_t satellites_visible; /*<  Number of satellites visible. If unknown, set to 255*/
 int32_t alt_ellipsoid; /*< [mm] Altitude (above WGS84, EGM96 ellipsoid). Positive for up.*/
 uint32_t h_acc; /*< [mm] Position uncertainty.*/
 uint32_t v_acc; /*< [mm] Altitude uncertainty.*/
 uint32_t vel_acc; /*< [mm] Speed uncertainty.*/
 uint32_t hdg_acc; /*< [degE5] Heading / track uncertainty*/
 uint16_t yaw; /*< [cdeg] Yaw in earth frame from north. Use 0 if this GPS does not provide yaw. Use 65535 if this GPS is configured to provide yaw and is currently unable to provide it. Use 36000 for north.*/
} mavlink_gps_raw_int_t;

#define MAVLINK_MSG_ID_GPS_RAW_INT_LEN 52
#define MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN 30
#define MAVLINK_MSG_ID_24_LEN 52
#define MAVLINK_MSG_ID_24_MIN_LEN 30

#define MAVLINK_MSG_ID_GPS_RAW_INT_CRC 24
#define MAVLINK_MSG_ID_24_CRC 24



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_RAW_INT { \
    24, \
    "GPS_RAW_INT", \
    16, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_raw_int_t, time_usec) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_gps_raw_int_t, fix_type) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_raw_int_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_gps_raw_int_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_gps_raw_int_t, alt) }, \
         { "eph", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_gps_raw_int_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_gps_raw_int_t, epv) }, \
         { "vel", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_gps_raw_int_t, vel) }, \
         { "cog", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_gps_raw_int_t, cog) }, \
         { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_gps_raw_int_t, satellites_visible) }, \
         { "alt_ellipsoid", NULL, MAVLINK_TYPE_INT32_T, 0, 30, offsetof(mavlink_gps_raw_int_t, alt_ellipsoid) }, \
         { "h_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 34, offsetof(mavlink_gps_raw_int_t, h_acc) }, \
         { "v_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 38, offsetof(mavlink_gps_raw_int_t, v_acc) }, \
         { "vel_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 42, offsetof(mavlink_gps_raw_int_t, vel_acc) }, \
         { "hdg_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 46, offsetof(mavlink_gps_raw_int_t, hdg_acc) }, \
         { "yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 50, offsetof(mavlink_gps_raw_int_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_RAW_INT { \
    "GPS_RAW_INT", \
    16, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_gps_raw_int_t, time_usec) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_gps_raw_int_t, fix_type) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_raw_int_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_gps_raw_int_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_gps_raw_int_t, alt) }, \
         { "eph", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_gps_raw_int_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_gps_raw_int_t, epv) }, \
         { "vel", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_gps_raw_int_t, vel) }, \
         { "cog", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_gps_raw_int_t, cog) }, \
         { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_gps_raw_int_t, satellites_visible) }, \
         { "alt_ellipsoid", NULL, MAVLINK_TYPE_INT32_T, 0, 30, offsetof(mavlink_gps_raw_int_t, alt_ellipsoid) }, \
         { "h_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 34, offsetof(mavlink_gps_raw_int_t, h_acc) }, \
         { "v_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 38, offsetof(mavlink_gps_raw_int_t, v_acc) }, \
         { "vel_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 42, offsetof(mavlink_gps_raw_int_t, vel_acc) }, \
         { "hdg_acc", NULL, MAVLINK_TYPE_UINT32_T, 0, 46, offsetof(mavlink_gps_raw_int_t, hdg_acc) }, \
         { "yaw", NULL, MAVLINK_TYPE_UINT16_T, 0, 50, offsetof(mavlink_gps_raw_int_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_raw_int message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param fix_type  GPS fix type.
 * @param lat [degE7] Latitude (WGS84, EGM96 ellipsoid)
 * @param lon [degE7] Longitude (WGS84, EGM96 ellipsoid)
 * @param alt [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide the MSL altitude in addition to the WGS84 altitude.
 * @param eph  GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX
 * @param epv  GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX
 * @param vel [cm/s] GPS ground speed. If unknown, set to: UINT16_MAX
 * @param cog [cdeg] Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
 * @param satellites_visible  Number of satellites visible. If unknown, set to 255
 * @param alt_ellipsoid [mm] Altitude (above WGS84, EGM96 ellipsoid). Positive for up.
 * @param h_acc [mm] Position uncertainty.
 * @param v_acc [mm] Altitude uncertainty.
 * @param vel_acc [mm] Speed uncertainty.
 * @param hdg_acc [degE5] Heading / track uncertainty
 * @param yaw [cdeg] Yaw in earth frame from north. Use 0 if this GPS does not provide yaw. Use 65535 if this GPS is configured to provide yaw and is currently unable to provide it. Use 36000 for north.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_raw_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t fix_type, int32_t lat, int32_t lon, int32_t alt, uint16_t eph, uint16_t epv, uint16_t vel, uint16_t cog, uint8_t satellites_visible, int32_t alt_ellipsoid, uint32_t h_acc, uint32_t v_acc, uint32_t vel_acc, uint32_t hdg_acc, uint16_t yaw)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_int32_t(((char*)msg->payloads), 8, lat);
    _mav_put_int32_t(((char*)msg->payloads), 12, lon);
    _mav_put_int32_t(((char*)msg->payloads), 16, alt);
    _mav_put_uint16_t(((char*)msg->payloads), 20, eph);
    _mav_put_uint16_t(((char*)msg->payloads), 22, epv);
    _mav_put_uint16_t(((char*)msg->payloads), 24, vel);
    _mav_put_uint16_t(((char*)msg->payloads), 26, cog);
    _mav_put_uint8_t(((char*)msg->payloads), 28, fix_type);
    _mav_put_uint8_t(((char*)msg->payloads), 29, satellites_visible);
    _mav_put_int32_t(((char*)msg->payloads), 30, alt_ellipsoid);
    _mav_put_uint32_t(((char*)msg->payloads), 34, h_acc);
    _mav_put_uint32_t(((char*)msg->payloads), 38, v_acc);
    _mav_put_uint32_t(((char*)msg->payloads), 42, vel_acc);
    _mav_put_uint32_t(((char*)msg->payloads), 46, hdg_acc);
    _mav_put_uint16_t(((char*)msg->payloads), 50, yaw);

    msg->msgid = MAVLINK_MSG_ID_GPS_RAW_INT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_CRC);
}

/**
 * @brief Pack a gps_raw_int message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param fix_type  GPS fix type.
 * @param lat [degE7] Latitude (WGS84, EGM96 ellipsoid)
 * @param lon [degE7] Longitude (WGS84, EGM96 ellipsoid)
 * @param alt [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide the MSL altitude in addition to the WGS84 altitude.
 * @param eph  GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX
 * @param epv  GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX
 * @param vel [cm/s] GPS ground speed. If unknown, set to: UINT16_MAX
 * @param cog [cdeg] Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
 * @param satellites_visible  Number of satellites visible. If unknown, set to 255
 * @param alt_ellipsoid [mm] Altitude (above WGS84, EGM96 ellipsoid). Positive for up.
 * @param h_acc [mm] Position uncertainty.
 * @param v_acc [mm] Altitude uncertainty.
 * @param vel_acc [mm] Speed uncertainty.
 * @param hdg_acc [degE5] Heading / track uncertainty
 * @param yaw [cdeg] Yaw in earth frame from north. Use 0 if this GPS does not provide yaw. Use 65535 if this GPS is configured to provide yaw and is currently unable to provide it. Use 36000 for north.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_raw_int_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t fix_type,int32_t lat,int32_t lon,int32_t alt,uint16_t eph,uint16_t epv,uint16_t vel,uint16_t cog,uint8_t satellites_visible,int32_t alt_ellipsoid,uint32_t h_acc,uint32_t v_acc,uint32_t vel_acc,uint32_t hdg_acc,uint16_t yaw)
{
    _mav_put_uint64_t(((char*)msg->payloads), 0, time_usec);
    _mav_put_int32_t(((char*)msg->payloads), 8, lat);
    _mav_put_int32_t(((char*)msg->payloads), 12, lon);
    _mav_put_int32_t(((char*)msg->payloads), 16, alt);
    _mav_put_uint16_t(((char*)msg->payloads), 20, eph);
    _mav_put_uint16_t(((char*)msg->payloads), 22, epv);
    _mav_put_uint16_t(((char*)msg->payloads), 24, vel);
    _mav_put_uint16_t(((char*)msg->payloads), 26, cog);
    _mav_put_uint8_t(((char*)msg->payloads), 28, fix_type);
    _mav_put_uint8_t(((char*)msg->payloads), 29, satellites_visible);
    _mav_put_int32_t(((char*)msg->payloads), 30, alt_ellipsoid);
    _mav_put_uint32_t(((char*)msg->payloads), 34, h_acc);
    _mav_put_uint32_t(((char*)msg->payloads), 38, v_acc);
    _mav_put_uint32_t(((char*)msg->payloads), 42, vel_acc);
    _mav_put_uint32_t(((char*)msg->payloads), 46, hdg_acc);
    _mav_put_uint16_t(((char*)msg->payloads), 50, yaw);


    msg->msgid = MAVLINK_MSG_ID_GPS_RAW_INT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_RAW_INT_MIN_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_LEN, MAVLINK_MSG_ID_GPS_RAW_INT_CRC);
}

/**
 * @brief Encode a gps_raw_int struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_raw_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_raw_int_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_raw_int_t* gps_raw_int)
{
    return mavlink_msg_gps_raw_int_pack(system_id, component_id, msg, gps_raw_int->time_usec, gps_raw_int->fix_type, gps_raw_int->lat, gps_raw_int->lon, gps_raw_int->alt, gps_raw_int->eph, gps_raw_int->epv, gps_raw_int->vel, gps_raw_int->cog, gps_raw_int->satellites_visible, gps_raw_int->alt_ellipsoid, gps_raw_int->h_acc, gps_raw_int->v_acc, gps_raw_int->vel_acc, gps_raw_int->hdg_acc, gps_raw_int->yaw);
}

/**
 * @brief Encode a gps_raw_int struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_raw_int C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_raw_int_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_raw_int_t* gps_raw_int)
{
    return mavlink_msg_gps_raw_int_pack_chan(system_id, component_id, chan, msg, gps_raw_int->time_usec, gps_raw_int->fix_type, gps_raw_int->lat, gps_raw_int->lon, gps_raw_int->alt, gps_raw_int->eph, gps_raw_int->epv, gps_raw_int->vel, gps_raw_int->cog, gps_raw_int->satellites_visible, gps_raw_int->alt_ellipsoid, gps_raw_int->h_acc, gps_raw_int->v_acc, gps_raw_int->vel_acc, gps_raw_int->hdg_acc, gps_raw_int->yaw);
}

// MESSAGE GPS_RAW_INT UNPACKING


/**
 * @brief Get field time_usec from gps_raw_int message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_gps_raw_int_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field fix_type from gps_raw_int message
 *
 * @return  GPS fix type.
 */
static inline uint8_t mavlink_msg_gps_raw_int_get_fix_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field lat from gps_raw_int message
 *
 * @return [degE7] Latitude (WGS84, EGM96 ellipsoid)
 */
static inline int32_t mavlink_msg_gps_raw_int_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field lon from gps_raw_int message
 *
 * @return [degE7] Longitude (WGS84, EGM96 ellipsoid)
 */
static inline int32_t mavlink_msg_gps_raw_int_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field alt from gps_raw_int message
 *
 * @return [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide the MSL altitude in addition to the WGS84 altitude.
 */
static inline int32_t mavlink_msg_gps_raw_int_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field eph from gps_raw_int message
 *
 * @return  GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX
 */
static inline uint16_t mavlink_msg_gps_raw_int_get_eph(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field epv from gps_raw_int message
 *
 * @return  GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX
 */
static inline uint16_t mavlink_msg_gps_raw_int_get_epv(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field vel from gps_raw_int message
 *
 * @return [cm/s] GPS ground speed. If unknown, set to: UINT16_MAX
 */
static inline uint16_t mavlink_msg_gps_raw_int_get_vel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field cog from gps_raw_int message
 *
 * @return [cdeg] Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
 */
static inline uint16_t mavlink_msg_gps_raw_int_get_cog(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field satellites_visible from gps_raw_int message
 *
 * @return  Number of satellites visible. If unknown, set to 255
 */
static inline uint8_t mavlink_msg_gps_raw_int_get_satellites_visible(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Get field alt_ellipsoid from gps_raw_int message
 *
 * @return [mm] Altitude (above WGS84, EGM96 ellipsoid). Positive for up.
 */
static inline int32_t mavlink_msg_gps_raw_int_get_alt_ellipsoid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  30);
}

/**
 * @brief Get field h_acc from gps_raw_int message
 *
 * @return [mm] Position uncertainty.
 */
static inline uint32_t mavlink_msg_gps_raw_int_get_h_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  34);
}

/**
 * @brief Get field v_acc from gps_raw_int message
 *
 * @return [mm] Altitude uncertainty.
 */
static inline uint32_t mavlink_msg_gps_raw_int_get_v_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  38);
}

/**
 * @brief Get field vel_acc from gps_raw_int message
 *
 * @return [mm] Speed uncertainty.
 */
static inline uint32_t mavlink_msg_gps_raw_int_get_vel_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  42);
}

/**
 * @brief Get field hdg_acc from gps_raw_int message
 *
 * @return [degE5] Heading / track uncertainty
 */
static inline uint32_t mavlink_msg_gps_raw_int_get_hdg_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  46);
}

/**
 * @brief Get field yaw from gps_raw_int message
 *
 * @return [cdeg] Yaw in earth frame from north. Use 0 if this GPS does not provide yaw. Use 65535 if this GPS is configured to provide yaw and is currently unable to provide it. Use 36000 for north.
 */
static inline uint16_t mavlink_msg_gps_raw_int_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  50);
}

/**
 * @brief Decode a gps_raw_int message into a struct
 *
 * @param msg The message to decode
 * @param gps_raw_int C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_raw_int_decode(const mavlink_message_t* msg, mavlink_gps_raw_int_t* gps_raw_int)
{
    gps_raw_int->time_usec = mavlink_msg_gps_raw_int_get_time_usec(msg);
    gps_raw_int->lat = mavlink_msg_gps_raw_int_get_lat(msg);
    gps_raw_int->lon = mavlink_msg_gps_raw_int_get_lon(msg);
    gps_raw_int->alt = mavlink_msg_gps_raw_int_get_alt(msg);
    gps_raw_int->eph = mavlink_msg_gps_raw_int_get_eph(msg);
    gps_raw_int->epv = mavlink_msg_gps_raw_int_get_epv(msg);
    gps_raw_int->vel = mavlink_msg_gps_raw_int_get_vel(msg);
    gps_raw_int->cog = mavlink_msg_gps_raw_int_get_cog(msg);
    gps_raw_int->fix_type = mavlink_msg_gps_raw_int_get_fix_type(msg);
    gps_raw_int->satellites_visible = mavlink_msg_gps_raw_int_get_satellites_visible(msg);
    gps_raw_int->alt_ellipsoid = mavlink_msg_gps_raw_int_get_alt_ellipsoid(msg);
    gps_raw_int->h_acc = mavlink_msg_gps_raw_int_get_h_acc(msg);
    gps_raw_int->v_acc = mavlink_msg_gps_raw_int_get_v_acc(msg);
    gps_raw_int->vel_acc = mavlink_msg_gps_raw_int_get_vel_acc(msg);
    gps_raw_int->hdg_acc = mavlink_msg_gps_raw_int_get_hdg_acc(msg);
    gps_raw_int->yaw = mavlink_msg_gps_raw_int_get_yaw(msg);
}
#endif
