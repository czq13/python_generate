#ifndef MAVLINK_MSG_set_gps_global_origin
#define MAVLINK_MSG_set_gps_global_origin
// MESSAGE SET_GPS_GLOBAL_ORIGIN PACKING

#define MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN 48

typedef struct __mavlink_set_gps_global_origin_t {
 int32_t latitude; /*< [degE7] Latitude (WGS84)*/
 int32_t longitude; /*< [degE7] Longitude (WGS84)*/
 int32_t altitude; /*< [mm] Altitude (MSL). Positive for up.*/
 uint8_t target_system; /*<  System ID*/
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
} mavlink_set_gps_global_origin_t;

#define MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN 21
#define MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_MIN_LEN 13
#define MAVLINK_MSG_ID_48_LEN 21
#define MAVLINK_MSG_ID_48_MIN_LEN 13

#define MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_CRC 41
#define MAVLINK_MSG_ID_48_CRC 41



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_GPS_GLOBAL_ORIGIN { \
    48, \
    "SET_GPS_GLOBAL_ORIGIN", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_set_gps_global_origin_t, target_system) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_set_gps_global_origin_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_set_gps_global_origin_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_set_gps_global_origin_t, altitude) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 13, offsetof(mavlink_set_gps_global_origin_t, time_usec) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_GPS_GLOBAL_ORIGIN { \
    "SET_GPS_GLOBAL_ORIGIN", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_set_gps_global_origin_t, target_system) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_set_gps_global_origin_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_set_gps_global_origin_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_set_gps_global_origin_t, altitude) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 13, offsetof(mavlink_set_gps_global_origin_t, time_usec) }, \
         } \
}
#endif

/**
 * @brief Pack a set_gps_global_origin message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param latitude [degE7] Latitude (WGS84)
 * @param longitude [degE7] Longitude (WGS84)
 * @param altitude [mm] Altitude (MSL). Positive for up.
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_gps_global_origin_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec)
{
    _mav_put_int32_t(msg->payloads, 0, latitude);
    _mav_put_int32_t(msg->payloads, 4, longitude);
    _mav_put_int32_t(msg->payloads, 8, altitude);
    _mav_put_uint8_t(msg->payloads, 12, target_system);
    _mav_put_uint64_t(msg->payloads, 13, time_usec);

    msg->msgid = MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_CRC);
}

/**
 * @brief Pack a set_gps_global_origin message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param latitude [degE7] Latitude (WGS84)
 * @param longitude [degE7] Longitude (WGS84)
 * @param altitude [mm] Altitude (MSL). Positive for up.
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_gps_global_origin_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,int32_t latitude,int32_t longitude,int32_t altitude,uint64_t time_usec)
{
    _mav_put_int32_t(msg->payloads, 0, latitude);
    _mav_put_int32_t(msg->payloads, 4, longitude);
    _mav_put_int32_t(msg->payloads, 8, altitude);
    _mav_put_uint8_t(msg->payloads, 12, target_system);
    _mav_put_uint64_t(msg->payloads, 13, time_usec);


    msg->msgid = MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN_CRC);
}

/**
 * @brief Encode a set_gps_global_origin struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_gps_global_origin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_gps_global_origin_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_gps_global_origin_t* set_gps_global_origin)
{
    return mavlink_msg_set_gps_global_origin_pack(system_id, component_id, msg, set_gps_global_origin->target_system, set_gps_global_origin->latitude, set_gps_global_origin->longitude, set_gps_global_origin->altitude, set_gps_global_origin->time_usec);
}

/**
 * @brief Encode a set_gps_global_origin struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_gps_global_origin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_gps_global_origin_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_gps_global_origin_t* set_gps_global_origin)
{
    return mavlink_msg_set_gps_global_origin_pack_chan(system_id, component_id, chan, msg, set_gps_global_origin->target_system, set_gps_global_origin->latitude, set_gps_global_origin->longitude, set_gps_global_origin->altitude, set_gps_global_origin->time_usec);
}

// MESSAGE SET_GPS_GLOBAL_ORIGIN UNPACKING


/**
 * @brief Get field target_system from set_gps_global_origin message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_set_gps_global_origin_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field latitude from set_gps_global_origin message
 *
 * @return [degE7] Latitude (WGS84)
 */
static inline int32_t mavlink_msg_set_gps_global_origin_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from set_gps_global_origin message
 *
 * @return [degE7] Longitude (WGS84)
 */
static inline int32_t mavlink_msg_set_gps_global_origin_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field altitude from set_gps_global_origin message
 *
 * @return [mm] Altitude (MSL). Positive for up.
 */
static inline int32_t mavlink_msg_set_gps_global_origin_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field time_usec from set_gps_global_origin message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_set_gps_global_origin_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  13);
}

/**
 * @brief Decode a set_gps_global_origin message into a struct
 *
 * @param msg The message to decode
 * @param set_gps_global_origin C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_gps_global_origin_decode(const mavlink_message_t* msg, mavlink_set_gps_global_origin_t* set_gps_global_origin)
{
    set_gps_global_origin->latitude = mavlink_msg_set_gps_global_origin_get_latitude(msg);
    set_gps_global_origin->longitude = mavlink_msg_set_gps_global_origin_get_longitude(msg);
    set_gps_global_origin->altitude = mavlink_msg_set_gps_global_origin_get_altitude(msg);
    set_gps_global_origin->target_system = mavlink_msg_set_gps_global_origin_get_target_system(msg);
    set_gps_global_origin->time_usec = mavlink_msg_set_gps_global_origin_get_time_usec(msg);
}
#endif
