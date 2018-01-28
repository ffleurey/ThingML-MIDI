/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing MidiParser
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "MidiParser.h"

/*****************************************************************************
 * Implementation for type : MidiParser
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void MidiParser_MidiEchoSC_OnExit(int state, struct MidiParser_Instance *_instance);
//Prototypes: Message Sending
void MidiParser_send_rawmidi_midi_open(struct MidiParser_Instance *_instance, uint8_t card, uint8_t dev, uint8_t sub);
void MidiParser_send_rawmidi_midi_close(struct MidiParser_Instance *_instance);
void MidiParser_send_rawmidi_midi_out(struct MidiParser_Instance *_instance, uint8_t b);
void MidiParser_send_midi_note_on(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity);
void MidiParser_send_midi_note_off(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity);
void MidiParser_send_midi_pitch_bend_change(struct MidiParser_Instance *_instance, uint8_t channel, uint16_t vpbend);
void MidiParser_send_midi_control_change(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t ctrl, uint8_t value);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void MidiParser_MidiEchoSC_OnEntry(int state, struct MidiParser_Instance *_instance) {
switch(state) {
case MIDIPARSER_MIDIECHOSC_STATE:{
_instance->MidiParser_MidiEchoSC_State = MIDIPARSER_MIDIECHOSC_WAITING_STATE;
MidiParser_send_rawmidi_midi_open(_instance, 2, 0, 0);
MidiParser_MidiEchoSC_OnEntry(_instance->MidiParser_MidiEchoSC_State, _instance);
break;
}
case MIDIPARSER_MIDIECHOSC_WAITING_STATE:{
break;
}
case MIDIPARSER_MIDIECHOSC_NOTEON_STATE:{
_instance->MidiParser_MidiEchoSC_NoteOn_idx_var = 0;
break;
}
case MIDIPARSER_MIDIECHOSC_NOTEOFF_STATE:{
_instance->MidiParser_MidiEchoSC_NoteOff_idx_var = 0;
break;
}
case MIDIPARSER_MIDIECHOSC_CTRLCHANGE_STATE:{
_instance->MidiParser_MidiEchoSC_CtrlChange_idx_var = 0;
break;
}
case MIDIPARSER_MIDIECHOSC_PBENDCHANGE_STATE:{
_instance->MidiParser_MidiEchoSC_PBendChange_idx_var = 0;
break;
}
default: break;
}
}

// On Exit Actions:
void MidiParser_MidiEchoSC_OnExit(int state, struct MidiParser_Instance *_instance) {
switch(state) {
case MIDIPARSER_MIDIECHOSC_STATE:{
MidiParser_MidiEchoSC_OnExit(_instance->MidiParser_MidiEchoSC_State, _instance);
break;}
case MIDIPARSER_MIDIECHOSC_WAITING_STATE:{
break;}
case MIDIPARSER_MIDIECHOSC_NOTEON_STATE:{
break;}
case MIDIPARSER_MIDIECHOSC_NOTEOFF_STATE:{
break;}
case MIDIPARSER_MIDIECHOSC_CTRLCHANGE_STATE:{
break;}
case MIDIPARSER_MIDIECHOSC_PBENDCHANGE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void MidiParser_handle_midi_pitch_bend_change(struct MidiParser_Instance *_instance, uint8_t channel, uint16_t vpbend) {
if(!(_instance->active)) return;
//Region MidiEchoSC
uint8_t MidiParser_MidiEchoSC_State_event_consumed = 0;
//End Region MidiEchoSC
//End dsregion MidiEchoSC
//Session list: 
if (1) {
MidiParser_send_rawmidi_midi_out(_instance, 0xE0 + channel);
;uint8_t b1 = vpbend & 0x007F;
;uint8_t b2 = vpbend >> 7;
MidiParser_send_rawmidi_midi_out(_instance, b1);
MidiParser_send_rawmidi_midi_out(_instance, b2);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
}
void MidiParser_handle_midi_note_off(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity) {
if(!(_instance->active)) return;
//Region MidiEchoSC
uint8_t MidiParser_MidiEchoSC_State_event_consumed = 0;
//End Region MidiEchoSC
//End dsregion MidiEchoSC
//Session list: 
if (1) {
MidiParser_send_rawmidi_midi_out(_instance, 0x80 + channel);
MidiParser_send_rawmidi_midi_out(_instance, key);
MidiParser_send_rawmidi_midi_out(_instance, velocity);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
}
void MidiParser_handle_midi_control_change(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t ctrl, uint8_t value) {
if(!(_instance->active)) return;
//Region MidiEchoSC
uint8_t MidiParser_MidiEchoSC_State_event_consumed = 0;
//End Region MidiEchoSC
//End dsregion MidiEchoSC
//Session list: 
if (1) {
MidiParser_send_rawmidi_midi_out(_instance, 0xB0 + channel);
MidiParser_send_rawmidi_midi_out(_instance, ctrl);
MidiParser_send_rawmidi_midi_out(_instance, value);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
}
void MidiParser_handle_midi_note_on(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity) {
if(!(_instance->active)) return;
//Region MidiEchoSC
uint8_t MidiParser_MidiEchoSC_State_event_consumed = 0;
//End Region MidiEchoSC
//End dsregion MidiEchoSC
//Session list: 
if (1) {
MidiParser_send_rawmidi_midi_out(_instance, 0x90 + channel);
MidiParser_send_rawmidi_midi_out(_instance, key);
MidiParser_send_rawmidi_midi_out(_instance, velocity);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
}
void MidiParser_handle_rawmidi_midi_in(struct MidiParser_Instance *_instance, uint8_t b) {
if(!(_instance->active)) return;
//Region MidiEchoSC
uint8_t MidiParser_MidiEchoSC_State_event_consumed = 0;
if (_instance->MidiParser_MidiEchoSC_State == MIDIPARSER_MIDIECHOSC_WAITING_STATE) {
if (MidiParser_MidiEchoSC_State_event_consumed == 0 && (0xF0 & b) == 0x90) {
MidiParser_MidiEchoSC_OnExit(MIDIPARSER_MIDIECHOSC_WAITING_STATE, _instance);
_instance->MidiParser_MidiEchoSC_State = MIDIPARSER_MIDIECHOSC_NOTEON_STATE;
_instance->MidiParser_MidiEchoSC_channel_var = (0x0F & b);
MidiParser_MidiEchoSC_OnEntry(MIDIPARSER_MIDIECHOSC_NOTEON_STATE, _instance);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
else if (MidiParser_MidiEchoSC_State_event_consumed == 0 && (0xF0 & b) == 0x80) {
MidiParser_MidiEchoSC_OnExit(MIDIPARSER_MIDIECHOSC_WAITING_STATE, _instance);
_instance->MidiParser_MidiEchoSC_State = MIDIPARSER_MIDIECHOSC_NOTEOFF_STATE;
_instance->MidiParser_MidiEchoSC_channel_var = (0x0F & b);
MidiParser_MidiEchoSC_OnEntry(MIDIPARSER_MIDIECHOSC_NOTEOFF_STATE, _instance);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
else if (MidiParser_MidiEchoSC_State_event_consumed == 0 && (0xF0 & b) == 0xE0) {
MidiParser_MidiEchoSC_OnExit(MIDIPARSER_MIDIECHOSC_WAITING_STATE, _instance);
_instance->MidiParser_MidiEchoSC_State = MIDIPARSER_MIDIECHOSC_PBENDCHANGE_STATE;
_instance->MidiParser_MidiEchoSC_channel_var = (0x0F & b);
MidiParser_MidiEchoSC_OnEntry(MIDIPARSER_MIDIECHOSC_PBENDCHANGE_STATE, _instance);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
else if (MidiParser_MidiEchoSC_State_event_consumed == 0 && (0xF0 & b) == 0xB0) {
MidiParser_MidiEchoSC_OnExit(MIDIPARSER_MIDIECHOSC_WAITING_STATE, _instance);
_instance->MidiParser_MidiEchoSC_State = MIDIPARSER_MIDIECHOSC_CTRLCHANGE_STATE;
_instance->MidiParser_MidiEchoSC_channel_var = (0x0F & b);
MidiParser_MidiEchoSC_OnEntry(MIDIPARSER_MIDIECHOSC_CTRLCHANGE_STATE, _instance);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
}
else if (_instance->MidiParser_MidiEchoSC_State == MIDIPARSER_MIDIECHOSC_NOTEON_STATE) {
if (MidiParser_MidiEchoSC_State_event_consumed == 0 && _instance->MidiParser_MidiEchoSC_NoteOn_idx_var == _instance->MidiParser_MidiEchoSC_NoteOn_buf_size_var - 1) {
MidiParser_MidiEchoSC_OnExit(MIDIPARSER_MIDIECHOSC_NOTEON_STATE, _instance);
_instance->MidiParser_MidiEchoSC_State = MIDIPARSER_MIDIECHOSC_WAITING_STATE;
_instance->MidiParser_MidiEchoSC_NoteOn_buf_var[_instance->MidiParser_MidiEchoSC_NoteOn_idx_var] = b;
MidiParser_send_midi_note_on(_instance, _instance->MidiParser_MidiEchoSC_channel_var, _instance->MidiParser_MidiEchoSC_NoteOn_buf_var[0]
, _instance->MidiParser_MidiEchoSC_NoteOn_buf_var[1]
);
MidiParser_MidiEchoSC_OnEntry(MIDIPARSER_MIDIECHOSC_WAITING_STATE, _instance);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
else if (MidiParser_MidiEchoSC_State_event_consumed == 0 && _instance->MidiParser_MidiEchoSC_NoteOn_idx_var < _instance->MidiParser_MidiEchoSC_NoteOn_buf_size_var - 1) {
_instance->MidiParser_MidiEchoSC_NoteOn_buf_var[_instance->MidiParser_MidiEchoSC_NoteOn_idx_var] = b;
_instance->MidiParser_MidiEchoSC_NoteOn_idx_var = _instance->MidiParser_MidiEchoSC_NoteOn_idx_var + 1;
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
}
else if (_instance->MidiParser_MidiEchoSC_State == MIDIPARSER_MIDIECHOSC_NOTEOFF_STATE) {
if (MidiParser_MidiEchoSC_State_event_consumed == 0 && _instance->MidiParser_MidiEchoSC_NoteOff_idx_var == _instance->MidiParser_MidiEchoSC_NoteOff_buf_size_var - 1) {
MidiParser_MidiEchoSC_OnExit(MIDIPARSER_MIDIECHOSC_NOTEOFF_STATE, _instance);
_instance->MidiParser_MidiEchoSC_State = MIDIPARSER_MIDIECHOSC_WAITING_STATE;
_instance->MidiParser_MidiEchoSC_NoteOff_buf_var[_instance->MidiParser_MidiEchoSC_NoteOff_idx_var] = b;
MidiParser_send_midi_note_off(_instance, _instance->MidiParser_MidiEchoSC_channel_var, _instance->MidiParser_MidiEchoSC_NoteOff_buf_var[0]
, _instance->MidiParser_MidiEchoSC_NoteOff_buf_var[1]
);
MidiParser_MidiEchoSC_OnEntry(MIDIPARSER_MIDIECHOSC_WAITING_STATE, _instance);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
else if (MidiParser_MidiEchoSC_State_event_consumed == 0 && _instance->MidiParser_MidiEchoSC_NoteOff_idx_var < _instance->MidiParser_MidiEchoSC_NoteOff_buf_size_var - 1) {
_instance->MidiParser_MidiEchoSC_NoteOff_buf_var[_instance->MidiParser_MidiEchoSC_NoteOff_idx_var] = b;
_instance->MidiParser_MidiEchoSC_NoteOff_idx_var = _instance->MidiParser_MidiEchoSC_NoteOff_idx_var + 1;
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
}
else if (_instance->MidiParser_MidiEchoSC_State == MIDIPARSER_MIDIECHOSC_CTRLCHANGE_STATE) {
if (MidiParser_MidiEchoSC_State_event_consumed == 0 && _instance->MidiParser_MidiEchoSC_CtrlChange_idx_var == _instance->MidiParser_MidiEchoSC_CtrlChange_buf_size_var - 1) {
MidiParser_MidiEchoSC_OnExit(MIDIPARSER_MIDIECHOSC_CTRLCHANGE_STATE, _instance);
_instance->MidiParser_MidiEchoSC_State = MIDIPARSER_MIDIECHOSC_WAITING_STATE;
_instance->MidiParser_MidiEchoSC_CtrlChange_buf_var[_instance->MidiParser_MidiEchoSC_CtrlChange_idx_var] = b;
MidiParser_send_midi_control_change(_instance, _instance->MidiParser_MidiEchoSC_channel_var, _instance->MidiParser_MidiEchoSC_CtrlChange_buf_var[0]
, _instance->MidiParser_MidiEchoSC_CtrlChange_buf_var[1]
);
MidiParser_MidiEchoSC_OnEntry(MIDIPARSER_MIDIECHOSC_WAITING_STATE, _instance);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
else if (MidiParser_MidiEchoSC_State_event_consumed == 0 && _instance->MidiParser_MidiEchoSC_CtrlChange_idx_var < _instance->MidiParser_MidiEchoSC_CtrlChange_buf_size_var - 1) {
_instance->MidiParser_MidiEchoSC_CtrlChange_buf_var[_instance->MidiParser_MidiEchoSC_CtrlChange_idx_var] = b;
_instance->MidiParser_MidiEchoSC_CtrlChange_idx_var = _instance->MidiParser_MidiEchoSC_CtrlChange_idx_var + 1;
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
}
else if (_instance->MidiParser_MidiEchoSC_State == MIDIPARSER_MIDIECHOSC_PBENDCHANGE_STATE) {
if (MidiParser_MidiEchoSC_State_event_consumed == 0 && _instance->MidiParser_MidiEchoSC_PBendChange_idx_var == _instance->MidiParser_MidiEchoSC_PBendChange_buf_size_var - 1) {
MidiParser_MidiEchoSC_OnExit(MIDIPARSER_MIDIECHOSC_PBENDCHANGE_STATE, _instance);
_instance->MidiParser_MidiEchoSC_State = MIDIPARSER_MIDIECHOSC_WAITING_STATE;
_instance->MidiParser_MidiEchoSC_PBendChange_buf_var[_instance->MidiParser_MidiEchoSC_PBendChange_idx_var] = b;
;uint16_t v = _instance->MidiParser_MidiEchoSC_PBendChange_buf_var[1]
;
v = v<<7;
v = v + _instance->MidiParser_MidiEchoSC_PBendChange_buf_var[0]
;
MidiParser_send_midi_pitch_bend_change(_instance, _instance->MidiParser_MidiEchoSC_channel_var, v);
MidiParser_MidiEchoSC_OnEntry(MIDIPARSER_MIDIECHOSC_WAITING_STATE, _instance);
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
else if (MidiParser_MidiEchoSC_State_event_consumed == 0 && _instance->MidiParser_MidiEchoSC_PBendChange_idx_var < _instance->MidiParser_MidiEchoSC_PBendChange_buf_size_var - 1) {
_instance->MidiParser_MidiEchoSC_PBendChange_buf_var[_instance->MidiParser_MidiEchoSC_PBendChange_idx_var] = b;
_instance->MidiParser_MidiEchoSC_PBendChange_idx_var = _instance->MidiParser_MidiEchoSC_PBendChange_idx_var + 1;
MidiParser_MidiEchoSC_State_event_consumed = 1;
}
}
//End Region MidiEchoSC
//End dsregion MidiEchoSC
//Session list: 
}

// Observers for outgoing messages:
void (*external_MidiParser_send_rawmidi_midi_open_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*MidiParser_send_rawmidi_midi_open_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_MidiParser_send_rawmidi_midi_open_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)){
external_MidiParser_send_rawmidi_midi_open_listener = _listener;
}
void register_MidiParser_send_rawmidi_midi_open_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)){
MidiParser_send_rawmidi_midi_open_listener = _listener;
}
void MidiParser_send_rawmidi_midi_open(struct MidiParser_Instance *_instance, uint8_t card, uint8_t dev, uint8_t sub){
if (MidiParser_send_rawmidi_midi_open_listener != 0x0) MidiParser_send_rawmidi_midi_open_listener(_instance, card, dev, sub);
if (external_MidiParser_send_rawmidi_midi_open_listener != 0x0) external_MidiParser_send_rawmidi_midi_open_listener(_instance, card, dev, sub);
;
}
void (*external_MidiParser_send_rawmidi_midi_close_listener)(struct MidiParser_Instance *)= 0x0;
void (*MidiParser_send_rawmidi_midi_close_listener)(struct MidiParser_Instance *)= 0x0;
void register_external_MidiParser_send_rawmidi_midi_close_listener(void (*_listener)(struct MidiParser_Instance *)){
external_MidiParser_send_rawmidi_midi_close_listener = _listener;
}
void register_MidiParser_send_rawmidi_midi_close_listener(void (*_listener)(struct MidiParser_Instance *)){
MidiParser_send_rawmidi_midi_close_listener = _listener;
}
void MidiParser_send_rawmidi_midi_close(struct MidiParser_Instance *_instance){
if (MidiParser_send_rawmidi_midi_close_listener != 0x0) MidiParser_send_rawmidi_midi_close_listener(_instance);
if (external_MidiParser_send_rawmidi_midi_close_listener != 0x0) external_MidiParser_send_rawmidi_midi_close_listener(_instance);
;
}
void (*external_MidiParser_send_rawmidi_midi_out_listener)(struct MidiParser_Instance *, uint8_t)= 0x0;
void (*MidiParser_send_rawmidi_midi_out_listener)(struct MidiParser_Instance *, uint8_t)= 0x0;
void register_external_MidiParser_send_rawmidi_midi_out_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t)){
external_MidiParser_send_rawmidi_midi_out_listener = _listener;
}
void register_MidiParser_send_rawmidi_midi_out_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t)){
MidiParser_send_rawmidi_midi_out_listener = _listener;
}
void MidiParser_send_rawmidi_midi_out(struct MidiParser_Instance *_instance, uint8_t b){
if (MidiParser_send_rawmidi_midi_out_listener != 0x0) MidiParser_send_rawmidi_midi_out_listener(_instance, b);
if (external_MidiParser_send_rawmidi_midi_out_listener != 0x0) external_MidiParser_send_rawmidi_midi_out_listener(_instance, b);
;
}
void (*external_MidiParser_send_midi_note_on_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*MidiParser_send_midi_note_on_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_MidiParser_send_midi_note_on_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)){
external_MidiParser_send_midi_note_on_listener = _listener;
}
void register_MidiParser_send_midi_note_on_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)){
MidiParser_send_midi_note_on_listener = _listener;
}
void MidiParser_send_midi_note_on(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity){
if (MidiParser_send_midi_note_on_listener != 0x0) MidiParser_send_midi_note_on_listener(_instance, channel, key, velocity);
if (external_MidiParser_send_midi_note_on_listener != 0x0) external_MidiParser_send_midi_note_on_listener(_instance, channel, key, velocity);
;
}
void (*external_MidiParser_send_midi_note_off_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*MidiParser_send_midi_note_off_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_MidiParser_send_midi_note_off_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)){
external_MidiParser_send_midi_note_off_listener = _listener;
}
void register_MidiParser_send_midi_note_off_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)){
MidiParser_send_midi_note_off_listener = _listener;
}
void MidiParser_send_midi_note_off(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity){
if (MidiParser_send_midi_note_off_listener != 0x0) MidiParser_send_midi_note_off_listener(_instance, channel, key, velocity);
if (external_MidiParser_send_midi_note_off_listener != 0x0) external_MidiParser_send_midi_note_off_listener(_instance, channel, key, velocity);
;
}
void (*external_MidiParser_send_midi_pitch_bend_change_listener)(struct MidiParser_Instance *, uint8_t, uint16_t)= 0x0;
void (*MidiParser_send_midi_pitch_bend_change_listener)(struct MidiParser_Instance *, uint8_t, uint16_t)= 0x0;
void register_external_MidiParser_send_midi_pitch_bend_change_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint16_t)){
external_MidiParser_send_midi_pitch_bend_change_listener = _listener;
}
void register_MidiParser_send_midi_pitch_bend_change_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint16_t)){
MidiParser_send_midi_pitch_bend_change_listener = _listener;
}
void MidiParser_send_midi_pitch_bend_change(struct MidiParser_Instance *_instance, uint8_t channel, uint16_t vpbend){
if (MidiParser_send_midi_pitch_bend_change_listener != 0x0) MidiParser_send_midi_pitch_bend_change_listener(_instance, channel, vpbend);
if (external_MidiParser_send_midi_pitch_bend_change_listener != 0x0) external_MidiParser_send_midi_pitch_bend_change_listener(_instance, channel, vpbend);
;
}
void (*external_MidiParser_send_midi_control_change_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*MidiParser_send_midi_control_change_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_MidiParser_send_midi_control_change_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)){
external_MidiParser_send_midi_control_change_listener = _listener;
}
void register_MidiParser_send_midi_control_change_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t)){
MidiParser_send_midi_control_change_listener = _listener;
}
void MidiParser_send_midi_control_change(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t ctrl, uint8_t value){
if (MidiParser_send_midi_control_change_listener != 0x0) MidiParser_send_midi_control_change_listener(_instance, channel, ctrl, value);
if (external_MidiParser_send_midi_control_change_listener != 0x0) external_MidiParser_send_midi_control_change_listener(_instance, channel, ctrl, value);
;
}



