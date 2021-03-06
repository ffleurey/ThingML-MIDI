/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated;

import no.sintef.jasm.*;
import no.sintef.jasm.ext.*;

import org.thingml.generated.api.*;
import org.thingml.generated.messages.*;

import java.util.*;
import org.thingml.generated.network.*;
public class Main {
//Things
public static XTouchExtenderClient XTouchExtenderClient_test;
public static void main(String args[]) {
//Things
final int[] test_slider_values_array = new int[32];
XTouchExtenderClient_test = (XTouchExtenderClient) new XTouchExtenderClient("test (XTouchExtenderClient)", test_slider_values_array, (int) (0)).buildBehavior(null, null);
//Connecting internal ports...
//Connectors
//Init instances (queues, etc)
XTouchExtenderClient_test.init();
//Network components for external connectors
/*$NETWORK$*/
MQTTJava null_MQTT = (MQTTJava) new MQTTJava("tcp://192.168.8.5:1883", "sh/xtouch/cmd", "sh/xtouch/state").buildBehavior(null, null);

//External Connectors
/*$EXT CONNECTORS$*/
null_MQTT.getXtouch_port().addListener(XTouchExtenderClient_test.getXtouch_port());
XTouchExtenderClient_test.getXtouch_port().addListener(null_MQTT.getXtouch_port());

/*$START$*/
null_MQTT.init().start();

XTouchExtenderClient_test.start();
//Hook to stop instances following client/server dependencies (clients firsts)
Runtime.getRuntime().addShutdownHook(new Thread() {
public void run() {
XTouchExtenderClient_test.stop();
/*$STOP$*/
null_MQTT.stop();

}
});

}
}
