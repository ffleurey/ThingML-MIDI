/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application XTouchExtenderMQTTClient
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <pthread.h>
#include "thingml_typedefs.h"
#include "runtime.h"
#include "XTouchExtenderClient.h"

#include "MQTT.h"




/*****************************************************************************
 * Definitions for configuration : XTouchExtenderMQTTClient
 *****************************************************************************/

uint8_t array_test_XTouchExtenderClient_slider_values_var[32];
//Declaration of instance variables
//Instance test
// Variables for the properties of the instance
struct XTouchExtenderClient_Instance test_var;
// Variables for the sessions of the instance

//Instance MQTT for network plugin PosixMQTTPlugin
struct MQTT_Instance MQTT_instance;



//New dispatcher for messages
void dispatch_button_release(uint16_t sender, uint8_t param_ch, uint8_t param_id) {
if (sender == MQTT_instance.listener_id) {

}

}


//New dispatcher for messages
void dispatch_pot(uint16_t sender, uint8_t param_ch, uint8_t param_value) {
if (sender == MQTT_instance.listener_id) {

}

}


//New dispatcher for messages
void dispatch_slider(uint16_t sender, uint8_t param_ch, uint8_t param_value) {
if (sender == MQTT_instance.listener_id) {
XTouchExtenderClient_handle_xtouch_slider(&test_var, param_ch, param_value);

}

}


//New dispatcher for messages
void dispatch_button_press(uint16_t sender, uint8_t param_ch, uint8_t param_id) {
if (sender == MQTT_instance.listener_id) {
XTouchExtenderClient_handle_xtouch_button_press(&test_var, param_ch, param_id);

}

}


int processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 1:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_button_release = 2;
union u_button_release_ch_t {
uint8_t p;
byte bytebuffer[1];
} u_button_release_ch;
u_button_release_ch.bytebuffer[0] = mbuf[mbufi_button_release + 0];
mbufi_button_release += 1;
union u_button_release_id_t {
uint8_t p;
byte bytebuffer[1];
} u_button_release_id;
u_button_release_id.bytebuffer[0] = mbuf[mbufi_button_release + 0];
mbufi_button_release += 1;
dispatch_button_release((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_button_release_ch.p /* ch */ ,
 u_button_release_id.p /* id */ );
break;
}
case 2:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_pot = 2;
union u_pot_ch_t {
uint8_t p;
byte bytebuffer[1];
} u_pot_ch;
u_pot_ch.bytebuffer[0] = mbuf[mbufi_pot + 0];
mbufi_pot += 1;
union u_pot_value_t {
uint8_t p;
byte bytebuffer[1];
} u_pot_value;
u_pot_value.bytebuffer[0] = mbuf[mbufi_pot + 0];
mbufi_pot += 1;
dispatch_pot((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_pot_ch.p /* ch */ ,
 u_pot_value.p /* value */ );
break;
}
case 3:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_slider = 2;
union u_slider_ch_t {
uint8_t p;
byte bytebuffer[1];
} u_slider_ch;
u_slider_ch.bytebuffer[0] = mbuf[mbufi_slider + 0];
mbufi_slider += 1;
union u_slider_value_t {
uint8_t p;
byte bytebuffer[1];
} u_slider_value;
u_slider_value.bytebuffer[0] = mbuf[mbufi_slider + 0];
mbufi_slider += 1;
dispatch_slider((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_slider_ch.p /* ch */ ,
 u_slider_value.p /* value */ );
break;
}
case 4:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_button_press = 2;
union u_button_press_ch_t {
uint8_t p;
byte bytebuffer[1];
} u_button_press_ch;
u_button_press_ch.bytebuffer[0] = mbuf[mbufi_button_press + 0];
mbufi_button_press += 1;
union u_button_press_id_t {
uint8_t p;
byte bytebuffer[1];
} u_button_press_id;
u_button_press_id.bytebuffer[0] = mbuf[mbufi_button_press + 0];
mbufi_button_press += 1;
dispatch_button_press((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_button_press_ch.p /* ch */ ,
 u_button_press_id.p /* id */ );
break;
}
}
return 1;
}

void forward_XTouchExtenderClient_send_xtouch_set_pot(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t value){
if(_instance->id_xtouch == test_var.id_xtouch) {
forward_MQTT_XTouchExtenderClient_send_xtouch_set_pot(_instance, ch, value);
}
}
void forward_XTouchExtenderClient_send_xtouch_button_light_off(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id){
if(_instance->id_xtouch == test_var.id_xtouch) {
forward_MQTT_XTouchExtenderClient_send_xtouch_button_light_off(_instance, ch, id);
}
}
void forward_XTouchExtenderClient_send_xtouch_set_meter(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t value){
if(_instance->id_xtouch == test_var.id_xtouch) {
forward_MQTT_XTouchExtenderClient_send_xtouch_set_meter(_instance, ch, value);
}
}
void forward_XTouchExtenderClient_send_xtouch_button_light_blink(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id){
if(_instance->id_xtouch == test_var.id_xtouch) {
forward_MQTT_XTouchExtenderClient_send_xtouch_button_light_blink(_instance, ch, id);
}
}
void forward_XTouchExtenderClient_send_xtouch_set_slider(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint16_t value){
if(_instance->id_xtouch == test_var.id_xtouch) {
forward_MQTT_XTouchExtenderClient_send_xtouch_set_slider(_instance, ch, value);
}
}
void forward_XTouchExtenderClient_send_xtouch_button_light_on(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id){
if(_instance->id_xtouch == test_var.id_xtouch) {
forward_MQTT_XTouchExtenderClient_send_xtouch_button_light_on(_instance, ch, id);
}
}

//external Message enqueue
void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id) {
if ((msgSize >= 2) && (msg != NULL)) {
uint8_t msgSizeOK = 0;
switch(msg[0] * 256 + msg[1]) {
case 1:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 2:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 3:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 4:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
}

if(msgSizeOK == 1) {
fifo_lock();
if ( fifo_byte_available() > (msgSize + 2) ) {
	uint8_t i;
	for (i = 0; i < 2; i++) {
		_fifo_enqueue(msg[i]);
	}
	_fifo_enqueue((listener_id >> 8) & 0xFF);
	_fifo_enqueue(listener_id & 0xFF);
	for (i = 2; i < msgSize; i++) {
		_fifo_enqueue(msg[i]);
	}
}
fifo_unlock_and_notify();
}
}
}

void initialize_configuration_XTouchExtenderMQTTClient() {
// Initialize connectors
register_external_XTouchExtenderClient_send_xtouch_button_light_on_listener(&forward_XTouchExtenderClient_send_xtouch_button_light_on);
register_external_XTouchExtenderClient_send_xtouch_button_light_off_listener(&forward_XTouchExtenderClient_send_xtouch_button_light_off);
register_external_XTouchExtenderClient_send_xtouch_button_light_blink_listener(&forward_XTouchExtenderClient_send_xtouch_button_light_blink);
register_external_XTouchExtenderClient_send_xtouch_set_slider_listener(&forward_XTouchExtenderClient_send_xtouch_set_slider);
register_external_XTouchExtenderClient_send_xtouch_set_pot_listener(&forward_XTouchExtenderClient_send_xtouch_set_pot);
register_external_XTouchExtenderClient_send_xtouch_set_meter_listener(&forward_XTouchExtenderClient_send_xtouch_set_meter);

// Init the ID, state variables and properties for external connector MQTT

// Network Initialization
// Initialise MQTT:
MQTT_instance.listener_id = add_instance(&MQTT_instance);
MQTT_setup(&MQTT_instance);
pthread_t thread_MQTT;
pthread_create( &thread_MQTT, NULL, MQTT_start_receiver_thread, NULL);

// End Network Initialization

// Init the ID, state variables and properties for instance test
test_var.active = true;
test_var.id_xtouch = add_instance( (void*) &test_var);
test_var.XTouchExtenderClient_XTouchExtenderTestSC_State = XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_RUNNING_STATE;
test_var.XTouchExtenderClient_current_bank_var = 0;
test_var.XTouchExtenderClient_slider_values_var = array_test_XTouchExtenderClient_slider_values_var;
test_var.XTouchExtenderClient_slider_values_var_size = 32;

XTouchExtenderClient_XTouchExtenderTestSC_OnEntry(XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_STATE, &test_var);
}




void term(int signum)
{
    

    fflush(stdout);
    fflush(stderr);
    exit(signum);
}


int main(int argc, char *argv[]) {
    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_handler = term;
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);

    init_runtime();
    
    initialize_configuration_XTouchExtenderMQTTClient();

    while (1) {
        
// Network Listener// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
}

        processMessageQueue();
  }
}