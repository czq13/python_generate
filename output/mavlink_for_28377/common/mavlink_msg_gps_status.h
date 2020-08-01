#ifndef MAVLINK_MSG_gps_status
#define MAVLINK_MSG_gps_status
// MESSAGE GPS_STATUS PACKING

#define MAVLINK_MSG_ID_GPS_STATUS 25

typedef struct __mavlink_gps_status_t {
 uint8_t satellites_visible; /*<  Number of satellites visible*/
 uint8_t satellite_prn[20]; /*<  Global satellite ID*/
 uint8_t satellite_used[20]; /*<  0: Satellite not used, 1: used for localization*/
 uint8_t satellite_elevation[20]; /*< [deg] Elevation (0: right on top of receiver, 90: on the horizon) of satellite*/
 uint8_t satellite_azimuth[20]; /*< [deg] Direction of satellite, 0: 0 deg, 255: 360 deg.*/
 uint8_t satellite_snr[20]; /*< [dB] Signal to noise ratio of satellite*/
} mavlink_gps_status_t;

#define MAVLINK_MSG_ID_GPS_STATUS_LEN 101
#define MAVLINK_MSG_ID_GPS_STATUS_MIN_LEN 101
#define MAVLINK_MSG_ID_25_LEN 101
#define MAVLINK_MSG_ID_25_MIN_LEN 101

#define MAVLINK_MSG_ID_GPS_STATUS_CRC 23
#define MAVLINK_MSG_ID_25_CRC 23

#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_PRN_LEN 20
#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_USED_LEN 20
#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_ELEVATION_LEN 20
#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_AZIMUTH_LEN 20
#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_SNR_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_STATUS { \
    25, \
    "GPS_STATUS", \
    6, \
    {  { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_gps_status_t, satellites_visible) }, \
         { "satellite_prn", NULL, MAVLINK_TYPE_UINT8_T, 20, 1, offsetof(mavlink_gps_status_t, satellite_prn) }, \
         { "satellite_used", NULL, MAVLINK_TYPE_UINT8_T, 20, 21, offsetof(mavlink_gps_status_t, satellite_used) }, \
         { "satellite_elevation", NULL, MAVLINK_TYPE_UINT8_T, 20, 41, offsetof(mavlink_gps_status_t, satellite_elevation) }, \
         { "satellite_azimuth", NULL, MAVLINK_TYPE_UINT8_T, 20, 61, offsetof(mavlink_gps_status_t, satellite_azimuth) }, \
         { "satellite_snr", NULL, MAVLINK_TYPE_UINT8_T, 20, 81, offsetof(mavlink_gps_status_t, satellite_snr) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_STATUS { \
    "GPS_STATUS", \
    6, \
    {  { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_gps_status_t, satellites_visible) }, \
         { "satellite_prn", NULL, MAVLINK_TYPE_UINT8_T, 20, 1, offsetof(mavlink_gps_status_t, satellite_prn) }, \
         { "satellite_used", NULL, MAVLINK_TYPE_UINT8_T, 20, 21, offsetof(mavlink_gps_status_t, satellite_used) }, \
         { "satellite_elevation", NULL, MAVLINK_TYPE_UINT8_T, 20, 41, offsetof(mavlink_gps_status_t, satellite_elevation) }, \
         { "satellite_azimuth", NULL, MAVLINK_TYPE_UINT8_T, 20, 61, offsetof(mavlink_gps_status_t, satellite_azimuth) }, \
         { "satellite_snr", NULL, MAVLINK_TYPE_UINT8_T, 20, 81, offsetof(mavlink_gps_status_t, satellite_snr) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param satellites_visible  Number of satellites visible
 * @param satellite_prn  Global satellite ID
 * @param satellite_used  0: Satellite not used, 1: used for localization
 * @param satellite_elevation [deg] Elevation (0: right on top of receiver, 90: on the horizon) of satellite
 * @param satellite_azimuth [deg] Direction of satellite, 0: 0 deg, 255: 360 deg.
 * @param satellite_snr [dB] Signal to noise ratio of satellite
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t satellites_visible, const uint8_t *satellite_prn, const uint8_t *satellite_used, const uint8_t *satellite_elevation, const uint8_t *satellite_azimuth, const uint8_t *satellite_snr)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, satellites_visible);
    _mav_put_uint8_t_array(((char*)msg->payloads), 1, satellite_prn, 20);
    _mav_put_uint8_t_array(((char*)msg->payloads), 21, satellite_used, 20);
    _mav_put_uint8_t_array(((char*)msg->payloads), 41, satellite_elevation, 20);
    _mav_put_uint8_t_array(((char*)msg->payloads), 61, satellite_azimuth, 20);
    _mav_put_uint8_t_array(((char*)msg->payloads), 81, satellite_snr, 20);
    msg->msgid = MAVLINK_MSG_ID_GPS_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_STATUS_MIN_LEN, MAVLINK_MSG_ID_GPS_STATUS_LEN, MAVLINK_MSG_ID_GPS_STATUS_CRC);
}

/**
 * @brief Pack a gps_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param satellites_visible  Number of satellites visible
 * @param satellite_prn  Global satellite ID
 * @param satellite_used  0: Satellite not used, 1: used for localization
 * @param satellite_elevation [deg] Elevation (0: right on top of receiver, 90: on the horizon) of satellite
 * @param satellite_azimuth [deg] Direction of satellite, 0: 0 deg, 255: 360 deg.
 * @param satellite_snr [dB] Signal to noise ratio of satellite
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t satellites_visible,const uint8_t *satellite_prn,const uint8_t *satellite_used,const uint8_t *satellite_elevation,const uint8_t *satellite_azimuth,const uint8_t *satellite_snr)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, satellites_visible);
    _mav_put_uint8_t_array(((char*)msg->payloads), 1, satellite_prn, 20);
    _mav_put_uint8_t_array(((char*)msg->payloads), 21, satellite_used, 20);
    _mav_put_uint8_t_array(((char*)msg->payloads), 41, satellite_elevation, 20);
    _mav_put_uint8_t_array(((char*)msg->payloads), 61, satellite_azimuth, 20);
    _mav_put_uint8_t_array(((char*)msg->payloads), 81, satellite_snr, 20);

    msg->msgid = MAVLINK_MSG_ID_GPS_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_STATUS_MIN_LEN, MAVLINK_MSG_ID_GPS_STATUS_LEN, MAVLINK_MSG_ID_GPS_STATUS_CRC);
}

/**
 * @brief Encode a gps_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_status_t* gps_status)
{
    return mavlink_msg_gps_status_pack(system_id, component_id, msg, gps_status->satellites_visible, gps_status->satellite_prn, gps_status->satellite_used, gps_status->satellite_elevation, gps_status->satellite_azimuth, gps_status->satellite_snr);
}

/**
 * @brief Encode a gps_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_status_t* gps_status)
{
    return mavlink_msg_gps_status_pack_chan(system_id, component_id, chan, msg, gps_status->satellites_visible, gps_status->satellite_prn, gps_status->satellite_used, gps_status->satellite_elevation, gps_status->satellite_azimuth, gps_status->satellite_snr);
}

// MESSAGE GPS_STATUS UNPACKING


/**
 * @brief Get field satellites_visible from gps_status message
 *
 * @return  Number of satellites visible
 */
static inline uint8_t mavlink_msg_gps_status_get_satellites_visible(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field satellite_prn from gps_status message
 *
 * @return  Global satellite ID
 */
static inline uint16_t mavlink_msg_gps_status_get_satellite_prn(const mavlink_message_t* msg, uint8_t *satellite_prn)
{
    return _MAV_RETURN_uint8_t_array(msg, satellite_prn, 20,  1);
}

/**
 * @brief Get field satellite_used from gps_status message
 *
 * @return  0: Satellite not used, 1: used for localization
 */
static inline uint16_t mavlink_msg_gps_status_get_satellite_used(const mavlink_message_t* msg, uint8_t *satellite_used)
{
    return _MAV_RETURN_uint8_t_array(msg, satellite_used, 20,  21);
}

/**
 * @brief Get field satellite_elevation from gps_status message
 *
 * @return [deg] Elevation (0: right on top of receiver, 90: on the horizon) of satellite
 */
static inline uint16_t mavlink_msg_gps_status_get_satellite_elevation(const mavlink_message_t* msg, uint8_t *satellite_elevation)
{
    return _MAV_RETURN_uint8_t_array(msg, satellite_elevation, 20,  41);
}

/**
 * @brief Get field satellite_azimuth from gps_status message
 *
 * @return [deg] Direction of satellite, 0: 0 deg, 255: 360 deg.
 */
static inline uint16_t mavlink_msg_gps_status_get_satellite_azimuth(const mavlink_message_t* msg, uint8_t *satellite_azimuth)
{
    return _MAV_RETURN_uint8_t_array(msg, satellite_azimuth, 20,  61);
}

/**
 * @brief Get field satellite_snr from gps_status message
 *
 * @return [dB] Signal to noise ratio of satellite
 */
static inline uint16_t mavlink_msg_gps_status_get_satellite_snr(const mavlink_message_t* msg, uint8_t *satellite_snr)
{
    return _MAV_RETURN_uint8_t_array(msg, satellite_snr, 20,  81);
}

/**
 * @brief Decode a gps_status message into a struct
 *
 * @param msg The message to decode
 * @param gps_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_status_decode(const mavlink_message_t* msg, mavlink_gps_status_t* gps_status)
{
    gps_status->satellites_visible = mavlink_msg_gps_status_get_satellites_visible(msg);
    mavlink_msg_gps_status_get_satellite_prn(msg, gps_status->satellite_prn);
    mavlink_msg_gps_status_get_satellite_used(msg, gps_status->satellite_used);
    mavlink_msg_gps_status_get_satellite_elevation(msg, gps_status->satellite_elevation);
    mavlink_msg_gps_status_get_satellite_azimuth(msg, gps_status->satellite_azimuth);
    mavlink_msg_gps_status_get_satellite_snr(msg, gps_status->satellite_snr);
}
#endif
