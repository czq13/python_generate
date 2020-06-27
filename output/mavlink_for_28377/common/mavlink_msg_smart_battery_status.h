#ifndef MAVLINK_MSG_smart_battery_status
#define MAVLINK_MSG_smart_battery_status
// MESSAGE SMART_BATTERY_STATUS PACKING

#define MAVLINK_MSG_ID_SMART_BATTERY_STATUS 371

typedef struct __mavlink_smart_battery_status_t {
 int32_t fault_bitmask; /*<  Fault/health indications.*/
 int32_t time_remaining; /*< [s] Estimated remaining battery time. -1: field not provided.*/
 uint16_t id; /*<  Battery ID*/
 int16_t capacity_remaining; /*< [%] Remaining battery energy. Values: [0-100], -1: field not provided.*/
 int16_t current; /*< [cA] Battery current (through all cells/loads). Positive if discharging, negative if charging. UINT16_MAX: field not provided.*/
 int16_t temperature; /*< [cdegC] Battery temperature. -1: field not provided.*/
 uint16_t cell_offset; /*<  The cell number of the first index in the 'voltages' array field. Using this field allows you to specify cell voltages for batteries with more than 16 cells.*/
 uint16_t voltages[16]; /*< [mV] Individual cell voltages. Batteries with more 16 cells can use the cell_offset field to specify the cell offset for the array specified in the current message . Index values above the valid cell count for this battery should have the UINT16_MAX value.*/
} mavlink_smart_battery_status_t;

#define MAVLINK_MSG_ID_SMART_BATTERY_STATUS_LEN 50
#define MAVLINK_MSG_ID_SMART_BATTERY_STATUS_MIN_LEN 50
#define MAVLINK_MSG_ID_371_LEN 50
#define MAVLINK_MSG_ID_371_MIN_LEN 50

#define MAVLINK_MSG_ID_SMART_BATTERY_STATUS_CRC 161
#define MAVLINK_MSG_ID_371_CRC 161

#define MAVLINK_MSG_SMART_BATTERY_STATUS_FIELD_VOLTAGES_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SMART_BATTERY_STATUS { \
    371, \
    "SMART_BATTERY_STATUS", \
    8, \
    {  { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_smart_battery_status_t, id) }, \
         { "capacity_remaining", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_smart_battery_status_t, capacity_remaining) }, \
         { "current", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_smart_battery_status_t, current) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_smart_battery_status_t, temperature) }, \
         { "fault_bitmask", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_smart_battery_status_t, fault_bitmask) }, \
         { "time_remaining", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_smart_battery_status_t, time_remaining) }, \
         { "cell_offset", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_smart_battery_status_t, cell_offset) }, \
         { "voltages", NULL, MAVLINK_TYPE_UINT16_T, 16, 18, offsetof(mavlink_smart_battery_status_t, voltages) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SMART_BATTERY_STATUS { \
    "SMART_BATTERY_STATUS", \
    8, \
    {  { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_smart_battery_status_t, id) }, \
         { "capacity_remaining", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_smart_battery_status_t, capacity_remaining) }, \
         { "current", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_smart_battery_status_t, current) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_smart_battery_status_t, temperature) }, \
         { "fault_bitmask", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_smart_battery_status_t, fault_bitmask) }, \
         { "time_remaining", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_smart_battery_status_t, time_remaining) }, \
         { "cell_offset", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_smart_battery_status_t, cell_offset) }, \
         { "voltages", NULL, MAVLINK_TYPE_UINT16_T, 16, 18, offsetof(mavlink_smart_battery_status_t, voltages) }, \
         } \
}
#endif

/**
 * @brief Pack a smart_battery_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id  Battery ID
 * @param capacity_remaining [%] Remaining battery energy. Values: [0-100], -1: field not provided.
 * @param current [cA] Battery current (through all cells/loads). Positive if discharging, negative if charging. UINT16_MAX: field not provided.
 * @param temperature [cdegC] Battery temperature. -1: field not provided.
 * @param fault_bitmask  Fault/health indications.
 * @param time_remaining [s] Estimated remaining battery time. -1: field not provided.
 * @param cell_offset  The cell number of the first index in the 'voltages' array field. Using this field allows you to specify cell voltages for batteries with more than 16 cells.
 * @param voltages [mV] Individual cell voltages. Batteries with more 16 cells can use the cell_offset field to specify the cell offset for the array specified in the current message . Index values above the valid cell count for this battery should have the UINT16_MAX value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_smart_battery_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t id, int16_t capacity_remaining, int16_t current, int16_t temperature, int32_t fault_bitmask, int32_t time_remaining, uint16_t cell_offset, const uint16_t *voltages)
{
    _mav_put_int32_t(msg->payloads, 0, fault_bitmask);
    _mav_put_int32_t(msg->payloads, 4, time_remaining);
    _mav_put_uint16_t(msg->payloads, 8, id);
    _mav_put_int16_t(msg->payloads, 10, capacity_remaining);
    _mav_put_int16_t(msg->payloads, 12, current);
    _mav_put_int16_t(msg->payloads, 14, temperature);
    _mav_put_uint16_t(msg->payloads, 16, cell_offset);
    _mav_put_uint16_t_array(msg->payloads, 18, voltages, 16);
    msg->msgid = MAVLINK_MSG_ID_SMART_BATTERY_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SMART_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_SMART_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_SMART_BATTERY_STATUS_CRC);
}

/**
 * @brief Pack a smart_battery_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id  Battery ID
 * @param capacity_remaining [%] Remaining battery energy. Values: [0-100], -1: field not provided.
 * @param current [cA] Battery current (through all cells/loads). Positive if discharging, negative if charging. UINT16_MAX: field not provided.
 * @param temperature [cdegC] Battery temperature. -1: field not provided.
 * @param fault_bitmask  Fault/health indications.
 * @param time_remaining [s] Estimated remaining battery time. -1: field not provided.
 * @param cell_offset  The cell number of the first index in the 'voltages' array field. Using this field allows you to specify cell voltages for batteries with more than 16 cells.
 * @param voltages [mV] Individual cell voltages. Batteries with more 16 cells can use the cell_offset field to specify the cell offset for the array specified in the current message . Index values above the valid cell count for this battery should have the UINT16_MAX value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_smart_battery_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t id,int16_t capacity_remaining,int16_t current,int16_t temperature,int32_t fault_bitmask,int32_t time_remaining,uint16_t cell_offset,const uint16_t *voltages)
{
    _mav_put_int32_t(msg->payloads, 0, fault_bitmask);
    _mav_put_int32_t(msg->payloads, 4, time_remaining);
    _mav_put_uint16_t(msg->payloads, 8, id);
    _mav_put_int16_t(msg->payloads, 10, capacity_remaining);
    _mav_put_int16_t(msg->payloads, 12, current);
    _mav_put_int16_t(msg->payloads, 14, temperature);
    _mav_put_uint16_t(msg->payloads, 16, cell_offset);
    _mav_put_uint16_t_array(msg->payloads, 18, voltages, 16);

    msg->msgid = MAVLINK_MSG_ID_SMART_BATTERY_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SMART_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_SMART_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_SMART_BATTERY_STATUS_CRC);
}

/**
 * @brief Encode a smart_battery_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param smart_battery_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_smart_battery_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_smart_battery_status_t* smart_battery_status)
{
    return mavlink_msg_smart_battery_status_pack(system_id, component_id, msg, smart_battery_status->id, smart_battery_status->capacity_remaining, smart_battery_status->current, smart_battery_status->temperature, smart_battery_status->fault_bitmask, smart_battery_status->time_remaining, smart_battery_status->cell_offset, smart_battery_status->voltages);
}

/**
 * @brief Encode a smart_battery_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param smart_battery_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_smart_battery_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_smart_battery_status_t* smart_battery_status)
{
    return mavlink_msg_smart_battery_status_pack_chan(system_id, component_id, chan, msg, smart_battery_status->id, smart_battery_status->capacity_remaining, smart_battery_status->current, smart_battery_status->temperature, smart_battery_status->fault_bitmask, smart_battery_status->time_remaining, smart_battery_status->cell_offset, smart_battery_status->voltages);
}

// MESSAGE SMART_BATTERY_STATUS UNPACKING


/**
 * @brief Get field id from smart_battery_status message
 *
 * @return  Battery ID
 */
static inline uint16_t mavlink_msg_smart_battery_status_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field capacity_remaining from smart_battery_status message
 *
 * @return [%] Remaining battery energy. Values: [0-100], -1: field not provided.
 */
static inline int16_t mavlink_msg_smart_battery_status_get_capacity_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field current from smart_battery_status message
 *
 * @return [cA] Battery current (through all cells/loads). Positive if discharging, negative if charging. UINT16_MAX: field not provided.
 */
static inline int16_t mavlink_msg_smart_battery_status_get_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field temperature from smart_battery_status message
 *
 * @return [cdegC] Battery temperature. -1: field not provided.
 */
static inline int16_t mavlink_msg_smart_battery_status_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field fault_bitmask from smart_battery_status message
 *
 * @return  Fault/health indications.
 */
static inline int32_t mavlink_msg_smart_battery_status_get_fault_bitmask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field time_remaining from smart_battery_status message
 *
 * @return [s] Estimated remaining battery time. -1: field not provided.
 */
static inline int32_t mavlink_msg_smart_battery_status_get_time_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field cell_offset from smart_battery_status message
 *
 * @return  The cell number of the first index in the 'voltages' array field. Using this field allows you to specify cell voltages for batteries with more than 16 cells.
 */
static inline uint16_t mavlink_msg_smart_battery_status_get_cell_offset(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field voltages from smart_battery_status message
 *
 * @return [mV] Individual cell voltages. Batteries with more 16 cells can use the cell_offset field to specify the cell offset for the array specified in the current message . Index values above the valid cell count for this battery should have the UINT16_MAX value.
 */
static inline uint16_t mavlink_msg_smart_battery_status_get_voltages(const mavlink_message_t* msg, uint16_t *voltages)
{
    return _MAV_RETURN_uint16_t_array(msg, voltages, 16,  18);
}

/**
 * @brief Decode a smart_battery_status message into a struct
 *
 * @param msg The message to decode
 * @param smart_battery_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_smart_battery_status_decode(const mavlink_message_t* msg, mavlink_smart_battery_status_t* smart_battery_status)
{
    smart_battery_status->fault_bitmask = mavlink_msg_smart_battery_status_get_fault_bitmask(msg);
    smart_battery_status->time_remaining = mavlink_msg_smart_battery_status_get_time_remaining(msg);
    smart_battery_status->id = mavlink_msg_smart_battery_status_get_id(msg);
    smart_battery_status->capacity_remaining = mavlink_msg_smart_battery_status_get_capacity_remaining(msg);
    smart_battery_status->current = mavlink_msg_smart_battery_status_get_current(msg);
    smart_battery_status->temperature = mavlink_msg_smart_battery_status_get_temperature(msg);
    smart_battery_status->cell_offset = mavlink_msg_smart_battery_status_get_cell_offset(msg);
    mavlink_msg_smart_battery_status_get_voltages(msg, smart_battery_status->voltages);
}
#endif
