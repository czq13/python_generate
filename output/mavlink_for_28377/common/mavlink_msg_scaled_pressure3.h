#ifndef MAVLINK_MSG_scaled_pressure3
#define MAVLINK_MSG_scaled_pressure3
// MESSAGE SCALED_PRESSURE3 PACKING

#define MAVLINK_MSG_ID_SCALED_PRESSURE3 143

typedef struct __mavlink_scaled_pressure3_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float press_abs; /*< [hPa] Absolute pressure*/
 float press_diff; /*< [hPa] Differential pressure*/
 int16_t temperature; /*< [cdegC] Temperature measurement*/
} mavlink_scaled_pressure3_t;

#define MAVLINK_MSG_ID_SCALED_PRESSURE3_LEN 14
#define MAVLINK_MSG_ID_SCALED_PRESSURE3_MIN_LEN 14
#define MAVLINK_MSG_ID_143_LEN 14
#define MAVLINK_MSG_ID_143_MIN_LEN 14

#define MAVLINK_MSG_ID_SCALED_PRESSURE3_CRC 131
#define MAVLINK_MSG_ID_143_CRC 131



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SCALED_PRESSURE3 { \
    143, \
    "SCALED_PRESSURE3", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_scaled_pressure3_t, time_boot_ms) }, \
         { "press_abs", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_scaled_pressure3_t, press_abs) }, \
         { "press_diff", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_scaled_pressure3_t, press_diff) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_scaled_pressure3_t, temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SCALED_PRESSURE3 { \
    "SCALED_PRESSURE3", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_scaled_pressure3_t, time_boot_ms) }, \
         { "press_abs", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_scaled_pressure3_t, press_abs) }, \
         { "press_diff", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_scaled_pressure3_t, press_diff) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_scaled_pressure3_t, temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a scaled_pressure3 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param press_abs [hPa] Absolute pressure
 * @param press_diff [hPa] Differential pressure
 * @param temperature [cdegC] Temperature measurement
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_scaled_pressure3_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float press_abs, float press_diff, int16_t temperature)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_float(((char*)msg->payloads), 4, press_abs);
    _mav_put_float(((char*)msg->payloads), 8, press_diff);
    _mav_put_int16_t(((char*)msg->payloads), 12, temperature);

    msg->msgid = MAVLINK_MSG_ID_SCALED_PRESSURE3;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SCALED_PRESSURE3_MIN_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE3_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE3_CRC);
}

/**
 * @brief Pack a scaled_pressure3 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param press_abs [hPa] Absolute pressure
 * @param press_diff [hPa] Differential pressure
 * @param temperature [cdegC] Temperature measurement
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_scaled_pressure3_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,float press_abs,float press_diff,int16_t temperature)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_float(((char*)msg->payloads), 4, press_abs);
    _mav_put_float(((char*)msg->payloads), 8, press_diff);
    _mav_put_int16_t(((char*)msg->payloads), 12, temperature);


    msg->msgid = MAVLINK_MSG_ID_SCALED_PRESSURE3;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SCALED_PRESSURE3_MIN_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE3_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE3_CRC);
}

/**
 * @brief Encode a scaled_pressure3 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param scaled_pressure3 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_scaled_pressure3_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_scaled_pressure3_t* scaled_pressure3)
{
    return mavlink_msg_scaled_pressure3_pack(system_id, component_id, msg, scaled_pressure3->time_boot_ms, scaled_pressure3->press_abs, scaled_pressure3->press_diff, scaled_pressure3->temperature);
}

/**
 * @brief Encode a scaled_pressure3 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param scaled_pressure3 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_scaled_pressure3_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_scaled_pressure3_t* scaled_pressure3)
{
    return mavlink_msg_scaled_pressure3_pack_chan(system_id, component_id, chan, msg, scaled_pressure3->time_boot_ms, scaled_pressure3->press_abs, scaled_pressure3->press_diff, scaled_pressure3->temperature);
}

// MESSAGE SCALED_PRESSURE3 UNPACKING


/**
 * @brief Get field time_boot_ms from scaled_pressure3 message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_scaled_pressure3_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field press_abs from scaled_pressure3 message
 *
 * @return [hPa] Absolute pressure
 */
static inline float mavlink_msg_scaled_pressure3_get_press_abs(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field press_diff from scaled_pressure3 message
 *
 * @return [hPa] Differential pressure
 */
static inline float mavlink_msg_scaled_pressure3_get_press_diff(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field temperature from scaled_pressure3 message
 *
 * @return [cdegC] Temperature measurement
 */
static inline int16_t mavlink_msg_scaled_pressure3_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Decode a scaled_pressure3 message into a struct
 *
 * @param msg The message to decode
 * @param scaled_pressure3 C-struct to decode the message contents into
 */
static inline void mavlink_msg_scaled_pressure3_decode(const mavlink_message_t* msg, mavlink_scaled_pressure3_t* scaled_pressure3)
{
    scaled_pressure3->time_boot_ms = mavlink_msg_scaled_pressure3_get_time_boot_ms(msg);
    scaled_pressure3->press_abs = mavlink_msg_scaled_pressure3_get_press_abs(msg);
    scaled_pressure3->press_diff = mavlink_msg_scaled_pressure3_get_press_diff(msg);
    scaled_pressure3->temperature = mavlink_msg_scaled_pressure3_get_temperature(msg);
}
#endif
