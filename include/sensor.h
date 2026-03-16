#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

// Combine two I2C bytes (high, low) into a raw 16-bit sensor value
uint16_t bytesToRaw(uint8_t high, uint8_t low);

// Convert raw sensor ADC value to force in LBS
double rawToForce(uint16_t sensorValue);

#endif // SENSOR_H
