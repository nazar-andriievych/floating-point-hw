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

// Test isfinite and isinf functions
TEST(FloatingPointTest, IsFiniteFloat) {
    EXPECT_TRUE(isfinite(1.5f));
    EXPECT_FALSE(isfinite(INFINITY));
    EXPECT_FALSE(isfinite(-INFINITY));
    EXPECT_FALSE(isfinite(NAN));
}

TEST(FloatingPointTest, IsFiniteDouble) {
    EXPECT_TRUE(isfinite(1.5));
    EXPECT_FALSE(isfinite(INFINITY));
    EXPECT_FALSE(isfinite(-INFINITY));
    EXPECT_FALSE(isfinite(NAN));
}

TEST(FloatingPointTest, IsInfFloat) {
    EXPECT_FALSE(isinf(1.5f));
    EXPECT_TRUE(isinf(INFINITY));
    EXPECT_TRUE(isinf(-INFINITY));
    EXPECT_FALSE(isinf(NAN));
}

TEST(FloatingPointTest, IsInfDouble) {
    EXPECT_FALSE(isinf(1.5));
    EXPECT_TRUE(isinf(INFINITY));
    EXPECT_TRUE(isinf(-INFINITY));
    EXPECT_FALSE(isinf(NAN));
}

// Test isposfinite and isneginf functions
TEST(FloatingPointTest, IsPosInfFloat) {
    EXPECT_FALSE(isposinf(1.5f));
    EXPECT_TRUE(isposinf(INFINITY));
    EXPECT_FALSE(isposinf(-INFINITY));
    EXPECT_FALSE(isposinf(NAN));
}

TEST(FloatingPointTest, IsPosInfDouble) {
    EXPECT_FALSE(isposinf(1.5));
    EXPECT_TRUE(isposinf(INFINITY));
    EXPECT_FALSE(isposinf(-INFINITY));
    EXPECT_FALSE(isposinf(NAN));
}

TEST(FloatingPointTest, IsNegInfFloat) {
    EXPECT_FALSE(isneginf(1.5f));
    EXPECT_FALSE(isneginf(INFINITY));
    EXPECT_TRUE(isneginf(-INFINITY));
    EXPECT_FALSE(isneginf(NAN));
}

TEST(FloatingPointTest, IsNegInfDouble) {
    EXPECT_FALSE(isneginf(1.5));
    EXPECT_FALSE(isneginf(INFINITY));
    EXPECT_TRUE(isneginf(-INFINITY));
    EXPECT_FALSE(isneginf(NAN));
}

// Test iszero, isposzero and isnegzero functions
TEST(FloatingPointTest, IsZeroFloat) {
    EXPECT_TRUE(iszero(0.0f));
    EXPECT_TRUE(iszero(-0.0f));
    EXPECT_FALSE(iszero(1.5f));
}

TEST(FloatingPointTest, IsZeroDouble) {
    EXPECT_TRUE(iszero(0.0));
    EXPECT_TRUE(iszero(-0.0));
    EXPECT_FALSE(iszero(1.5));
}

TEST(FloatingPointTest, IsPosZeroFloat) {
    EXPECT_TRUE(isposzero(0.0f));
    EXPECT_FALSE(isposzero(-0.0f));
    EXPECT_FALSE(isposzero(1.5f));
}

TEST(FloatingPointTest, IsPosZeroDouble) {
    EXPECT_TRUE(isposzero(0.0));
    EXPECT_FALSE(isposzero(-0.0));
    EXPECT_FALSE(isposzero(1.5));
}

TEST(FloatingPointTest, IsNegZeroFloat) {
    EXPECT_FALSE(isnegzero(0.0f));
    EXPECT_TRUE(isnegzero(-0.0f));
    EXPECT_FALSE(isnegzero(1.5f));
}

TEST(FloatingPointTest, IsNegZeroDouble) {
    EXPECT_FALSE(isnegzero(0.0));
    EXPECT_TRUE(isnegzero(-0.0));
    EXPECT_FALSE(isnegzero(1.5));
}

// Test isnan function
TEST(FloatingPointTest, IsNanFloat) {
    EXPECT_TRUE(isnan(NAN));
    EXPECT_FALSE(isnan(1.5f));
}

TEST(FloatingPointTest, IsNanDouble) {
    EXPECT_TRUE(isnan(NAN));
    EXPECT_FALSE(isnan(1.5));
}

// Test isnormal ans issubnormal functions
TEST(FloatingPointTest, IsNormalFloat) {
    EXPECT_TRUE(isnormal(1.5f));
    EXPECT_FALSE(isnormal(0.0f));
    EXPECT_FALSE(isnormal(NAN));
    EXPECT_FALSE(isnormal(INFINITY));
    EXPECT_FALSE(isnormal(-INFINITY));
}

TEST(FloatingPointTest, IsNormalDouble) {
    EXPECT_TRUE(isnormal(1.5));
    EXPECT_FALSE(isnormal(0.0));
    EXPECT_FALSE(isnormal(NAN));
    EXPECT_FALSE(isnormal(INFINITY));
    EXPECT_FALSE(isnormal(-INFINITY));
}

TEST(FloatingPointTest, IsSubnormalFloat) {
    EXPECT_FALSE(issubnormal(1.5f));
    EXPECT_FALSE(issubnormal(0.0f));
    EXPECT_FALSE(issubnormal(NAN));
    EXPECT_FALSE(issubnormal(INFINITY));
    EXPECT_FALSE(issubnormal(-INFINITY));
    EXPECT_TRUE(issubnormal(1.0e-40f));    // Googled
}

TEST(FloatingPointTest, IsSubnormalDouble) {
    EXPECT_FALSE(issubnormal(1.5));
    EXPECT_FALSE(issubnormal(0.0));
    EXPECT_FALSE(issubnormal(NAN));
    EXPECT_FALSE(issubnormal(INFINITY));
    EXPECT_FALSE(issubnormal(-INFINITY));
    EXPECT_TRUE(issubnormal(1.0e-320));    // Googled
}

// Test issigned function
TEST(FloatingPointTest, IsSignedFloat) {
    EXPECT_TRUE(issigned(-1.5f));
    EXPECT_FALSE(issigned(1.5f));
    EXPECT_FALSE(issigned(NAN));
    EXPECT_FALSE(issigned(INFINITY));
    EXPECT_TRUE(issigned(-INFINITY));
}

// Test clasify function
TEST(FloatingPointTest, ClassifyFloat) {
    EXPECT_EQ(classify(0.0f), Classify::ZERO);
    EXPECT_EQ(classify(-0.0f), Classify::ZERO);
    EXPECT_EQ(classify(1.5f), Classify::NORMAL);
    EXPECT_EQ(classify(-1.5f), Classify::NORMAL);
    EXPECT_EQ(classify(INFINITY), Classify::INFINITE);
    EXPECT_EQ(classify(-INFINITY), Classify::INFINITE);
    EXPECT_EQ(classify(NAN), Classify::NaN);
}

TEST(FloatingPointTest, ClassifyDouble) {
    EXPECT_EQ(classify(0.0), Classify::ZERO);
    EXPECT_EQ(classify(-0.0), Classify::ZERO);
    EXPECT_EQ(classify(1.5), Classify::NORMAL);
    EXPECT_EQ(classify(-1.5), Classify::NORMAL);
    EXPECT_EQ(classify(INFINITY), Classify::INFINITE);
    EXPECT_EQ(classify(-INFINITY), Classify::INFINITE);
    EXPECT_EQ(classify(NAN), Classify::NaN);
}

// Test absolute, min, max and clamp functions
TEST(FloatingPointTest, AbsoluteFloat) {
    EXPECT_EQ(absolute(-5.0f), 5.0f);
    EXPECT_EQ(absolute(5.0f), 5.0f);
}

TEST(FloatingPointTest, AbsoluteDouble) {
    EXPECT_EQ(absolute(-5.0), 5.0);
    EXPECT_EQ(absolute(5.0), 5.0);
}

TEST(FloatingPointTest, MinFloat) {
    EXPECT_EQ(min(3.0f, 4.0f), 3.0f);
    EXPECT_EQ(min(4.0f, -1.0f), -1.0f);
}

TEST(FloatingPointTest, MinDouble) {
    EXPECT_EQ(min(3.0, 4.0), 3.0);
    EXPECT_EQ(min(4.0, -1.0), -1.0);
}

TEST(FloatingPointTest, MaxFloat) {
    EXPECT_EQ(max(3.0f, 4.0f), 4.0f);
    EXPECT_EQ(max(4.0f, -1.0f), 4.0f);
}

TEST(FloatingPointTest, MaxDouble) {
    EXPECT_EQ(max(3.0, 4.0), 4.0);
    EXPECT_EQ(max(4.0, -1.0), 4.0);
}

TEST(FloatingPointTest, ClampFloat) {
    EXPECT_EQ(clamp(5.0f, 1.0f, 10.0f), 5.0f);
    EXPECT_EQ(clamp(-1.0f, 1.0f, 10.0f), 1.0f);
    EXPECT_EQ(clamp(15.0f, 1.0f, 10.0f), 10.0f);
}

TEST(FloatingPointTest, ClampDouble) {
    EXPECT_EQ(clamp(5.0, 1.0, 10.0), 5.0);
    EXPECT_EQ(clamp(-1.0, 1.0, 10.0), 1.0);
    EXPECT_EQ(clamp(15.0, 1.0, 10.0), 10.0);
}

// Test isequal, less, greater, isnearlyequal, nearlyless, nearlygreater functions
TEST(FloatingPointTest, IsEqualFloat) {
    EXPECT_TRUE(isequal(1.5f, 1.5f));
    EXPECT_FALSE(isequal(1.5f, 1.6f));
}

TEST(FloatingPointTest, IsEqualDouble) {
    EXPECT_TRUE(isequal(1.5, 1.5));
    EXPECT_FALSE(isequal(1.5, 1.6));
}

TEST(FloatingPointTest, IsNearlyEqualFloat) {
    EXPECT_TRUE(isnearlyequal(1.5f, 1.5001f, 1.501f));
    EXPECT_FALSE(isnearlyequal(1.5f, 1.6f, 0.001f));
}

TEST(FloatingPointTest, IsNearlyEqualDouble) {
    EXPECT_TRUE(isnearlyequal(1.5, 1.5001, 1.501));
    EXPECT_FALSE(isnearlyequal(1.5, 1.6, 0.001));
}

TEST(FloatingPointTest, LessFloat) {
    EXPECT_TRUE(less(1.0f, 2.0f));
    EXPECT_FALSE(less(2.0f, 1.0f));
    EXPECT_FALSE(less(1.0f, 1.0f));
}

TEST(FloatingPointTest, LessDouble) {
    EXPECT_TRUE(less(1.0, 2.0));
    EXPECT_FALSE(less(2.0, 1.0));
    EXPECT_FALSE(less(1.0, 1.0));
}

TEST(FloatingPointTest, NearlyLessFloat) {
    EXPECT_TRUE(nearlyless(1.0f, 1.2f, 0.1f));
    EXPECT_FALSE(nearlyless(1.0f, 1.05f, 0.1f));
    EXPECT_FALSE(nearlyless(1.0f, 1.0f, 0.1f));
}

TEST(FloatingPointTest, NearlyLessDouble) {
    EXPECT_TRUE(nearlyless(1.0, 1.2, 0.1));
    EXPECT_FALSE(nearlyless(1.0, 1.05, 0.1));
    EXPECT_FALSE(nearlyless(1.0, 1.0, 0.1));
}

TEST(FloatingPointTest, GreaterFloat) {
    EXPECT_TRUE(greater(2.0f, 1.0f));
    EXPECT_FALSE(greater(1.0f, 2.0f));
    EXPECT_FALSE(greater(1.0f, 1.0f));
}

TEST(FloatingPointTest, GreaterDouble) {
    EXPECT_TRUE(greater(2.0, 1.0));
    EXPECT_FALSE(greater(1.0, 2.0));
    EXPECT_FALSE(greater(1.0, 1.0));
}

TEST(FloatingPointTest, NearlyGreaterFloat) {
    EXPECT_TRUE(nearlygreater(1.2f, 1.0f, 0.1f));
    EXPECT_FALSE(nearlygreater(1.05f, 1.0f, 0.1f));
    EXPECT_FALSE(nearlygreater(1.0f, 1.0f, 0.1f));
}

TEST(FloatingPointTest, NearlyGreaterDouble) {
    EXPECT_TRUE(nearlygreater(1.2, 1.0, 0.1));
    EXPECT_FALSE(nearlygreater(1.05, 1.0, 0.1));
    EXPECT_FALSE(nearlygreater(1.0, 1.0, 0.1));
}