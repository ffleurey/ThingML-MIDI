/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing XTouchExtender
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef XTouchExtender_H_
#define XTouchExtender_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : XTouchExtender
 *****************************************************************************/

// Definition of the instance struct:
struct XTouchExtender_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_midi;
uint16_t id_xtouch;
// Variables for the current instance state
int XTouchExtender_XTouchExtenderSC_State;
// Variables for the properties of the instance

};
// Declaration of prototypes outgoing messages :
void XTouchExtender_XTouchExtenderSC_OnEntry(int state, struct XTouchExtender_Instance *_instance);
void XTouchExtender_handle_xtouch_button_light_blink(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id);
void XTouchExtender_handle_xtouch_set_slider(struct XTouchExtender_Instance *_instance, uint8_t ch, uint16_t value);
void XTouchExtender_handle_xtouch_set_meter(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value);
void XTouchExtender_handle_xtouch_button_light_off(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id);
void XTouchExtender_handle_xtouch_button_light_on(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t id);
void XTouchExtender_handle_xtouch_set_pot(struct XTouchExtender_Instance *_instance, uint8_t ch, uint8_t value);
void XTouchExtender_handle_midi_control_change(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t ctrl, uint8_t value);
void XTouchExtender_handle_midi_note_on(struct XTouchExtender_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity);
// Declaration of callbacks for incoming messages:
void register_XTouchExtender_send_midi_note_on_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_XTouchExtender_send_midi_note_on_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t));
void register_XTouchExtender_send_midi_note_off_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_XTouchExtender_send_midi_note_off_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t));
void register_XTouchExtender_send_midi_pitch_bend_change_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint16_t));
void register_external_XTouchExtender_send_midi_pitch_bend_change_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint16_t));
void register_XTouchExtender_send_midi_control_change_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_XTouchExtender_send_midi_control_change_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t, uint8_t));
void register_XTouchExtender_send_xtouch_slider_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t));
void register_external_XTouchExtender_send_xtouch_slider_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t));
void register_XTouchExtender_send_xtouch_pot_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t));
void register_external_XTouchExtender_send_xtouch_pot_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t));
void register_XTouchExtender_send_xtouch_button_press_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t));
void register_external_XTouchExtender_send_xtouch_button_press_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t));
void register_XTouchExtender_send_xtouch_button_release_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t));
void register_external_XTouchExtender_send_xtouch_button_release_listener(void (*_listener)(struct XTouchExtender_Instance *, uint8_t, uint8_t));

// Definition of the states:
#define XTOUCHEXTENDER_XTOUCHEXTENDERSC_RUNNING_STATE 0
#define XTOUCHEXTENDER_XTOUCHEXTENDERSC_STATE 1



#ifdef __cplusplus
}
#endif

#endif //XTouchExtender_H_
