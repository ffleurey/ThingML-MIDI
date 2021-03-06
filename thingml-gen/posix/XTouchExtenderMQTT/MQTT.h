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

#include "MidiParser.h"
#include "XTouchExtender.h"
#include "RawMidi.h"


struct MQTT_Instance {
    uint16_t listener_id;
    /*INSTANCE_INFORMATION*/
};

void MQTT_setup(struct MQTT_Instance *_instance);

void MQTT_start_receiver_thread();
void MQTT_loop_poll();

// Forwarding of messages MQTT::XTouchExtender::xtouch::slider
void forward_MQTT_XTouchExtender_send_xtouch_slider(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value);
// Forwarding of messages MQTT::XTouchExtender::xtouch::button_press
void forward_MQTT_XTouchExtender_send_xtouch_button_press(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id);
// Forwarding of messages MQTT::XTouchExtender::xtouch::button_release
void forward_MQTT_XTouchExtender_send_xtouch_button_release(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id);
// Forwarding of messages MQTT::XTouchExtender::xtouch::pot_slow
void forward_MQTT_XTouchExtender_send_xtouch_pot_slow(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value);
// Forwarding of messages MQTT::XTouchExtender::xtouch::slider_slow
void forward_MQTT_XTouchExtender_send_xtouch_slider_slow(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value);
// Forwarding of messages MQTT::XTouchExtender::xtouch::pot
void forward_MQTT_XTouchExtender_send_xtouch_pot(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value);


#endif
