#mqttpublish.py 
#listen to the channel

import time
import paho.mqtt.client as paho
#broker="broker.hivemq.com"
broker="m11.cloudmqtt.com"
#define callback
def on_message(client, userdata, message):
    time.sleep(1)
    print("message topic=",message.topic)
    print("received message =",str(message.payload.decode("utf-8")))


def on_connect(client, userdata, flags, rc):
    print("rc: " + str(rc))
    pass
def on_disconnect():
	client.loop_stop()
	pass
client= paho.Client("client-001") #create client object client1.on_publish = on_publish #assign function to callback client1.connect(broker,port) #establish connection client1.publish("house/bulb1","on")
######Bind function to callback
client.on_message=on_message
client.on_connect=on_connect
client.on_disconnect = on_disconnect
#####
client.username_pw_set("lyhdpqlj","4OCSTRT0DPlQ")
client.connect(broker, 12492)

#client.loop_start() #start loop to process received messages
print("subscribing ")
client.subscribe("iot/channels/#")#subscribe
print("connecting to broker ",broker)


rc = 0
while rc == 0:
    rc = client.loop_forever()
    time.sleep(3)

print("rc: " + str(rc))
