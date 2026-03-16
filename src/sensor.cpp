#include "sensor.h"

double rawToForce(uint16_t sensorValue) {
    // Defined Equation from TE connectivity datasheet for force output
    return 10.0 * ( (double)sensorValue - 1000.0 ) / 15000.0; // LBS
}

uint16_t bytesToRaw(uint8_t high, uint8_t low) {
    return ( (uint16_t)high << 8 ) | (uint16_t)low;
}
