#ifndef MAVLINK_MSG_open_drone_id_location
#define MAVLINK_MSG_open_drone_id_location
// MESSAGE OPEN_DRONE_ID_LOCATION PACKING

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION 12901

typedef struct __mavlink_open_drone_id_location_t {
 int32_t latitude; /*< [degE7] Current latitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon).*/
 int32_t longitude; /*< [degE7] Current longitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon).*/
 float altitude_barometric; /*< [m] The altitude calculated from the barometric pressue. Reference is against 29.92inHg or 1013.2mb. If unknown: -1000 m.*/
 float altitude_geodetic; /*< [m] The geodetic altitude as defined by WGS84. If unknown: -1000 m.*/
 float height; /*< [m] The current height of the unmanned aircraft above the take-off location or the ground as indicated by height_reference. If unknown: -1000 m.*/
 float timestamp; /*< [s] Seconds after the full hour with reference to UTC time. Typically the GPS outputs a time-of-week value in milliseconds. First convert that to UTC and then convert for this field using ((float) (time_week_ms % (60*60*1000))) / 1000.*/
 uint16_t direction; /*< [cdeg] Direction over ground (not heading, but direction of movement) measured clockwise from true North: 0 - 35999 centi-degrees. If unknown: 36100 centi-degrees.*/
 uint16_t speed_horizontal; /*< [cm/s] Ground speed. Positive only. If unknown: 25500 cm/s. If speed is larger than 25425 cm/s, use 25425 cm/s.*/
 int16_t speed_vertical; /*< [cm/s] The vertical speed. Up is positive. If unknown: 6300 cm/s. If speed is larger than 6200 cm/s, use 6200 cm/s. If lower than -6200 cm/s, use -6200 cm/s.*/
 uint8_t target_system; /*<  System ID (0 for broadcast).*/
 uint8_t target_component; /*<  Component ID (0 for broadcast).*/
 uint8_t id_or_mac[20]; /*<  Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html. */
 uint8_t status; /*<  Indicates whether the unmanned aircraft is on the ground or in the air.*/
 uint8_t height_reference; /*<  Indicates the reference point for the height field.*/
 uint8_t horizontal_accuracy; /*<  The accuracy of the horizontal position.*/
 uint8_t vertical_accuracy; /*<  The accuracy of the vertical position.*/
 uint8_t barometer_accuracy; /*<  The accuracy of the barometric altitude.*/
 uint8_t speed_accuracy; /*<  The accuracy of the horizontal and vertical speed.*/
 uint8_t timestamp_accuracy; /*<  The accuracy of the timestamps.*/
} mavlink_open_drone_id_location_t;

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION_LEN 59
#define MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION_MIN_LEN 59
#define MAVLINK_MSG_ID_12901_LEN 59
#define MAVLINK_MSG_ID_12901_MIN_LEN 59

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION_CRC 254
#define MAVLINK_MSG_ID_12901_CRC 254

#define MAVLINK_MSG_OPEN_DRONE_ID_LOCATION_FIELD_ID_OR_MAC_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_LOCATION { \
    12901, \
    "OPEN_DRONE_ID_LOCATION", \
    19, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_open_drone_id_location_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_open_drone_id_location_t, target_component) }, \
         { "id_or_mac", NULL, MAVLINK_TYPE_UINT8_T, 20, 32, offsetof(mavlink_open_drone_id_location_t, id_or_mac) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_open_drone_id_location_t, status) }, \
         { "direction", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_open_drone_id_location_t, direction) }, \
         { "speed_horizontal", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_open_drone_id_location_t, speed_horizontal) }, \
         { "speed_vertical", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_open_drone_id_location_t, speed_vertical) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_open_drone_id_location_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_open_drone_id_location_t, longitude) }, \
         { "altitude_barometric", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_open_drone_id_location_t, altitude_barometric) }, \
         { "altitude_geodetic", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_open_drone_id_location_t, altitude_geodetic) }, \
         { "height_reference", NULL, MAVLINK_TYPE_UINT8_T, 0, 53, offsetof(mavlink_open_drone_id_location_t, height_reference) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_open_drone_id_location_t, height) }, \
         { "horizontal_accuracy", NULL, MAVLINK_TYPE_UINT8_T, 0, 54, offsetof(mavlink_open_drone_id_location_t, horizontal_accuracy) }, \
         { "vertical_accuracy", NULL, MAVLINK_TYPE_UINT8_T, 0, 55, offsetof(mavlink_open_drone_id_location_t, vertical_accuracy) }, \
         { "barometer_accuracy", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_open_drone_id_location_t, barometer_accuracy) }, \
         { "speed_accuracy", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_open_drone_id_location_t, speed_accuracy) }, \
         { "timestamp", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_open_drone_id_location_t, timestamp) }, \
         { "timestamp_accuracy", NULL, MAVLINK_TYPE_UINT8_T, 0, 58, offsetof(mavlink_open_drone_id_location_t, timestamp_accuracy) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_LOCATION { \
    "OPEN_DRONE_ID_LOCATION", \
    19, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_open_drone_id_location_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_open_drone_id_location_t, target_component) }, \
         { "id_or_mac", NULL, MAVLINK_TYPE_UINT8_T, 20, 32, offsetof(mavlink_open_drone_id_location_t, id_or_mac) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_open_drone_id_location_t, status) }, \
         { "direction", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_open_drone_id_location_t, direction) }, \
         { "speed_horizontal", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_open_drone_id_location_t, speed_horizontal) }, \
         { "speed_vertical", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_open_drone_id_location_t, speed_vertical) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_open_drone_id_location_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_open_drone_id_location_t, longitude) }, \
         { "altitude_barometric", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_open_drone_id_location_t, altitude_barometric) }, \
         { "altitude_geodetic", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_open_drone_id_location_t, altitude_geodetic) }, \
         { "height_reference", NULL, MAVLINK_TYPE_UINT8_T, 0, 53, offsetof(mavlink_open_drone_id_location_t, height_reference) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_open_drone_id_location_t, height) }, \
         { "horizontal_accuracy", NULL, MAVLINK_TYPE_UINT8_T, 0, 54, offsetof(mavlink_open_drone_id_location_t, horizontal_accuracy) }, \
         { "vertical_accuracy", NULL, MAVLINK_TYPE_UINT8_T, 0, 55, offsetof(mavlink_open_drone_id_location_t, vertical_accuracy) }, \
         { "barometer_accuracy", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_open_drone_id_location_t, barometer_accuracy) }, \
         { "speed_accuracy", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_open_drone_id_location_t, speed_accuracy) }, \
         { "timestamp", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_open_drone_id_location_t, timestamp) }, \
         { "timestamp_accuracy", NULL, MAVLINK_TYPE_UINT8_T, 0, 58, offsetof(mavlink_open_drone_id_location_t, timestamp_accuracy) }, \
         } \
}
#endif

/**
 * @brief Pack a open_drone_id_location message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID (0 for broadcast).
 * @param target_component  Component ID (0 for broadcast).
 * @param id_or_mac  Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html. 
 * @param status  Indicates whether the unmanned aircraft is on the ground or in the air.
 * @param direction [cdeg] Direction over ground (not heading, but direction of movement) measured clockwise from true North: 0 - 35999 centi-degrees. If unknown: 36100 centi-degrees.
 * @param speed_horizontal [cm/s] Ground speed. Positive only. If unknown: 25500 cm/s. If speed is larger than 25425 cm/s, use 25425 cm/s.
 * @param speed_vertical [cm/s] The vertical speed. Up is positive. If unknown: 6300 cm/s. If speed is larger than 6200 cm/s, use 6200 cm/s. If lower than -6200 cm/s, use -6200 cm/s.
 * @param latitude [degE7] Current latitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon).
 * @param longitude [degE7] Current longitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon).
 * @param altitude_barometric [m] The altitude calculated from the barometric pressue. Reference is against 29.92inHg or 1013.2mb. If unknown: -1000 m.
 * @param altitude_geodetic [m] The geodetic altitude as defined by WGS84. If unknown: -1000 m.
 * @param height_reference  Indicates the reference point for the height field.
 * @param height [m] The current height of the unmanned aircraft above the take-off location or the ground as indicated by height_reference. If unknown: -1000 m.
 * @param horizontal_accuracy  The accuracy of the horizontal position.
 * @param vertical_accuracy  The accuracy of the vertical position.
 * @param barometer_accuracy  The accuracy of the barometric altitude.
 * @param speed_accuracy  The accuracy of the horizontal and vertical speed.
 * @param timestamp [s] Seconds after the full hour with reference to UTC time. Typically the GPS outputs a time-of-week value in milliseconds. First convert that to UTC and then convert for this field using ((float) (time_week_ms % (60*60*1000))) / 1000.
 * @param timestamp_accuracy  The accuracy of the timestamps.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_open_drone_id_location_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const uint8_t *id_or_mac, uint8_t status, uint16_t direction, uint16_t speed_horizontal, int16_t speed_vertical, int32_t latitude, int32_t longitude, float altitude_barometric, float altitude_geodetic, uint8_t height_reference, float height, uint8_t horizontal_accuracy, uint8_t vertical_accuracy, uint8_t barometer_accuracy, uint8_t speed_accuracy, float timestamp, uint8_t timestamp_accuracy)
{
    _mav_put_int32_t(((char*)msg->payloads), 0, latitude);
    _mav_put_int32_t(((char*)msg->payloads), 4, longitude);
    _mav_put_float(((char*)msg->payloads), 8, altitude_barometric);
    _mav_put_float(((char*)msg->payloads), 12, altitude_geodetic);
    _mav_put_float(((char*)msg->payloads), 16, height);
    _mav_put_float(((char*)msg->payloads), 20, timestamp);
    _mav_put_uint16_t(((char*)msg->payloads), 24, direction);
    _mav_put_uint16_t(((char*)msg->payloads), 26, speed_horizontal);
    _mav_put_int16_t(((char*)msg->payloads), 28, speed_vertical);
    _mav_put_uint8_t(((char*)msg->payloads), 30, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 31, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 52, status);
    _mav_put_uint8_t(((char*)msg->payloads), 53, height_reference);
    _mav_put_uint8_t(((char*)msg->payloads), 54, horizontal_accuracy);
    _mav_put_uint8_t(((char*)msg->payloads), 55, vertical_accuracy);
    _mav_put_uint8_t(((char*)msg->payloads), 56, barometer_accuracy);
    _mav_put_uint8_t(((char*)msg->payloads), 57, speed_accuracy);
    _mav_put_uint8_t(((char*)msg->payloads), 58, timestamp_accuracy);
    _mav_put_uint8_t_array(((char*)msg->payloads), 32, id_or_mac, 20);
    msg->msgid = MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION_CRC);
}

/**
 * @brief Pack a open_drone_id_location message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID (0 for broadcast).
 * @param target_component  Component ID (0 for broadcast).
 * @param id_or_mac  Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html. 
 * @param status  Indicates whether the unmanned aircraft is on the ground or in the air.
 * @param direction [cdeg] Direction over ground (not heading, but direction of movement) measured clockwise from true North: 0 - 35999 centi-degrees. If unknown: 36100 centi-degrees.
 * @param speed_horizontal [cm/s] Ground speed. Positive only. If unknown: 25500 cm/s. If speed is larger than 25425 cm/s, use 25425 cm/s.
 * @param speed_vertical [cm/s] The vertical speed. Up is positive. If unknown: 6300 cm/s. If speed is larger than 6200 cm/s, use 6200 cm/s. If lower than -6200 cm/s, use -6200 cm/s.
 * @param latitude [degE7] Current latitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon).
 * @param longitude [degE7] Current longitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon).
 * @param altitude_barometric [m] The altitude calculated from the barometric pressue. Reference is against 29.92inHg or 1013.2mb. If unknown: -1000 m.
 * @param altitude_geodetic [m] The geodetic altitude as defined by WGS84. If unknown: -1000 m.
 * @param height_reference  Indicates the reference point for the height field.
 * @param height [m] The current height of the unmanned aircraft above the take-off location or the ground as indicated by height_reference. If unknown: -1000 m.
 * @param horizontal_accuracy  The accuracy of the horizontal position.
 * @param vertical_accuracy  The accuracy of the vertical position.
 * @param barometer_accuracy  The accuracy of the barometric altitude.
 * @param speed_accuracy  The accuracy of the horizontal and vertical speed.
 * @param timestamp [s] Seconds after the full hour with reference to UTC time. Typically the GPS outputs a time-of-week value in milliseconds. First convert that to UTC and then convert for this field using ((float) (time_week_ms % (60*60*1000))) / 1000.
 * @param timestamp_accuracy  The accuracy of the timestamps.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_open_drone_id_location_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const uint8_t *id_or_mac,uint8_t status,uint16_t direction,uint16_t speed_horizontal,int16_t speed_vertical,int32_t latitude,int32_t longitude,float altitude_barometric,float altitude_geodetic,uint8_t height_reference,float height,uint8_t horizontal_accuracy,uint8_t vertical_accuracy,uint8_t barometer_accuracy,uint8_t speed_accuracy,float timestamp,uint8_t timestamp_accuracy)
{
    _mav_put_int32_t(((char*)msg->payloads), 0, latitude);
    _mav_put_int32_t(((char*)msg->payloads), 4, longitude);
    _mav_put_float(((char*)msg->payloads), 8, altitude_barometric);
    _mav_put_float(((char*)msg->payloads), 12, altitude_geodetic);
    _mav_put_float(((char*)msg->payloads), 16, height);
    _mav_put_float(((char*)msg->payloads), 20, timestamp);
    _mav_put_uint16_t(((char*)msg->payloads), 24, direction);
    _mav_put_uint16_t(((char*)msg->payloads), 26, speed_horizontal);
    _mav_put_int16_t(((char*)msg->payloads), 28, speed_vertical);
    _mav_put_uint8_t(((char*)msg->payloads), 30, target_system);
    _mav_put_uint8_t(((char*)msg->payloads), 31, target_component);
    _mav_put_uint8_t(((char*)msg->payloads), 52, status);
    _mav_put_uint8_t(((char*)msg->payloads), 53, height_reference);
    _mav_put_uint8_t(((char*)msg->payloads), 54, horizontal_accuracy);
    _mav_put_uint8_t(((char*)msg->payloads), 55, vertical_accuracy);
    _mav_put_uint8_t(((char*)msg->payloads), 56, barometer_accuracy);
    _mav_put_uint8_t(((char*)msg->payloads), 57, speed_accuracy);
    _mav_put_uint8_t(((char*)msg->payloads), 58, timestamp_accuracy);
    _mav_put_uint8_t_array(((char*)msg->payloads), 32, id_or_mac, 20);

    msg->msgid = MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_LOCATION_CRC);
}

/**
 * @brief Encode a open_drone_id_location struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param open_drone_id_location C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_open_drone_id_location_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_open_drone_id_location_t* open_drone_id_location)
{
    return mavlink_msg_open_drone_id_location_pack(system_id, component_id, msg, open_drone_id_location->target_system, open_drone_id_location->target_component, open_drone_id_location->id_or_mac, open_drone_id_location->status, open_drone_id_location->direction, open_drone_id_location->speed_horizontal, open_drone_id_location->speed_vertical, open_drone_id_location->latitude, open_drone_id_location->longitude, open_drone_id_location->altitude_barometric, open_drone_id_location->altitude_geodetic, open_drone_id_location->height_reference, open_drone_id_location->height, open_drone_id_location->horizontal_accuracy, open_drone_id_location->vertical_accuracy, open_drone_id_location->barometer_accuracy, open_drone_id_location->speed_accuracy, open_drone_id_location->timestamp, open_drone_id_location->timestamp_accuracy);
}

/**
 * @brief Encode a open_drone_id_location struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param open_drone_id_location C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_open_drone_id_location_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_open_drone_id_location_t* open_drone_id_location)
{
    return mavlink_msg_open_drone_id_location_pack_chan(system_id, component_id, chan, msg, open_drone_id_location->target_system, open_drone_id_location->target_component, open_drone_id_location->id_or_mac, open_drone_id_location->status, open_drone_id_location->direction, open_drone_id_location->speed_horizontal, open_drone_id_location->speed_vertical, open_drone_id_location->latitude, open_drone_id_location->longitude, open_drone_id_location->altitude_barometric, open_drone_id_location->altitude_geodetic, open_drone_id_location->height_reference, open_drone_id_location->height, open_drone_id_location->horizontal_accuracy, open_drone_id_location->vertical_accuracy, open_drone_id_location->barometer_accuracy, open_drone_id_location->speed_accuracy, open_drone_id_location->timestamp, open_drone_id_location->timestamp_accuracy);
}

// MESSAGE OPEN_DRONE_ID_LOCATION UNPACKING


/**
 * @brief Get field target_system from open_drone_id_location message
 *
 * @return  System ID (0 for broadcast).
 */
static inline uint8_t mavlink_msg_open_drone_id_location_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field target_component from open_drone_id_location message
 *
 * @return  Component ID (0 for broadcast).
 */
static inline uint8_t mavlink_msg_open_drone_id_location_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field id_or_mac from open_drone_id_location message
 *
 * @return  Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html. 
 */
static inline uint16_t mavlink_msg_open_drone_id_location_get_id_or_mac(const mavlink_message_t* msg, uint8_t *id_or_mac)
{
    return _MAV_RETURN_uint8_t_array(msg, id_or_mac, 20,  32);
}

/**
 * @brief Get field status from open_drone_id_location message
 *
 * @return  Indicates whether the unmanned aircraft is on the ground or in the air.
 */
static inline uint8_t mavlink_msg_open_drone_id_location_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  52);
}

/**
 * @brief Get field direction from open_drone_id_location message
 *
 * @return [cdeg] Direction over ground (not heading, but direction of movement) measured clockwise from true North: 0 - 35999 centi-degrees. If unknown: 36100 centi-degrees.
 */
static inline uint16_t mavlink_msg_open_drone_id_location_get_direction(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field speed_horizontal from open_drone_id_location message
 *
 * @return [cm/s] Ground speed. Positive only. If unknown: 25500 cm/s. If speed is larger than 25425 cm/s, use 25425 cm/s.
 */
static inline uint16_t mavlink_msg_open_drone_id_location_get_speed_horizontal(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field speed_vertical from open_drone_id_location message
 *
 * @return [cm/s] The vertical speed. Up is positive. If unknown: 6300 cm/s. If speed is larger than 6200 cm/s, use 6200 cm/s. If lower than -6200 cm/s, use -6200 cm/s.
 */
static inline int16_t mavlink_msg_open_drone_id_location_get_speed_vertical(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field latitude from open_drone_id_location message
 *
 * @return [degE7] Current latitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon).
 */
static inline int32_t mavlink_msg_open_drone_id_location_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from open_drone_id_location message
 *
 * @return [degE7] Current longitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon).
 */
static inline int32_t mavlink_msg_open_drone_id_location_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field altitude_barometric from open_drone_id_location message
 *
 * @return [m] The altitude calculated from the barometric pressue. Reference is against 29.92inHg or 1013.2mb. If unknown: -1000 m.
 */
static inline float mavlink_msg_open_drone_id_location_get_altitude_barometric(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field altitude_geodetic from open_drone_id_location message
 *
 * @return [m] The geodetic altitude as defined by WGS84. If unknown: -1000 m.
 */
static inline float mavlink_msg_open_drone_id_location_get_altitude_geodetic(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field height_reference from open_drone_id_location message
 *
 * @return  Indicates the reference point for the height field.
 */
static inline uint8_t mavlink_msg_open_drone_id_location_get_height_reference(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  53);
}

/**
 * @brief Get field height from open_drone_id_location message
 *
 * @return [m] The current height of the unmanned aircraft above the take-off location or the ground as indicated by height_reference. If unknown: -1000 m.
 */
static inline float mavlink_msg_open_drone_id_location_get_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field horizontal_accuracy from open_drone_id_location message
 *
 * @return  The accuracy of the horizontal position.
 */
static inline uint8_t mavlink_msg_open_drone_id_location_get_horizontal_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  54);
}

/**
 * @brief Get field vertical_accuracy from open_drone_id_location message
 *
 * @return  The accuracy of the vertical position.
 */
static inline uint8_t mavlink_msg_open_drone_id_location_get_vertical_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  55);
}

/**
 * @brief Get field barometer_accuracy from open_drone_id_location message
 *
 * @return  The accuracy of the barometric altitude.
 */
static inline uint8_t mavlink_msg_open_drone_id_location_get_barometer_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  56);
}

/**
 * @brief Get field speed_accuracy from open_drone_id_location message
 *
 * @return  The accuracy of the horizontal and vertical speed.
 */
static inline uint8_t mavlink_msg_open_drone_id_location_get_speed_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  57);
}

/**
 * @brief Get field timestamp from open_drone_id_location message
 *
 * @return [s] Seconds after the full hour with reference to UTC time. Typically the GPS outputs a time-of-week value in milliseconds. First convert that to UTC and then convert for this field using ((float) (time_week_ms % (60*60*1000))) / 1000.
 */
static inline float mavlink_msg_open_drone_id_location_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field timestamp_accuracy from open_drone_id_location message
 *
 * @return  The accuracy of the timestamps.
 */
static inline uint8_t mavlink_msg_open_drone_id_location_get_timestamp_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  58);
}

/**
 * @brief Decode a open_drone_id_location message into a struct
 *
 * @param msg The message to decode
 * @param open_drone_id_location C-struct to decode the message contents into
 */
static inline void mavlink_msg_open_drone_id_location_decode(const mavlink_message_t* msg, mavlink_open_drone_id_location_t* open_drone_id_location)
{
    open_drone_id_location->latitude = mavlink_msg_open_drone_id_location_get_latitude(msg);
    open_drone_id_location->longitude = mavlink_msg_open_drone_id_location_get_longitude(msg);
    open_drone_id_location->altitude_barometric = mavlink_msg_open_drone_id_location_get_altitude_barometric(msg);
    open_drone_id_location->altitude_geodetic = mavlink_msg_open_drone_id_location_get_altitude_geodetic(msg);
    open_drone_id_location->height = mavlink_msg_open_drone_id_location_get_height(msg);
    open_drone_id_location->timestamp = mavlink_msg_open_drone_id_location_get_timestamp(msg);
    open_drone_id_location->direction = mavlink_msg_open_drone_id_location_get_direction(msg);
    open_drone_id_location->speed_horizontal = mavlink_msg_open_drone_id_location_get_speed_horizontal(msg);
    open_drone_id_location->speed_vertical = mavlink_msg_open_drone_id_location_get_speed_vertical(msg);
    open_drone_id_location->target_system = mavlink_msg_open_drone_id_location_get_target_system(msg);
    open_drone_id_location->target_component = mavlink_msg_open_drone_id_location_get_target_component(msg);
    mavlink_msg_open_drone_id_location_get_id_or_mac(msg, open_drone_id_location->id_or_mac);
    open_drone_id_location->status = mavlink_msg_open_drone_id_location_get_status(msg);
    open_drone_id_location->height_reference = mavlink_msg_open_drone_id_location_get_height_reference(msg);
    open_drone_id_location->horizontal_accuracy = mavlink_msg_open_drone_id_location_get_horizontal_accuracy(msg);
    open_drone_id_location->vertical_accuracy = mavlink_msg_open_drone_id_location_get_vertical_accuracy(msg);
    open_drone_id_location->barometer_accuracy = mavlink_msg_open_drone_id_location_get_barometer_accuracy(msg);
    open_drone_id_location->speed_accuracy = mavlink_msg_open_drone_id_location_get_speed_accuracy(msg);
    open_drone_id_location->timestamp_accuracy = mavlink_msg_open_drone_id_location_get_timestamp_accuracy(msg);
}
#endif
