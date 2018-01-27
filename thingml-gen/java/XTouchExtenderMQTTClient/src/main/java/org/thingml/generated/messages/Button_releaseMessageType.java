/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated.messages;

import no.sintef.jasm.*;
import no.sintef.jasm.ext.*;

import java.util.*;
import java.nio.*;

public class Button_releaseMessageType extends EventType {
public Button_releaseMessageType(short code) {super("button_release", code);
}

public Button_releaseMessageType() {
super("button_release", (short) 0);
}

public Event instantiate(final int ch, final int id) { return new Button_releaseMessage(this, ch, id); }
public Event instantiate(Map<String, Object> params) {return instantiate((Integer) params.get("ch"), (Integer) params.get("id"));
}

public class Button_releaseMessage extends Event implements java.io.Serializable {

public final int ch;
public final int id;
public String toString(){
return "button_release (" + "ch: " + ch + ", " + "id: " + id + ")";
}

protected Button_releaseMessage(EventType type, final int ch, final int id) {
super(type);
this.ch = ch;
this.id = id;
}
public Event clone() {
return instantiate(this.ch, this.id);
}}

}
