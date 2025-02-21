#include "pch.h"

#include "D:\University\Selected_Math_Topics_for_Game_Development\floating-point-hw\FloatingPoint\funtions.cpp"

// Test to_bits and to_float functions
TEST(FloatingPointTest, ToBitsAndToFloat) {
    float f = 1.5f;
    uint32_t bits = to_bits(f);
    float f_converted = to_float(bits);
    EXPECT_EQ(f, f_converted);
}

TEST(FloatingPointTest, ToBitsAndToDouble) {
    double d = 1.5;
    uint64_t bits = to_bits(d);
    double d_converted = to_double(bits);
    EXPECT_EQ(d, d_converted);
}

// Test get_sign, get_exponent, and get_mantissa functions
TEST(FloatingPointTest, GetSignFloat) {
    float f = -1.5f;
    uint32_t bits = to_bits(f);
    EXPECT_EQ(get_sign(bits), 1);
}

TEST(FloatingPointTest, GetSignDouble) {
    double d = -1.5;
    uint64_t bits = to_bits(d);
    EXPECT_EQ(get_sign(bits), 1);
}

TEST(FloatingPointTest, GetExponentFloat) {
    float f = 1.5f;
    uint32_t bits = to_bits(f);
    EXPECT_EQ(get_exponent(bits), 127);
}

TEST(FloatingPointTest, GetExponentDouble) {
    double d = 1.5;
    uint64_t bits = to_bits(d);
    EXPECT_EQ(get_exponent(bits), 1023);
}

TEST(FloatingPointTest, GetMantissaFloat) {
    float f = 1.5f;
    uint32_t bits = to_bits(f);
    EXPECT_EQ(get_mantissa(bits), 0x400000);
}

TEST(FloatingPointTest, GetMantissaDouble) {
    double d = 1.5;
    uint64_t bits = to_bits(d);
    EXPECT_EQ(get_mantissa(bits), 0x8000000000000);
}