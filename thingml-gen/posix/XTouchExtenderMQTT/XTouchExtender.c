/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing XTouchExtender
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "XTouchExtender.h"

/*****************************************************************************
 * Implementation for type : XTouchExtender
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void XTouchExtender_XTouchExtenderSC_OnExit(int state, struct XTouchExtender_Instance *_instance);
//Prototypes: Message Sending
void XTouchExtender_send_midi_note_on(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity);
void XTouchExtender_send_midi_note_off(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity);
void XTouchExtender_send_midi_pitch_bend_change(struct XTouchExtender_Instance *_instance, uint8_t channel, uint16_t vpbend);
void XTouchExtender_send_midi_control_change(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t ctrl, uint8_t value);
void XTouchExtender_send_clock_timer_start(struct XTouchExtender_Instance *_instance, uint8_t id, uint32_t time);
void XTouchExtender_send_clock_timer_cancel(struct XTouchExtender_Instance *_instance, uint8_t id);
void XTouchExtender_send_xtouch_slider(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value);
void XTouchExtender_send_xtouch_pot(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value);
void XTouchExtender_send_xtouch_button_press(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id);
void XTouchExtender_send_xtouch_button_release(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id);
void XTouchExtender_send_xtouch_slider_slow(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value);
void XTouchExtender_send_xtouch_pot_slow(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void XTouchExtender_XTouchExtenderSC_OnEntry(int state, struct XTouchExtender_Instance *_instance) {
switch(state) {
case XTOUCHEXTENDER_XTOUCHEXTENDERSC_STATE:{
_instance->XTouchExtender_XTouchExtenderSC_State = XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE;
;uint8_t i = 0;
while(i < 8) {
_instance->XTouchExtender_XTouchExtenderSC_last_slider_var[i] = 0xFF;
_instance->XTouchExtender_XTouchExtenderSC_last_pot_var[i] = 0xFF;
i = i + 1;

}
XTouchExtender_XTouchExtenderSC_OnEntry(_instance->XTouchExtender_XTouchExtenderSC_State, _instance);
break;
}
case XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void XTouchExtender_XTouchExtenderSC_OnExit(int state, struct XTouchExtender_Instance *_instance) {
switch(state) {
case XTOUCHEXTENDER_XTOUCHEXTENDERSC_STATE:{
XTouchExtender_XTouchExtenderSC_OnExit(_instance->XTouchExtender_XTouchExtenderSC_State, _instance);
break;}
case XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void XTouchExtender_handle_xtouch_set_pot(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value) {
if(!(_instance->active)) return;
//Region XTouchExtenderSC
uint8_t XTouchExtender_XTouchExtenderSC_State_event_consumed = 0;
if (_instance->XTouchExtender_XTouchExtenderSC_State == XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE) {
if (XTouchExtender_XTouchExtenderSC_State_event_consumed == 0 && 1) {
XTouchExtender_send_midi_control_change(_instance, 0, 80 + ch, value);
XTouchExtender_XTouchExtenderSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderSC
//End dsregion XTouchExtenderSC
//Session list: 
}
void XTouchExtender_handle_xtouch_button_light_on(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id) {
if(!(_instance->active)) return;
//Region XTouchExtenderSC
uint8_t XTouchExtender_XTouchExtenderSC_State_event_consumed = 0;
if (_instance->XTouchExtender_XTouchExtenderSC_State == XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE) {
if (XTouchExtender_XTouchExtenderSC_State_event_consumed == 0 && 1) {
if(id == 1) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 32, 127);

}
if(id == 2) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 24, 127);

}
if(id == 3) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 16, 127);

}
if(id == 4) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 8, 127);

}
XTouchExtender_XTouchExtenderSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderSC
//End dsregion XTouchExtenderSC
//Session list: 
}
void XTouchExtender_handle_xtouch_set_meter(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value) {
if(!(_instance->active)) return;
//Region XTouchExtenderSC
uint8_t XTouchExtender_XTouchExtenderSC_State_event_consumed = 0;
if (_instance->XTouchExtender_XTouchExtenderSC_State == XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE) {
if (XTouchExtender_XTouchExtenderSC_State_event_consumed == 0 && 1) {
XTouchExtender_send_midi_control_change(_instance, 0, 90 + ch, value);
XTouchExtender_XTouchExtenderSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderSC
//End dsregion XTouchExtenderSC
//Session list: 
}
void XTouchExtender_handle_xtouch_set_slider(struct XTouchExtender_Instance *_instance, uint8_t ch, uint16_t value) {
if(!(_instance->active)) return;
//Region XTouchExtenderSC
uint8_t XTouchExtender_XTouchExtenderSC_State_event_consumed = 0;
if (_instance->XTouchExtender_XTouchExtenderSC_State == XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE) {
if (XTouchExtender_XTouchExtenderSC_State_event_consumed == 0 && 1) {
XTouchExtender_send_midi_control_change(_instance, 0, 70 + ch, value);
XTouchExtender_XTouchExtenderSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderSC
//End dsregion XTouchExtenderSC
//Session list: 
}
void XTouchExtender_handle_xtouch_button_light_off(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id) {
if(!(_instance->active)) return;
//Region XTouchExtenderSC
uint8_t XTouchExtender_XTouchExtenderSC_State_event_consumed = 0;
if (_instance->XTouchExtender_XTouchExtenderSC_State == XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE) {
if (XTouchExtender_XTouchExtenderSC_State_event_consumed == 0 && 1) {
if(id == 1) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 32, 0);

}
if(id == 2) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 24, 0);

}
if(id == 3) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 16, 0);

}
if(id == 4) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 8, 0);

}
XTouchExtender_XTouchExtenderSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderSC
//End dsregion XTouchExtenderSC
//Session list: 
}
void XTouchExtender_handle_xtouch_button_light_blink(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id) {
if(!(_instance->active)) return;
//Region XTouchExtenderSC
uint8_t XTouchExtender_XTouchExtenderSC_State_event_consumed = 0;
if (_instance->XTouchExtender_XTouchExtenderSC_State == XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE) {
if (XTouchExtender_XTouchExtenderSC_State_event_consumed == 0 && 1) {
if(id == 1) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 32, 64);

}
if(id == 2) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 24, 64);

}
if(id == 3) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 16, 64);

}
if(id == 4) {
XTouchExtender_send_midi_note_on(_instance, 0, ch + 8, 64);

}
XTouchExtender_XTouchExtenderSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderSC
//End dsregion XTouchExtenderSC
//Session list: 
}
void XTouchExtender_handle_midi_note_on(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity) {
if(!(_instance->active)) return;
//Region XTouchExtenderSC
uint8_t XTouchExtender_XTouchExtenderSC_State_event_consumed = 0;
if (_instance->XTouchExtender_XTouchExtenderSC_State == XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE) {
if (XTouchExtender_XTouchExtenderSC_State_event_consumed == 0 && 1) {
fprintf(stdout, "[->] NOTE ON \t\tchannel:");
fprintf(stdout, "%i",channel);
fprintf(stdout, " \tkey:");
fprintf(stdout, "%i",key);
fprintf(stdout, " \tvelocity:");
fprintf(stdout, "%i",velocity);
fprintf(stdout, "\n");
if(key >= 110 && key < 118) {
if(velocity == 0) {
XTouchExtender_send_xtouch_button_press(_instance, key - 110, 0);

} else {
XTouchExtender_send_xtouch_button_release(_instance, key - 110, 0);

}

} else {
if(key >= 32 && key < 40) {
if(velocity == 0) {
XTouchExtender_send_xtouch_button_press(_instance, key - 32, 1);

} else {
XTouchExtender_send_xtouch_button_release(_instance, key - 32, 1);

}

} else {
if(key >= 24 && key < 32) {
if(velocity == 0) {
XTouchExtender_send_xtouch_button_press(_instance, key - 24, 2);

} else {
XTouchExtender_send_xtouch_button_release(_instance, key - 24, 2);

}

} else {
if(key >= 16 && key < 24) {
if(velocity == 0) {
XTouchExtender_send_xtouch_button_press(_instance, key - 16, 3);

} else {
XTouchExtender_send_xtouch_button_release(_instance, key - 16, 3);

}

} else {
if(key >= 8 && key < 16) {
if(velocity == 0) {
XTouchExtender_send_xtouch_button_press(_instance, key - 8, 4);

} else {
XTouchExtender_send_xtouch_button_release(_instance, key - 8, 4);

}

} else {
if(key >= 0 && key < 8) {
if(velocity == 0) {
XTouchExtender_send_xtouch_button_press(_instance, key, 5);

} else {
XTouchExtender_send_xtouch_button_release(_instance, key, 5);

}

}

}

}

}

}

}
XTouchExtender_XTouchExtenderSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderSC
//End dsregion XTouchExtenderSC
//Session list: 
}
void XTouchExtender_handle_midi_control_change(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t ctrl, uint8_t value) {
if(!(_instance->active)) return;
//Region XTouchExtenderSC
uint8_t XTouchExtender_XTouchExtenderSC_State_event_consumed = 0;
if (_instance->XTouchExtender_XTouchExtenderSC_State == XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE) {
if (XTouchExtender_XTouchExtenderSC_State_event_consumed == 0 && 1) {
fprintf(stdout, "[->] CONTROL CHG \tchannel:");
fprintf(stdout, "%i",channel);
fprintf(stdout, " \tcontrol:");
fprintf(stdout, "%i",ctrl);
fprintf(stdout, " \tvelocity:");
fprintf(stdout, "%i",value);
fprintf(stdout, "\n");
if(ctrl >= 70 && ctrl < 78) {
;uint8_t idx = ctrl - 70;
if(_instance->XTouchExtender_XTouchExtenderSC_last_slider_var[idx]
 == 0xFF) {
XTouchExtender_send_clock_timer_start(_instance, idx, 333);

}
_instance->XTouchExtender_XTouchExtenderSC_last_slider_var[idx] = value;
XTouchExtender_send_xtouch_slider(_instance, idx, value);

} else {
if(ctrl >= 80 && ctrl < 88) {
;uint8_t idx = ctrl - 80;
if(_instance->XTouchExtender_XTouchExtenderSC_last_pot_var[idx]
 == 0xFF) {
XTouchExtender_send_clock_timer_start(_instance, idx + 8, 333);

}
_instance->XTouchExtender_XTouchExtenderSC_last_pot_var[idx] = value;
XTouchExtender_send_xtouch_pot(_instance, idx, value);

}

}
XTouchExtender_XTouchExtenderSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderSC
//End dsregion XTouchExtenderSC
//Session list: 
}
void XTouchExtender_handle_clock_timer_timeout(struct XTouchExtender_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region XTouchExtenderSC
uint8_t XTouchExtender_XTouchExtenderSC_State_event_consumed = 0;
if (_instance->XTouchExtender_XTouchExtenderSC_State == XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE) {
if (XTouchExtender_XTouchExtenderSC_State_event_consumed == 0 && 1) {
if(id < 8) {
XTouchExtender_send_xtouch_slider_slow(_instance, id, _instance->XTouchExtender_XTouchExtenderSC_last_slider_var[id]
);
_instance->XTouchExtender_XTouchExtenderSC_last_slider_var[id] = 0xFF;

} else {
if(id < 16) {
XTouchExtender_send_xtouch_pot_slow(_instance, id - 8, _instance->XTouchExtender_XTouchExtenderSC_last_pot_var[id - 8]
);
_instance->XTouchExtender_XTouchExtenderSC_last_pot_var[id - 8] = 0xFF;

}

}
XTouchExtender_XTouchExtenderSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderSC
//End dsregion XTouchExtenderSC
//Session list: 
}

// Observers for outgoing messages:
void (*external_XTouchExtender_send_midi_note_on_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*XTouchExtender_send_midi_note_on_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtender_send_midi_note_on_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)){
external_XTouchExtender_send_midi_note_on_listener = _listener;
}
void register_XTouchExtender_send_midi_note_on_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)){
XTouchExtender_send_midi_note_on_listener = _listener;
}
void XTouchExtender_send_midi_note_on(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity){
if (XTouchExtender_send_midi_note_on_listener != 0x0) XTouchExtender_send_midi_note_on_listener(_instance, channel, key, velocity);
if (external_XTouchExtender_send_midi_note_on_listener != 0x0) external_XTouchExtender_send_midi_note_on_listener(_instance, channel, key, velocity);
;
}
void (*external_XTouchExtender_send_midi_note_off_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*XTouchExtender_send_midi_note_off_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtender_send_midi_note_off_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)){
external_XTouchExtender_send_midi_note_off_listener = _listener;
}
void register_XTouchExtender_send_midi_note_off_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)){
XTouchExtender_send_midi_note_off_listener = _listener;
}
void XTouchExtender_send_midi_note_off(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity){
if (XTouchExtender_send_midi_note_off_listener != 0x0) XTouchExtender_send_midi_note_off_listener(_instance, channel, key, velocity);
if (external_XTouchExtender_send_midi_note_off_listener != 0x0) external_XTouchExtender_send_midi_note_off_listener(_instance, channel, key, velocity);
;
}
void (*external_XTouchExtender_send_midi_pitch_bend_change_listener)(struct XTouchExtender_Instance *, uint8_t, uint16_t)= 0x0;
void (*XTouchExtender_send_midi_pitch_bend_change_listener)(struct XTouchExtender_Instance *, uint8_t, uint16_t)= 0x0;
void register_external_XTouchExtender_send_midi_pitch_bend_change_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint16_t)){
external_XTouchExtender_send_midi_pitch_bend_change_listener = _listener;
}
void register_XTouchExtender_send_midi_pitch_bend_change_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint16_t)){
XTouchExtender_send_midi_pitch_bend_change_listener = _listener;
}
void XTouchExtender_send_midi_pitch_bend_change(struct XTouchExtender_Instance *_instance, uint8_t channel, uint16_t vpbend){
if (XTouchExtender_send_midi_pitch_bend_change_listener != 0x0) XTouchExtender_send_midi_pitch_bend_change_listener(_instance, channel, vpbend);
if (external_XTouchExtender_send_midi_pitch_bend_change_listener != 0x0) external_XTouchExtender_send_midi_pitch_bend_change_listener(_instance, channel, vpbend);
;
}
void (*external_XTouchExtender_send_midi_control_change_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*XTouchExtender_send_midi_control_change_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtender_send_midi_control_change_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)){
external_XTouchExtender_send_midi_control_change_listener = _listener;
}
void register_XTouchExtender_send_midi_control_change_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t)){
XTouchExtender_send_midi_control_change_listener = _listener;
}
void XTouchExtender_send_midi_control_change(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t ctrl, uint8_t value){
if (XTouchExtender_send_midi_control_change_listener != 0x0) XTouchExtender_send_midi_control_change_listener(_instance, channel, ctrl, value);
if (external_XTouchExtender_send_midi_control_change_listener != 0x0) external_XTouchExtender_send_midi_control_change_listener(_instance, channel, ctrl, value);
;
}
void (*external_XTouchExtender_send_clock_timer_start_listener)(struct XTouchExtender_Instance *, uint8_t, uint32_t)= 0x0;
void (*XTouchExtender_send_clock_timer_start_listener)(struct XTouchExtender_Instance *, uint8_t, uint32_t)= 0x0;
void register_external_XTouchExtender_send_clock_timer_start_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint32_t)){
external_XTouchExtender_send_clock_timer_start_listener = _listener;
}
void register_XTouchExtender_send_clock_timer_start_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint32_t)){
XTouchExtender_send_clock_timer_start_listener = _listener;
}
void XTouchExtender_send_clock_timer_start(struct XTouchExtender_Instance *_instance, uint8_t id, uint32_t time){
if (XTouchExtender_send_clock_timer_start_listener != 0x0) XTouchExtender_send_clock_timer_start_listener(_instance, id, time);
if (external_XTouchExtender_send_clock_timer_start_listener != 0x0) external_XTouchExtender_send_clock_timer_start_listener(_instance, id, time);
;
}
void (*external_XTouchExtender_send_clock_timer_cancel_listener)(struct XTouchExtender_Instance *, uint8_t)= 0x0;
void (*XTouchExtender_send_clock_timer_cancel_listener)(struct XTouchExtender_Instance *, uint8_t)= 0x0;
void register_external_XTouchExtender_send_clock_timer_cancel_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t)){
external_XTouchExtender_send_clock_timer_cancel_listener = _listener;
}
void register_XTouchExtender_send_clock_timer_cancel_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t)){
XTouchExtender_send_clock_timer_cancel_listener = _listener;
}
void XTouchExtender_send_clock_timer_cancel(struct XTouchExtender_Instance *_instance, uint8_t id){
if (XTouchExtender_send_clock_timer_cancel_listener != 0x0) XTouchExtender_send_clock_timer_cancel_listener(_instance, id);
if (external_XTouchExtender_send_clock_timer_cancel_listener != 0x0) external_XTouchExtender_send_clock_timer_cancel_listener(_instance, id);
;
}
void (*external_XTouchExtender_send_xtouch_slider_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtender_send_xtouch_slider_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtender_send_xtouch_slider_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
external_XTouchExtender_send_xtouch_slider_listener = _listener;
}
void register_XTouchExtender_send_xtouch_slider_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
XTouchExtender_send_xtouch_slider_listener = _listener;
}
void XTouchExtender_send_xtouch_slider(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value){
if (XTouchExtender_send_xtouch_slider_listener != 0x0) XTouchExtender_send_xtouch_slider_listener(_instance, ch, value);
if (external_XTouchExtender_send_xtouch_slider_listener != 0x0) external_XTouchExtender_send_xtouch_slider_listener(_instance, ch, value);
;
}
void (*external_XTouchExtender_send_xtouch_pot_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtender_send_xtouch_pot_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtender_send_xtouch_pot_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
external_XTouchExtender_send_xtouch_pot_listener = _listener;
}
void register_XTouchExtender_send_xtouch_pot_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
XTouchExtender_send_xtouch_pot_listener = _listener;
}
void XTouchExtender_send_xtouch_pot(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value){
if (XTouchExtender_send_xtouch_pot_listener != 0x0) XTouchExtender_send_xtouch_pot_listener(_instance, ch, value);
if (external_XTouchExtender_send_xtouch_pot_listener != 0x0) external_XTouchExtender_send_xtouch_pot_listener(_instance, ch, value);
;
}
void (*external_XTouchExtender_send_xtouch_button_press_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtender_send_xtouch_button_press_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtender_send_xtouch_button_press_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
external_XTouchExtender_send_xtouch_button_press_listener = _listener;
}
void register_XTouchExtender_send_xtouch_button_press_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
XTouchExtender_send_xtouch_button_press_listener = _listener;
}
void XTouchExtender_send_xtouch_button_press(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id){
if (XTouchExtender_send_xtouch_button_press_listener != 0x0) XTouchExtender_send_xtouch_button_press_listener(_instance, ch, id);
if (external_XTouchExtender_send_xtouch_button_press_listener != 0x0) external_XTouchExtender_send_xtouch_button_press_listener(_instance, ch, id);
;
}
void (*external_XTouchExtender_send_xtouch_button_release_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtender_send_xtouch_button_release_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtender_send_xtouch_button_release_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
external_XTouchExtender_send_xtouch_button_release_listener = _listener;
}
void register_XTouchExtender_send_xtouch_button_release_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
XTouchExtender_send_xtouch_button_release_listener = _listener;
}
void XTouchExtender_send_xtouch_button_release(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id){
if (XTouchExtender_send_xtouch_button_release_listener != 0x0) XTouchExtender_send_xtouch_button_release_listener(_instance, ch, id);
if (external_XTouchExtender_send_xtouch_button_release_listener != 0x0) external_XTouchExtender_send_xtouch_button_release_listener(_instance, ch, id);
;
}
void (*external_XTouchExtender_send_xtouch_slider_slow_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtender_send_xtouch_slider_slow_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtender_send_xtouch_slider_slow_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
external_XTouchExtender_send_xtouch_slider_slow_listener = _listener;
}
void register_XTouchExtender_send_xtouch_slider_slow_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
XTouchExtender_send_xtouch_slider_slow_listener = _listener;
}
void XTouchExtender_send_xtouch_slider_slow(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value){
if (XTouchExtender_send_xtouch_slider_slow_listener != 0x0) XTouchExtender_send_xtouch_slider_slow_listener(_instance, ch, value);
if (external_XTouchExtender_send_xtouch_slider_slow_listener != 0x0) external_XTouchExtender_send_xtouch_slider_slow_listener(_instance, ch, value);
;
}
void (*external_XTouchExtender_send_xtouch_pot_slow_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtender_send_xtouch_pot_slow_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtender_send_xtouch_pot_slow_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
external_XTouchExtender_send_xtouch_pot_slow_listener = _listener;
}
void register_XTouchExtender_send_xtouch_pot_slow_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t)){
XTouchExtender_send_xtouch_pot_slow_listener = _listener;
}
void XTouchExtender_send_xtouch_pot_slow(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value){
if (XTouchExtender_send_xtouch_pot_slow_listener != 0x0) XTouchExtender_send_xtouch_pot_slow_listener(_instance, ch, value);
if (external_XTouchExtender_send_xtouch_pot_slow_listener != 0x0) external_XTouchExtender_send_xtouch_pot_slow_listener(_instance, ch, value);
;
}



