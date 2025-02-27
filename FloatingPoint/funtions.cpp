#include <bit>
#include <iostream>
#include <cstdint>

#include "functions.h"


// Task 1
uint32_t to_bits(float const value){
    return std::bit_cast<uint32_t>(value);
}

float to_float(uint32_t const value){
    return std::bit_cast<float>(value);
}

uint64_t to_bits(double const value) {
    return std::bit_cast<uint64_t>(value);
}

double to_double(uint64_t const value) {
    return std::bit_cast<double>(value);
}

// Extra functions
uint32_t get_sign(uint32_t const value) {
    return (value >> 31) & 1;
}

uint64_t get_sign(uint64_t const value) {
    return (value >> 63) & 1;
}

uint32_t get_exponent(uint32_t const value) {
    return (value >> 23) & 0xFF;
}

uint64_t get_exponent(uint64_t const value) {
    return (value >> 52) & 0x7FF;
}

uint32_t get_mantissa(uint32_t const value) {
    return value & 0x7FFFFF;
}

uint64_t get_mantissa(uint64_t const value) {
    return value & 0xFFFFFFFFFFFFF;
}

// Task 2
bool isfinite(float x) {
    uint32_t bits = to_bits(x);
    uint32_t exponent = get_exponent(bits);

    return exponent != 0xFF;
}

bool isfinite(double x) {
    uint64_t bits = to_bits(x);
    uint64_t exponent = get_exponent(bits);

    return exponent != 0x7FF;
}

bool isinf(float x) {
    uint32_t bits = to_bits(x);
    uint32_t exponent = get_exponent(bits);
    uint32_t mantissa = get_mantissa(bits);

    return (exponent == 0xFF) && (mantissa == 0);
}

bool isinf(double x) {
    uint64_t bits = to_bits(x);
    uint64_t exponent = get_exponent(bits);
    uint64_t mantissa = get_mantissa(bits);

    return (exponent == 0x7FF) && (mantissa == 0);
}

bool isposinf(float x) {
    uint32_t bits = to_bits(x);
    uint32_t sign = get_sign(bits);
    uint32_t exponent = get_exponent(bits);
    uint32_t mantissa = get_mantissa(bits);

    return (sign == 0) && (exponent == 0xFF) && (mantissa == 0);
}

bool isposinf(double x) {
    uint64_t bits = to_bits(x);
    uint64_t sign = get_sign(bits);
    uint64_t exponent = get_exponent(bits);
    uint64_t mantissa = get_mantissa(bits);

    return (sign == 0) && (exponent == 0x7FF) && (mantissa == 0);
}

bool isneginf(float x) {
    uint32_t bits = to_bits(x);
    uint32_t sign = get_sign(bits);
    uint32_t exponent = get_exponent(bits);
    uint32_t mantissa = get_mantissa(bits);

    return (sign == 1) && (exponent == 0xFF) && (mantissa == 0);
}

bool isneginf(double x) {
    uint64_t bits = to_bits(x);
    uint64_t sign = get_sign(bits);
    uint64_t exponent = get_exponent(bits);
    uint64_t mantissa = get_mantissa(bits);

    return (sign == 1) && (exponent == 0x7FF) && (mantissa == 0);
}

bool iszero(float x) {
    uint32_t bits = to_bits(x);

    return (bits << 1) == 0;
}

bool iszero(double x) {
    uint64_t bits = to_bits(x);

    return (bits << 1) == 0;
}

bool isposzero(float x) {
    uint32_t bits = to_bits(x);
    uint32_t sign = get_sign(bits);

    return (sign == 0) && ((bits << 1) == 0);
}

bool isposzero(double x) {
    uint64_t bits = to_bits(x);
    uint64_t sign = get_sign(bits);

    return (sign == 0) && (bits << 1) == 0;
}

bool isnegzero(float x) {
    uint32_t bits = to_bits(x);
    uint32_t sign = get_sign(bits);

    return (sign == 1) && ((bits << 1) == 0);
}

bool isnegzero(double x) {
    uint64_t bits = to_bits(x);
    uint64_t sign = get_sign(bits);

    return (sign == 1) && (bits << 1) == 0;
}

bool isnan(float x) {
    uint32_t bits = to_bits(x);
    uint32_t sign = get_sign(bits);
    uint32_t exponent = get_exponent(bits);
    uint32_t mantissa = get_mantissa(bits);

    return (sign == 0) && (exponent == 0xFF) && (mantissa != 0);
}

bool isnan(double x) {
    uint64_t bits = to_bits(x);
    uint64_t sign = get_sign(bits);
    uint64_t exponent = get_exponent(bits);
    uint64_t mantissa = get_mantissa(bits);

    return (sign == 0) && (exponent == 0x7FF) && (mantissa != 0);
}

bool isnormal(float x) {
    uint32_t bits = to_bits(x);
    uint32_t exponent = get_exponent(bits);

    return (exponent != 0xFF) && (exponent != 0);
}

bool isnormal(double x) {
    uint64_t bits = to_bits(x);
    uint64_t exponent = get_exponent(bits);

    return (exponent != 0x7FF) && (exponent != 0);
}

bool issubnormal(float x) {
    uint32_t bits = to_bits(x);
    uint32_t exponent = get_exponent(bits);
    uint32_t mantissa = get_mantissa(bits);

    return (exponent == 0) && (mantissa != 0);
}

bool issubnormal(double x) {
    uint64_t bits = to_bits(x);
    uint64_t exponent = get_exponent(bits);
    uint64_t mantissa = get_mantissa(bits);

    return (exponent == 0) && (mantissa != 0);
}

bool issigned(float x) {
    uint32_t bits = to_bits(x);
    uint32_t sign = get_sign(bits);

    return sign == 1;
}

bool issigned(double x) {
    uint64_t bits = to_bits(x);
    uint64_t sign = get_sign(bits);

    return sign == 1;
}

Classify classify(float x) {
    uint32_t bits = to_bits(x);
    uint32_t exponent = get_exponent(bits);
    uint32_t mantissa = get_mantissa(bits);

    if (exponent == 0xFF) {
        return (mantissa == 0) ? Classify::INFINITE : Classify::NaN;
    }
    if (exponent == 0) {
        return (mantissa == 0) ? Classify::ZERO : Classify::SUBNORMAL;
    }
    return (mantissa == 0) ? Classify::NORMAL : Classify::NORMAL;
}

Classify classify(double x) {
    uint64_t bits = to_bits(x);
    uint64_t exponent = get_exponent(bits);
    uint64_t mantissa = get_mantissa(bits);

    if (exponent == 0x7FF) {
        return (mantissa == 0) ? Classify::INFINITE : Classify::NaN;
    }
    if (exponent == 0) {
        return (mantissa == 0) ? Classify::ZERO : Classify::SUBNORMAL;
    }
    return Classify::NORMAL;
}

// Task 3
float absolute(float x) {
    uint32_t bits = to_bits(x);

    return to_float((bits << 1) >> 1);
}

double absolute(double x) {
    uint64_t bits = to_bits(x);

    return to_double((bits << 1) >> 1);
}

float min(float x, float y) {
    uint32_t x_bits = to_bits(x);
    uint32_t y_bits = to_bits(y);

    // Handle NaN cases
    if (isnan(x_bits)) return y;
    if (isnan(y_bits)) return x;

    // Flip sign for correct comparison
    uint32_t x_ordered = x_bits ^ (1U << 31);
    uint32_t y_ordered = y_bits ^ (1U << 31);

    return (x_ordered < y_ordered) ? x : y;
}

double min(double x, double y) {
    uint64_t x_bits = to_bits(x);
    uint64_t y_bits = to_bits(y);

    // Handle NaN cases
    if (isnan(x_bits)) return y;
    if (isnan(y_bits)) return x;

    // Flip sign for correct comparison
    uint64_t x_ordered = x_bits ^ (1ULL << 63);
    uint64_t y_ordered = y_bits ^ (1ULL << 63);

    return (x_ordered < y_ordered) ? x : y;
}

float max(float x, float y) {
    uint32_t x_bits = to_bits(x);
    uint32_t y_bits = to_bits(y);

    // Handle NaN cases
    if (isnan(x_bits)) return y;
    if (isnan(y_bits)) return x;

    // Flip sign for correct comparison
    uint32_t x_ordered = x_bits ^ (1U << 31);
    uint32_t y_ordered = y_bits ^ (1U << 31);

    return (x_ordered > y_ordered) ? x : y;
}

double max(double x, double y) {
    uint64_t x_bits = to_bits(x);
    uint64_t y_bits = to_bits(y);

    // Handle NaN cases
    if (isnan(x_bits)) return y;
    if (isnan(y_bits)) return x;

    // Flip sign for correct comparison
    uint64_t x_ordered = x_bits ^ (1ULL << 63);
    uint64_t y_ordered = y_bits ^ (1ULL << 63);

    return (x_ordered > y_ordered) ? x : y;
}

float clamp(float x, float low, float high) {
    uint32_t x_bits = to_bits(x);
    uint32_t low_bits = to_bits(low);
    uint32_t high_bits = to_bits(high);

    // Handle NaN cases
    if (isnan(x_bits)) return low;
    if (isnan(low_bits)) return high;
    if (isnan(high_bits)) return low;

    // Flip sign for correct comparison
    uint32_t x_ordered = x_bits ^ (1U << 31);
    uint32_t low_ordered = low_bits ^ (1U << 31);
    uint32_t high_ordered = high_bits ^ (1U << 31);

    if (x_ordered < low_ordered) return low;
    if (x_ordered > high_ordered) return high;
    return x;
}

double clamp(double x, double low, double high) {
    uint64_t x_bits = to_bits(x);
    uint64_t low_bits = to_bits(low);
    uint64_t high_bits = to_bits(high);

    // Handle NaN cases
    if (isnan(x_bits)) return low;
    if (isnan(low_bits)) return high;
    if (isnan(high_bits)) return low;

    // Flip sign for correct comparison
    uint64_t x_ordered = x_bits ^ (1ULL << 63);
    uint64_t low_ordered = low_bits ^ (1ULL << 63);
    uint64_t high_ordered = high_bits ^ (1ULL << 63);

    if (x_ordered < low_ordered) return low;
    if (x_ordered > high_ordered) return high;
    return x;
}

// Task 4
bool isequal(float x, float y) {
    return x == y;
}

bool isequal(double x, double y) {
    return x == y;
}

bool isnearlyequal(float x, float y, float epsilon) {
    return absolute(x - y) <= epsilon;
}

bool isnearlyequal(double x, double y, double epsilon) {
    return absolute(x - y) <= epsilon;
}

bool less(float x, float y) {
    return x < y;
}

bool less(double x, double y) {
    return x < y;
}

bool nearlyless(float x, float y, float epsilon) {
    return (y - x) > epsilon;
}

bool nearlyless(double x, double y, double epsilon) {
    return (y - x) > epsilon;
}

bool greater(float x, float y) {
    return x > y;
}

bool greater(double x, double y) {
    return x > y;
}

bool nearlygreater(float x, float y, float epsilon) {
    return (x - y) > epsilon;
}

bool nearlygreater(double x, double y, double epsilon) {
    return (x - y) > epsilon;
}

void cheaksForTask6(){
    uint32_t num1 = 0b10011010100110010001100100111111;
    uint32_t num2 = 0b10010011001110011111011101000010;
    uint32_t num3 = 0b11001010100111000101111011000011;

    std::cout << to_float(num1) << std::endl;
    std::cout << to_float(num2) << std::endl;
    std::cout << to_float(num3) << std::endl;
    return;
}