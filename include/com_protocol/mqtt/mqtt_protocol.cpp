#include "mqtt_protocol.h"
#include <string.h>
#include <math.h>

#define MQTT_MAX_FIXED_HEADER_SIZE 5
#define MQTT_3_1_VARIABLE_HEADER_SIZE 12
#define MQTT_3_1_1_VARIABLE_HEADER_SIZE 10

void mqtt_protocol::msg_init()
{
    conn = (struct mqtt_connection*)malloc(sizeof(struct mqtt_connection));
    conn->buffer_length = MQTT_BUFFER_SIZE_BYTE;
    conn->buffer = (uint8_t*)malloc(sizeof(uint8_t) * (conn->buffer_length));
}

void mqtt_protocol::mqtt_msg_connect(mqtt_connect_info_t *info)
{
    int header_len = MQTT_MAX_FIXED_HEADER_SIZE;
    message_length = header_len;

    char* variable_header = (char*)(conn->buffer + message_length);

    int header_idx = 0;
    variable_header[header_idx++] = 0;
    variable_header[header_idx++] = 4;
    memcpy(&variable_header[header_idx], "MQTT", 4);
    header_idx = header_idx + 4;
    variable_header[header_idx++] = 4; // |00|04|M|Q|T|T|04

    variable_header[header_idx++] = 2; // Connect flag
    variable_header[header_idx++] = info->keepalive >> 8;
    variable_header[header_idx++] = info->keepalive & 0xff;

    message_length += header_idx;
    if(info->client_id != NULL && info->client_id[0] != '\0')
    {
        append_string_(conn, info->client_id, strlen(info->client_id), message_length);
    }

    if(info->will_topic != NULL && info->will_topic[0] != '\0')
    {
        append_string_(conn, info->will_topic, strlen(info->will_topic), message_length);
    }
    
    if(info->will_message != NULL && info->will_message[0] != '\0')
    {
        append_string_(conn, info->will_message, strlen(info->will_message), message_length);
    }
    
    if(info->username != NULL && info->username[0] != '\0')
    {
        append_string_(conn, info->username, strlen(info->username), message_length);
    }

    if(info->password != NULL && info->password[0] != '\0')
    {
        append_string_(conn, info->password, strlen(info->password), message_length);
    }

    fini_message_(conn, MQTT_CONTROL_CONNECT, 0, 0, 0, message_length);
}

uint8_t* mqtt_protocol::get_message()
{
    return buffer;
}

int mqtt_protocol::get_message_length()
{
    return message_length;
}