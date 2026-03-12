#include <Arduino.h>
#include <Wire.h>
#define SENSOR_ADDRESS 0x28

void setup() 
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() 
{
  Wire.requestFrom(SENSOR_ADDRESS, 2);    // request 2 bytes from sensor
  if (Wire.available() >= 2) {
    byte x1 = Wire.read();
    byte x0 = Wire.read();



  } else {
    Serial.println("Sensor data not available");
  }

  delay(1000);
}