# CC = /*CC*/
LIBS = -lpthread -l mosquitto
CFLAGS = -O2 -w
SRCS = XTouchExtenderClient.c XTouchExtenderMQTTClient_cfg.c MQTT.c runtime.c
OBJS = XTouchExtenderClient.o XTouchExtenderMQTTClient_cfg.o MQTT.o runtime.o

all : XTouchExtenderMQTTClient

.c.o :
	${CC} ${CFLAGS} -c $< 

.cpp.o :
	${CC} ${CFLAGS} -c $< 

XTouchExtenderMQTTClient : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ XTouchExtenderMQTTClient
