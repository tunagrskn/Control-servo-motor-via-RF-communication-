/**
 * Transmitter script
 * 
 * @author  Tuna Girişken
 * @date 03/9/21
 * @language Arduino
 */
//SCK -> 13
//MISO -> 12
//MOSI -> 11
//CSN -> 10
//CE -> 9
#include <Servo.h> 
 #include <SPI.h>
 #include "RF24.h"
Servo Servo_motor; 
RF24 radio(9,10);
 const uint64_t pipe = 0xE8E8F0F0E1LL; 
 int derece[1];
 void setup() 
 { 
 Serial.begin(9600);
 Servo_motor.attach(6); 
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening(); 
 } 
 void loop() 
 { 
 if (radio.available()){
 bool done = false;
 while (!done){
 radio.read(derece, 1); 
 Servo_motor.write (derece[0]);
  
 }
 }
 }
