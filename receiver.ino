/* IR Transmitter Module [S066] : http://rdiot.tistory.com/160 [RDIoT Demo] */

#include <IRremote.h>
//* An IR LED must be connected to Arduino PWM pin 3.
IRsend irsend;
void loop() {
 
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
 
  unsigned int  rawData[67] = {4500,4400, 600,1650, 550,1650, 650,1600, 600,550, 550,550, 550,550, 550,550, 550,550, 550,1650, 600,1650, 550,1650, 600,550, 550,550, 550,550, 550,550, 550,550, 600,500, 600,1600, 600,550, 550,550, 550,550, 550,550, 550,550, 550,550, 600,1600, 600,550, 550,1650, 600,1650, 550,1650, 600,1650, 600,1650, 550,1650, 600};  // SAMSUNG E0E040BF
  unsigned int  data = 0xE0E040BF;
 
  irsend.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), khz); //Note the approach used to automatically calculate the size of the array.
 
  delay(5000); //In this example, the signal will be repeated every 5 seconds, approximately.
}
