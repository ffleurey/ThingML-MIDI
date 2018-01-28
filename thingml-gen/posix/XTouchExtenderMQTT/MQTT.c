#include "MQTT.h"

const char *MQTT_topics[3] = {
    "sh/xtouch/cmd",
    "ThingML",
    "sh/xtouch/state"
};
int MQTT_topics_subscribed[3];

const int MQTT_qos = 1;

struct mosquitto *MQTT_mosq = NULL;

// Callback declarations
void MQTT_log_callback(struct mosquitto *, void *, int , const char *);
void MQTT_connect_callback(struct mosquitto *, void *, int);
void MQTT_subscribe_callback(struct mosquitto *, void *, int , int , const int *);
void MQTT_message_callback(struct mosquitto *, void *, const struct mosquitto_message *);

// Setup
void MQTT_setup(struct MQTT_Instance *_instance)
{
    const char *host = "localhost";
    int port = 1883;
    const char *client_id = NULL;
    const char *username = NULL;
    const char *password = NULL;
    const char *will_topic = NULL;
    const char *will_string = NULL;

    // Initialise
    printf("[MQTT] Initialising MQTT at %s:%i\n", host, port);
    mosquitto_lib_init();
    MQTT_mosq = mosquitto_new(client_id, true, _instance);
    if (!MQTT_mosq) {
        perror("[MQTT] mosquitto_new failed ");
        exit(1); // Exit in case of error
        return;
    }

    // Set username and password
    if (password && !username) fprintf(stderr, "[MQTT] Warning: Not using password since username is not set.\n");
    if (username && !password) fprintf(stderr, "[MQTT] Warning: Not using username since password is not set.\n");
    if (username && password && mosquitto_username_pw_set(MQTT_mosq, username, password)) {
        fprintf(stderr, "[MQTT] mosquitto_username_pw_set failed\n");
        exit(1); // Exit in case of error
        return;
    }

    // Set callbacks
    mosquitto_log_callback_set(MQTT_mosq, MQTT_log_callback);
    mosquitto_connect_callback_set(MQTT_mosq, MQTT_connect_callback);
    mosquitto_subscribe_callback_set(MQTT_mosq, MQTT_subscribe_callback);
    mosquitto_message_callback_set(MQTT_mosq, MQTT_message_callback);

    // Set will
    if (will_string && !will_topic) fprintf(stderr, "[MQTT] Warning: Not setting will since will_topic is not set.\n");
    if (will_string && will_topic && mosquitto_will_set(MQTT_mosq, will_topic, strlen(will_string), will_string, MQTT_qos, false)) {
        fprintf(stderr, "[MQTT] mosquitto_will_set failed\n");
        exit(1); // Exit in case of error
        return;
    }

    // Connect to broker
    int result = mosquitto_connect(MQTT_mosq, host, port, 10);
    if (result == MOSQ_ERR_ERRNO) {
        perror("[MQTT] mosquitto_connect failed ");
        exit(1); // Exit in case of error
    }
    else if (result) {
        fprintf(stderr, "[MQTT] mosquitto_connect failed : %s\n", mosquitto_strerror(result));
        exit(1); // Exit in case of error    
    }

    if (result) MQTT_mosq = NULL;
}

// Threaded execution and polling functions
void MQTT_start_receiver_thread() {
    int result = mosquitto_loop_forever(MQTT_mosq, -1, 1);

    if (result == MOSQ_ERR_ERRNO) {
        perror("[MQTT] mosquitto_loop_forever_failed ");
    }
    else if (result) {
        fprintf(stderr, "[MQTT] mosquitto_connect failed : %s\n", mosquitto_strerror(result));
    }

	mosquitto_destroy(MQTT_mosq);
	MQTT_mosq = NULL;
	mosquitto_lib_cleanup();
    exit(1); // Exit in case of error
}

void MQTT_loop_poll() {
	if (MQTT_mosq) {
        int result = mosquitto_loop(MQTT_mosq, 0, 1);

        if (result == MOSQ_ERR_ERRNO) {
            perror("[MQTT] mosquitto_loop_forever_failed ");
        }
        else if (result) {
            fprintf(stderr, "[MQTT] mosquitto_connect failed : %s\n", mosquitto_strerror(result));
        }

        if (result) {
            mosquitto_destroy(MQTT_mosq);
            MQTT_mosq = NULL;
            mosquitto_lib_cleanup();
            exit(1); // Exit in case of error
        }
    }
}

// Logging
void MQTT_log_callback(struct mosquitto *mosq, void *_instance, int level, const char *str)
{
    //printf("[MQTT] %s\n", str);
}

// On connected
void MQTT_connect_callback(struct mosquitto *mosq, void *_instance, int result)
{
    int ret, i;
    switch (result) {
        case 0:
            for (i = 0; i < 3; i++) {
                ret = mosquitto_subscribe(mosq, &MQTT_topics_subscribed[i], MQTT_topics[i], MQTT_qos);
                if (ret) {
                    fprintf(stderr, "[MQTT] mosquitto_subscribe failed for %s : %s\n", MQTT_topics[i], mosquitto_strerror(result));
                    exit(1); // Exit in case of error
                }
            }
            break;
        case 1:
            fprintf(stderr, "[MQTT] Connection error : unacceptable protocol version\n");
            exit(1); // Exit in case of error
            break;
        case 2:
            fprintf(stderr, "[MQTT] Connection error : identifier rejected\n");
            exit(1); // Exit in case of error
            break;
        case 3:
            fprintf(stderr, "[MQTT] Connection error : broker unavailable\n");
            exit(1); // Exit in case of error
            break;
        default:
            fprintf(stderr, "[MQTT] Connection error : unknown reason\n");
            exit(1); // Exit in case of error
            break;
    }
}

// On subscribed
void MQTT_subscribe_callback(struct mosquitto *mosq, void *_instance, int mid, int qos_count, const int *granted_qos)
{
    int print = false, i;
    //print = true;
    if (print) {
        // Find subscribed topic
        for (i = 0; i < 3; i++) {
            if (MQTT_topics_subscribed[i] == mid) break;
        }
        printf("[MQTT] Subscribed to topic '%s' - QoS levels ", MQTT_topics[i]);
        for (i = 0; i < qos_count; i++) printf("%i ",granted_qos[i]);
        printf("\n");
    }
    for (i = 0; i < qos_count; i++)
        if (granted_qos[i] == MQTT_qos) return;

    for (i = 0; i < 3; i++) {
        if (MQTT_topics_subscribed[i] == mid) break;
    }
    fprintf(stderr, "[MQTT] Topic '%s' was not granted the specified QoS level\n", MQTT_topics[i]);
}

/* ---------- INCOMMING MESSAGES ----------*/
static uint8_t *jump_to(uint8_t *msg, int len, uint8_t *ptr, uint8_t a, uint8_t b)
{
    if (!ptr) return NULL;
    while (ptr-msg <= len) {
        if(*ptr == a || *ptr == b) return ptr;
        ptr++;
    }
    return NULL;
}

static uint8_t *jump_space(uint8_t *msg, int len, uint8_t *ptr)
{
    if (!ptr) return NULL;
    while (ptr-msg <= len) {
        if (!isspace(*ptr)) return ptr;
        ptr++;
    }
    return NULL;
}

static int parse_set_pot(uint8_t *msg, int size, uint8_t *out_buffer) {
    uint8_t *ptr = msg;
    uint8_t *start = NULL;
    uint8_t *end = NULL;
    uint8_t *pstart = NULL;
    int index = 0;
    // Port-message code
    out_buffer[index+0] = (2 >> 8);
    out_buffer[index+1] = (2 & 0xFF);
    index += 2;
    // Find all forwarded parameters
    int np;
    for (np = 0; np < 2; np++) {
        // Parameter name
        ptr = jump_space(msg, size, ptr);
        if (!ptr || *ptr != '"') return -2;
        start = ptr+1;
        ptr = jump_to(msg, size, start, '"', '"');
        if (!ptr) return -3;
        end = ptr;
        // Parameter value
        ptr = jump_to(msg, size, end, ':', ':');
        if (!ptr) return -4;
        ptr = jump_space(msg, size, ptr+1);
        if (!ptr) return -5;
        pstart = ptr;
        ptr = jump_to(msg, size, pstart, ',', '}');
        if (!ptr) return -6;
        // Find matching parameter
        if (ptr-pstart < 1) return -7;
        else if (strncmp("ch", start, end-start) == 0) {
            union u_ch_t { uint8_t ch; uint8_t bytebuffer[1]; } u_ch;
            u_ch.ch = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[2], u_ch.bytebuffer, 1);
        }
        else if (strncmp("value", start, end-start) == 0) {
            union u_value_t { uint8_t value; uint8_t bytebuffer[1]; } u_value;
            u_value.value = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[3], u_value.bytebuffer, 1);
        }
        ptr = jump_to(msg, size, ptr, ',', '}');
        if (!ptr) return -8;
        ptr = ptr+1;
    }
    // Zero-init all non-forwarded messages
    // Make sure we are at the end of the message
    ptr = jump_space(msg, size, ptr);
    if (!ptr || *ptr != '}') return -9;
    // Parsing complete
    return 4;
}

static int parse_button_light_off(uint8_t *msg, int size, uint8_t *out_buffer) {
    uint8_t *ptr = msg;
    uint8_t *start = NULL;
    uint8_t *end = NULL;
    uint8_t *pstart = NULL;
    int index = 0;
    // Port-message code
    out_buffer[index+0] = (3 >> 8);
    out_buffer[index+1] = (3 & 0xFF);
    index += 2;
    // Find all forwarded parameters
    int np;
    for (np = 0; np < 2; np++) {
        // Parameter name
        ptr = jump_space(msg, size, ptr);
        if (!ptr || *ptr != '"') return -2;
        start = ptr+1;
        ptr = jump_to(msg, size, start, '"', '"');
        if (!ptr) return -3;
        end = ptr;
        // Parameter value
        ptr = jump_to(msg, size, end, ':', ':');
        if (!ptr) return -4;
        ptr = jump_space(msg, size, ptr+1);
        if (!ptr) return -5;
        pstart = ptr;
        ptr = jump_to(msg, size, pstart, ',', '}');
        if (!ptr) return -6;
        // Find matching parameter
        if (ptr-pstart < 1) return -7;
        else if (strncmp("ch", start, end-start) == 0) {
            union u_ch_t { uint8_t ch; uint8_t bytebuffer[1]; } u_ch;
            u_ch.ch = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[2], u_ch.bytebuffer, 1);
        }
        else if (strncmp("id", start, end-start) == 0) {
            union u_id_t { uint8_t id; uint8_t bytebuffer[1]; } u_id;
            u_id.id = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[3], u_id.bytebuffer, 1);
        }
        ptr = jump_to(msg, size, ptr, ',', '}');
        if (!ptr) return -8;
        ptr = ptr+1;
    }
    // Zero-init all non-forwarded messages
    // Make sure we are at the end of the message
    ptr = jump_space(msg, size, ptr);
    if (!ptr || *ptr != '}') return -9;
    // Parsing complete
    return 4;
}

static int parse_button_light_blink(uint8_t *msg, int size, uint8_t *out_buffer) {
    uint8_t *ptr = msg;
    uint8_t *start = NULL;
    uint8_t *end = NULL;
    uint8_t *pstart = NULL;
    int index = 0;
    // Port-message code
    out_buffer[index+0] = (4 >> 8);
    out_buffer[index+1] = (4 & 0xFF);
    index += 2;
    // Find all forwarded parameters
    int np;
    for (np = 0; np < 2; np++) {
        // Parameter name
        ptr = jump_space(msg, size, ptr);
        if (!ptr || *ptr != '"') return -2;
        start = ptr+1;
        ptr = jump_to(msg, size, start, '"', '"');
        if (!ptr) return -3;
        end = ptr;
        // Parameter value
        ptr = jump_to(msg, size, end, ':', ':');
        if (!ptr) return -4;
        ptr = jump_space(msg, size, ptr+1);
        if (!ptr) return -5;
        pstart = ptr;
        ptr = jump_to(msg, size, pstart, ',', '}');
        if (!ptr) return -6;
        // Find matching parameter
        if (ptr-pstart < 1) return -7;
        else if (strncmp("ch", start, end-start) == 0) {
            union u_ch_t { uint8_t ch; uint8_t bytebuffer[1]; } u_ch;
            u_ch.ch = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[2], u_ch.bytebuffer, 1);
        }
        else if (strncmp("id", start, end-start) == 0) {
            union u_id_t { uint8_t id; uint8_t bytebuffer[1]; } u_id;
            u_id.id = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[3], u_id.bytebuffer, 1);
        }
        ptr = jump_to(msg, size, ptr, ',', '}');
        if (!ptr) return -8;
        ptr = ptr+1;
    }
    // Zero-init all non-forwarded messages
    // Make sure we are at the end of the message
    ptr = jump_space(msg, size, ptr);
    if (!ptr || *ptr != '}') return -9;
    // Parsing complete
    return 4;
}

static int parse_set_slider(uint8_t *msg, int size, uint8_t *out_buffer) {
    uint8_t *ptr = msg;
    uint8_t *start = NULL;
    uint8_t *end = NULL;
    uint8_t *pstart = NULL;
    int index = 0;
    // Port-message code
    out_buffer[index+0] = (5 >> 8);
    out_buffer[index+1] = (5 & 0xFF);
    index += 2;
    // Find all forwarded parameters
    int np;
    for (np = 0; np < 2; np++) {
        // Parameter name
        ptr = jump_space(msg, size, ptr);
        if (!ptr || *ptr != '"') return -2;
        start = ptr+1;
        ptr = jump_to(msg, size, start, '"', '"');
        if (!ptr) return -3;
        end = ptr;
        // Parameter value
        ptr = jump_to(msg, size, end, ':', ':');
        if (!ptr) return -4;
        ptr = jump_space(msg, size, ptr+1);
        if (!ptr) return -5;
        pstart = ptr;
        ptr = jump_to(msg, size, pstart, ',', '}');
        if (!ptr) return -6;
        // Find matching parameter
        if (ptr-pstart < 1) return -7;
        else if (strncmp("ch", start, end-start) == 0) {
            union u_ch_t { uint8_t ch; uint8_t bytebuffer[1]; } u_ch;
            u_ch.ch = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[2], u_ch.bytebuffer, 1);
        }
        else if (strncmp("value", start, end-start) == 0) {
            union u_value_t { uint16_t value; uint8_t bytebuffer[2]; } u_value;
            u_value.value = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[3], u_value.bytebuffer, 2);
        }
        ptr = jump_to(msg, size, ptr, ',', '}');
        if (!ptr) return -8;
        ptr = ptr+1;
    }
    // Zero-init all non-forwarded messages
    // Make sure we are at the end of the message
    ptr = jump_space(msg, size, ptr);
    if (!ptr || *ptr != '}') return -9;
    // Parsing complete
    return 5;
}

static int parse_button_light_on(uint8_t *msg, int size, uint8_t *out_buffer) {
    uint8_t *ptr = msg;
    uint8_t *start = NULL;
    uint8_t *end = NULL;
    uint8_t *pstart = NULL;
    int index = 0;
    // Port-message code
    out_buffer[index+0] = (6 >> 8);
    out_buffer[index+1] = (6 & 0xFF);
    index += 2;
    // Find all forwarded parameters
    int np;
    for (np = 0; np < 2; np++) {
        // Parameter name
        ptr = jump_space(msg, size, ptr);
        if (!ptr || *ptr != '"') return -2;
        start = ptr+1;
        ptr = jump_to(msg, size, start, '"', '"');
        if (!ptr) return -3;
        end = ptr;
        // Parameter value
        ptr = jump_to(msg, size, end, ':', ':');
        if (!ptr) return -4;
        ptr = jump_space(msg, size, ptr+1);
        if (!ptr) return -5;
        pstart = ptr;
        ptr = jump_to(msg, size, pstart, ',', '}');
        if (!ptr) return -6;
        // Find matching parameter
        if (ptr-pstart < 1) return -7;
        else if (strncmp("ch", start, end-start) == 0) {
            union u_ch_t { uint8_t ch; uint8_t bytebuffer[1]; } u_ch;
            u_ch.ch = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[2], u_ch.bytebuffer, 1);
        }
        else if (strncmp("id", start, end-start) == 0) {
            union u_id_t { uint8_t id; uint8_t bytebuffer[1]; } u_id;
            u_id.id = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[3], u_id.bytebuffer, 1);
        }
        ptr = jump_to(msg, size, ptr, ',', '}');
        if (!ptr) return -8;
        ptr = ptr+1;
    }
    // Zero-init all non-forwarded messages
    // Make sure we are at the end of the message
    ptr = jump_space(msg, size, ptr);
    if (!ptr || *ptr != '}') return -9;
    // Parsing complete
    return 4;
}

static int parse_set_meter(uint8_t *msg, int size, uint8_t *out_buffer) {
    uint8_t *ptr = msg;
    uint8_t *start = NULL;
    uint8_t *end = NULL;
    uint8_t *pstart = NULL;
    int index = 0;
    // Port-message code
    out_buffer[index+0] = (7 >> 8);
    out_buffer[index+1] = (7 & 0xFF);
    index += 2;
    // Find all forwarded parameters
    int np;
    for (np = 0; np < 2; np++) {
        // Parameter name
        ptr = jump_space(msg, size, ptr);
        if (!ptr || *ptr != '"') return -2;
        start = ptr+1;
        ptr = jump_to(msg, size, start, '"', '"');
        if (!ptr) return -3;
        end = ptr;
        // Parameter value
        ptr = jump_to(msg, size, end, ':', ':');
        if (!ptr) return -4;
        ptr = jump_space(msg, size, ptr+1);
        if (!ptr) return -5;
        pstart = ptr;
        ptr = jump_to(msg, size, pstart, ',', '}');
        if (!ptr) return -6;
        // Find matching parameter
        if (ptr-pstart < 1) return -7;
        else if (strncmp("ch", start, end-start) == 0) {
            union u_ch_t { uint8_t ch; uint8_t bytebuffer[1]; } u_ch;
            u_ch.ch = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[2], u_ch.bytebuffer, 1);
        }
        else if (strncmp("value", start, end-start) == 0) {
            union u_value_t { uint8_t value; uint8_t bytebuffer[1]; } u_value;
            u_value.value = strtoul(pstart, &ptr, 10);
            memcpy(&out_buffer[3], u_value.bytebuffer, 1);
        }
        ptr = jump_to(msg, size, ptr, ',', '}');
        if (!ptr) return -8;
        ptr = ptr+1;
    }
    // Zero-init all non-forwarded messages
    // Make sure we are at the end of the message
    ptr = jump_space(msg, size, ptr);
    if (!ptr || *ptr != '}') return -9;
    // Parsing complete
    return 4;
}

void MQTT_parser(uint8_t *msg, int size, struct MQTT_Instance *_instance) {
    uint8_t *ptr = msg;
    uint8_t *start = NULL;
    uint8_t *end = NULL;
    // Find opening '{'
    ptr = jump_space(msg, size, ptr);
    if (!ptr || *ptr != '{') return;
    // Find start of message name '"'
    ptr = jump_space(msg, size, ptr+1);
    if (!ptr || *ptr != '"') return;
    start = ptr+1;
    // Find end of message name '"'
    ptr = jump_to(msg, size, start, '"', '"');
    if (!ptr) return;
    end = ptr;

    // Find the message object ':{'
    ptr = jump_space(msg, size, ptr+1);
    if (!ptr || *ptr != ':') return;
    ptr = jump_space(msg, size, ptr+1);
    if (!ptr || *ptr != '{') return;
    ptr++;

    // Make room for parsing
    uint8_t enqueue_buffer[5];

    // Parse the message
    int result = -1;
    if (0) {}
    else if (strncmp("set_pot", start, end-start) == 0) {
        result = parse_set_pot(ptr, size-(ptr-msg), enqueue_buffer);
    }
    else if (strncmp("button_light_off", start, end-start) == 0) {
        result = parse_button_light_off(ptr, size-(ptr-msg), enqueue_buffer);
    }
    else if (strncmp("button_light_blink", start, end-start) == 0) {
        result = parse_button_light_blink(ptr, size-(ptr-msg), enqueue_buffer);
    }
    else if (strncmp("set_slider", start, end-start) == 0) {
        result = parse_set_slider(ptr, size-(ptr-msg), enqueue_buffer);
    }
    else if (strncmp("button_light_on", start, end-start) == 0) {
        result = parse_button_light_on(ptr, size-(ptr-msg), enqueue_buffer);
    }
    else if (strncmp("set_meter", start, end-start) == 0) {
        result = parse_set_meter(ptr, size-(ptr-msg), enqueue_buffer);
    }

    // Enqueue the message
    if (result > 0) {
        externalMessageEnqueue(enqueue_buffer, result, _instance->listener_id);
    } else {
        fprintf(stderr, "[MQTT]: Error parsing message %i\n", result);
    }

}

void MQTT_message_callback(struct mosquitto *mosq, void *_instance, const struct mosquitto_message *msg)
{
    //printf("[MQTT] Received message (%i bytes) on topic %s\n", msg->payloadlen, msg->topic);
    // Find the topic index of the message
    int i;
    for (i = 0; i < 3; i++)
        if (strcmp(msg->topic, MQTT_topics[i]) == 0) break;

    // Only parse and enqueue the message if we are listening for it on this topic
    if (i < 3 && (i == 0)) {
        MQTT_parser(msg->payload, msg->payloadlen, (struct MQTT_Instance*)_instance);
    }
}


/* ---------- FORWARDERS ----------*/
void MQTT_send_message(uint8_t *msg, int msglen, int topic)
{
    int ret;
    if (topic < 3) {
        //printf("[MQTT] Sending message (%i bytes) on topic %s\n", msglen, MQTT_topics[topic]);
        ret = mosquitto_publish(MQTT_mosq, NULL, MQTT_topics[topic], msglen, msg, MQTT_qos, false);
        if (ret) {
            fprintf(stderr, "[MQTT] mosquitto_publish failed for %s : %s\n", MQTT_topics[topic], mosquitto_strerror(ret));
            exit(1); // Exit in case of error
        }
    }
}

// Forwarding of messages MQTT::XTouchExtender::xtouch::slider
void forward_MQTT_XTouchExtender_send_xtouch_slider(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value){
    uint8_t buffer[35];
    int index = 0;
    int result;

    //Start of serialized message
    result = sprintf(&buffer[index], "%.*s", 35-index, "{\"slider\":{");
    if (result >= 0) { index += result; } else { return; }
    // Parameter ch
    result = sprintf(&buffer[index], "%.*s", 35-index, "\"ch\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", ch);
    if (result >= 0) { index += result; } else { return; }
    // Parameter value
    result = sprintf(&buffer[index], "%.*s", 35-index, ",\"value\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", value);
    if (result >= 0) { index += result; } else { return; }
    //End of serialized message
    result = sprintf(&buffer[index], "%.*s", 35-index, "}}");
    if (result >= 0) { index += result; } else { return; }

    // Publish the serialized message
    MQTT_send_message(buffer, index, 2);
}

// Forwarding of messages MQTT::XTouchExtender::xtouch::pot
void forward_MQTT_XTouchExtender_send_xtouch_pot(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value){
    uint8_t buffer[32];
    int index = 0;
    int result;

    //Start of serialized message
    result = sprintf(&buffer[index], "%.*s", 32-index, "{\"pot\":{");
    if (result >= 0) { index += result; } else { return; }
    // Parameter ch
    result = sprintf(&buffer[index], "%.*s", 32-index, "\"ch\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", ch);
    if (result >= 0) { index += result; } else { return; }
    // Parameter value
    result = sprintf(&buffer[index], "%.*s", 32-index, ",\"value\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", value);
    if (result >= 0) { index += result; } else { return; }
    //End of serialized message
    result = sprintf(&buffer[index], "%.*s", 32-index, "}}");
    if (result >= 0) { index += result; } else { return; }

    // Publish the serialized message
    MQTT_send_message(buffer, index, 2);
}

// Forwarding of messages MQTT::XTouchExtender::xtouch::button_release
void forward_MQTT_XTouchExtender_send_xtouch_button_release(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id){
    uint8_t buffer[40];
    int index = 0;
    int result;

    //Start of serialized message
    result = sprintf(&buffer[index], "%.*s", 40-index, "{\"button_release\":{");
    if (result >= 0) { index += result; } else { return; }
    // Parameter ch
    result = sprintf(&buffer[index], "%.*s", 40-index, "\"ch\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", ch);
    if (result >= 0) { index += result; } else { return; }
    // Parameter id
    result = sprintf(&buffer[index], "%.*s", 40-index, ",\"id\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", id);
    if (result >= 0) { index += result; } else { return; }
    //End of serialized message
    result = sprintf(&buffer[index], "%.*s", 40-index, "}}");
    if (result >= 0) { index += result; } else { return; }

    // Publish the serialized message
    MQTT_send_message(buffer, index, 2);
}

// Forwarding of messages MQTT::XTouchExtender::xtouch::pot_slow
void forward_MQTT_XTouchExtender_send_xtouch_pot_slow(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value){
    uint8_t buffer[37];
    int index = 0;
    int result;

    //Start of serialized message
    result = sprintf(&buffer[index], "%.*s", 37-index, "{\"pot_slow\":{");
    if (result >= 0) { index += result; } else { return; }
    // Parameter ch
    result = sprintf(&buffer[index], "%.*s", 37-index, "\"ch\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", ch);
    if (result >= 0) { index += result; } else { return; }
    // Parameter value
    result = sprintf(&buffer[index], "%.*s", 37-index, ",\"value\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", value);
    if (result >= 0) { index += result; } else { return; }
    //End of serialized message
    result = sprintf(&buffer[index], "%.*s", 37-index, "}}");
    if (result >= 0) { index += result; } else { return; }

    // Publish the serialized message
    MQTT_send_message(buffer, index, 2);
}

// Forwarding of messages MQTT::XTouchExtender::xtouch::slider_slow
void forward_MQTT_XTouchExtender_send_xtouch_slider_slow(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value){
    uint8_t buffer[40];
    int index = 0;
    int result;

    //Start of serialized message
    result = sprintf(&buffer[index], "%.*s", 40-index, "{\"slider_slow\":{");
    if (result >= 0) { index += result; } else { return; }
    // Parameter ch
    result = sprintf(&buffer[index], "%.*s", 40-index, "\"ch\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", ch);
    if (result >= 0) { index += result; } else { return; }
    // Parameter value
    result = sprintf(&buffer[index], "%.*s", 40-index, ",\"value\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", value);
    if (result >= 0) { index += result; } else { return; }
    //End of serialized message
    result = sprintf(&buffer[index], "%.*s", 40-index, "}}");
    if (result >= 0) { index += result; } else { return; }

    // Publish the serialized message
    MQTT_send_message(buffer, index, 2);
}

// Forwarding of messages MQTT::XTouchExtender::xtouch::button_press
void forward_MQTT_XTouchExtender_send_xtouch_button_press(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id){
    uint8_t buffer[38];
    int index = 0;
    int result;

    //Start of serialized message
    result = sprintf(&buffer[index], "%.*s", 38-index, "{\"button_press\":{");
    if (result >= 0) { index += result; } else { return; }
    // Parameter ch
    result = sprintf(&buffer[index], "%.*s", 38-index, "\"ch\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", ch);
    if (result >= 0) { index += result; } else { return; }
    // Parameter id
    result = sprintf(&buffer[index], "%.*s", 38-index, ",\"id\":");
    if (result >= 0) { index += result; } else { return; }
    result = sprintf(&buffer[index], "%u", id);
    if (result >= 0) { index += result; } else { return; }
    //End of serialized message
    result = sprintf(&buffer[index], "%.*s", 38-index, "}}");
    if (result >= 0) { index += result; } else { return; }

    // Publish the serialized message
    MQTT_send_message(buffer, index, 2);
}


