/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing XTouchExtenderClient
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef XTouchExtenderClient_H_
#define XTouchExtenderClient_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : XTouchExtenderClient
 *****************************************************************************/

// Definition of the instance struct:
struct XTouchExtenderClient_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_xtouch;
// Variables for the current instance state
int XTouchExtenderClient_XTouchExtenderTestSC_State;
// Variables for the properties of the instance
uint8_t XTouchExtenderClient_current_bank_var;
uint8_t * XTouchExtenderClient_slider_values_var;
uint16_t XTouchExtenderClient_slider_values_var_size;

};
// Declaration of prototypes outgoing messages :
void XTouchExtenderClient_XTouchExtenderTestSC_OnEntry(int state, struct XTouchExtenderClient_Instance *_instance);
void XTouchExtenderClient_handle_xtouch_slider(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t value);
void XTouchExtenderClient_handle_xtouch_button_press(struct XTouchExtenderClient_Instance *_instance, uint8_t ch, uint8_t id);
// Declaration of callbacks for incoming messages:
void register_XTouchExtenderClient_send_xtouch_button_light_on_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t));
void register_external_XTouchExtenderClient_send_xtouch_button_light_on_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t));
void register_XTouchExtenderClient_send_xtouch_button_light_off_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t));
void register_external_XTouchExtenderClient_send_xtouch_button_light_off_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t));
void register_XTouchExtenderClient_send_xtouch_button_light_blink_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t));
void register_external_XTouchExtenderClient_send_xtouch_button_light_blink_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t));
void register_XTouchExtenderClient_send_xtouch_set_slider_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint16_t));
void register_external_XTouchExtenderClient_send_xtouch_set_slider_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint16_t));
void register_XTouchExtenderClient_send_xtouch_set_pot_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t));
void register_external_XTouchExtenderClient_send_xtouch_set_pot_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t));
void register_XTouchExtenderClient_send_xtouch_set_meter_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t));
void register_external_XTouchExtenderClient_send_xtouch_set_meter_listener(void (*_listener)(struct XTouchExtenderClient_Instance *, uint8_t, uint8_t));

// Definition of the states:
#define XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_RUNNING_STATE 0
#define XTOUCHEXTENDERCLIENT_XTOUCHEXTENDERTESTSC_STATE 1



#ifdef __cplusplus
}
#endif

#endif //XTouchExtenderClient_H_
