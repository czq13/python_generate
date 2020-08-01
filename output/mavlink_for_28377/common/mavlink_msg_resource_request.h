#ifndef MAVLINK_MSG_resource_request
#define MAVLINK_MSG_resource_request
// MESSAGE RESOURCE_REQUEST PACKING

#define MAVLINK_MSG_ID_RESOURCE_REQUEST 142

typedef struct __mavlink_resource_request_t {
 uint8_t request_id; /*<  Request ID. This ID should be re-used when sending back URI contents*/
 uint8_t uri_type; /*<  The type of requested URI. 0 = a file via URL. 1 = a UAVCAN binary*/
 uint8_t uri[120]; /*<  The requested unique resource identifier (URI). It is not necessarily a straight domain name (depends on the URI type enum)*/
 uint8_t transfer_type; /*<  The way the autopilot wants to receive the URI. 0 = MAVLink FTP. 1 = binary stream.*/
 uint8_t storage[120]; /*<  The storage path the autopilot wants the URI to be stored in. Will only be valid if the transfer_type has a storage associated (e.g. MAVLink FTP).*/
} mavlink_resource_request_t;

#define MAVLINK_MSG_ID_RESOURCE_REQUEST_LEN 243
#define MAVLINK_MSG_ID_RESOURCE_REQUEST_MIN_LEN 243
#define MAVLINK_MSG_ID_142_LEN 243
#define MAVLINK_MSG_ID_142_MIN_LEN 243

#define MAVLINK_MSG_ID_RESOURCE_REQUEST_CRC 72
#define MAVLINK_MSG_ID_142_CRC 72

#define MAVLINK_MSG_RESOURCE_REQUEST_FIELD_URI_LEN 120
#define MAVLINK_MSG_RESOURCE_REQUEST_FIELD_STORAGE_LEN 120

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RESOURCE_REQUEST { \
    142, \
    "RESOURCE_REQUEST", \
    5, \
    {  { "request_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_resource_request_t, request_id) }, \
         { "uri_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_resource_request_t, uri_type) }, \
         { "uri", NULL, MAVLINK_TYPE_UINT8_T, 120, 2, offsetof(mavlink_resource_request_t, uri) }, \
         { "transfer_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 122, offsetof(mavlink_resource_request_t, transfer_type) }, \
         { "storage", NULL, MAVLINK_TYPE_UINT8_T, 120, 123, offsetof(mavlink_resource_request_t, storage) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RESOURCE_REQUEST { \
    "RESOURCE_REQUEST", \
    5, \
    {  { "request_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_resource_request_t, request_id) }, \
         { "uri_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_resource_request_t, uri_type) }, \
         { "uri", NULL, MAVLINK_TYPE_UINT8_T, 120, 2, offsetof(mavlink_resource_request_t, uri) }, \
         { "transfer_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 122, offsetof(mavlink_resource_request_t, transfer_type) }, \
         { "storage", NULL, MAVLINK_TYPE_UINT8_T, 120, 123, offsetof(mavlink_resource_request_t, storage) }, \
         } \
}
#endif

/**
 * @brief Pack a resource_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param request_id  Request ID. This ID should be re-used when sending back URI contents
 * @param uri_type  The type of requested URI. 0 = a file via URL. 1 = a UAVCAN binary
 * @param uri  The requested unique resource identifier (URI). It is not necessarily a straight domain name (depends on the URI type enum)
 * @param transfer_type  The way the autopilot wants to receive the URI. 0 = MAVLink FTP. 1 = binary stream.
 * @param storage  The storage path the autopilot wants the URI to be stored in. Will only be valid if the transfer_type has a storage associated (e.g. MAVLink FTP).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_resource_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t request_id, uint8_t uri_type, const uint8_t *uri, uint8_t transfer_type, const uint8_t *storage)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, request_id);
    _mav_put_uint8_t(((char*)msg->payloads), 1, uri_type);
    _mav_put_uint8_t(((char*)msg->payloads), 122, transfer_type);
    _mav_put_uint8_t_array(((char*)msg->payloads), 2, uri, 120);
    _mav_put_uint8_t_array(((char*)msg->payloads), 123, storage, 120);
    msg->msgid = MAVLINK_MSG_ID_RESOURCE_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RESOURCE_REQUEST_MIN_LEN, MAVLINK_MSG_ID_RESOURCE_REQUEST_LEN, MAVLINK_MSG_ID_RESOURCE_REQUEST_CRC);
}

/**
 * @brief Pack a resource_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param request_id  Request ID. This ID should be re-used when sending back URI contents
 * @param uri_type  The type of requested URI. 0 = a file via URL. 1 = a UAVCAN binary
 * @param uri  The requested unique resource identifier (URI). It is not necessarily a straight domain name (depends on the URI type enum)
 * @param transfer_type  The way the autopilot wants to receive the URI. 0 = MAVLink FTP. 1 = binary stream.
 * @param storage  The storage path the autopilot wants the URI to be stored in. Will only be valid if the transfer_type has a storage associated (e.g. MAVLink FTP).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_resource_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t request_id,uint8_t uri_type,const uint8_t *uri,uint8_t transfer_type,const uint8_t *storage)
{
    _mav_put_uint8_t(((char*)msg->payloads), 0, request_id);
    _mav_put_uint8_t(((char*)msg->payloads), 1, uri_type);
    _mav_put_uint8_t(((char*)msg->payloads), 122, transfer_type);
    _mav_put_uint8_t_array(((char*)msg->payloads), 2, uri, 120);
    _mav_put_uint8_t_array(((char*)msg->payloads), 123, storage, 120);

    msg->msgid = MAVLINK_MSG_ID_RESOURCE_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RESOURCE_REQUEST_MIN_LEN, MAVLINK_MSG_ID_RESOURCE_REQUEST_LEN, MAVLINK_MSG_ID_RESOURCE_REQUEST_CRC);
}

/**
 * @brief Encode a resource_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param resource_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_resource_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_resource_request_t* resource_request)
{
    return mavlink_msg_resource_request_pack(system_id, component_id, msg, resource_request->request_id, resource_request->uri_type, resource_request->uri, resource_request->transfer_type, resource_request->storage);
}

/**
 * @brief Encode a resource_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param resource_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_resource_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_resource_request_t* resource_request)
{
    return mavlink_msg_resource_request_pack_chan(system_id, component_id, chan, msg, resource_request->request_id, resource_request->uri_type, resource_request->uri, resource_request->transfer_type, resource_request->storage);
}

// MESSAGE RESOURCE_REQUEST UNPACKING


/**
 * @brief Get field request_id from resource_request message
 *
 * @return  Request ID. This ID should be re-used when sending back URI contents
 */
static inline uint8_t mavlink_msg_resource_request_get_request_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field uri_type from resource_request message
 *
 * @return  The type of requested URI. 0 = a file via URL. 1 = a UAVCAN binary
 */
static inline uint8_t mavlink_msg_resource_request_get_uri_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field uri from resource_request message
 *
 * @return  The requested unique resource identifier (URI). It is not necessarily a straight domain name (depends on the URI type enum)
 */
static inline uint16_t mavlink_msg_resource_request_get_uri(const mavlink_message_t* msg, uint8_t *uri)
{
    return _MAV_RETURN_uint8_t_array(msg, uri, 120,  2);
}

/**
 * @brief Get field transfer_type from resource_request message
 *
 * @return  The way the autopilot wants to receive the URI. 0 = MAVLink FTP. 1 = binary stream.
 */
static inline uint8_t mavlink_msg_resource_request_get_transfer_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  122);
}

/**
 * @brief Get field storage from resource_request message
 *
 * @return  The storage path the autopilot wants the URI to be stored in. Will only be valid if the transfer_type has a storage associated (e.g. MAVLink FTP).
 */
static inline uint16_t mavlink_msg_resource_request_get_storage(const mavlink_message_t* msg, uint8_t *storage)
{
    return _MAV_RETURN_uint8_t_array(msg, storage, 120,  123);
}

/**
 * @brief Decode a resource_request message into a struct
 *
 * @param msg The message to decode
 * @param resource_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_resource_request_decode(const mavlink_message_t* msg, mavlink_resource_request_t* resource_request)
{
    resource_request->request_id = mavlink_msg_resource_request_get_request_id(msg);
    resource_request->uri_type = mavlink_msg_resource_request_get_uri_type(msg);
    mavlink_msg_resource_request_get_uri(msg, resource_request->uri);
    resource_request->transfer_type = mavlink_msg_resource_request_get_transfer_type(msg);
    mavlink_msg_resource_request_get_storage(msg, resource_request->storage);
}
#endif
