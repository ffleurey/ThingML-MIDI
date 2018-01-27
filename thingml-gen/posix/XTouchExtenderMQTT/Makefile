# CC = /*CC*/
LIBS = -lpthread -l asound -l mosquitto
CFLAGS = -O2 -w
SRCS = RawMidi.c MidiParser.c XTouchExtender.c XTouchExtenderMQTT_cfg.c MQTT.c runtime.c
OBJS = RawMidi.o MidiParser.o XTouchExtender.o XTouchExtenderMQTT_cfg.o MQTT.o runtime.o

all : XTouchExtenderMQTT

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

XTouchExtenderMQTT : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ XTouchExtenderMQTT
