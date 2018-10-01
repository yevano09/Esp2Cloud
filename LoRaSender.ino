#include <SPI.h>
#include <LoRa.h>
#include <U8x8lib.h>

#define SS 18
#define RST 14
#define DI0 26

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);
char buf[10];
int counter = 0;

void setup() {
  Serial.begin(115200);

  SPI.begin(5, 19, 27, 18);
  LoRa.setPins(SS, RST, DI0);
  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("{Temp : ");
  LoRa.print(counter);
  LoRa.print(" }");
  LoRa.endPacket();
  u8x8.drawString(0, 0, "Sent packet  ");
 // char currentrs[8];
  sprintf(buf, "%d", counter);
  u8x8.drawString(0, 1, buf);

  counter++;

  delay(30000);
}
