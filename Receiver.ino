/**
 * Receiver script
 * 
 * @author  Tuna Girişken
 * @date 03/9/21
 * @language Arduino
 */
#include <SPI.h>
#include "RF24.h"
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
  
MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
  
int derece[1];
  
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL; 
void setup(void){ 
Wire.begin();
mpu.initialize();
Serial.begin(9600);
radio.begin();
radio.openWritingPipe(pipe);
}
void loop(void){ 
 mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
derece[0] = map(ax, 0, 17000, 0,179);
 radio.write(derece, 1);
 Serial.println(derece[0]);
 delay(500);
 
}
