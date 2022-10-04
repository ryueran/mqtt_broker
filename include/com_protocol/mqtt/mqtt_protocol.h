#include <string>
#include <string.h>
#include <iostream>
#include <unistd.h>

/*
I set this structure accrdoing to a website: https://openlabpro.com/guide/mqtt-packet-format/,
don't blame me if you find mistake from it
*/
#define MQTT_MAX_FIXED_HEADER_SIZE 5
#define MQTT_3_1_VARIABLE_HEADER_SIZE 12
#define MQTT_3_1_1_VARIABLE_HEADER_SIZE 10
#define MQTT_BUFFER_SIZE_BYTE 512

typedef enum esp_mqtt_protocol_ver_t {
    MQTT_PROTOCOL_UNDEFINED = 0,
    MQTT_PROTOCOL_V_3_1,
    MQTT_PROTOCOL_V_3_1_1
} esp_mqtt_protocol_ver_t;

enum MQTTControlPacketType {
    MQTT_CONTROL_CONNECT = 1u,
    MQTT_CONTROL_CONNACK = 2u,
    MQTT_CONTROL_PUBLISH = 3u,
    MQTT_CONTROL_PUBACK = 4u,
    MQTT_CONTROL_PUBREC = 5u,
    MQTT_CONTROL_PUBREL = 6u,
    MQTT_CONTROL_PUBCOMP = 7u,
    MQTT_CONTROL_SUBSCRIBE = 8u,
    MQTT_CONTROL_SUBACK = 9u,
    MQTT_CONTROL_UNSUBSCRIBE = 10u,
    MQTT_CONTROL_UNSUBACK = 11u,
    MQTT_CONTROL_PINGREQ = 12u,
    MQTT_CONTROL_PINGRESP = 13u,
    MQTT_CONTROL_DISCONNECT = 14u
};

typedef struct mqtt_message {
    uint8_t *data;
    size_t length;
    size_t fragment_msg_total_length;
    size_t fragment_msg_data_offset;
} mqtt_message_t;

typedef struct mqtt_connection {
    #if MQTT_MSG_ID_INCREMENTAL
    uint16_t last_message_id;
    #endif
    uint8_t *buffer;
    size_t buffer_length;
} mqtt_connection_t;

typedef struct mqtt_connect_info {
    char* client_id;
    char* username;
    char* password;
    char* will_topic;
    char* will_message;
    int64_t keepalive;
    int will_length;
    int will_qos;
    int will_retain;
    int clean_session;
    esp_mqtt_protocol_ver_t protocol_ver;
} mqtt_connect_info_t;

class mqtt_protocol
{
private:
    struct mqtt_message *message;

    uint8_t offset_set_(uint8_t* encoded_lens, int total_length)
    {
        int encoded_length = 0;
        int len_bytes = 0;
        do {
            encoded_length = total_length % 128;
            total_length /= 128;
            if(total_length > 0) {
                encoded_length |= 0x80;
            }

            encoded_lens[len_bytes] = encoded_length;
            len_bytes++;
        } while(total_length > 0);

        return len_bytes;
    }

    void append_string_(mqtt_connection_t* conn, const char* string, int len, int & message_position)
    {
        conn->buffer[message_position++] = len >> 8;
        conn->buffer[message_position++] = len & 0xff;
        memcpy(conn->buffer + message_position, string, len);
        message_position += len;
    }

    void fini_message_(mqtt_connection_t* conn, int type, int dup, int qos, int retain, int m_len)
    {
        int message_length = m_len - MQTT_MAX_FIXED_HEADER_SIZE;
        int total_length = message_length;
        uint8_t encoded_lens[4] = {0};
        int len_bytes = offset_set_(encoded_lens, total_length);

        int offs = MQTT_MAX_FIXED_HEADER_SIZE - 1 - len_bytes;
        int offset = offs;
        conn->buffer[offs++] = (((type & 0x0f) << 4)|((dup & 1) << 3)|((qos & 3) << 1)|(retain & 1));
        
        for(int j = 0; j < len_bytes; j++) {
            conn->buffer[offs++] = encoded_lens[j];
        }

        buffer = conn->buffer + offset;
        m_len = 0;
    }

    uint8_t* buffer;
    int message_length;
    struct mqtt_connection *conn;
public:
    void msg_init();
    void mqtt_msg_connect(mqtt_connect_info_t *info);
    int get_message_length();
    uint8_t* get_message();
};