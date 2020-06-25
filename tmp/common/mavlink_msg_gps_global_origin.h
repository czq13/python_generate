#pragma once
// MESSAGE GPS_GLOBAL_ORIGIN PACKING

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN 49

typedef struct __mavlink_gps_global_origin_t {
 int32_t latitude; /*< [degE7] Latitude (WGS84)*/
 int32_t longitude; /*< [degE7] Longitude (WGS84)*/
 int32_t altitude; /*< [mm] Altitude (MSL). Positive for up.*/
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
} mavlink_gps_global_origin_t;

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_LEN 20
#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_MIN_LEN 12
#define MAVLINK_MSG_ID_49_LEN 20
#define MAVLINK_MSG_ID_49_MIN_LEN 12

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_CRC 39
#define MAVLINK_MSG_ID_49_CRC 39



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_GLOBAL_ORIGIN { \
    49, \
    "GPS_GLOBAL_ORIGIN", \
    4, \
    {  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gps_global_origin_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gps_global_origin_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_global_origin_t, altitude) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 12, offsetof(mavlink_gps_global_origin_t, time_usec) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_GLOBAL_ORIGIN { \
    "GPS_GLOBAL_ORIGIN", \
    4, \
    {  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gps_global_origin_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gps_global_origin_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_global_origin_t, altitude) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 12, offsetof(mavlink_gps_global_origin_t, time_usec) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_global_origin message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param latitude [degE7] Latitude (WGS84)
 * @param longitude [degE7] Longitude (WGS84)
 * @param altitude [mm] Altitude (MSL). Positive for up.
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_global_origin_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec)
{
    _mav_put_int32_t(msg->payloads, 0, latitude);
    _mav_put_int32_t(msg->payloads, 4, longitude);
    _mav_put_int32_t(msg->payloads, 8, altitude);
    _mav_put_uint64_t(msg->payloads, 12, time_usec);

    msg->msgid = MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_CRC);
}

/**
 * @brief Pack a gps_global_origin message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param latitude [degE7] Latitude (WGS84)
 * @param longitude [degE7] Longitude (WGS84)
 * @param altitude [mm] Altitude (MSL). Positive for up.
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_global_origin_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t latitude,int32_t longitude,int32_t altitude,uint64_t time_usec)
{
    _mav_put_int32_t(msg->payloads, 0, latitude);
    _mav_put_int32_t(msg->payloads, 4, longitude);
    _mav_put_int32_t(msg->payloads, 8, altitude);
    _mav_put_uint64_t(msg->payloads, 12, time_usec);


    msg->msgid = MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_CRC);
}

/**
 * @brief Encode a gps_global_origin struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_global_origin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_global_origin_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_global_origin_t* gps_global_origin)
{
    return mavlink_msg_gps_global_origin_pack(system_id, component_id, msg, gps_global_origin->latitude, gps_global_origin->longitude, gps_global_origin->altitude, gps_global_origin->time_usec);
}

/**
 * @brief Encode a gps_global_origin struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_global_origin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_global_origin_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_global_origin_t* gps_global_origin)
{
    return mavlink_msg_gps_global_origin_pack_chan(system_id, component_id, chan, msg, gps_global_origin->latitude, gps_global_origin->longitude, gps_global_origin->altitude, gps_global_origin->time_usec);
}

// MESSAGE GPS_GLOBAL_ORIGIN UNPACKING


/**
 * @brief Get field latitude from gps_global_origin message
 *
 * @return [degE7] Latitude (WGS84)
 */
static inline int32_t mavlink_msg_gps_global_origin_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from gps_global_origin message
 *
 * @return [degE7] Longitude (WGS84)
 */
static inline int32_t mavlink_msg_gps_global_origin_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field altitude from gps_global_origin message
 *
 * @return [mm] Altitude (MSL). Positive for up.
 */
static inline int32_t mavlink_msg_gps_global_origin_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field time_usec from gps_global_origin message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_gps_global_origin_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  12);
}

/**
 * @brief Decode a gps_global_origin message into a struct
 *
 * @param msg The message to decode
 * @param gps_global_origin C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_global_origin_decode(const mavlink_message_t* msg, mavlink_gps_global_origin_t* gps_global_origin)
{
    gps_global_origin->latitude = mavlink_msg_gps_global_origin_get_latitude(msg);
    gps_global_origin->longitude = mavlink_msg_gps_global_origin_get_longitude(msg);
    gps_global_origin->altitude = mavlink_msg_gps_global_origin_get_altitude(msg);
    gps_global_origin->time_usec = mavlink_msg_gps_global_origin_get_time_usec(msg);
}
