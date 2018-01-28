/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing RawMidi
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "RawMidi.h"

/*****************************************************************************
 * Implementation for type : RawMidi
 *****************************************************************************/


// BEGIN: Code from the c_global annotation RawMidi

snd_rawmidi_t* midiin  = NULL;      // structure to access MIDI input
snd_rawmidi_t* midiout = NULL;      // structure to access MIDI output

void errormessage(const char *format, ...) {
   va_list ap;
   va_start(ap, format);
   vfprintf(stderr, format, ap);
   va_end(ap);
   putc('\n', stderr);
}
// END: Code from the c_global annotation RawMidi

// Declaration of prototypes:
//Prototypes: State Machine
void RawMidi_RawMidiSC_OnExit(int state, struct RawMidi_Instance *_instance);
//Prototypes: Message Sending
void RawMidi_send_rawmidi_midi_in(struct RawMidi_Instance *_instance, uint8_t b);
void RawMidi_send_rawmidi_midi_error(struct RawMidi_Instance *_instance, int code);
//Prototypes: Function
void f_RawMidi_start_read_thread(struct RawMidi_Instance *_instance);
uint8_t f_RawMidi_connect(struct RawMidi_Instance *_instance, uint8_t card, uint8_t dev, uint8_t sub);
void f_RawMidi_close(struct RawMidi_Instance *_instance);
void f_RawMidi_sendByte(struct RawMidi_Instance *_instance, uint8_t b);
void f_RawMidi_sendNoteOn(struct RawMidi_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity);
void f_RawMidi_sendNoteOff(struct RawMidi_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity);
// Declaration of functions:
// Fork a thread to execute the function f_RawMidi_start_read_thread

// Struct for the parameters of the function  f_RawMidi_start_read_thread
struct f_RawMidi_start_read_thread_struct {
  struct RawMidi_Instance *_instance;

  pthread_mutex_t *lock;
  pthread_cond_t *cv;
};

// Definition of function start_receiver_process (executed in a separate thread)
void f_RawMidi_start_read_thread_run(struct RawMidi_Instance *_instance)
{
  char buffer[1];        // Storage for input buffer received
	   int status;
	   while (_instance->RawMidi_connected_var) {
	      if ((status = snd_rawmidi_read(midiin, buffer, 1)) < 0) {
	         errormessage("Problem reading MIDI input: %s", snd_strerror(status));
	         exit(1);
	      }
RawMidi_send_rawmidi_midi_in(_instance, buffer[0]);
}
f_RawMidi_close(_instance);

}


void f_RawMidi_start_read_thread_proc(void * p)
{
  // Get parameters from the main thread
  struct f_RawMidi_start_read_thread_struct params = *((struct f_RawMidi_start_read_thread_struct *) p);
  
  // Unblock the main thread
  pthread_mutex_lock(params.lock);
  pthread_cond_signal(params.cv);
  pthread_mutex_unlock(params.lock);
  
  // Run the function
  //f_RawMidi_start_read_thread_run(params._instance, params.esums_device);
  f_RawMidi_start_read_thread_run(params._instance);
}

// Operation called by the runtime and forking a new thread
void f_RawMidi_start_read_thread(struct RawMidi_Instance *_instance)
{
  // Store parameters
  struct f_RawMidi_start_read_thread_struct params;
  pthread_mutex_t lock;
  pthread_cond_t cv;
  params.lock = &lock;
  params.cv = &cv;
  params._instance = _instance;

  pthread_mutex_init(params.lock, NULL);
  pthread_cond_init(params.cv, NULL);
  //Start the new thread
  pthread_mutex_lock(params.lock);
  pthread_t thread; 
  pthread_create( &thread, NULL, f_RawMidi_start_read_thread_proc, (void*) &params);
  // Wait until it has started and read its parameters
  pthread_cond_wait(params.cv, params.lock);
  // Realease mutex
  pthread_mutex_unlock(params.lock);
}// Definition of function connect
uint8_t f_RawMidi_connect(struct RawMidi_Instance *_instance, uint8_t card, uint8_t dev, uint8_t sub) {
const char* portname = "hw:2,0,0";
	   int status;
	   int mode = SND_RAWMIDI_SYNC;
	
	   if ((status = snd_rawmidi_open(&midiin, &midiout, portname, mode)) < 0) {
	      errormessage("Problem opening MIDI input: %s", snd_strerror(status));
_instance->RawMidi_connected_var = 0;
RawMidi_send_rawmidi_midi_error(_instance, status);
exit(1);
	   }
_instance->RawMidi_connected_var = 1;
f_RawMidi_start_read_thread(_instance);
return _instance->RawMidi_connected_var;
}
// Definition of function close
void f_RawMidi_close(struct RawMidi_Instance *_instance) {
snd_rawmidi_close(midiin);
     snd_rawmidi_close(midiout);
     midiin  = NULL;    // snd_rawmidi_close() does not clear invalid pointer,
     midiout = NULL;    // so might be a good idea to erase it after closing.
}
// Definition of function sendByte
void f_RawMidi_sendByte(struct RawMidi_Instance *_instance, uint8_t b) {
char buffer[1];
buffer[0] = b;
int status;
if ((status = snd_rawmidi_write(midiout, buffer, 1)) < 0) {
     	errormessage("Problem writing to MIDI output: %s\n", snd_strerror(status));
RawMidi_send_rawmidi_midi_error(_instance, status);
exit(1);
     }
}
// Definition of function sendNoteOn
void f_RawMidi_sendNoteOn(struct RawMidi_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity) {
char buffer[3];
buffer[0] = 0x90 | channel;
buffer[1] = key;
buffer[2] = velocity;
int status;
if ((status = snd_rawmidi_write(midiout, buffer, 3)) < 0) {
     	errormessage("Problem writing to MIDI output: %s", snd_strerror(status));
RawMidi_send_rawmidi_midi_error(_instance, status);
exit(1);
     }
}
// Definition of function sendNoteOff
void f_RawMidi_sendNoteOff(struct RawMidi_Instance *_instance, uint8_t channel, uint8_t key, uint8_t velocity) {
char buffer[3];
buffer[0] = 0x80 | channel;
buffer[1] = key;
buffer[2] = velocity;
int status;
if ((status = snd_rawmidi_write(midiout, buffer, 3)) < 0) {
     	errormessage("Problem writing to MIDI output: %s", snd_strerror(status));
RawMidi_send_rawmidi_midi_error(_instance, status);
exit(1);
     }
}

// Sessions functionss:


// On Entry Actions:
void RawMidi_RawMidiSC_OnEntry(int state, struct RawMidi_Instance *_instance) {
switch(state) {
case RAWMIDI_RAWMIDISC_STATE:{
_instance->RawMidi_RawMidiSC_State = RAWMIDI_RAWMIDISC_DISCONNECTED_STATE;
RawMidi_RawMidiSC_OnEntry(_instance->RawMidi_RawMidiSC_State, _instance);
break;
}
case RAWMIDI_RAWMIDISC_DISCONNECTED_STATE:{
break;
}
case RAWMIDI_RAWMIDISC_CONNECTED_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void RawMidi_RawMidiSC_OnExit(int state, struct RawMidi_Instance *_instance) {
switch(state) {
case RAWMIDI_RAWMIDISC_STATE:{
RawMidi_RawMidiSC_OnExit(_instance->RawMidi_RawMidiSC_State, _instance);
break;}
case RAWMIDI_RAWMIDISC_DISCONNECTED_STATE:{
break;}
case RAWMIDI_RAWMIDISC_CONNECTED_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void RawMidi_handle_rawmidi_midi_open(struct RawMidi_Instance *_instance, uint8_t card, uint8_t dev, uint8_t sub) {
if(!(_instance->active)) return;
//Region RawMidiSC
uint8_t RawMidi_RawMidiSC_State_event_consumed = 0;
if (_instance->RawMidi_RawMidiSC_State == RAWMIDI_RAWMIDISC_DISCONNECTED_STATE) {
if (RawMidi_RawMidiSC_State_event_consumed == 0 && 1) {
RawMidi_RawMidiSC_OnExit(RAWMIDI_RAWMIDISC_DISCONNECTED_STATE, _instance);
_instance->RawMidi_RawMidiSC_State = RAWMIDI_RAWMIDISC_CONNECTED_STATE;
f_RawMidi_connect(_instance, card, dev, sub);
RawMidi_RawMidiSC_OnEntry(RAWMIDI_RAWMIDISC_CONNECTED_STATE, _instance);
RawMidi_RawMidiSC_State_event_consumed = 1;
}
}
//End Region RawMidiSC
//End dsregion RawMidiSC
//Session list: 
}
void RawMidi_handle_rawmidi_midi_close(struct RawMidi_Instance *_instance) {
if(!(_instance->active)) return;
//Region RawMidiSC
uint8_t RawMidi_RawMidiSC_State_event_consumed = 0;
if (_instance->RawMidi_RawMidiSC_State == RAWMIDI_RAWMIDISC_CONNECTED_STATE) {
if (RawMidi_RawMidiSC_State_event_consumed == 0 && 1) {
RawMidi_RawMidiSC_OnExit(RAWMIDI_RAWMIDISC_CONNECTED_STATE, _instance);
_instance->RawMidi_RawMidiSC_State = RAWMIDI_RAWMIDISC_DISCONNECTED_STATE;
_instance->RawMidi_connected_var = 0;
RawMidi_RawMidiSC_OnEntry(RAWMIDI_RAWMIDISC_DISCONNECTED_STATE, _instance);
RawMidi_RawMidiSC_State_event_consumed = 1;
}
}
//End Region RawMidiSC
//End dsregion RawMidiSC
//Session list: 
}
void RawMidi_handle_rawmidi_midi_out(struct RawMidi_Instance *_instance, uint8_t b) {
if(!(_instance->active)) return;
//Region RawMidiSC
uint8_t RawMidi_RawMidiSC_State_event_consumed = 0;
if (_instance->RawMidi_RawMidiSC_State == RAWMIDI_RAWMIDISC_CONNECTED_STATE) {
if (RawMidi_RawMidiSC_State_event_consumed == 0 && 1) {
f_RawMidi_sendByte(_instance, b);
RawMidi_RawMidiSC_State_event_consumed = 1;
}
}
//End Region RawMidiSC
//End dsregion RawMidiSC
//Session list: 
}

// Observers for outgoing messages:
void (*external_RawMidi_send_rawmidi_midi_in_listener)(struct RawMidi_Instance *, uint8_t)= 0x0;
void (*RawMidi_send_rawmidi_midi_in_listener)(struct RawMidi_Instance *, uint8_t)= 0x0;
void register_external_RawMidi_send_rawmidi_midi_in_listener(void (*_listener)(struct RawMidi_Instance *, uint8_t)){
external_RawMidi_send_rawmidi_midi_in_listener = _listener;
}
void register_RawMidi_send_rawmidi_midi_in_listener(void (*_listener)(struct RawMidi_Instance *, uint8_t)){
RawMidi_send_rawmidi_midi_in_listener = _listener;
}
void RawMidi_send_rawmidi_midi_in(struct RawMidi_Instance *_instance, uint8_t b){
if (RawMidi_send_rawmidi_midi_in_listener != 0x0) RawMidi_send_rawmidi_midi_in_listener(_instance, b);
if (external_RawMidi_send_rawmidi_midi_in_listener != 0x0) external_RawMidi_send_rawmidi_midi_in_listener(_instance, b);
;
}
void (*external_RawMidi_send_rawmidi_midi_error_listener)(struct RawMidi_Instance *, int)= 0x0;
void (*RawMidi_send_rawmidi_midi_error_listener)(struct RawMidi_Instance *, int)= 0x0;
void register_external_RawMidi_send_rawmidi_midi_error_listener(void (*_listener)(struct RawMidi_Instance *, int)){
external_RawMidi_send_rawmidi_midi_error_listener = _listener;
}
void register_RawMidi_send_rawmidi_midi_error_listener(void (*_listener)(struct RawMidi_Instance *, int)){
RawMidi_send_rawmidi_midi_error_listener = _listener;
}
void RawMidi_send_rawmidi_midi_error(struct RawMidi_Instance *_instance, int code){
if (RawMidi_send_rawmidi_midi_error_listener != 0x0) RawMidi_send_rawmidi_midi_error_listener(_instance, code);
if (external_RawMidi_send_rawmidi_midi_error_listener != 0x0) external_RawMidi_send_rawmidi_midi_error_listener(_instance, code);
;
}



