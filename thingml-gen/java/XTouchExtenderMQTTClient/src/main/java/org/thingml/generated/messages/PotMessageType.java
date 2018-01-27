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

public class PotMessageType extends EventType {
public PotMessageType(short code) {super("pot", code);
}

public PotMessageType() {
super("pot", (short) 0);
}

public Event instantiate(final int ch, final int value) { return new PotMessage(this, ch, value); }
public Event instantiate(Map<String, Object> params) {return instantiate((Integer) params.get("ch"), (Integer) params.get("value"));
}

public class PotMessage extends Event implements java.io.Serializable {

public final int ch;
public final int value;
public String toString(){
return "pot (" + "ch: " + ch + ", " + "value: " + value + ")";
}

protected PotMessage(EventType type, final int ch, final int value) {
super(type);
this.ch = ch;
this.value = value;
}
public Event clone() {
return instantiate(this.ch, this.value);
}}

}
