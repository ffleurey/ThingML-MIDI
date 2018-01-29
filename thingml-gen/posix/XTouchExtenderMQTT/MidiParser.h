/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing MidiParser
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef MidiParser_H_
#define MidiParser_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : MidiParser
 *****************************************************************************/

// Definition of the instance struct:
struct MidiParser_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_rawmidi;
uint16_t id_midi;
// Variables for the current instance state
int MidiParser_MidiEchoSC_State;
// Variables for the properties of the instance
uint8_t MidiParser_MidiEchoSC_NoteOff_buf_size_var;
int8_t MidiParser_MidiEchoSC_NoteOff_idx_var;
uint8_t * MidiParser_MidiEchoSC_NoteOn_buf_var;
uint16_t MidiParser_MidiEchoSC_NoteOn_buf_var_size;
int8_t MidiParser_MidiEchoSC_CtrlChange_idx_var;
uint8_t MidiParser_MidiEchoSC_CtrlChange_buf_size_var;
uint8_t MidiParser_MidiEchoSC_NoteOn_buf_size_var;
uint8_t MidiParser_MidiEchoSC_channel_var;
uint8_t * MidiParser_MidiEchoSC_NoteOff_buf_var;
uint16_t MidiParser_MidiEchoSC_NoteOff_buf_var_size;
uint8_t * MidiParser_MidiEchoSC_CtrlChange_buf_var;
uint16_t MidiParser_MidiEchoSC_CtrlChange_buf_var_size;
uint8_t MidiParser_MidiEchoSC_PBendChange_buf_size_var;
uint8_t * MidiParser_MidiEchoSC_PBendChange_buf_var;
uint16_t MidiParser_MidiEchoSC_PBendChange_buf_var_size;
int8_t MidiParser_MidiEchoSC_NoteOn_idx_var;
int8_t MidiParser_MidiEchoSC_PBendChange_idx_var;

};
// Declaration of prototypes outgoing messages :
void MidiParser_MidiEchoSC_OnEntry(int state, struct MidiParser_Instance *_instance);
void MidiParser_handle_midi_note_on(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity);
void MidiParser_handle_midi_pitch_bend_change(struct MidiParser_Instance *_instance, uint8_t channel, uint16_t vpbend);
void MidiParser_handle_midi_control_change(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t ctrl, uint8_t value);
void MidiParser_handle_midi_note_off(struct MidiParser_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity);
void MidiParser_handle_rawmidi_midi_in(struct MidiParser_Instance *_instance, uint8_t b);
// Declaration of callbacks for incoming messages:
void register_MidiParser_send_rawmidi_midi_open_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_MidiParser_send_rawmidi_midi_open_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t));
void register_MidiParser_send_rawmidi_midi_close_listener(void (*_listener)(struct MidiParser_Instance *));
void register_external_MidiParser_send_rawmidi_midi_close_listener(void (*_listener)(struct MidiParser_Instance *));
void register_MidiParser_send_rawmidi_midi_out_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t));
void register_external_MidiParser_send_rawmidi_midi_out_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t));
void register_MidiParser_send_midi_note_on_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_MidiParser_send_midi_note_on_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t));
void register_MidiParser_send_midi_note_off_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_MidiParser_send_midi_note_off_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t));
void register_MidiParser_send_midi_pitch_bend_change_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint16_t));
void register_external_MidiParser_send_midi_pitch_bend_change_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint16_t));
void register_MidiParser_send_midi_control_change_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_MidiParser_send_midi_control_change_listener(void (*_listener)(struct MidiParser_Instance *, uint8_t, uint8_t, uint8_t));

// Definition of the states:
#define MIDIPARSER_MIDIECHOSC_CTRLCHANGE_STATE 0
#define MIDIPARSER_MIDIECHOSC_STATE 1
#define MIDIPARSER_MIDIECHOSC_NOTEON_STATE 2
#define MIDIPARSER_MIDIECHOSC_WAITING_STATE 3
#define MIDIPARSER_MIDIECHOSC_NOTEOFF_STATE 4
#define MIDIPARSER_MIDIECHOSC_PBENDCHANGE_STATE 5



#ifdef __cplusplus
}
#endif

#endif //MidiParser_H_
