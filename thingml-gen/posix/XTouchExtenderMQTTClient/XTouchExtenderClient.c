/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing XTouchExtenderClient
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "XTouchExtenderClient.h"

/*****************************************************************************
 * Implementation for type : XTouchExtenderClient
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void XTouchExtenderClient_XTouchExtenderTestSC_OnExit(int state, struct XTouchExtenderClient_Instance *_instance);
//Prototypes: Message Sending
void XTouchExtenderClient_send_xtouch_button_light_on(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id);
void XTouchExtenderClient_send_xtouch_button_light_off(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id);
void XTouchExtenderClient_send_xtouch_button_light_blink(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id);
void XTouchExtenderClient_send_xtouch_set_slider(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint16_t value);
void XTouchExtenderClient_send_xtouch_set_pot(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t value);
void XTouchExtenderClient_send_xtouch_set_meter(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t value);
//Prototypes: Function
void f_XTouchExtenderClient_init_slider_values(struct XTouchExtenderClient_Instance *_instance);
void f_XTouchExtenderClient_send_slider_values(struct XTouchExtenderClient_Instance *_instance);
void f_XTouchExtenderClient_select_bank(struct XTouchExtenderClient_Instance *_instance);
// Declaration of functions:
// Definition of function init_slider_values
void f_XTouchExtenderClient_init_slider_values(struct XTouchExtenderClient_Instance *_instance) {
;uint8_t i = 0;
while(i < 32) {
_instance->XTouchExtenderClient_slider_values_var[i] = 0;
i = i + 1;

}
}
// Definition of function send_slider_values
void f_XTouchExtenderClient_send_slider_values(struct XTouchExtenderClient_Instance *_instance) {
;uint8_t i = 0;
while(i < 8) {
XTouchExtenderClient_send_xtouch_set_slider(_instance, i, _instance->XTouchExtenderClient_slider_values_var[8 * _instance->XTouchExtenderClient_current_bank_var + i]
);
i = i + 1;

}
}
// Definition of function select_bank
void f_XTouchExtenderClient_select_bank(struct XTouchExtenderClient_Instance *_instance) {
;uint8_t i = 0;
while(i < 4) {
XTouchExtenderClient_send_xtouch_button_light_off(_instance, i, 1);
i = i + 1;

}
XTouchExtenderClient_send_xtouch_button_light_on(_instance, _instance->XTouchExtenderClient_current_bank_var, 1);
}

// Sessions functionss:


// On Entry Actions:
void XTouchExtenderClient_XTouchExtenderTestSC_OnEntry(int state, struct XTouchExtenderClient_Instance *_instance) {
switch(state) {
case XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_STATE:{
_instance->XTouchExtenderClient_XTouchExtenderTestSC_State = XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_RUNNING_STATE;
f_XTouchExtenderClient_init_slider_values(_instance);
_instance->XTouchExtenderClient_current_bank_var = 0;
XTouchExtenderClient_XTouchExtenderTestSC_OnEntry(_instance->XTouchExtenderClient_XTouchExtenderTestSC_State, _instance);
break;
}
case XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_RUNNING_STATE:{
f_XTouchExtenderClient_select_bank(_instance);
f_XTouchExtenderClient_send_slider_values(_instance);
break;
}
default: break;
}
}

// On Exit Actions:
void XTouchExtenderClient_XTouchExtenderTestSC_OnExit(int state, struct XTouchExtenderClient_Instance *_instance) {
switch(state) {
case XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_STATE:{
XTouchExtenderClient_XTouchExtenderTestSC_OnExit(_instance->XTouchExtenderClient_XTouchExtenderTestSC_State, _instance);
break;}
case XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_RUNNING_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void XTouchExtenderClient_handle_xtouch_slider(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t value) {
if(!(_instance->active)) return;
//Region XTouchExtenderTestSC
uint8_t XTouchExtenderClient_XTouchExtenderTestSC_State_event_consumed = 0;
if (_instance->XTouchExtenderClient_XTouchExtenderTestSC_State == XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_RUNNING_STATE) {
if (XTouchExtenderClient_XTouchExtenderTestSC_State_event_consumed == 0 && 1) {
_instance->XTouchExtenderClient_slider_values_var[8 * _instance->XTouchExtenderClient_current_bank_var + ch] = value;
XTouchExtenderClient_XTouchExtenderTestSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderTestSC
//End dsregion XTouchExtenderTestSC
//Session list: 
}
void XTouchExtenderClient_handle_xtouch_button_press(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id) {
if(!(_instance->active)) return;
//Region XTouchExtenderTestSC
uint8_t XTouchExtenderClient_XTouchExtenderTestSC_State_event_consumed = 0;
if (_instance->XTouchExtenderClient_XTouchExtenderTestSC_State == XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_RUNNING_STATE) {
if (XTouchExtenderClient_XTouchExtenderTestSC_State_event_consumed == 0 && ch < 4 && id == 1) {
XTouchExtenderClient_XTouchExtenderTestSC_OnExit(XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_RUNNING_STATE, _instance);
_instance->XTouchExtenderClient_XTouchExtenderTestSC_State = XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_RUNNING_STATE;
_instance->XTouchExtenderClient_current_bank_var = ch;
XTouchExtenderClient_XTouchExtenderTestSC_OnEntry(XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_RUNNING_STATE, _instance);
XTouchExtenderClient_XTouchExtenderTestSC_State_event_consumed = 1;
}
}
//End Region XTouchExtenderTestSC
//End dsregion XTouchExtenderTestSC
//Session list: 
}

// Observers for outgoing messages:
void (*external_XTouchExtenderClient_send_xtouch_button_light_on_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtenderClient_send_xtouch_button_light_on_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtenderClient_send_xtouch_button_light_on_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)){
external_XTouchExtenderClient_send_xtouch_button_light_on_listener = _listener;
}
void register_XTouchExtenderClient_send_xtouch_button_light_on_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)){
XTouchExtenderClient_send_xtouch_button_light_on_listener = _listener;
}
void XTouchExtenderClient_send_xtouch_button_light_on(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id){
if (XTouchExtenderClient_send_xtouch_button_light_on_listener != 0x0) XTouchExtenderClient_send_xtouch_button_light_on_listener(_instance, ch, id);
if (external_XTouchExtenderClient_send_xtouch_button_light_on_listener != 0x0) external_XTouchExtenderClient_send_xtouch_button_light_on_listener(_instance, ch, id);
;
}
void (*external_XTouchExtenderClient_send_xtouch_button_light_off_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtenderClient_send_xtouch_button_light_off_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtenderClient_send_xtouch_button_light_off_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)){
external_XTouchExtenderClient_send_xtouch_button_light_off_listener = _listener;
}
void register_XTouchExtenderClient_send_xtouch_button_light_off_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)){
XTouchExtenderClient_send_xtouch_button_light_off_listener = _listener;
}
void XTouchExtenderClient_send_xtouch_button_light_off(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id){
if (XTouchExtenderClient_send_xtouch_button_light_off_listener != 0x0) XTouchExtenderClient_send_xtouch_button_light_off_listener(_instance, ch, id);
if (external_XTouchExtenderClient_send_xtouch_button_light_off_listener != 0x0) external_XTouchExtenderClient_send_xtouch_button_light_off_listener(_instance, ch, id);
;
}
void (*external_XTouchExtenderClient_send_xtouch_button_light_blink_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtenderClient_send_xtouch_button_light_blink_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtenderClient_send_xtouch_button_light_blink_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)){
external_XTouchExtenderClient_send_xtouch_button_light_blink_listener = _listener;
}
void register_XTouchExtenderClient_send_xtouch_button_light_blink_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)){
XTouchExtenderClient_send_xtouch_button_light_blink_listener = _listener;
}
void XTouchExtenderClient_send_xtouch_button_light_blink(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id){
if (XTouchExtenderClient_send_xtouch_button_light_blink_listener != 0x0) XTouchExtenderClient_send_xtouch_button_light_blink_listener(_instance, ch, id);
if (external_XTouchExtenderClient_send_xtouch_button_light_blink_listener != 0x0) external_XTouchExtenderClient_send_xtouch_button_light_blink_listener(_instance, ch, id);
;
}
void (*external_XTouchExtenderClient_send_xtouch_set_slider_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint16_t)= 0x0;
void (*XTouchExtenderClient_send_xtouch_set_slider_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint16_t)= 0x0;
void register_external_XTouchExtenderClient_send_xtouch_set_slider_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint16_t)){
external_XTouchExtenderClient_send_xtouch_set_slider_listener = _listener;
}
void register_XTouchExtenderClient_send_xtouch_set_slider_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint16_t)){
XTouchExtenderClient_send_xtouch_set_slider_listener = _listener;
}
void XTouchExtenderClient_send_xtouch_set_slider(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint16_t value){
if (XTouchExtenderClient_send_xtouch_set_slider_listener != 0x0) XTouchExtenderClient_send_xtouch_set_slider_listener(_instance, ch, value);
if (external_XTouchExtenderClient_send_xtouch_set_slider_listener != 0x0) external_XTouchExtenderClient_send_xtouch_set_slider_listener(_instance, ch, value);
;
}
void (*external_XTouchExtenderClient_send_xtouch_set_pot_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtenderClient_send_xtouch_set_pot_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtenderClient_send_xtouch_set_pot_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)){
external_XTouchExtenderClient_send_xtouch_set_pot_listener = _listener;
}
void register_XTouchExtenderClient_send_xtouch_set_pot_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)){
XTouchExtenderClient_send_xtouch_set_pot_listener = _listener;
}
void XTouchExtenderClient_send_xtouch_set_pot(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t value){
if (XTouchExtenderClient_send_xtouch_set_pot_listener != 0x0) XTouchExtenderClient_send_xtouch_set_pot_listener(_instance, ch, value);
if (external_XTouchExtenderClient_send_xtouch_set_pot_listener != 0x0) external_XTouchExtenderClient_send_xtouch_set_pot_listener(_instance, ch, value);
;
}
void (*external_XTouchExtenderClient_send_xtouch_set_meter_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)= 0x0;
void (*XTouchExtenderClient_send_xtouch_set_meter_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_XTouchExtenderClient_send_xtouch_set_meter_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)){
external_XTouchExtenderClient_send_xtouch_set_meter_listener = _listener;
}
void register_XTouchExtenderClient_send_xtouch_set_meter_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t)){
XTouchExtenderClient_send_xtouch_set_meter_listener = _listener;
}
void XTouchExtenderClient_send_xtouch_set_meter(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t value){
if (XTouchExtenderClient_send_xtouch_set_meter_listener != 0x0) XTouchExtenderClient_send_xtouch_set_meter_listener(_instance, ch, value);
if (external_XTouchExtenderClient_send_xtouch_set_meter_listener != 0x0) external_XTouchExtenderClient_send_xtouch_set_meter_listener(_instance, ch, value);
;
}



