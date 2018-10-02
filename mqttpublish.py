
#listen to the channel
import sys
import time
import paho.mqtt.client as paho
#broker="broker.hivemq.com"
broker="m11.cloudmqtt.com"
# Define event callbacks
program_name = sys.argv[0]
arguments = sys.argv[1:]
count = len(arguments)

if len (sys.argv) != 3 :
    print ("Usage: python mqttlisten.py  <clientid> <message>")
    sys.exit (1)

def on_connect(client, userdata, flags, rc):
    print("rc: " + str(rc))

def on_message(client, obj, msg):
    print(msg.topic + " " + str(msg.qos) + " " + str(msg.payload))

def on_publish(client, obj, mid):
    print("mid: " + str(mid))

def on_subscribe(client, obj, mid, granted_qos):
    print("Subscribed: " + str(mid) + " " + str(granted_qos))

def on_log(client, obj, level, string):
    print(string)



client= paho.Client("Client-1") #create cl sys.argv[2]  object client1.on_publish = on_publish #assign function to callback client1.connect(broker,port) #establish connection client1.publish("house/bulb1","on")
######Bind function to callback
client.on_message=on_message
client.on_connect = on_connect
client.on_publish = on_publish
client.on_subscribe = on_subscribe
#####
print("connecting to broker ",broker)

client.username_pw_set("lyhdpqlj","4OCSTRT0DPlQ")
client.connect(broker, 12492)
#client.connect(broker)#connect
print("subscribing ")
client.subscribe("#")#subscribe
time.sleep(2)
print("publishing ")
client.publish("iot/channels/"+sys.argv[1], sys.argv[2]) #publish

# Continue the network loop, exit when an error occurs
#rc = 0
#while rc == 0:
#    rc = client.loop()
#print("rc: " + str(rc))

client.disconnect()
