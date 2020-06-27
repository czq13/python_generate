#ifndef MAVLINK_MSG_onboard_computer_status
#define MAVLINK_MSG_onboard_computer_status
// MESSAGE ONBOARD_COMPUTER_STATUS PACKING

#define MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS 390

typedef struct __mavlink_onboard_computer_status_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint32_t uptime; /*< [ms] Time since system boot.*/
 uint32_t ram_usage; /*< [MiB] Amount of used RAM on the component system. A value of UINT32_MAX implies the field is unused.*/
 uint32_t ram_total; /*< [MiB] Total amount of RAM on the component system. A value of UINT32_MAX implies the field is unused.*/
 uint32_t storage_type[4]; /*<  Storage type: 0: HDD, 1: SSD, 2: EMMC, 3: SD card (non-removable), 4: SD card (removable). A value of UINT32_MAX implies the field is unused.*/
 uint32_t storage_usage[4]; /*< [MiB] Amount of used storage space on the component system. A value of UINT32_MAX implies the field is unused.*/
 uint32_t storage_total[4]; /*< [MiB] Total amount of storage space on the component system. A value of UINT32_MAX implies the field is unused.*/
 uint32_t link_type[6]; /*<  Link type: 0-9: UART, 10-19: Wired network, 20-29: Wifi, 30-39: Point-to-point proprietary, 40-49: Mesh proprietary*/
 uint32_t link_tx_rate[6]; /*< [KiB/s] Network traffic from the component system. A value of UINT32_MAX implies the field is unused.*/
 uint32_t link_rx_rate[6]; /*< [KiB/s] Network traffic to the component system. A value of UINT32_MAX implies the field is unused.*/
 uint32_t link_tx_max[6]; /*< [KiB/s] Network capacity from the component system. A value of UINT32_MAX implies the field is unused.*/
 uint32_t link_rx_max[6]; /*< [KiB/s] Network capacity to the component system. A value of UINT32_MAX implies the field is unused.*/
 int16_t fan_speed[4]; /*< [rpm] Fan speeds. A value of INT16_MAX implies the field is unused.*/
 uint8_t type; /*<  Type of the onboard computer: 0: Mission computer primary, 1: Mission computer backup 1, 2: Mission computer backup 2, 3: Compute node, 4-5: Compute spares, 6-9: Payload computers.*/
 uint8_t cpu_cores[8]; /*<  CPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused.*/
 uint8_t cpu_combined[10]; /*<  Combined CPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused.*/
 uint8_t gpu_cores[4]; /*<  GPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused.*/
 uint8_t gpu_combined[10]; /*<  Combined GPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused.*/
 int8_t temperature_board; /*< [degC] Temperature of the board. A value of INT8_MAX implies the field is unused.*/
 int8_t temperature_core[8]; /*< [degC] Temperature of the CPU core. A value of INT8_MAX implies the field is unused.*/
} mavlink_onboard_computer_status_t;

#define MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS_LEN 238
#define MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS_MIN_LEN 238
#define MAVLINK_MSG_ID_390_LEN 238
#define MAVLINK_MSG_ID_390_MIN_LEN 238

#define MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS_CRC 156
#define MAVLINK_MSG_ID_390_CRC 156

#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_STORAGE_TYPE_LEN 4
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_STORAGE_USAGE_LEN 4
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_STORAGE_TOTAL_LEN 4
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_LINK_TYPE_LEN 6
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_LINK_TX_RATE_LEN 6
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_LINK_RX_RATE_LEN 6
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_LINK_TX_MAX_LEN 6
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_LINK_RX_MAX_LEN 6
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_FAN_SPEED_LEN 4
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_CPU_CORES_LEN 8
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_CPU_COMBINED_LEN 10
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_GPU_CORES_LEN 4
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_GPU_COMBINED_LEN 10
#define MAVLINK_MSG_ONBOARD_COMPUTER_STATUS_FIELD_TEMPERATURE_CORE_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ONBOARD_COMPUTER_STATUS { \
    390, \
    "ONBOARD_COMPUTER_STATUS", \
    20, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_onboard_computer_status_t, time_usec) }, \
         { "uptime", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_onboard_computer_status_t, uptime) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 196, offsetof(mavlink_onboard_computer_status_t, type) }, \
         { "cpu_cores", NULL, MAVLINK_TYPE_UINT8_T, 8, 197, offsetof(mavlink_onboard_computer_status_t, cpu_cores) }, \
         { "cpu_combined", NULL, MAVLINK_TYPE_UINT8_T, 10, 205, offsetof(mavlink_onboard_computer_status_t, cpu_combined) }, \
         { "gpu_cores", NULL, MAVLINK_TYPE_UINT8_T, 4, 215, offsetof(mavlink_onboard_computer_status_t, gpu_cores) }, \
         { "gpu_combined", NULL, MAVLINK_TYPE_UINT8_T, 10, 219, offsetof(mavlink_onboard_computer_status_t, gpu_combined) }, \
         { "temperature_board", NULL, MAVLINK_TYPE_INT8_T, 0, 229, offsetof(mavlink_onboard_computer_status_t, temperature_board) }, \
         { "temperature_core", NULL, MAVLINK_TYPE_INT8_T, 8, 230, offsetof(mavlink_onboard_computer_status_t, temperature_core) }, \
         { "fan_speed", NULL, MAVLINK_TYPE_INT16_T, 4, 188, offsetof(mavlink_onboard_computer_status_t, fan_speed) }, \
         { "ram_usage", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_onboard_computer_status_t, ram_usage) }, \
         { "ram_total", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_onboard_computer_status_t, ram_total) }, \
         { "storage_type", NULL, MAVLINK_TYPE_UINT32_T, 4, 20, offsetof(mavlink_onboard_computer_status_t, storage_type) }, \
         { "storage_usage", NULL, MAVLINK_TYPE_UINT32_T, 4, 36, offsetof(mavlink_onboard_computer_status_t, storage_usage) }, \
         { "storage_total", NULL, MAVLINK_TYPE_UINT32_T, 4, 52, offsetof(mavlink_onboard_computer_status_t, storage_total) }, \
         { "link_type", NULL, MAVLINK_TYPE_UINT32_T, 6, 68, offsetof(mavlink_onboard_computer_status_t, link_type) }, \
         { "link_tx_rate", NULL, MAVLINK_TYPE_UINT32_T, 6, 92, offsetof(mavlink_onboard_computer_status_t, link_tx_rate) }, \
         { "link_rx_rate", NULL, MAVLINK_TYPE_UINT32_T, 6, 116, offsetof(mavlink_onboard_computer_status_t, link_rx_rate) }, \
         { "link_tx_max", NULL, MAVLINK_TYPE_UINT32_T, 6, 140, offsetof(mavlink_onboard_computer_status_t, link_tx_max) }, \
         { "link_rx_max", NULL, MAVLINK_TYPE_UINT32_T, 6, 164, offsetof(mavlink_onboard_computer_status_t, link_rx_max) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ONBOARD_COMPUTER_STATUS { \
    "ONBOARD_COMPUTER_STATUS", \
    20, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_onboard_computer_status_t, time_usec) }, \
         { "uptime", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_onboard_computer_status_t, uptime) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 196, offsetof(mavlink_onboard_computer_status_t, type) }, \
         { "cpu_cores", NULL, MAVLINK_TYPE_UINT8_T, 8, 197, offsetof(mavlink_onboard_computer_status_t, cpu_cores) }, \
         { "cpu_combined", NULL, MAVLINK_TYPE_UINT8_T, 10, 205, offsetof(mavlink_onboard_computer_status_t, cpu_combined) }, \
         { "gpu_cores", NULL, MAVLINK_TYPE_UINT8_T, 4, 215, offsetof(mavlink_onboard_computer_status_t, gpu_cores) }, \
         { "gpu_combined", NULL, MAVLINK_TYPE_UINT8_T, 10, 219, offsetof(mavlink_onboard_computer_status_t, gpu_combined) }, \
         { "temperature_board", NULL, MAVLINK_TYPE_INT8_T, 0, 229, offsetof(mavlink_onboard_computer_status_t, temperature_board) }, \
         { "temperature_core", NULL, MAVLINK_TYPE_INT8_T, 8, 230, offsetof(mavlink_onboard_computer_status_t, temperature_core) }, \
         { "fan_speed", NULL, MAVLINK_TYPE_INT16_T, 4, 188, offsetof(mavlink_onboard_computer_status_t, fan_speed) }, \
         { "ram_usage", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_onboard_computer_status_t, ram_usage) }, \
         { "ram_total", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_onboard_computer_status_t, ram_total) }, \
         { "storage_type", NULL, MAVLINK_TYPE_UINT32_T, 4, 20, offsetof(mavlink_onboard_computer_status_t, storage_type) }, \
         { "storage_usage", NULL, MAVLINK_TYPE_UINT32_T, 4, 36, offsetof(mavlink_onboard_computer_status_t, storage_usage) }, \
         { "storage_total", NULL, MAVLINK_TYPE_UINT32_T, 4, 52, offsetof(mavlink_onboard_computer_status_t, storage_total) }, \
         { "link_type", NULL, MAVLINK_TYPE_UINT32_T, 6, 68, offsetof(mavlink_onboard_computer_status_t, link_type) }, \
         { "link_tx_rate", NULL, MAVLINK_TYPE_UINT32_T, 6, 92, offsetof(mavlink_onboard_computer_status_t, link_tx_rate) }, \
         { "link_rx_rate", NULL, MAVLINK_TYPE_UINT32_T, 6, 116, offsetof(mavlink_onboard_computer_status_t, link_rx_rate) }, \
         { "link_tx_max", NULL, MAVLINK_TYPE_UINT32_T, 6, 140, offsetof(mavlink_onboard_computer_status_t, link_tx_max) }, \
         { "link_rx_max", NULL, MAVLINK_TYPE_UINT32_T, 6, 164, offsetof(mavlink_onboard_computer_status_t, link_rx_max) }, \
         } \
}
#endif

/**
 * @brief Pack a onboard_computer_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param uptime [ms] Time since system boot.
 * @param type  Type of the onboard computer: 0: Mission computer primary, 1: Mission computer backup 1, 2: Mission computer backup 2, 3: Compute node, 4-5: Compute spares, 6-9: Payload computers.
 * @param cpu_cores  CPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused.
 * @param cpu_combined  Combined CPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused.
 * @param gpu_cores  GPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused.
 * @param gpu_combined  Combined GPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused.
 * @param temperature_board [degC] Temperature of the board. A value of INT8_MAX implies the field is unused.
 * @param temperature_core [degC] Temperature of the CPU core. A value of INT8_MAX implies the field is unused.
 * @param fan_speed [rpm] Fan speeds. A value of INT16_MAX implies the field is unused.
 * @param ram_usage [MiB] Amount of used RAM on the component system. A value of UINT32_MAX implies the field is unused.
 * @param ram_total [MiB] Total amount of RAM on the component system. A value of UINT32_MAX implies the field is unused.
 * @param storage_type  Storage type: 0: HDD, 1: SSD, 2: EMMC, 3: SD card (non-removable), 4: SD card (removable). A value of UINT32_MAX implies the field is unused.
 * @param storage_usage [MiB] Amount of used storage space on the component system. A value of UINT32_MAX implies the field is unused.
 * @param storage_total [MiB] Total amount of storage space on the component system. A value of UINT32_MAX implies the field is unused.
 * @param link_type  Link type: 0-9: UART, 10-19: Wired network, 20-29: Wifi, 30-39: Point-to-point proprietary, 40-49: Mesh proprietary
 * @param link_tx_rate [KiB/s] Network traffic from the component system. A value of UINT32_MAX implies the field is unused.
 * @param link_rx_rate [KiB/s] Network traffic to the component system. A value of UINT32_MAX implies the field is unused.
 * @param link_tx_max [KiB/s] Network capacity from the component system. A value of UINT32_MAX implies the field is unused.
 * @param link_rx_max [KiB/s] Network capacity to the component system. A value of UINT32_MAX implies the field is unused.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_onboard_computer_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint32_t uptime, uint8_t type, const uint8_t *cpu_cores, const uint8_t *cpu_combined, const uint8_t *gpu_cores, const uint8_t *gpu_combined, int8_t temperature_board, const int8_t *temperature_core, const int16_t *fan_speed, uint32_t ram_usage, uint32_t ram_total, const uint32_t *storage_type, const uint32_t *storage_usage, const uint32_t *storage_total, const uint32_t *link_type, const uint32_t *link_tx_rate, const uint32_t *link_rx_rate, const uint32_t *link_tx_max, const uint32_t *link_rx_max)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint32_t(msg->payloads, 8, uptime);
    _mav_put_uint32_t(msg->payloads, 12, ram_usage);
    _mav_put_uint32_t(msg->payloads, 16, ram_total);
    _mav_put_uint8_t(msg->payloads, 196, type);
    _mav_put_int8_t(msg->payloads, 229, temperature_board);
    _mav_put_uint32_t_array(msg->payloads, 20, storage_type, 4);
    _mav_put_uint32_t_array(msg->payloads, 36, storage_usage, 4);
    _mav_put_uint32_t_array(msg->payloads, 52, storage_total, 4);
    _mav_put_uint32_t_array(msg->payloads, 68, link_type, 6);
    _mav_put_uint32_t_array(msg->payloads, 92, link_tx_rate, 6);
    _mav_put_uint32_t_array(msg->payloads, 116, link_rx_rate, 6);
    _mav_put_uint32_t_array(msg->payloads, 140, link_tx_max, 6);
    _mav_put_uint32_t_array(msg->payloads, 164, link_rx_max, 6);
    _mav_put_int16_t_array(msg->payloads, 188, fan_speed, 4);
    _mav_put_uint8_t_array(msg->payloads, 197, cpu_cores, 8);
    _mav_put_uint8_t_array(msg->payloads, 205, cpu_combined, 10);
    _mav_put_uint8_t_array(msg->payloads, 215, gpu_cores, 4);
    _mav_put_uint8_t_array(msg->payloads, 219, gpu_combined, 10);
    _mav_put_int8_t_array(msg->payloads, 230, temperature_core, 8);
    msg->msgid = MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS_CRC);
}

/**
 * @brief Pack a onboard_computer_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param uptime [ms] Time since system boot.
 * @param type  Type of the onboard computer: 0: Mission computer primary, 1: Mission computer backup 1, 2: Mission computer backup 2, 3: Compute node, 4-5: Compute spares, 6-9: Payload computers.
 * @param cpu_cores  CPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused.
 * @param cpu_combined  Combined CPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused.
 * @param gpu_cores  GPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused.
 * @param gpu_combined  Combined GPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused.
 * @param temperature_board [degC] Temperature of the board. A value of INT8_MAX implies the field is unused.
 * @param temperature_core [degC] Temperature of the CPU core. A value of INT8_MAX implies the field is unused.
 * @param fan_speed [rpm] Fan speeds. A value of INT16_MAX implies the field is unused.
 * @param ram_usage [MiB] Amount of used RAM on the component system. A value of UINT32_MAX implies the field is unused.
 * @param ram_total [MiB] Total amount of RAM on the component system. A value of UINT32_MAX implies the field is unused.
 * @param storage_type  Storage type: 0: HDD, 1: SSD, 2: EMMC, 3: SD card (non-removable), 4: SD card (removable). A value of UINT32_MAX implies the field is unused.
 * @param storage_usage [MiB] Amount of used storage space on the component system. A value of UINT32_MAX implies the field is unused.
 * @param storage_total [MiB] Total amount of storage space on the component system. A value of UINT32_MAX implies the field is unused.
 * @param link_type  Link type: 0-9: UART, 10-19: Wired network, 20-29: Wifi, 30-39: Point-to-point proprietary, 40-49: Mesh proprietary
 * @param link_tx_rate [KiB/s] Network traffic from the component system. A value of UINT32_MAX implies the field is unused.
 * @param link_rx_rate [KiB/s] Network traffic to the component system. A value of UINT32_MAX implies the field is unused.
 * @param link_tx_max [KiB/s] Network capacity from the component system. A value of UINT32_MAX implies the field is unused.
 * @param link_rx_max [KiB/s] Network capacity to the component system. A value of UINT32_MAX implies the field is unused.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_onboard_computer_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint32_t uptime,uint8_t type,const uint8_t *cpu_cores,const uint8_t *cpu_combined,const uint8_t *gpu_cores,const uint8_t *gpu_combined,int8_t temperature_board,const int8_t *temperature_core,const int16_t *fan_speed,uint32_t ram_usage,uint32_t ram_total,const uint32_t *storage_type,const uint32_t *storage_usage,const uint32_t *storage_total,const uint32_t *link_type,const uint32_t *link_tx_rate,const uint32_t *link_rx_rate,const uint32_t *link_tx_max,const uint32_t *link_rx_max)
{
    _mav_put_uint64_t(msg->payloads, 0, time_usec);
    _mav_put_uint32_t(msg->payloads, 8, uptime);
    _mav_put_uint32_t(msg->payloads, 12, ram_usage);
    _mav_put_uint32_t(msg->payloads, 16, ram_total);
    _mav_put_uint8_t(msg->payloads, 196, type);
    _mav_put_int8_t(msg->payloads, 229, temperature_board);
    _mav_put_uint32_t_array(msg->payloads, 20, storage_type, 4);
    _mav_put_uint32_t_array(msg->payloads, 36, storage_usage, 4);
    _mav_put_uint32_t_array(msg->payloads, 52, storage_total, 4);
    _mav_put_uint32_t_array(msg->payloads, 68, link_type, 6);
    _mav_put_uint32_t_array(msg->payloads, 92, link_tx_rate, 6);
    _mav_put_uint32_t_array(msg->payloads, 116, link_rx_rate, 6);
    _mav_put_uint32_t_array(msg->payloads, 140, link_tx_max, 6);
    _mav_put_uint32_t_array(msg->payloads, 164, link_rx_max, 6);
    _mav_put_int16_t_array(msg->payloads, 188, fan_speed, 4);
    _mav_put_uint8_t_array(msg->payloads, 197, cpu_cores, 8);
    _mav_put_uint8_t_array(msg->payloads, 205, cpu_combined, 10);
    _mav_put_uint8_t_array(msg->payloads, 215, gpu_cores, 4);
    _mav_put_uint8_t_array(msg->payloads, 219, gpu_combined, 10);
    _mav_put_int8_t_array(msg->payloads, 230, temperature_core, 8);

    msg->msgid = MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS_MIN_LEN, MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS_LEN, MAVLINK_MSG_ID_ONBOARD_COMPUTER_STATUS_CRC);
}

/**
 * @brief Encode a onboard_computer_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param onboard_computer_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_onboard_computer_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_onboard_computer_status_t* onboard_computer_status)
{
    return mavlink_msg_onboard_computer_status_pack(system_id, component_id, msg, onboard_computer_status->time_usec, onboard_computer_status->uptime, onboard_computer_status->type, onboard_computer_status->cpu_cores, onboard_computer_status->cpu_combined, onboard_computer_status->gpu_cores, onboard_computer_status->gpu_combined, onboard_computer_status->temperature_board, onboard_computer_status->temperature_core, onboard_computer_status->fan_speed, onboard_computer_status->ram_usage, onboard_computer_status->ram_total, onboard_computer_status->storage_type, onboard_computer_status->storage_usage, onboard_computer_status->storage_total, onboard_computer_status->link_type, onboard_computer_status->link_tx_rate, onboard_computer_status->link_rx_rate, onboard_computer_status->link_tx_max, onboard_computer_status->link_rx_max);
}

/**
 * @brief Encode a onboard_computer_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param onboard_computer_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_onboard_computer_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_onboard_computer_status_t* onboard_computer_status)
{
    return mavlink_msg_onboard_computer_status_pack_chan(system_id, component_id, chan, msg, onboard_computer_status->time_usec, onboard_computer_status->uptime, onboard_computer_status->type, onboard_computer_status->cpu_cores, onboard_computer_status->cpu_combined, onboard_computer_status->gpu_cores, onboard_computer_status->gpu_combined, onboard_computer_status->temperature_board, onboard_computer_status->temperature_core, onboard_computer_status->fan_speed, onboard_computer_status->ram_usage, onboard_computer_status->ram_total, onboard_computer_status->storage_type, onboard_computer_status->storage_usage, onboard_computer_status->storage_total, onboard_computer_status->link_type, onboard_computer_status->link_tx_rate, onboard_computer_status->link_rx_rate, onboard_computer_status->link_tx_max, onboard_computer_status->link_rx_max);
}

// MESSAGE ONBOARD_COMPUTER_STATUS UNPACKING


/**
 * @brief Get field time_usec from onboard_computer_status message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_onboard_computer_status_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field uptime from onboard_computer_status message
 *
 * @return [ms] Time since system boot.
 */
static inline uint32_t mavlink_msg_onboard_computer_status_get_uptime(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field type from onboard_computer_status message
 *
 * @return  Type of the onboard computer: 0: Mission computer primary, 1: Mission computer backup 1, 2: Mission computer backup 2, 3: Compute node, 4-5: Compute spares, 6-9: Payload computers.
 */
static inline uint8_t mavlink_msg_onboard_computer_status_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  196);
}

/**
 * @brief Get field cpu_cores from onboard_computer_status message
 *
 * @return  CPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_cpu_cores(const mavlink_message_t* msg, uint8_t *cpu_cores)
{
    return _MAV_RETURN_uint8_t_array(msg, cpu_cores, 8,  197);
}

/**
 * @brief Get field cpu_combined from onboard_computer_status message
 *
 * @return  Combined CPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_cpu_combined(const mavlink_message_t* msg, uint8_t *cpu_combined)
{
    return _MAV_RETURN_uint8_t_array(msg, cpu_combined, 10,  205);
}

/**
 * @brief Get field gpu_cores from onboard_computer_status message
 *
 * @return  GPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_gpu_cores(const mavlink_message_t* msg, uint8_t *gpu_cores)
{
    return _MAV_RETURN_uint8_t_array(msg, gpu_cores, 4,  215);
}

/**
 * @brief Get field gpu_combined from onboard_computer_status message
 *
 * @return  Combined GPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_gpu_combined(const mavlink_message_t* msg, uint8_t *gpu_combined)
{
    return _MAV_RETURN_uint8_t_array(msg, gpu_combined, 10,  219);
}

/**
 * @brief Get field temperature_board from onboard_computer_status message
 *
 * @return [degC] Temperature of the board. A value of INT8_MAX implies the field is unused.
 */
static inline int8_t mavlink_msg_onboard_computer_status_get_temperature_board(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  229);
}

/**
 * @brief Get field temperature_core from onboard_computer_status message
 *
 * @return [degC] Temperature of the CPU core. A value of INT8_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_temperature_core(const mavlink_message_t* msg, int8_t *temperature_core)
{
    return _MAV_RETURN_int8_t_array(msg, temperature_core, 8,  230);
}

/**
 * @brief Get field fan_speed from onboard_computer_status message
 *
 * @return [rpm] Fan speeds. A value of INT16_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_fan_speed(const mavlink_message_t* msg, int16_t *fan_speed)
{
    return _MAV_RETURN_int16_t_array(msg, fan_speed, 4,  188);
}

/**
 * @brief Get field ram_usage from onboard_computer_status message
 *
 * @return [MiB] Amount of used RAM on the component system. A value of UINT32_MAX implies the field is unused.
 */
static inline uint32_t mavlink_msg_onboard_computer_status_get_ram_usage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field ram_total from onboard_computer_status message
 *
 * @return [MiB] Total amount of RAM on the component system. A value of UINT32_MAX implies the field is unused.
 */
static inline uint32_t mavlink_msg_onboard_computer_status_get_ram_total(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field storage_type from onboard_computer_status message
 *
 * @return  Storage type: 0: HDD, 1: SSD, 2: EMMC, 3: SD card (non-removable), 4: SD card (removable). A value of UINT32_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_storage_type(const mavlink_message_t* msg, uint32_t *storage_type)
{
    return _MAV_RETURN_uint32_t_array(msg, storage_type, 4,  20);
}

/**
 * @brief Get field storage_usage from onboard_computer_status message
 *
 * @return [MiB] Amount of used storage space on the component system. A value of UINT32_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_storage_usage(const mavlink_message_t* msg, uint32_t *storage_usage)
{
    return _MAV_RETURN_uint32_t_array(msg, storage_usage, 4,  36);
}

/**
 * @brief Get field storage_total from onboard_computer_status message
 *
 * @return [MiB] Total amount of storage space on the component system. A value of UINT32_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_storage_total(const mavlink_message_t* msg, uint32_t *storage_total)
{
    return _MAV_RETURN_uint32_t_array(msg, storage_total, 4,  52);
}

/**
 * @brief Get field link_type from onboard_computer_status message
 *
 * @return  Link type: 0-9: UART, 10-19: Wired network, 20-29: Wifi, 30-39: Point-to-point proprietary, 40-49: Mesh proprietary
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_link_type(const mavlink_message_t* msg, uint32_t *link_type)
{
    return _MAV_RETURN_uint32_t_array(msg, link_type, 6,  68);
}

/**
 * @brief Get field link_tx_rate from onboard_computer_status message
 *
 * @return [KiB/s] Network traffic from the component system. A value of UINT32_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_link_tx_rate(const mavlink_message_t* msg, uint32_t *link_tx_rate)
{
    return _MAV_RETURN_uint32_t_array(msg, link_tx_rate, 6,  92);
}

/**
 * @brief Get field link_rx_rate from onboard_computer_status message
 *
 * @return [KiB/s] Network traffic to the component system. A value of UINT32_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_link_rx_rate(const mavlink_message_t* msg, uint32_t *link_rx_rate)
{
    return _MAV_RETURN_uint32_t_array(msg, link_rx_rate, 6,  116);
}

/**
 * @brief Get field link_tx_max from onboard_computer_status message
 *
 * @return [KiB/s] Network capacity from the component system. A value of UINT32_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_link_tx_max(const mavlink_message_t* msg, uint32_t *link_tx_max)
{
    return _MAV_RETURN_uint32_t_array(msg, link_tx_max, 6,  140);
}

/**
 * @brief Get field link_rx_max from onboard_computer_status message
 *
 * @return [KiB/s] Network capacity to the component system. A value of UINT32_MAX implies the field is unused.
 */
static inline uint16_t mavlink_msg_onboard_computer_status_get_link_rx_max(const mavlink_message_t* msg, uint32_t *link_rx_max)
{
    return _MAV_RETURN_uint32_t_array(msg, link_rx_max, 6,  164);
}

/**
 * @brief Decode a onboard_computer_status message into a struct
 *
 * @param msg The message to decode
 * @param onboard_computer_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_onboard_computer_status_decode(const mavlink_message_t* msg, mavlink_onboard_computer_status_t* onboard_computer_status)
{
    onboard_computer_status->time_usec = mavlink_msg_onboard_computer_status_get_time_usec(msg);
    onboard_computer_status->uptime = mavlink_msg_onboard_computer_status_get_uptime(msg);
    onboard_computer_status->ram_usage = mavlink_msg_onboard_computer_status_get_ram_usage(msg);
    onboard_computer_status->ram_total = mavlink_msg_onboard_computer_status_get_ram_total(msg);
    mavlink_msg_onboard_computer_status_get_storage_type(msg, onboard_computer_status->storage_type);
    mavlink_msg_onboard_computer_status_get_storage_usage(msg, onboard_computer_status->storage_usage);
    mavlink_msg_onboard_computer_status_get_storage_total(msg, onboard_computer_status->storage_total);
    mavlink_msg_onboard_computer_status_get_link_type(msg, onboard_computer_status->link_type);
    mavlink_msg_onboard_computer_status_get_link_tx_rate(msg, onboard_computer_status->link_tx_rate);
    mavlink_msg_onboard_computer_status_get_link_rx_rate(msg, onboard_computer_status->link_rx_rate);
    mavlink_msg_onboard_computer_status_get_link_tx_max(msg, onboard_computer_status->link_tx_max);
    mavlink_msg_onboard_computer_status_get_link_rx_max(msg, onboard_computer_status->link_rx_max);
    mavlink_msg_onboard_computer_status_get_fan_speed(msg, onboard_computer_status->fan_speed);
    onboard_computer_status->type = mavlink_msg_onboard_computer_status_get_type(msg);
    mavlink_msg_onboard_computer_status_get_cpu_cores(msg, onboard_computer_status->cpu_cores);
    mavlink_msg_onboard_computer_status_get_cpu_combined(msg, onboard_computer_status->cpu_combined);
    mavlink_msg_onboard_computer_status_get_gpu_cores(msg, onboard_computer_status->gpu_cores);
    mavlink_msg_onboard_computer_status_get_gpu_combined(msg, onboard_computer_status->gpu_combined);
    onboard_computer_status->temperature_board = mavlink_msg_onboard_computer_status_get_temperature_board(msg);
    mavlink_msg_onboard_computer_status_get_temperature_core(msg, onboard_computer_status->temperature_core);
}
#endif
