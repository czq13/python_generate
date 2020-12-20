#ifndef MAVLINK_MSG_component_information
#define MAVLINK_MSG_component_information
// MESSAGE COMPONENT_INFORMATION PACKING

#define MAVLINK_MSG_ID_COMPONENT_INFORMATION 395

typedef struct __mavlink_component_information_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 uint32_t metadata_type; /*<  The type of metadata being requested.*/
 uint32_t metadata_uid; /*<  Unique uid for this metadata which a gcs can use for created cached metadata and understanding whether it's cache it up to date or whether it needs to download new data.*/
 uint32_t translation_uid; /*<  Unique uid for the translation file associated with the metadata.*/
 char metadata_uri[70]; /*<  Component definition URI. If prefix mavlinkftp:// file is downloaded from vehicle over mavlink ftp protocol. If prefix http[s]:// file is downloaded over internet. Files are json format. They can end in .gz to indicate file is in gzip format.*/
 char translation_uri[70]; /*<  The translations for strings within the metadata file. If null the either do not exist or may be included in the metadata file itself. The translations specified here supercede any which may be in the metadata file itself. The uri format is the same as component_metadata_uri . Files are in Json Translation spec format. Empty string indicates no tranlsation file.*/
} mavlink_component_information_t;

#define MAVLINK_MSG_ID_COMPONENT_INFORMATION_LEN 156
#define MAVLINK_MSG_ID_COMPONENT_INFORMATION_MIN_LEN 156
#define MAVLINK_MSG_ID_395_LEN 156
#define MAVLINK_MSG_ID_395_MIN_LEN 156

#define MAVLINK_MSG_ID_COMPONENT_INFORMATION_CRC 163
#define MAVLINK_MSG_ID_395_CRC 163

#define MAVLINK_MSG_COMPONENT_INFORMATION_FIELD_METADATA_URI_LEN 70
#define MAVLINK_MSG_COMPONENT_INFORMATION_FIELD_TRANSLATION_URI_LEN 70

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMPONENT_INFORMATION { \
    395, \
    "COMPONENT_INFORMATION", \
    6, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_component_information_t, time_boot_ms) }, \
         { "metadata_type", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_component_information_t, metadata_type) }, \
         { "metadata_uid", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_component_information_t, metadata_uid) }, \
         { "metadata_uri", NULL, MAVLINK_TYPE_CHAR, 70, 16, offsetof(mavlink_component_information_t, metadata_uri) }, \
         { "translation_uid", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_component_information_t, translation_uid) }, \
         { "translation_uri", NULL, MAVLINK_TYPE_CHAR, 70, 86, offsetof(mavlink_component_information_t, translation_uri) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMPONENT_INFORMATION { \
    "COMPONENT_INFORMATION", \
    6, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_component_information_t, time_boot_ms) }, \
         { "metadata_type", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_component_information_t, metadata_type) }, \
         { "metadata_uid", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_component_information_t, metadata_uid) }, \
         { "metadata_uri", NULL, MAVLINK_TYPE_CHAR, 70, 16, offsetof(mavlink_component_information_t, metadata_uri) }, \
         { "translation_uid", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_component_information_t, translation_uid) }, \
         { "translation_uri", NULL, MAVLINK_TYPE_CHAR, 70, 86, offsetof(mavlink_component_information_t, translation_uri) }, \
         } \
}
#endif

/**
 * @brief Pack a component_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param metadata_type  The type of metadata being requested.
 * @param metadata_uid  Unique uid for this metadata which a gcs can use for created cached metadata and understanding whether it's cache it up to date or whether it needs to download new data.
 * @param metadata_uri  Component definition URI. If prefix mavlinkftp:// file is downloaded from vehicle over mavlink ftp protocol. If prefix http[s]:// file is downloaded over internet. Files are json format. They can end in .gz to indicate file is in gzip format.
 * @param translation_uid  Unique uid for the translation file associated with the metadata.
 * @param translation_uri  The translations for strings within the metadata file. If null the either do not exist or may be included in the metadata file itself. The translations specified here supercede any which may be in the metadata file itself. The uri format is the same as component_metadata_uri . Files are in Json Translation spec format. Empty string indicates no tranlsation file.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_component_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t metadata_type, uint32_t metadata_uid, const char *metadata_uri, uint32_t translation_uid, const char *translation_uri)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_uint32_t(((char*)msg->payloads), 4, metadata_type);
    _mav_put_uint32_t(((char*)msg->payloads), 8, metadata_uid);
    _mav_put_uint32_t(((char*)msg->payloads), 12, translation_uid);
    _mav_put_char_array(((char*)msg->payloads), 16, metadata_uri, 70);
    _mav_put_char_array(((char*)msg->payloads), 86, translation_uri, 70);
    msg->msgid = MAVLINK_MSG_ID_COMPONENT_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMPONENT_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_INFORMATION_LEN, MAVLINK_MSG_ID_COMPONENT_INFORMATION_CRC);
}

/**
 * @brief Pack a component_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param metadata_type  The type of metadata being requested.
 * @param metadata_uid  Unique uid for this metadata which a gcs can use for created cached metadata and understanding whether it's cache it up to date or whether it needs to download new data.
 * @param metadata_uri  Component definition URI. If prefix mavlinkftp:// file is downloaded from vehicle over mavlink ftp protocol. If prefix http[s]:// file is downloaded over internet. Files are json format. They can end in .gz to indicate file is in gzip format.
 * @param translation_uid  Unique uid for the translation file associated with the metadata.
 * @param translation_uri  The translations for strings within the metadata file. If null the either do not exist or may be included in the metadata file itself. The translations specified here supercede any which may be in the metadata file itself. The uri format is the same as component_metadata_uri . Files are in Json Translation spec format. Empty string indicates no tranlsation file.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_component_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t metadata_type,uint32_t metadata_uid,const char *metadata_uri,uint32_t translation_uid,const char *translation_uri)
{
    _mav_put_uint32_t(((char*)msg->payloads), 0, time_boot_ms);
    _mav_put_uint32_t(((char*)msg->payloads), 4, metadata_type);
    _mav_put_uint32_t(((char*)msg->payloads), 8, metadata_uid);
    _mav_put_uint32_t(((char*)msg->payloads), 12, translation_uid);
    _mav_put_char_array(((char*)msg->payloads), 16, metadata_uri, 70);
    _mav_put_char_array(((char*)msg->payloads), 86, translation_uri, 70);

    msg->msgid = MAVLINK_MSG_ID_COMPONENT_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMPONENT_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_COMPONENT_INFORMATION_LEN, MAVLINK_MSG_ID_COMPONENT_INFORMATION_CRC);
}

/**
 * @brief Encode a component_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param component_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_component_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_component_information_t* component_information)
{
    return mavlink_msg_component_information_pack(system_id, component_id, msg, component_information->time_boot_ms, component_information->metadata_type, component_information->metadata_uid, component_information->metadata_uri, component_information->translation_uid, component_information->translation_uri);
}

/**
 * @brief Encode a component_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param component_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_component_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_component_information_t* component_information)
{
    return mavlink_msg_component_information_pack_chan(system_id, component_id, chan, msg, component_information->time_boot_ms, component_information->metadata_type, component_information->metadata_uid, component_information->metadata_uri, component_information->translation_uid, component_information->translation_uri);
}

// MESSAGE COMPONENT_INFORMATION UNPACKING


/**
 * @brief Get field time_boot_ms from component_information message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_component_information_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field metadata_type from component_information message
 *
 * @return  The type of metadata being requested.
 */
static inline uint32_t mavlink_msg_component_information_get_metadata_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field metadata_uid from component_information message
 *
 * @return  Unique uid for this metadata which a gcs can use for created cached metadata and understanding whether it's cache it up to date or whether it needs to download new data.
 */
static inline uint32_t mavlink_msg_component_information_get_metadata_uid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field metadata_uri from component_information message
 *
 * @return  Component definition URI. If prefix mavlinkftp:// file is downloaded from vehicle over mavlink ftp protocol. If prefix http[s]:// file is downloaded over internet. Files are json format. They can end in .gz to indicate file is in gzip format.
 */
static inline uint16_t mavlink_msg_component_information_get_metadata_uri(const mavlink_message_t* msg, char *metadata_uri)
{
    return _MAV_RETURN_char_array(msg, metadata_uri, 70,  16);
}

/**
 * @brief Get field translation_uid from component_information message
 *
 * @return  Unique uid for the translation file associated with the metadata.
 */
static inline uint32_t mavlink_msg_component_information_get_translation_uid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field translation_uri from component_information message
 *
 * @return  The translations for strings within the metadata file. If null the either do not exist or may be included in the metadata file itself. The translations specified here supercede any which may be in the metadata file itself. The uri format is the same as component_metadata_uri . Files are in Json Translation spec format. Empty string indicates no tranlsation file.
 */
static inline uint16_t mavlink_msg_component_information_get_translation_uri(const mavlink_message_t* msg, char *translation_uri)
{
    return _MAV_RETURN_char_array(msg, translation_uri, 70,  86);
}

/**
 * @brief Decode a component_information message into a struct
 *
 * @param msg The message to decode
 * @param component_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_component_information_decode(const mavlink_message_t* msg, mavlink_component_information_t* component_information)
{
    component_information->time_boot_ms = mavlink_msg_component_information_get_time_boot_ms(msg);
    component_information->metadata_type = mavlink_msg_component_information_get_metadata_type(msg);
    component_information->metadata_uid = mavlink_msg_component_information_get_metadata_uid(msg);
    component_information->translation_uid = mavlink_msg_component_information_get_translation_uid(msg);
    mavlink_msg_component_information_get_metadata_uri(msg, component_information->metadata_uri);
    mavlink_msg_component_information_get_translation_uri(msg, component_information->translation_uri);
}
#endif
