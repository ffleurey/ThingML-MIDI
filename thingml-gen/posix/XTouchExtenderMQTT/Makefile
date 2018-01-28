# CC = /*CC*/
LIBS = -lpthread -l asound -l mosquitto
CFLAGS = -O2 -w
SRCS = MidiParser.c RawMidi.c XTouchExtender.c XTouchExtenderMQTT_cfg.c MQTT.c Timer.c runtime.c
OBJS = MidiParser.o RawMidi.o XTouchExtender.o XTouchExtenderMQTT_cfg.o MQTT.o Timer.o runtime.o

all : XTouchExtenderMQTT

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

XTouchExtenderMQTT : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ XTouchExtenderMQTT
