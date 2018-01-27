/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application XTouchExtenderMQTT
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
#include "RawMidi.h"
#include "MidiParser.h"
#include "XTouchExtender.h"

#include "MQTT.h"




/*****************************************************************************
 * Definitions for configuration : XTouchExtenderMQTT
 *****************************************************************************/

uint8_t array_parser_MidiParser_MidiEchoSC_NoteOff_buf_var[2];
uint8_t array_parser_MidiParser_MidiEchoSC_PBendChange_buf_var[2];
uint8_t array_parser_MidiParser_MidiEchoSC_NoteOn_buf_var[2];
uint8_t array_parser_MidiParser_MidiEchoSC_CtrlChange_buf_var[2];
//Declaration of instance variables
//Instance midi
// Variables for the properties of the instance
struct RawMidi_Instance midi_var;
// Variables for the sessions of the instance
//Instance parser
// Variables for the properties of the instance
struct MidiParser_Instance parser_var;
// Variables for the sessions of the instance
//Instance xtouch
// Variables for the properties of the instance
struct XTouchExtender_Instance xtouch_var;
// Variables for the sessions of the instance

//Instance MQTT for network plugin PosixMQTTPlugin
struct MQTT_Instance MQTT_instance;

// Enqueue of messages RawMidi::rawmidi::midi_error
void enqueue_RawMidi_send_rawmidi_midi_error(struct RawMidi_Instance *_instance, int code){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_rawmidi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_rawmidi & 0xFF );

// parameter code
union u_code_t {
int p;
byte bytebuffer[2];
} u_code;
u_code.p = code;
_fifo_enqueue(u_code.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_code.bytebuffer[1] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages RawMidi::rawmidi::midi_in
void enqueue_RawMidi_send_rawmidi_midi_in(struct RawMidi_Instance *_instance, uint8_t b){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_rawmidi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_rawmidi & 0xFF );

// parameter b
union u_b_t {
uint8_t p;
byte bytebuffer[1];
} u_b;
u_b.p = b;
_fifo_enqueue(u_b.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages MidiParser::rawmidi::midi_out
void enqueue_MidiParser_send_rawmidi_midi_out(struct MidiParser_Instance *_instance, uint8_t b){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (9 >> 8) & 0xFF );
_fifo_enqueue( 9 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_rawmidi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_rawmidi & 0xFF );

// parameter b
union u_b_t {
uint8_t p;
byte bytebuffer[1];
} u_b;
u_b.p = b;
_fifo_enqueue(u_b.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages MidiParser::rawmidi::midi_open
void enqueue_MidiParser_send_rawmidi_midi_open(struct MidiParser_Instance *_instance, uint8_t card, uint8_t dev, uint8_t sub){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (10 >> 8) & 0xFF );
_fifo_enqueue( 10 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_rawmidi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_rawmidi & 0xFF );

// parameter card
union u_card_t {
uint8_t p;
byte bytebuffer[1];
} u_card;
u_card.p = card;
_fifo_enqueue(u_card.bytebuffer[0] & 0xFF );

// parameter dev
union u_dev_t {
uint8_t p;
byte bytebuffer[1];
} u_dev;
u_dev.p = dev;
_fifo_enqueue(u_dev.bytebuffer[0] & 0xFF );

// parameter sub
union u_sub_t {
uint8_t p;
byte bytebuffer[1];
} u_sub;
u_sub.p = sub;
_fifo_enqueue(u_sub.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages MidiParser::rawmidi::midi_close
void enqueue_MidiParser_send_rawmidi_midi_close(struct MidiParser_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (11 >> 8) & 0xFF );
_fifo_enqueue( 11 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_rawmidi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_rawmidi & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages MidiParser::midi::note_on
void enqueue_MidiParser_send_midi_note_on(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (12 >> 8) & 0xFF );
_fifo_enqueue( 12 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_midi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_midi & 0xFF );

// parameter channel
union u_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_channel;
u_channel.p = channel;
_fifo_enqueue(u_channel.bytebuffer[0] & 0xFF );

// parameter key
union u_key_t {
uint8_t p;
byte bytebuffer[1];
} u_key;
u_key.p = key;
_fifo_enqueue(u_key.bytebuffer[0] & 0xFF );

// parameter velocity
union u_velocity_t {
uint8_t p;
byte bytebuffer[1];
} u_velocity;
u_velocity.p = velocity;
_fifo_enqueue(u_velocity.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages MidiParser::midi::pitch_bend_change
void enqueue_MidiParser_send_midi_pitch_bend_change(struct MidiParser_Instance *_instance, uint8_t channel, uint16_t vpbend){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (13 >> 8) & 0xFF );
_fifo_enqueue( 13 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_midi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_midi & 0xFF );

// parameter channel
union u_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_channel;
u_channel.p = channel;
_fifo_enqueue(u_channel.bytebuffer[0] & 0xFF );

// parameter vpbend
union u_vpbend_t {
uint16_t p;
byte bytebuffer[2];
} u_vpbend;
u_vpbend.p = vpbend;
_fifo_enqueue(u_vpbend.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_vpbend.bytebuffer[1] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages MidiParser::midi::note_off
void enqueue_MidiParser_send_midi_note_off(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (14 >> 8) & 0xFF );
_fifo_enqueue( 14 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_midi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_midi & 0xFF );

// parameter channel
union u_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_channel;
u_channel.p = channel;
_fifo_enqueue(u_channel.bytebuffer[0] & 0xFF );

// parameter key
union u_key_t {
uint8_t p;
byte bytebuffer[1];
} u_key;
u_key.p = key;
_fifo_enqueue(u_key.bytebuffer[0] & 0xFF );

// parameter velocity
union u_velocity_t {
uint8_t p;
byte bytebuffer[1];
} u_velocity;
u_velocity.p = velocity;
_fifo_enqueue(u_velocity.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages MidiParser::midi::control_change
void enqueue_MidiParser_send_midi_control_change(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t ctrl, uint8_t value){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (15 >> 8) & 0xFF );
_fifo_enqueue( 15 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_midi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_midi & 0xFF );

// parameter channel
union u_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_channel;
u_channel.p = channel;
_fifo_enqueue(u_channel.bytebuffer[0] & 0xFF );

// parameter ctrl
union u_ctrl_t {
uint8_t p;
byte bytebuffer[1];
} u_ctrl;
u_ctrl.p = ctrl;
_fifo_enqueue(u_ctrl.bytebuffer[0] & 0xFF );

// parameter value
union u_value_t {
uint8_t p;
byte bytebuffer[1];
} u_value;
u_value.p = value;
_fifo_enqueue(u_value.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages XTouchExtender::midi::note_on
void enqueue_XTouchExtender_send_midi_note_on(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (12 >> 8) & 0xFF );
_fifo_enqueue( 12 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_midi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_midi & 0xFF );

// parameter channel
union u_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_channel;
u_channel.p = channel;
_fifo_enqueue(u_channel.bytebuffer[0] & 0xFF );

// parameter key
union u_key_t {
uint8_t p;
byte bytebuffer[1];
} u_key;
u_key.p = key;
_fifo_enqueue(u_key.bytebuffer[0] & 0xFF );

// parameter velocity
union u_velocity_t {
uint8_t p;
byte bytebuffer[1];
} u_velocity;
u_velocity.p = velocity;
_fifo_enqueue(u_velocity.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages XTouchExtender::midi::pitch_bend_change
void enqueue_XTouchExtender_send_midi_pitch_bend_change(struct XTouchExtender_Instance *_instance, uint8_t channel, uint16_t vpbend){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (13 >> 8) & 0xFF );
_fifo_enqueue( 13 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_midi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_midi & 0xFF );

// parameter channel
union u_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_channel;
u_channel.p = channel;
_fifo_enqueue(u_channel.bytebuffer[0] & 0xFF );

// parameter vpbend
union u_vpbend_t {
uint16_t p;
byte bytebuffer[2];
} u_vpbend;
u_vpbend.p = vpbend;
_fifo_enqueue(u_vpbend.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_vpbend.bytebuffer[1] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages XTouchExtender::midi::note_off
void enqueue_XTouchExtender_send_midi_note_off(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (14 >> 8) & 0xFF );
_fifo_enqueue( 14 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_midi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_midi & 0xFF );

// parameter channel
union u_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_channel;
u_channel.p = channel;
_fifo_enqueue(u_channel.bytebuffer[0] & 0xFF );

// parameter key
union u_key_t {
uint8_t p;
byte bytebuffer[1];
} u_key;
u_key.p = key;
_fifo_enqueue(u_key.bytebuffer[0] & 0xFF );

// parameter velocity
union u_velocity_t {
uint8_t p;
byte bytebuffer[1];
} u_velocity;
u_velocity.p = velocity;
_fifo_enqueue(u_velocity.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages XTouchExtender::midi::control_change
void enqueue_XTouchExtender_send_midi_control_change(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t ctrl, uint8_t value){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (15 >> 8) & 0xFF );
_fifo_enqueue( 15 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_midi >> 8) & 0xFF );
_fifo_enqueue( _instance->id_midi & 0xFF );

// parameter channel
union u_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_channel;
u_channel.p = channel;
_fifo_enqueue(u_channel.bytebuffer[0] & 0xFF );

// parameter ctrl
union u_ctrl_t {
uint8_t p;
byte bytebuffer[1];
} u_ctrl;
u_ctrl.p = ctrl;
_fifo_enqueue(u_ctrl.bytebuffer[0] & 0xFF );

// parameter value
union u_value_t {
uint8_t p;
byte bytebuffer[1];
} u_value;
u_value.p = value;
_fifo_enqueue(u_value.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}


//New dispatcher for messages
void dispatch_midi_error(uint16_t sender, int param_code) {
if (sender == midi_var.id_rawmidi) {

}

}


//New dispatcher for messages
void dispatch_note_off(uint16_t sender, uint8_t param_channel, uint8_t param_key, uint8_t param_velocity) {
if (sender == xtouch_var.id_midi) {
MidiParser_handle_midi_note_off(&parser_var, param_channel, param_key, param_velocity);

}
if (sender == parser_var.id_midi) {

}

}


//New dispatcher for messages
void dispatch_button_light_on(uint16_t sender, uint8_t param_ch, uint8_t param_id) {
if (sender == MQTT_instance.listener_id) {
XTouchExtender_handle_xtouch_button_light_on(&xtouch_var, param_ch, param_id);

}

}


//New dispatcher for messages
void dispatch_set_pot(uint16_t sender, uint8_t param_ch, uint8_t param_value) {
if (sender == MQTT_instance.listener_id) {
XTouchExtender_handle_xtouch_set_pot(&xtouch_var, param_ch, param_value);

}

}


//New dispatcher for messages
void dispatch_set_meter(uint16_t sender, uint8_t param_ch, uint8_t param_value) {
if (sender == MQTT_instance.listener_id) {
XTouchExtender_handle_xtouch_set_meter(&xtouch_var, param_ch, param_value);

}

}


//New dispatcher for messages
void dispatch_midi_in(uint16_t sender, uint8_t param_b) {
if (sender == midi_var.id_rawmidi) {
MidiParser_handle_rawmidi_midi_in(&parser_var, param_b);

}

}


//New dispatcher for messages
void dispatch_note_on(uint16_t sender, uint8_t param_channel, uint8_t param_key, uint8_t param_velocity) {
if (sender == xtouch_var.id_midi) {
MidiParser_handle_midi_note_on(&parser_var, param_channel, param_key, param_velocity);

}
if (sender == parser_var.id_midi) {
XTouchExtender_handle_midi_note_on(&xtouch_var, param_channel, param_key, param_velocity);

}

}


//New dispatcher for messages
void dispatch_midi_out(uint16_t sender, uint8_t param_b) {
if (sender == parser_var.id_rawmidi) {
RawMidi_handle_rawmidi_midi_out(&midi_var, param_b);

}

}


//New dispatcher for messages
void dispatch_pitch_bend_change(uint16_t sender, uint8_t param_channel, uint16_t param_vpbend) {
if (sender == xtouch_var.id_midi) {
MidiParser_handle_midi_pitch_bend_change(&parser_var, param_channel, param_vpbend);

}
if (sender == parser_var.id_midi) {

}

}


//New dispatcher for messages
void dispatch_set_slider(uint16_t sender, uint8_t param_ch, uint16_t param_value) {
if (sender == MQTT_instance.listener_id) {
XTouchExtender_handle_xtouch_set_slider(&xtouch_var, param_ch, param_value);

}

}


//New dispatcher for messages
void dispatch_button_light_blink(uint16_t sender, uint8_t param_ch, uint8_t param_id) {
if (sender == MQTT_instance.listener_id) {
XTouchExtender_handle_xtouch_button_light_blink(&xtouch_var, param_ch, param_id);

}

}


//New dispatcher for messages
void dispatch_control_change(uint16_t sender, uint8_t param_channel, uint8_t param_ctrl, uint8_t param_value) {
if (sender == xtouch_var.id_midi) {
MidiParser_handle_midi_control_change(&parser_var, param_channel, param_ctrl, param_value);

}
if (sender == parser_var.id_midi) {
XTouchExtender_handle_midi_control_change(&xtouch_var, param_channel, param_ctrl, param_value);

}

}


//New dispatcher for messages
void dispatch_midi_open(uint16_t sender, uint8_t param_card, uint8_t param_dev, uint8_t param_sub) {
if (sender == parser_var.id_rawmidi) {
RawMidi_handle_rawmidi_midi_open(&midi_var, param_card, param_dev, param_sub);

}

}


//New dispatcher for messages
void dispatch_button_light_off(uint16_t sender, uint8_t param_ch, uint8_t param_id) {
if (sender == MQTT_instance.listener_id) {
XTouchExtender_handle_xtouch_button_light_off(&xtouch_var, param_ch, param_id);

}

}


//New dispatcher for messages
void dispatch_midi_close(uint16_t sender) {
if (sender == parser_var.id_rawmidi) {
RawMidi_handle_rawmidi_midi_close(&midi_var);

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
case 7:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_midi_error = 2;
union u_midi_error_code_t {
int p;
byte bytebuffer[2];
} u_midi_error_code;
u_midi_error_code.bytebuffer[0] = mbuf[mbufi_midi_error + 0];
u_midi_error_code.bytebuffer[1] = mbuf[mbufi_midi_error + 1];
mbufi_midi_error += 2;
dispatch_midi_error((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_midi_error_code.p /* code */ );
break;
}
case 14:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_note_off = 2;
union u_note_off_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_note_off_channel;
u_note_off_channel.bytebuffer[0] = mbuf[mbufi_note_off + 0];
mbufi_note_off += 1;
union u_note_off_key_t {
uint8_t p;
byte bytebuffer[1];
} u_note_off_key;
u_note_off_key.bytebuffer[0] = mbuf[mbufi_note_off + 0];
mbufi_note_off += 1;
union u_note_off_velocity_t {
uint8_t p;
byte bytebuffer[1];
} u_note_off_velocity;
u_note_off_velocity.bytebuffer[0] = mbuf[mbufi_note_off + 0];
mbufi_note_off += 1;
dispatch_note_off((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_note_off_channel.p /* channel */ ,
 u_note_off_key.p /* key */ ,
 u_note_off_velocity.p /* velocity */ );
break;
}
case 3:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_button_light_on = 2;
union u_button_light_on_ch_t {
uint8_t p;
byte bytebuffer[1];
} u_button_light_on_ch;
u_button_light_on_ch.bytebuffer[0] = mbuf[mbufi_button_light_on + 0];
mbufi_button_light_on += 1;
union u_button_light_on_id_t {
uint8_t p;
byte bytebuffer[1];
} u_button_light_on_id;
u_button_light_on_id.bytebuffer[0] = mbuf[mbufi_button_light_on + 0];
mbufi_button_light_on += 1;
dispatch_button_light_on((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_button_light_on_ch.p /* ch */ ,
 u_button_light_on_id.p /* id */ );
break;
}
case 4:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_set_pot = 2;
union u_set_pot_ch_t {
uint8_t p;
byte bytebuffer[1];
} u_set_pot_ch;
u_set_pot_ch.bytebuffer[0] = mbuf[mbufi_set_pot + 0];
mbufi_set_pot += 1;
union u_set_pot_value_t {
uint8_t p;
byte bytebuffer[1];
} u_set_pot_value;
u_set_pot_value.bytebuffer[0] = mbuf[mbufi_set_pot + 0];
mbufi_set_pot += 1;
dispatch_set_pot((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_set_pot_ch.p /* ch */ ,
 u_set_pot_value.p /* value */ );
break;
}
case 5:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_set_meter = 2;
union u_set_meter_ch_t {
uint8_t p;
byte bytebuffer[1];
} u_set_meter_ch;
u_set_meter_ch.bytebuffer[0] = mbuf[mbufi_set_meter + 0];
mbufi_set_meter += 1;
union u_set_meter_value_t {
uint8_t p;
byte bytebuffer[1];
} u_set_meter_value;
u_set_meter_value.bytebuffer[0] = mbuf[mbufi_set_meter + 0];
mbufi_set_meter += 1;
dispatch_set_meter((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_set_meter_ch.p /* ch */ ,
 u_set_meter_value.p /* value */ );
break;
}
case 8:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_midi_in = 2;
union u_midi_in_b_t {
uint8_t p;
byte bytebuffer[1];
} u_midi_in_b;
u_midi_in_b.bytebuffer[0] = mbuf[mbufi_midi_in + 0];
mbufi_midi_in += 1;
dispatch_midi_in((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_midi_in_b.p /* b */ );
break;
}
case 12:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_note_on = 2;
union u_note_on_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_note_on_channel;
u_note_on_channel.bytebuffer[0] = mbuf[mbufi_note_on + 0];
mbufi_note_on += 1;
union u_note_on_key_t {
uint8_t p;
byte bytebuffer[1];
} u_note_on_key;
u_note_on_key.bytebuffer[0] = mbuf[mbufi_note_on + 0];
mbufi_note_on += 1;
union u_note_on_velocity_t {
uint8_t p;
byte bytebuffer[1];
} u_note_on_velocity;
u_note_on_velocity.bytebuffer[0] = mbuf[mbufi_note_on + 0];
mbufi_note_on += 1;
dispatch_note_on((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_note_on_channel.p /* channel */ ,
 u_note_on_key.p /* key */ ,
 u_note_on_velocity.p /* velocity */ );
break;
}
case 9:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_midi_out = 2;
union u_midi_out_b_t {
uint8_t p;
byte bytebuffer[1];
} u_midi_out_b;
u_midi_out_b.bytebuffer[0] = mbuf[mbufi_midi_out + 0];
mbufi_midi_out += 1;
dispatch_midi_out((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_midi_out_b.p /* b */ );
break;
}
case 13:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_pitch_bend_change = 2;
union u_pitch_bend_change_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_pitch_bend_change_channel;
u_pitch_bend_change_channel.bytebuffer[0] = mbuf[mbufi_pitch_bend_change + 0];
mbufi_pitch_bend_change += 1;
union u_pitch_bend_change_vpbend_t {
uint16_t p;
byte bytebuffer[2];
} u_pitch_bend_change_vpbend;
u_pitch_bend_change_vpbend.bytebuffer[0] = mbuf[mbufi_pitch_bend_change + 0];
u_pitch_bend_change_vpbend.bytebuffer[1] = mbuf[mbufi_pitch_bend_change + 1];
mbufi_pitch_bend_change += 2;
dispatch_pitch_bend_change((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_pitch_bend_change_channel.p /* channel */ ,
 u_pitch_bend_change_vpbend.p /* vpbend */ );
break;
}
case 2:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_button_light_blink = 2;
union u_button_light_blink_ch_t {
uint8_t p;
byte bytebuffer[1];
} u_button_light_blink_ch;
u_button_light_blink_ch.bytebuffer[0] = mbuf[mbufi_button_light_blink + 0];
mbufi_button_light_blink += 1;
union u_button_light_blink_id_t {
uint8_t p;
byte bytebuffer[1];
} u_button_light_blink_id;
u_button_light_blink_id.bytebuffer[0] = mbuf[mbufi_button_light_blink + 0];
mbufi_button_light_blink += 1;
dispatch_button_light_blink((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_button_light_blink_ch.p /* ch */ ,
 u_button_light_blink_id.p /* id */ );
break;
}
case 1:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_set_slider = 2;
union u_set_slider_ch_t {
uint8_t p;
byte bytebuffer[1];
} u_set_slider_ch;
u_set_slider_ch.bytebuffer[0] = mbuf[mbufi_set_slider + 0];
mbufi_set_slider += 1;
union u_set_slider_value_t {
uint16_t p;
byte bytebuffer[2];
} u_set_slider_value;
u_set_slider_value.bytebuffer[0] = mbuf[mbufi_set_slider + 0];
u_set_slider_value.bytebuffer[1] = mbuf[mbufi_set_slider + 1];
mbufi_set_slider += 2;
dispatch_set_slider((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_set_slider_ch.p /* ch */ ,
 u_set_slider_value.p /* value */ );
break;
}
case 15:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_control_change = 2;
union u_control_change_channel_t {
uint8_t p;
byte bytebuffer[1];
} u_control_change_channel;
u_control_change_channel.bytebuffer[0] = mbuf[mbufi_control_change + 0];
mbufi_control_change += 1;
union u_control_change_ctrl_t {
uint8_t p;
byte bytebuffer[1];
} u_control_change_ctrl;
u_control_change_ctrl.bytebuffer[0] = mbuf[mbufi_control_change + 0];
mbufi_control_change += 1;
union u_control_change_value_t {
uint8_t p;
byte bytebuffer[1];
} u_control_change_value;
u_control_change_value.bytebuffer[0] = mbuf[mbufi_control_change + 0];
mbufi_control_change += 1;
dispatch_control_change((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_control_change_channel.p /* channel */ ,
 u_control_change_ctrl.p /* ctrl */ ,
 u_control_change_value.p /* value */ );
break;
}
case 10:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_midi_open = 2;
union u_midi_open_card_t {
uint8_t p;
byte bytebuffer[1];
} u_midi_open_card;
u_midi_open_card.bytebuffer[0] = mbuf[mbufi_midi_open + 0];
mbufi_midi_open += 1;
union u_midi_open_dev_t {
uint8_t p;
byte bytebuffer[1];
} u_midi_open_dev;
u_midi_open_dev.bytebuffer[0] = mbuf[mbufi_midi_open + 0];
mbufi_midi_open += 1;
union u_midi_open_sub_t {
uint8_t p;
byte bytebuffer[1];
} u_midi_open_sub;
u_midi_open_sub.bytebuffer[0] = mbuf[mbufi_midi_open + 0];
mbufi_midi_open += 1;
dispatch_midi_open((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_midi_open_card.p /* card */ ,
 u_midi_open_dev.p /* dev */ ,
 u_midi_open_sub.p /* sub */ );
break;
}
case 6:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_button_light_off = 2;
union u_button_light_off_ch_t {
uint8_t p;
byte bytebuffer[1];
} u_button_light_off_ch;
u_button_light_off_ch.bytebuffer[0] = mbuf[mbufi_button_light_off + 0];
mbufi_button_light_off += 1;
union u_button_light_off_id_t {
uint8_t p;
byte bytebuffer[1];
} u_button_light_off_id;
u_button_light_off_id.bytebuffer[0] = mbuf[mbufi_button_light_off + 0];
mbufi_button_light_off += 1;
dispatch_button_light_off((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_button_light_off_ch.p /* ch */ ,
 u_button_light_off_id.p /* id */ );
break;
}
case 11:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_midi_close = 2;
dispatch_midi_close((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}
return 1;
}

void forward_XTouchExtender_send_xtouch_slider(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value){
if(_instance->id_xtouch == xtouch_var.id_xtouch) {
forward_MQTT_XTouchExtender_send_xtouch_slider(_instance, ch, value);
}
}
void forward_XTouchExtender_send_xtouch_button_press(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id){
if(_instance->id_xtouch == xtouch_var.id_xtouch) {
forward_MQTT_XTouchExtender_send_xtouch_button_press(_instance, ch, id);
}
}
void forward_XTouchExtender_send_xtouch_button_release(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id){
if(_instance->id_xtouch == xtouch_var.id_xtouch) {
forward_MQTT_XTouchExtender_send_xtouch_button_release(_instance, ch, id);
}
}
void forward_XTouchExtender_send_xtouch_pot(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value){
if(_instance->id_xtouch == xtouch_var.id_xtouch) {
forward_MQTT_XTouchExtender_send_xtouch_pot(_instance, ch, value);
}
}

//external Message enqueue
void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id) {
if ((msgSize >= 2) && (msg != NULL)) {
uint8_t msgSizeOK = 0;
switch(msg[0] * 256 + msg[1]) {
case 3:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 2:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 1:
if(msgSize == 5) {
msgSizeOK = 1;}
break;
case 4:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 5:
if(msgSize == 4) {
msgSizeOK = 1;}
break;
case 6:
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

void initialize_configuration_XTouchExtenderMQTT() {
// Initialize connectors
register_external_XTouchExtender_send_xtouch_slider_listener(&forward_XTouchExtender_send_xtouch_slider);
register_external_XTouchExtender_send_xtouch_pot_listener(&forward_XTouchExtender_send_xtouch_pot);
register_external_XTouchExtender_send_xtouch_button_press_listener(&forward_XTouchExtender_send_xtouch_button_press);
register_external_XTouchExtender_send_xtouch_button_release_listener(&forward_XTouchExtender_send_xtouch_button_release);
register_RawMidi_send_rawmidi_midi_in_listener(&enqueue_RawMidi_send_rawmidi_midi_in);
register_RawMidi_send_rawmidi_midi_error_listener(&enqueue_RawMidi_send_rawmidi_midi_error);
register_MidiParser_send_rawmidi_midi_open_listener(&enqueue_MidiParser_send_rawmidi_midi_open);
register_MidiParser_send_rawmidi_midi_close_listener(&enqueue_MidiParser_send_rawmidi_midi_close);
register_MidiParser_send_rawmidi_midi_out_listener(&enqueue_MidiParser_send_rawmidi_midi_out);
register_MidiParser_send_midi_note_on_listener(&enqueue_MidiParser_send_midi_note_on);
register_MidiParser_send_midi_note_off_listener(&enqueue_MidiParser_send_midi_note_off);
register_MidiParser_send_midi_pitch_bend_change_listener(&enqueue_MidiParser_send_midi_pitch_bend_change);
register_MidiParser_send_midi_control_change_listener(&enqueue_MidiParser_send_midi_control_change);
register_XTouchExtender_send_midi_note_on_listener(&enqueue_XTouchExtender_send_midi_note_on);
register_XTouchExtender_send_midi_note_off_listener(&enqueue_XTouchExtender_send_midi_note_off);
register_XTouchExtender_send_midi_pitch_bend_change_listener(&enqueue_XTouchExtender_send_midi_pitch_bend_change);
register_XTouchExtender_send_midi_control_change_listener(&enqueue_XTouchExtender_send_midi_control_change);

// Init the ID, state variables and properties for external connector MQTT

// Network Initialization
// Initialise MQTT:
MQTT_instance.listener_id = add_instance(&MQTT_instance);
MQTT_setup(&MQTT_instance);
pthread_t thread_MQTT;
pthread_create( &thread_MQTT, NULL, MQTT_start_receiver_thread, NULL);

// End Network Initialization

// Init the ID, state variables and properties for instance midi
midi_var.active = true;
midi_var.id_rawmidi = add_instance( (void*) &midi_var);
midi_var.RawMidi_RawMidiSC_State = RAWMIDI_RAWMIDISC_DISCONNECTED_STATE;
midi_var.RawMidi_connected_var = 0;

RawMidi_RawMidiSC_OnEntry(RAWMIDI_RAWMIDISC_STATE, &midi_var);
// Init the ID, state variables and properties for instance parser
parser_var.active = true;
parser_var.id_rawmidi = add_instance( (void*) &parser_var);
parser_var.id_midi = add_instance( (void*) &parser_var);
parser_var.MidiParser_MidiEchoSC_State = MIDIPARSER_MIDIECHOSC_WAITING_STATE;
parser_var.MidiParser_MidiEchoSC_PBendChange_buf_size_var = 2;
parser_var.MidiParser_MidiEchoSC_NoteOff_buf_size_var = 2;
parser_var.MidiParser_MidiEchoSC_CtrlChange_buf_size_var = 2;
parser_var.MidiParser_MidiEchoSC_CtrlChange_idx_var = 0;
parser_var.MidiParser_MidiEchoSC_NoteOn_buf_size_var = 2;
parser_var.MidiParser_MidiEchoSC_PBendChange_idx_var = 0;
parser_var.MidiParser_MidiEchoSC_NoteOff_idx_var = 0;
parser_var.MidiParser_MidiEchoSC_NoteOff_buf_var = array_parser_MidiParser_MidiEchoSC_NoteOff_buf_var;
parser_var.MidiParser_MidiEchoSC_NoteOff_buf_var_size = 2;
parser_var.MidiParser_MidiEchoSC_PBendChange_buf_var = array_parser_MidiParser_MidiEchoSC_PBendChange_buf_var;
parser_var.MidiParser_MidiEchoSC_PBendChange_buf_var_size = 2;
parser_var.MidiParser_MidiEchoSC_NoteOn_buf_var = array_parser_MidiParser_MidiEchoSC_NoteOn_buf_var;
parser_var.MidiParser_MidiEchoSC_NoteOn_buf_var_size = 2;
parser_var.MidiParser_MidiEchoSC_CtrlChange_buf_var = array_parser_MidiParser_MidiEchoSC_CtrlChange_buf_var;
parser_var.MidiParser_MidiEchoSC_CtrlChange_buf_var_size = 2;

MidiParser_MidiEchoSC_OnEntry(MIDIPARSER_MIDIECHOSC_STATE, &parser_var);
// Init the ID, state variables and properties for instance xtouch
xtouch_var.active = true;
xtouch_var.id_midi = add_instance( (void*) &xtouch_var);
xtouch_var.id_xtouch = add_instance( (void*) &xtouch_var);
xtouch_var.XTouchExtender_XTouchExtenderSC_State = XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE;

XTouchExtender_XTouchExtenderSC_OnEntry(XTOUCHEXTENDER_XTOUCHEXTENDERSC_STATE, &xtouch_var);
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
    
    initialize_configuration_XTouchExtenderMQTT();

    while (1) {
        
// Network Listener// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
}

        processMessageQueue();
  }
}