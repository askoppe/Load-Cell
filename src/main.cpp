#include <Arduino.h>
#include <Wire.h>
#include "sensor.h"
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
    byte highByte = Wire.read(); // read first byte
    byte lowByte = Wire.read(); // read second byte
    uint16_t sensorValue = bytesToRaw(highByte, lowByte); // combine bytes into raw sensor value
    Serial.print("Sensor Value(raw): ");
    Serial.println(sensorValue);
    // convert raw value to physical units using testable helper
    double force = rawToForce(sensorValue); // LBS
    Serial.print("Force (LBS): ");
    Serial.println(force);
  } else {
    Serial.println("Sensor data not available");
  }

  delay(1000);
}
