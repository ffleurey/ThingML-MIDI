/*****************************************************/
//                    POSIX Timer
/*****************************************************/
#include <stdint.h>

#include "MidiParser.h"
#include "XTouchExtender.h"
#include "RawMidi.h"


#define NB_SOFT_TIMERS 32

struct Timer_Instance {
    uint16_t listener_id;
    /*INSTANCE_INFORMATION*/
};

void Timer_setup(struct Timer_Instance *_instance);
void Timer_loop(struct Timer_Instance *_instance);

void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id);

// Forwarding of messages Timer::XTouchExtender::clock::timer_start
void forward_Timer_XTouchExtender_send_clock_timer_start(struct XTouchExtender_Instance *_instance, uint8_t id, uint32_t time);
// Forwarding of messages Timer::XTouchExtender::clock::timer_cancel
void forward_Timer_XTouchExtender_send_clock_timer_cancel(struct XTouchExtender_Instance *_instance, uint8_t id);

