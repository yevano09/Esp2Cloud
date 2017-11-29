
# Esp2Cloud - Smart Home Automation 

This is a project to use ESP8266 to communicate with Cloud to pass the data to the cloud
The Project has three modules 
a. ATMEGA - to control the Relays and PWM 
b. ESP to provide the interface for ATMEGA for the Collection of data and trigger using MQTT
c. Cloud Part which acts as the data store and Operation Centre


### Brief introduction 

#### ATMEGA project
    ATMEGA would be used to control the PINS. and read the Analog sensor  values.
    there would be a possibility to control 16 devices with one H/W unit.
    The communication from ATMEGA and ESP should be bidirectional
    The Switching on / off should happen only via ATMEGA microcontroller.
    The ESP8266 would be like controller, it can send messages to enable on / off the ATMEGA


#### ESP module
    ESP module would be used for integration and intial config. 
    ESP would host / Listen to MQTT Topics configured to enable or disable Switches.
    ESP would also collect the Useage data and then publish back to server
    
  
#### Cloud part
    The Cloud part is still open. 
    The main aim is Manage the house from Remote location.
        It should support Auth/ Authorize the ESP's.
        It should have ability to store the data. 
        It should allow the customer to Analyze the usage of electricity across home
        It should allow uses to tag events in the data, and suggets further events based on past tagging
        It should create profiles like
                                - weekday's
                                - weekends
                                - holidays
                                - out of stations
        Based on the different profiles,it should optimize the use of electicity.
        Allows users to predict the Rise in use and preempt maintainence
        
#### Data format existing between ESP and ATMEGA to collect current usage
	JSON is the datafromat used for communication between ESP and ATMEGA.
	There is always a one to one mapping between ATMEGA and ESP, hence the Dataformat JSON is transmitted via Serial port.

##### Request 
   {
       " ReadPW ":"ReadALL",
       "ip":"120.100.0.100",
    }

##### Response

    {
   
	"IP": "120.100.0.100",
	"MAC": "40:6A:8E:4C:7A:D5",
	"TS": {
		"time": "< epochtime >"
	}
	30: 2.5,
	31: 3,
	33: 5,
	34: 0,
	35: 10,
	36: 0,
	37: 8,
	40: 34,
	41: 50,
}

'''
####

