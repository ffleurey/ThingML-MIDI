#ifndef MQTT_PosixMQTT_Client_h
#define  MQTT_PosixMQTT_Client_h

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <mosquitto.h>

#include "XTouchExtenderClient.h"


struct MQTT_Instance {
    uint16_t listener_id;
    /*INSTANCE_INFORMATION*/
};

void MQTT_setup(struct MQTT_Instance *_instance);

void MQTT_start_receiver_thread();
void MQTT_loop_poll();

// Forwarding of messages MQTT::XTouchExtenderClient::xtouch::button_light_on
void forward_MQTT_XTouchExtenderClient_send_xtouch_button_light_on(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id);
// Forwarding of messages MQTT::XTouchExtenderClient::xtouch::set_meter
void forward_MQTT_XTouchExtenderClient_send_xtouch_set_meter(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t value);
// Forwarding of messages MQTT::XTouchExtenderClient::xtouch::set_pot
void forward_MQTT_XTouchExtenderClient_send_xtouch_set_pot(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t value);
// Forwarding of messages MQTT::XTouchExtenderClient::xtouch::button_light_off
void forward_MQTT_XTouchExtenderClient_send_xtouch_button_light_off(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id);
// Forwarding of messages MQTT::XTouchExtenderClient::xtouch::set_slider
void forward_MQTT_XTouchExtenderClient_send_xtouch_set_slider(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint16_t value);
// Forwarding of messages MQTT::XTouchExtenderClient::xtouch::button_light_blink
void forward_MQTT_XTouchExtenderClient_send_xtouch_button_light_blink(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id);


#endif
