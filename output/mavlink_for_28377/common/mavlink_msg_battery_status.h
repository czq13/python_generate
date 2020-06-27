#pragma once
// MESSAGE BATTERY_STATUS PACKING

#define MAVLINK_MSG_ID_BATTERY_STATUS 147

typedef struct __mavlink_battery_status_t {
 int32_t current_consumed; /*< [mAh] Consumed charge, -1: autopilot does not provide consumption estimate*/
 int32_t energy_consumed; /*< [hJ] Consumed energy, -1: autopilot does not provide energy consumption estimate*/
 int16_t temperature; /*< [cdegC] Temperature of the battery. INT16_MAX for unknown temperature.*/
 uint16_t voltages[10]; /*< [mV] Battery voltage of cells. Cells above the valid cell count for this battery should have the UINT16_MAX value. If individual cell voltages are unknown or not measured for this battery, then the overall battery voltage should be filled in cell 0, with all others set to UINT16_MAX. If the voltage of the battery is greater than (UINT16_MAX - 1), then cell 0 should be set to (UINT16_MAX - 1), and cell 1 to the remaining voltage. This can be extended to multiple cells if the total voltage is greater than 2 * (UINT16_MAX - 1).*/
 int16_t current_battery; /*< [cA] Battery current, -1: autopilot does not measure the current*/
 uint8_t id; /*<  Battery ID*/
 uint8_t battery_function; /*<  Function of the battery*/
 uint8_t type; /*<  Type (chemistry) of the battery*/
 int8_t battery_remaining; /*< [%] Remaining battery energy. Values: [0-100], -1: autopilot does not estimate the remaining battery.*/
 int32_t time_remaining; /*< [s] Remaining battery time, 0: autopilot does not provide remaining battery time estimate*/
 uint8_t charge_state; /*<  State for extent of discharge, provided by autopilot for warning or external reactions*/
} mavlink_battery_status_t;

#define MAVLINK_MSG_ID_BATTERY_STATUS_LEN 41
#define MAVLINK_MSG_ID_BATTERY_STATUS_MIN_LEN 36
#define MAVLINK_MSG_ID_147_LEN 41
#define MAVLINK_MSG_ID_147_MIN_LEN 36

#define MAVLINK_MSG_ID_BATTERY_STATUS_CRC 154
#define MAVLINK_MSG_ID_147_CRC 154

#define MAVLINK_MSG_BATTERY_STATUS_FIELD_VOLTAGES_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BATTERY_STATUS { \
    147, \
    "BATTERY_STATUS", \
    11, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_battery_status_t, id) }, \
         { "battery_function", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_battery_status_t, battery_function) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_battery_status_t, type) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_battery_status_t, temperature) }, \
         { "voltages", NULL, MAVLINK_TYPE_UINT16_T, 10, 10, offsetof(mavlink_battery_status_t, voltages) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_battery_status_t, current_battery) }, \
         { "current_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_battery_status_t, current_consumed) }, \
         { "energy_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_battery_status_t, energy_consumed) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 35, offsetof(mavlink_battery_status_t, battery_remaining) }, \
         { "time_remaining", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_battery_status_t, time_remaining) }, \
         { "charge_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_battery_status_t, charge_state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BATTERY_STATUS { \
    "BATTERY_STATUS", \
    11, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_battery_status_t, id) }, \
         { "battery_function", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_battery_status_t, battery_function) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_battery_status_t, type) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_battery_status_t, temperature) }, \
         { "voltages", NULL, MAVLINK_TYPE_UINT16_T, 10, 10, offsetof(mavlink_battery_status_t, voltages) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_battery_status_t, current_battery) }, \
         { "current_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_battery_status_t, current_consumed) }, \
         { "energy_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_battery_status_t, energy_consumed) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 35, offsetof(mavlink_battery_status_t, battery_remaining) }, \
         { "time_remaining", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_battery_status_t, time_remaining) }, \
         { "charge_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_battery_status_t, charge_state) }, \
         } \
}
#endif

/**
 * @brief Pack a battery_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id  Battery ID
 * @param battery_function  Function of the battery
 * @param type  Type (chemistry) of the battery
 * @param temperature [cdegC] Temperature of the battery. INT16_MAX for unknown temperature.
 * @param voltages [mV] Battery voltage of cells. Cells above the valid cell count for this battery should have the UINT16_MAX value. If individual cell voltages are unknown or not measured for this battery, then the overall battery voltage should be filled in cell 0, with all others set to UINT16_MAX. If the voltage of the battery is greater than (UINT16_MAX - 1), then cell 0 should be set to (UINT16_MAX - 1), and cell 1 to the remaining voltage. This can be extended to multiple cells if the total voltage is greater than 2 * (UINT16_MAX - 1).
 * @param current_battery [cA] Battery current, -1: autopilot does not measure the current
 * @param current_consumed [mAh] Consumed charge, -1: autopilot does not provide consumption estimate
 * @param energy_consumed [hJ] Consumed energy, -1: autopilot does not provide energy consumption estimate
 * @param battery_remaining [%] Remaining battery energy. Values: [0-100], -1: autopilot does not estimate the remaining battery.
 * @param time_remaining [s] Remaining battery time, 0: autopilot does not provide remaining battery time estimate
 * @param charge_state  State for extent of discharge, provided by autopilot for warning or external reactions
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_battery_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t id, uint8_t battery_function, uint8_t type, int16_t temperature, const uint16_t *voltages, int16_t current_battery, int32_t current_consumed, int32_t energy_consumed, int8_t battery_remaining, int32_t time_remaining, uint8_t charge_state)
{
    _mav_put_int32_t(msg->payloads, 0, current_consumed);
    _mav_put_int32_t(msg->payloads, 4, energy_consumed);
    _mav_put_int16_t(msg->payloads, 8, temperature);
    _mav_put_int16_t(msg->payloads, 30, current_battery);
    _mav_put_uint8_t(msg->payloads, 32, id);
    _mav_put_uint8_t(msg->payloads, 33, battery_function);
    _mav_put_uint8_t(msg->payloads, 34, type);
    _mav_put_int8_t(msg->payloads, 35, battery_remaining);
    _mav_put_int32_t(msg->payloads, 36, time_remaining);
    _mav_put_uint8_t(msg->payloads, 40, charge_state);
    _mav_put_uint16_t_array(msg->payloads, 10, voltages, 10);
    msg->msgid = MAVLINK_MSG_ID_BATTERY_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_BATTERY_STATUS_CRC);
}

/**
 * @brief Pack a battery_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id  Battery ID
 * @param battery_function  Function of the battery
 * @param type  Type (chemistry) of the battery
 * @param temperature [cdegC] Temperature of the battery. INT16_MAX for unknown temperature.
 * @param voltages [mV] Battery voltage of cells. Cells above the valid cell count for this battery should have the UINT16_MAX value. If individual cell voltages are unknown or not measured for this battery, then the overall battery voltage should be filled in cell 0, with all others set to UINT16_MAX. If the voltage of the battery is greater than (UINT16_MAX - 1), then cell 0 should be set to (UINT16_MAX - 1), and cell 1 to the remaining voltage. This can be extended to multiple cells if the total voltage is greater than 2 * (UINT16_MAX - 1).
 * @param current_battery [cA] Battery current, -1: autopilot does not measure the current
 * @param current_consumed [mAh] Consumed charge, -1: autopilot does not provide consumption estimate
 * @param energy_consumed [hJ] Consumed energy, -1: autopilot does not provide energy consumption estimate
 * @param battery_remaining [%] Remaining battery energy. Values: [0-100], -1: autopilot does not estimate the remaining battery.
 * @param time_remaining [s] Remaining battery time, 0: autopilot does not provide remaining battery time estimate
 * @param charge_state  State for extent of discharge, provided by autopilot for warning or external reactions
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_battery_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t id,uint8_t battery_function,uint8_t type,int16_t temperature,const uint16_t *voltages,int16_t current_battery,int32_t current_consumed,int32_t energy_consumed,int8_t battery_remaining,int32_t time_remaining,uint8_t charge_state)
{
    _mav_put_int32_t(msg->payloads, 0, current_consumed);
    _mav_put_int32_t(msg->payloads, 4, energy_consumed);
    _mav_put_int16_t(msg->payloads, 8, temperature);
    _mav_put_int16_t(msg->payloads, 30, current_battery);
    _mav_put_uint8_t(msg->payloads, 32, id);
    _mav_put_uint8_t(msg->payloads, 33, battery_function);
    _mav_put_uint8_t(msg->payloads, 34, type);
    _mav_put_int8_t(msg->payloads, 35, battery_remaining);
    _mav_put_int32_t(msg->payloads, 36, time_remaining);
    _mav_put_uint8_t(msg->payloads, 40, charge_state);
    _mav_put_uint16_t_array(msg->payloads, 10, voltages, 10);

    msg->msgid = MAVLINK_MSG_ID_BATTERY_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_BATTERY_STATUS_CRC);
}

/**
 * @brief Encode a battery_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param battery_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_battery_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_battery_status_t* battery_status)
{
    return mavlink_msg_battery_status_pack(system_id, component_id, msg, battery_status->id, battery_status->battery_function, battery_status->type, battery_status->temperature, battery_status->voltages, battery_status->current_battery, battery_status->current_consumed, battery_status->energy_consumed, battery_status->battery_remaining, battery_status->time_remaining, battery_status->charge_state);
}

/**
 * @brief Encode a battery_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param battery_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_battery_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_battery_status_t* battery_status)
{
    return mavlink_msg_battery_status_pack_chan(system_id, component_id, chan, msg, battery_status->id, battery_status->battery_function, battery_status->type, battery_status->temperature, battery_status->voltages, battery_status->current_battery, battery_status->current_consumed, battery_status->energy_consumed, battery_status->battery_remaining, battery_status->time_remaining, battery_status->charge_state);
}

// MESSAGE BATTERY_STATUS UNPACKING


/**
 * @brief Get field id from battery_status message
 *
 * @return  Battery ID
 */
static inline uint8_t mavlink_msg_battery_status_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field battery_function from battery_status message
 *
 * @return  Function of the battery
 */
static inline uint8_t mavlink_msg_battery_status_get_battery_function(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Get field type from battery_status message
 *
 * @return  Type (chemistry) of the battery
 */
static inline uint8_t mavlink_msg_battery_status_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field temperature from battery_status message
 *
 * @return [cdegC] Temperature of the battery. INT16_MAX for unknown temperature.
 */
static inline int16_t mavlink_msg_battery_status_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field voltages from battery_status message
 *
 * @return [mV] Battery voltage of cells. Cells above the valid cell count for this battery should have the UINT16_MAX value. If individual cell voltages are unknown or not measured for this battery, then the overall battery voltage should be filled in cell 0, with all others set to UINT16_MAX. If the voltage of the battery is greater than (UINT16_MAX - 1), then cell 0 should be set to (UINT16_MAX - 1), and cell 1 to the remaining voltage. This can be extended to multiple cells if the total voltage is greater than 2 * (UINT16_MAX - 1).
 */
static inline uint16_t mavlink_msg_battery_status_get_voltages(const mavlink_message_t* msg, uint16_t *voltages)
{
    return _MAV_RETURN_uint16_t_array(msg, voltages, 10,  10);
}

/**
 * @brief Get field current_battery from battery_status message
 *
 * @return [cA] Battery current, -1: autopilot does not measure the current
 */
static inline int16_t mavlink_msg_battery_status_get_current_battery(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field current_consumed from battery_status message
 *
 * @return [mAh] Consumed charge, -1: autopilot does not provide consumption estimate
 */
static inline int32_t mavlink_msg_battery_status_get_current_consumed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field energy_consumed from battery_status message
 *
 * @return [hJ] Consumed energy, -1: autopilot does not provide energy consumption estimate
 */
static inline int32_t mavlink_msg_battery_status_get_energy_consumed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field battery_remaining from battery_status message
 *
 * @return [%] Remaining battery energy. Values: [0-100], -1: autopilot does not estimate the remaining battery.
 */
static inline int8_t mavlink_msg_battery_status_get_battery_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  35);
}

/**
 * @brief Get field time_remaining from battery_status message
 *
 * @return [s] Remaining battery time, 0: autopilot does not provide remaining battery time estimate
 */
static inline int32_t mavlink_msg_battery_status_get_time_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Get field charge_state from battery_status message
 *
 * @return  State for extent of discharge, provided by autopilot for warning or external reactions
 */
static inline uint8_t mavlink_msg_battery_status_get_charge_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Decode a battery_status message into a struct
 *
 * @param msg The message to decode
 * @param battery_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_battery_status_decode(const mavlink_message_t* msg, mavlink_battery_status_t* battery_status)
{
    battery_status->current_consumed = mavlink_msg_battery_status_get_current_consumed(msg);
    battery_status->energy_consumed = mavlink_msg_battery_status_get_energy_consumed(msg);
    battery_status->temperature = mavlink_msg_battery_status_get_temperature(msg);
    mavlink_msg_battery_status_get_voltages(msg, battery_status->voltages);
    battery_status->current_battery = mavlink_msg_battery_status_get_current_battery(msg);
    battery_status->id = mavlink_msg_battery_status_get_id(msg);
    battery_status->battery_function = mavlink_msg_battery_status_get_battery_function(msg);
    battery_status->type = mavlink_msg_battery_status_get_type(msg);
    battery_status->battery_remaining = mavlink_msg_battery_status_get_battery_remaining(msg);
    battery_status->time_remaining = mavlink_msg_battery_status_get_time_remaining(msg);
    battery_status->charge_state = mavlink_msg_battery_status_get_charge_state(msg);
}
