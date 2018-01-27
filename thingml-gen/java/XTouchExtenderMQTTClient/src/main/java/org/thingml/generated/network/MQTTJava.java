package org.thingml.generated.network;

import org.thingml.generated.messages.*;
import org.thingml.java.*;
import org.thingml.java.ext.*;

import org.fusesource.hawtbuf.Buffer;
import org.fusesource.hawtbuf.UTF8Buffer;
import org.fusesource.mqtt.client.*;

import java.net.URISyntaxException;

public class MQTTJava extends Component {

	private final MQTTBinaryProtocol formatter = new MQTTBinaryProtocol();
	private final String pubtopic;
	private final String subtopic;

	//TODO: Make QoS parameterized

	final CallbackConnection connection;
	final Callback<Void> disconnectOnFailure = new Callback<Void>() {
		public void onSuccess(Void v) {}
		public void onFailure(Throwable value) {
			System.err.println("MQTT failure: " + value.getMessage());
			disconnect();
		}
	};

	/*$PORTS$*/
private Port xtouch_port;
public Port getXtouch_port(){return xtouch_port;}


	public MQTTJava(String url, String pubtopic, String subtopic) {
		this.pubtopic = pubtopic;
		this.subtopic = subtopic;
		final MQTT mqtt = new MQTT();
		try {
			mqtt.setHost(url);
		} catch (URISyntaxException e) {
			e.printStackTrace();
		}
		connection = mqtt.callbackConnection();
		registerListener();
		connect();
	}

	private void registerListener() {
		connection.listener(new	Listener() {
			public void onDisconnected() {}
			public void onConnected() {}
			public void onPublish(UTF8Buffer topic, Buffer payload, Runnable ack) {
				if (topic.toString().equals(MQTTJava.this.subtopic)) {
					final Event event = formatter.instantiate(new String(payload.toByteArray(), java.nio.charset.StandardCharsets.UTF_8));
if (event != null) xtouch_port.send(event);

				}
				ack.run();
			}
			public void onFailure(Throwable value) {
				System.err.println("MQTT failure: " + value.getMessage());
				disconnect(); // a connection failure occured.
			}
		});
	}

	private void disconnect() {
		connection.disconnect(new Callback<Void>() {
			@Override
			public void onSuccess(Void aVoid) {}
			@Override
			public void onFailure(Throwable throwable) {}
		});
	}

	private void connect() {
		connection.connect(new Callback<Void>() {
			public void onFailure(Throwable value) {
				System.err.println("Cannot connect to MQTT broker: " + value.getMessage());
				disconnect();
			}
			// Once we connect..
			public void onSuccess(Void v) {
				// Subscribe to a topic
				Topic[] topics = {new Topic(MQTTJava.this.subtopic, QoS.AT_LEAST_ONCE)};
				connection.subscribe(topics, new Callback<byte[]>() {
					public void onSuccess(byte[] qoses) {}
					public void onFailure(Throwable value) {
						System.err.println("Cannot subscribe to MQTT topic: " + value.getMessage());
						disconnect();
					}
				});
			}
		});
	}

	@Override
	public void stop() {
		super.stop();
		disconnect();
	}

	@Override
	public void run() {
		while (active.get()) {
			try {
				final Event e = queue.take();//should block if queue is empty, waiting for a message
				final Object payload = formatter.format(e);
				if (payload != null) {
					connection.publish(new UTF8Buffer(this.pubtopic), new Buffer(((String)payload).getBytes()), QoS.AT_LEAST_ONCE, false, disconnectOnFailure);

				}
			} catch (InterruptedException e) {
				//e.printStackTrace();
			}
		}
	}

	@Override
	public Component buildBehavior(String id, Component root) {
        /*$INIT PORTS$*/
xtouch_port = new Port("xtouch", this);

		final java.util.List < AtomicState > states = new java.util.ArrayList < AtomicState > ();
		final AtomicState init = new AtomicState("Init");
		states.add(init);
		behavior = new CompositeState("default");
		behavior.add(init);
		behavior.initial(init);
		return this;
	}

}