#pragma once
// MESSAGE OBSTACLE_DISTANCE PACKING

#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE 330

typedef struct __mavlink_obstacle_distance_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint16_t distances[72]; /*< [cm] Distance of obstacles around the vehicle with index 0 corresponding to north + angle_offset, unless otherwise specified in the frame. A value of 0 is valid and means that the obstacle is practically touching the sensor. A value of max_distance +1 means no obstacle is present. A value of UINT16_MAX for unknown/not used. In a array element, one unit corresponds to 1cm.*/
 uint16_t min_distance; /*< [cm] Minimum distance the sensor can measure.*/
 uint16_t max_distance; /*< [cm] Maximum distance the sensor can measure.*/
 uint8_t sensor_type; /*<  Class id of the distance sensor type.*/
 uint8_t increment; /*< [deg] Angular width in degrees of each array element. Increment direction is clockwise. This field is ignored if increment_f is non-zero.*/
 float increment_f; /*< [deg] Angular width in degrees of each array element as a float. If non-zero then this value is used instead of the uint8_t increment field. Positive is clockwise direction, negative is counter-clockwise.*/
 float angle_offset; /*< [deg] Relative angle offset of the 0-index element in the distances array. Value of 0 corresponds to forward. Positive is clockwise direction, negative is counter-clockwise.*/
 uint8_t frame; /*<  Coordinate frame of reference for the yaw rotation and offset of the sensor data. Defaults to MAV_FRAME_GLOBAL, which is north aligned. For body-mounted sensors use MAV_FRAME_BODY_FRD, which is vehicle front aligned.*/
} mavlink_obstacle_distance_t;

#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN 167
#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN 158
#define MAVLINK_MSG_ID_330_LEN 167
#define MAVLINK_MSG_ID_330_MIN_LEN 158

#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC 23
#define MAVLINK_MSG_ID_330_CRC 23

#define MAVLINK_MSG_OBSTACLE_DISTANCE_FIELD_DISTANCES_LEN 72

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OBSTACLE_DISTANCE { \
    330, \
    "OBSTACLE_DISTANCE", \
    9, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_obstacle_distance_t, time_usec) }, \
         { "sensor_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 156, offsetof(mavlink_obstacle_distance_t, sensor_type) }, \
         { "distances", NULL, MAVLINK_TYPE_UINT16_T, 72, 8, offsetof(mavlink_obstacle_distance_t, distances) }, \
         { "increment", NULL, MAVLINK_TYPE_UINT8_T, 0, 157, offsetof(mavlink_obstacle_distance_t, increment) }, \
         { "min_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 152, offsetof(mavlink_obstacle_distance_t, min_distance) }, \
         { "max_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 154, offsetof(mavlink_obstacle_distance_t, max_distance) }, \
         { "increment_f", NULL, MAVLINK_TYPE_FLOAT, 0, 158, offsetof(mavlink_obstacle_distance_t, increment_f) }, \
         { "angle_offset", NULL, MAVLINK_TYPE_FLOAT, 0, 162, offsetof(mavlink_obstacle_distance_t, angle_offset) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 166, offsetof(mavlink_obstacle_distance_t, frame) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OBSTACLE_DISTANCE { \
    "OBSTACLE_DISTANCE", \
    9, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_obstacle_distance_t, time_usec) }, \
         { "sensor_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 156, offsetof(mavlink_obstacle_distance_t, sensor_type) }, \
         { "distances", NULL, MAVLINK_TYPE_UINT16_T, 72, 8, offsetof(mavlink_obstacle_distance_t, distances) }, \
         { "increment", NULL, MAVLINK_TYPE_UINT8_T, 0, 157, offsetof(mavlink_obstacle_distance_t, increment) }, \
         { "min_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 152, offsetof(mavlink_obstacle_distance_t, min_distance) }, \
         { "max_distance", NULL, MAVLINK_TYPE_UINT16_T, 0, 154, offsetof(mavlink_obstacle_distance_t, max_distance) }, \
         { "increment_f", NULL, MAVLINK_TYPE_FLOAT, 0, 158, offsetof(mavlink_obstacle_distance_t, increment_f) }, \
         { "angle_offset", NULL, MAVLINK_TYPE_FLOAT, 0, 162, offsetof(mavlink_obstacle_distance_t, angle_offset) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 166, offsetof(mavlink_obstacle_distance_t, frame) }, \
         } \
}
#endif

/**
 * @brief Pack a obstacle_distance message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param sensor_type  Class id of the distance sensor type.
 * @param distances [cm] Distance of obstacles around the vehicle with index 0 corresponding to north + angle_offset, unless otherwise specified in the frame. A value of 0 is valid and means that the obstacle is practically touching the sensor. A value of max_distance +1 means no obstacle is present. A value of UINT16_MAX for unknown/not used. In a array element, one unit corresponds to 1cm.
 * @param increment [deg] Angular width in degrees of each array element. Increment direction is clockwise. This field is ignored if increment_f is non-zero.
 * @param min_distance [cm] Minimum distance the sensor can measure.
 * @param max_distance [cm] Maximum distance the sensor can measure.
 * @param increment_f [deg] Angular width in degrees of each array element as a float. If non-zero then this value is used instead of the uint8_t increment field. Positive is clockwise direction, negative is counter-clockwise.
 * @param angle_offset [deg] Relative angle offset of the 0-index element in the distances array. Value of 0 corresponds to forward. Positive is clockwise direction, negative is counter-clockwise.
 * @param frame  Coordinate frame of reference for the yaw rotation and offset of the sensor data. Defaults to MAV_FRAME_GLOBAL, which is north aligned. For body-mounted sensors use MAV_FRAME_BODY_FRD, which is vehicle front aligned.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_obstacle_distance_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t sensor_type, const uint16_t *distances, uint8_t increment, uint16_t min_distance, uint16_t max_distance, float increment_f, float angle_offset, uint8_t frame)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint16_t(msg->payloads, 152, min_distance);
    _mav_put_uint16_t(msg->payloads, 154, max_distance);
    _mav_put_uint8_t(msg->payloads, 156, sensor_type);
    _mav_put_uint8_t(msg->payloads, 157, increment);
    _mav_put_float(msg->payloads, 158, increment_f);
    _mav_put_float(msg->payloads, 162, angle_offset);
    _mav_put_uint8_t(msg->payloads, 166, frame);
    _mav_put_uint16_t_array(msg->payloads, 8, distances, 72);
    msg->msgid = MAVLINK_MSG_ID_OBSTACLE_DISTANCE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
}

/**
 * @brief Pack a obstacle_distance message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param sensor_type  Class id of the distance sensor type.
 * @param distances [cm] Distance of obstacles around the vehicle with index 0 corresponding to north + angle_offset, unless otherwise specified in the frame. A value of 0 is valid and means that the obstacle is practically touching the sensor. A value of max_distance +1 means no obstacle is present. A value of UINT16_MAX for unknown/not used. In a array element, one unit corresponds to 1cm.
 * @param increment [deg] Angular width in degrees of each array element. Increment direction is clockwise. This field is ignored if increment_f is non-zero.
 * @param min_distance [cm] Minimum distance the sensor can measure.
 * @param max_distance [cm] Maximum distance the sensor can measure.
 * @param increment_f [deg] Angular width in degrees of each array element as a float. If non-zero then this value is used instead of the uint8_t increment field. Positive is clockwise direction, negative is counter-clockwise.
 * @param angle_offset [deg] Relative angle offset of the 0-index element in the distances array. Value of 0 corresponds to forward. Positive is clockwise direction, negative is counter-clockwise.
 * @param frame  Coordinate frame of reference for the yaw rotation and offset of the sensor data. Defaults to MAV_FRAME_GLOBAL, which is north aligned. For body-mounted sensors use MAV_FRAME_BODY_FRD, which is vehicle front aligned.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_obstacle_distance_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t sensor_type,const uint16_t *distances,uint8_t increment,uint16_t min_distance,uint16_t max_distance,float increment_f,float angle_offset,uint8_t frame)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint16_t(msg->payloads, 152, min_distance);
    _mav_put_uint16_t(msg->payloads, 154, max_distance);
    _mav_put_uint8_t(msg->payloads, 156, sensor_type);
    _mav_put_uint8_t(msg->payloads, 157, increment);
    _mav_put_float(msg->payloads, 158, increment_f);
    _mav_put_float(msg->payloads, 162, angle_offset);
    _mav_put_uint8_t(msg->payloads, 166, frame);
    _mav_put_uint16_t_array(msg->payloads, 8, distances, 72);

    msg->msgid = MAVLINK_MSG_ID_OBSTACLE_DISTANCE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
}

/**
 * @brief Encode a obstacle_distance struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param obstacle_distance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_obstacle_distance_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_obstacle_distance_t* obstacle_distance)
{
    return mavlink_msg_obstacle_distance_pack(system_id, component_id, msg, obstacle_distance->time_usec, obstacle_distance->sensor_type, obstacle_distance->distances, obstacle_distance->increment, obstacle_distance->min_distance, obstacle_distance->max_distance, obstacle_distance->increment_f, obstacle_distance->angle_offset, obstacle_distance->frame);
}

/**
 * @brief Encode a obstacle_distance struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param obstacle_distance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_obstacle_distance_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_obstacle_distance_t* obstacle_distance)
{
    return mavlink_msg_obstacle_distance_pack_chan(system_id, component_id, chan, msg, obstacle_distance->time_usec, obstacle_distance->sensor_type, obstacle_distance->distances, obstacle_distance->increment, obstacle_distance->min_distance, obstacle_distance->max_distance, obstacle_distance->increment_f, obstacle_distance->angle_offset, obstacle_distance->frame);
}

// MESSAGE OBSTACLE_DISTANCE UNPACKING


/**
 * @brief Get field time_usec from obstacle_distance message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_obstacle_distance_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field sensor_type from obstacle_distance message
 *
 * @return  Class id of the distance sensor type.
 */
static inline uint8_t mavlink_msg_obstacle_distance_get_sensor_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  156);
}

/**
 * @brief Get field distances from obstacle_distance message
 *
 * @return [cm] Distance of obstacles around the vehicle with index 0 corresponding to north + angle_offset, unless otherwise specified in the frame. A value of 0 is valid and means that the obstacle is practically touching the sensor. A value of max_distance +1 means no obstacle is present. A value of UINT16_MAX for unknown/not used. In a array element, one unit corresponds to 1cm.
 */
static inline uint16_t mavlink_msg_obstacle_distance_get_distances(const mavlink_message_t* msg, uint16_t *distances)
{
    return _MAV_RETURN_uint16_t_array(msg, distances, 72,  8);
}

/**
 * @brief Get field increment from obstacle_distance message
 *
 * @return [deg] Angular width in degrees of each array element. Increment direction is clockwise. This field is ignored if increment_f is non-zero.
 */
static inline uint8_t mavlink_msg_obstacle_distance_get_increment(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  157);
}

/**
 * @brief Get field min_distance from obstacle_distance message
 *
 * @return [cm] Minimum distance the sensor can measure.
 */
static inline uint16_t mavlink_msg_obstacle_distance_get_min_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  152);
}

/**
 * @brief Get field max_distance from obstacle_distance message
 *
 * @return [cm] Maximum distance the sensor can measure.
 */
static inline uint16_t mavlink_msg_obstacle_distance_get_max_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  154);
}

/**
 * @brief Get field increment_f from obstacle_distance message
 *
 * @return [deg] Angular width in degrees of each array element as a float. If non-zero then this value is used instead of the uint8_t increment field. Positive is clockwise direction, negative is counter-clockwise.
 */
static inline float mavlink_msg_obstacle_distance_get_increment_f(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  158);
}

/**
 * @brief Get field angle_offset from obstacle_distance message
 *
 * @return [deg] Relative angle offset of the 0-index element in the distances array. Value of 0 corresponds to forward. Positive is clockwise direction, negative is counter-clockwise.
 */
static inline float mavlink_msg_obstacle_distance_get_angle_offset(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  162);
}

/**
 * @brief Get field frame from obstacle_distance message
 *
 * @return  Coordinate frame of reference for the yaw rotation and offset of the sensor data. Defaults to MAV_FRAME_GLOBAL, which is north aligned. For body-mounted sensors use MAV_FRAME_BODY_FRD, which is vehicle front aligned.
 */
static inline uint8_t mavlink_msg_obstacle_distance_get_frame(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  166);
}

/**
 * @brief Decode a obstacle_distance message into a struct
 *
 * @param msg The message to decode
 * @param obstacle_distance C-struct to decode the message contents into
 */
static inline void mavlink_msg_obstacle_distance_decode(const mavlink_message_t* msg, mavlink_obstacle_distance_t* obstacle_distance)
{
    obstacle_distance->time_usec = mavlink_msg_obstacle_distance_get_time_usec(msg);
    mavlink_msg_obstacle_distance_get_distances(msg, obstacle_distance->distances);
    obstacle_distance->min_distance = mavlink_msg_obstacle_distance_get_min_distance(msg);
    obstacle_distance->max_distance = mavlink_msg_obstacle_distance_get_max_distance(msg);
    obstacle_distance->sensor_type = mavlink_msg_obstacle_distance_get_sensor_type(msg);
    obstacle_distance->increment = mavlink_msg_obstacle_distance_get_increment(msg);
    obstacle_distance->increment_f = mavlink_msg_obstacle_distance_get_increment_f(msg);
    obstacle_distance->angle_offset = mavlink_msg_obstacle_distance_get_angle_offset(msg);
    obstacle_distance->frame = mavlink_msg_obstacle_distance_get_frame(msg);
}
