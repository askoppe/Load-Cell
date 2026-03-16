#include <unity.h>
#include "sensor.h"

// Include the implementation directly for host-based (native) unit tests
#include "../src/sensor.cpp"

void test_rawToForce_zero_raw()
{
    // raw == 1000 -> force 0.0
    double f = rawToForce(1000);
    TEST_ASSERT_FLOAT_WITHIN(1e-6, 0.0, (float)f);
}

void test_rawToForce_positive()
{
    // raw == 2500 -> force = 10*(2500-1000)/15000 = 1.0
    double f = rawToForce(2500);
    TEST_ASSERT_FLOAT_WITHIN(1e-6, 1.0, (float)f);
}

void test_rawToForce_max()
{
    // raw == 16000 -> force = 10*(16000-1000)/15000 = 10.0
    double f = rawToForce(16000);
    TEST_ASSERT_FLOAT_WITHIN(1e-6, 10.0, (float)f);
}

void test_bytesToRaw_zero()
{
    uint16_t r = bytesToRaw(0x00, 0x00);
    TEST_ASSERT_EQUAL_UINT16(0x0000, r);
}

void test_bytesToRaw_simple()
{
    uint16_t r = bytesToRaw(0x12, 0x34);
    TEST_ASSERT_EQUAL_UINT16(0x1234, r);
}

void test_bytesToRaw_full()
{
    uint16_t r = bytesToRaw(0xFF, 0xFF);
    TEST_ASSERT_EQUAL_UINT16(0xFFFF, r);
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_rawToForce_zero_raw);
    RUN_TEST(test_rawToForce_positive);
    RUN_TEST(test_rawToForce_max);
    RUN_TEST(test_bytesToRaw_zero);
    RUN_TEST(test_bytesToRaw_simple);
    RUN_TEST(test_bytesToRaw_full);
    return UNITY_END();
}
