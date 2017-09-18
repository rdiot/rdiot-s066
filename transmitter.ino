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

Receiver
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "IRremote.h"
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int receiver = 11; // pin 1 of IR receiver to Arduino digital pin 11
 
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'
String str_hex = "";
String str_value = "";
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  irrecv.enableIRIn(); // Start the receiver
 
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S066:IR Transmitter");
  
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    //    Serial.println(results.value, HEX);  UN Comment to see raw values
    translateIR(); 
 
    lcd.setCursor(0,1);
    lcd.print("str_hex=" + (String)str_hex);
    lcd.setCursor(0,2);
    lcd.print("str_value=" + (String)str_value);
 
    irrecv.resume(); // receive the next value
  }   
}
 
void translateIR() // takes action based on IR code received
{
  switch(results.value)
  {
 
  case 0xE0E040BF:  
    str_hex = "0xE0E040BF";
    str_value = "power off ";
    break;
 
  default: 
    str_hex = (String)results.value;
    str_value = "NONE      ";
 
  } 
  delay(500);
 
} //END translateIR
