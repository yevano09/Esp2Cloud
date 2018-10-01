/*
  LoRa Receive Example :
  Support Devices: LG01. 

  Require Library:
  https://github.com/sandeepmistry/arduino-LoRa 
  
  Example sketch showing how to receive LoRa packets and print out in Console. 

  modified 14 Jul 2017
  by Dragino Tech <support@dragino.com>
*/
#include <SPI.h>
#include <LoRa.h>
#include <Console.h>
#include <Process.h>
#include <ArduinoJson.h>

// Set center frequency
uint32_t freq = 433E6;
int SF = 12,Denominator = 5;
long SBW = 125E3;
  StaticJsonDocument<200> doc;
  
long old_time=millis();
long new_time;
long status_update_interval=60000;  //update Status every 30 seconds. 

//Receiver LoRa packets
void receivepacket() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Console.print("Received packet '");
    String incoming = "";   
    while( LoRa.available() ){
      incoming+=((char)LoRa.read());
    }
    incoming+="\0";
    Console.println(incoming+"'");
    
    //Console.println();
 
  }
}

void show_config()
{
  Console.print("The frequency is ");Console.print(freq);Console.println("Hz");
  Console.print("The spreading factor is ");Console.println(SF);
  Console.print("The coderate is ");Console.println(Denominator);
  Console.print("The single bandwith is ");Console.print(SBW);Console.println("Hz");
}
void setup() {
  Bridge.begin(115200);
  Console.begin();
//  while (!Console);

  Console.println("LoRa Receiver");

  if (!LoRa.begin(freq)) {
    Console.println("Starting LoRa failed!");
    while (1);
  }
  /*
  LoRa.setSpreadingFactor(SF);
  LoRa.setSignalBandwidth(SBW);
  LoRa.setCodingRate4(Denominator);
  LoRa.setSyncWord(0x34); 
  LoRa.receive(0);    
  */
  show_config();  
}

void loop() {
  receivepacket();
  new_time = millis();

  if( (new_time-old_time) > status_update_interval){
      Console.println("");
      Console.println("not receive overtime");
      old_time = new_time;
  }
}
