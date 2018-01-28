/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing RawMidi
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef RawMidi_H_
#define RawMidi_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : RawMidi
 *****************************************************************************/


// BEGIN: Code from the c_header annotation RawMidi
#include <alsa/asoundlib.h>
void errormessage(const char *format, ...);
// END: Code from the c_header annotation RawMidi

// Definition of the instance struct:
struct RawMidi_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_rawmidi;
// Variables for the current instance state
int RawMidi_RawMidiSC_State;
// Variables for the properties of the instance
uint8_t RawMidi_connected_var;

};
// Declaration of prototypes outgoing messages :
void RawMidi_RawMidiSC_OnEntry(int state, struct RawMidi_Instance *_instance);
void RawMidi_handle_rawmidi_midi_open(struct RawMidi_Instance *_instance, uint8_t card, uint8_t dev, uint8_t sub);
void RawMidi_handle_rawmidi_midi_close(struct RawMidi_Instance *_instance);
void RawMidi_handle_rawmidi_midi_out(struct RawMidi_Instance *_instance, uint8_t b);
// Declaration of callbacks for incoming messages:
void register_RawMidi_send_rawmidi_midi_in_listener(void (*_listener)(struct RawMidi_Instance *, uint8_t));
void register_external_RawMidi_send_rawmidi_midi_in_listener(void (*_listener)(struct RawMidi_Instance *, uint8_t));
void register_RawMidi_send_rawmidi_midi_error_listener(void (*_listener)(struct RawMidi_Instance *, int));
void register_external_RawMidi_send_rawmidi_midi_error_listener(void (*_listener)(struct RawMidi_Instance *, int));

// Definition of the states:
#define RAWMIDI_RAWMIDISC_STATE 0
#define RAWMIDI_RAWMIDISC_DISCONNECTED_STATE 1
#define RAWMIDI_RAWMIDISC_CONNECTED_STATE 2



#ifdef __cplusplus
}
#endif

#endif //RawMidi_H_
