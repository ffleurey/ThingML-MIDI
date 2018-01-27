package org.thingml.generated.network;

import org.thingml.generated.messages.*;
import no.sintef.jasm.ext.Event;
import com.eclipsesource.json.JsonObject;
import com.eclipsesource.json.JsonValue;
import com.eclipsesource.json.Json;
public class MQTTBinaryProtocol implements StringJava {
private static final Button_pressMessageType BUTTON_PRESS = new Button_pressMessageType();
private static final PotMessageType POT = new PotMessageType();
private static final Button_releaseMessageType BUTTON_RELEASE = new Button_releaseMessageType();
private static final SliderMessageType SLIDER = new SliderMessageType();
public Event instantiate(String payload) {
try{
final JsonObject msg = Json.parse(payload).asObject();
final String msgName = msg.names().get(0);
if(msgName.equals(BUTTON_PRESS.getName())){
return BUTTON_PRESS.instantiate((int) msg.get(msgName).asObject().get("ch").asInt(), (int) msg.get(msgName).asObject().get("id").asInt());
}
else if(msgName.equals(POT.getName())){
return POT.instantiate((int) msg.get(msgName).asObject().get("ch").asInt(), (int) msg.get(msgName).asObject().get("value").asInt());
}
else if(msgName.equals(BUTTON_RELEASE.getName())){
return BUTTON_RELEASE.instantiate((int) msg.get(msgName).asObject().get("ch").asInt(), (int) msg.get(msgName).asObject().get("id").asInt());
}
else if(msgName.equals(SLIDER.getName())){
return SLIDER.instantiate((int) msg.get(msgName).asObject().get("ch").asInt(), (int) msg.get(msgName).asObject().get("value").asInt());
}

}catch(Exception pe){
System.out.println("Cannot parse " + payload + " because of " + pe.getMessage());
}
return null;
}
public String format(Event e){
if (e.getType().equals(BUTTON_LIGHT_OFF)) {
return format((Button_light_offMessageType.Button_light_offMessage)e)
;}
else if (e.getType().equals(SET_POT)) {
return format((Set_potMessageType.Set_potMessage)e)
;}
else if (e.getType().equals(SET_METER)) {
return format((Set_meterMessageType.Set_meterMessage)e)
;}
else if (e.getType().equals(SET_SLIDER)) {
return format((Set_sliderMessageType.Set_sliderMessage)e)
;}
else if (e.getType().equals(BUTTON_LIGHT_ON)) {
return format((Button_light_onMessageType.Button_light_onMessage)e)
;}
else if (e.getType().equals(BUTTON_LIGHT_BLINK)) {
return format((Button_light_blinkMessageType.Button_light_blinkMessage)e)
;}
return null;
}
private static final Button_light_offMessageType BUTTON_LIGHT_OFF = new Button_light_offMessageType();
/**Serializes a message into a JSON format*/
private String format(final Button_light_offMessageType.Button_light_offMessage _this) {
final JsonObject msg = new JsonObject();
final JsonObject params = new JsonObject();
params.add("ch", _this.ch);
params.add("id", _this.id);
msg.add("button_light_off",params);
return msg.toString();
}

private static final Set_potMessageType SET_POT = new Set_potMessageType();
/**Serializes a message into a JSON format*/
private String format(final Set_potMessageType.Set_potMessage _this) {
final JsonObject msg = new JsonObject();
final JsonObject params = new JsonObject();
params.add("ch", _this.ch);
params.add("value", _this.value);
msg.add("set_pot",params);
return msg.toString();
}

private static final Set_meterMessageType SET_METER = new Set_meterMessageType();
/**Serializes a message into a JSON format*/
private String format(final Set_meterMessageType.Set_meterMessage _this) {
final JsonObject msg = new JsonObject();
final JsonObject params = new JsonObject();
params.add("ch", _this.ch);
params.add("value", _this.value);
msg.add("set_meter",params);
return msg.toString();
}

private static final Set_sliderMessageType SET_SLIDER = new Set_sliderMessageType();
/**Serializes a message into a JSON format*/
private String format(final Set_sliderMessageType.Set_sliderMessage _this) {
final JsonObject msg = new JsonObject();
final JsonObject params = new JsonObject();
params.add("ch", _this.ch);
params.add("value", _this.value);
msg.add("set_slider",params);
return msg.toString();
}

private static final Button_light_onMessageType BUTTON_LIGHT_ON = new Button_light_onMessageType();
/**Serializes a message into a JSON format*/
private String format(final Button_light_onMessageType.Button_light_onMessage _this) {
final JsonObject msg = new JsonObject();
final JsonObject params = new JsonObject();
params.add("ch", _this.ch);
params.add("id", _this.id);
msg.add("button_light_on",params);
return msg.toString();
}

private static final Button_light_blinkMessageType BUTTON_LIGHT_BLINK = new Button_light_blinkMessageType();
/**Serializes a message into a JSON format*/
private String format(final Button_light_blinkMessageType.Button_light_blinkMessage _this) {
final JsonObject msg = new JsonObject();
final JsonObject params = new JsonObject();
params.add("ch", _this.ch);
params.add("id", _this.id);
msg.add("button_light_blink",params);
return msg.toString();
}



}
