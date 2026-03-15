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
    byte x1 = Wire.read(); // read first byte
    byte x2 = Wire.read(); // read second byte
    int sensorValue = (x1 << 8) | x2; // combine bytes
    Serial.print("Sensor Value(raw): ");
    Serial.println(sensorValue);
    // Convert raw value to physical units (example conversion)
    int Force = 10*(sensorValue-1000)/15000; // LBS
    Serial.print("Force (LBS): ");
    Serial.println(Force);
  } else {
    Serial.println("Sensor data not available");
  }

  delay(1000);
}
