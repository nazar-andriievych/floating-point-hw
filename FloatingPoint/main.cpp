#include <bit>
#include <iostream>

enum FpClassify {
    FP_ZERO,
    FP_NORMAL,
    FP_SUBNORMAL,
    FP_INFINITE,
    FP_NAN
};

// Task1
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

// Task2
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

FpClassify fpclassify(float x) {
    uint32_t bits = to_bits(x);
    uint32_t exponent = get_exponent(bits);
    uint32_t mantissa = get_mantissa(bits);

    if (exponent == 0xFF) {
        return (mantissa == 0) ? FpClassify::FP_INFINITE : FpClassify::FP_NAN;
    }
    if (exponent == 0) {
        return (mantissa == 0) ? FpClassify::FP_ZERO : FpClassify::FP_SUBNORMAL;
    }
    return (mantissa == 0) ? FpClassify::FP_NORMAL : FpClassify::FP_NORMAL;
}

FpClassify fpclassify(double x) {
    uint64_t bits = to_bits(x);
    uint64_t exponent = get_exponent(bits);
    uint64_t mantissa = get_mantissa(bits);

    if (exponent == 0x7FF) {
        return (mantissa == 0) ? FpClassify::FP_INFINITE : FpClassify::FP_NAN;
    }
    if (exponent == 0) {
        return (mantissa == 0) ? FpClassify::FP_ZERO : FpClassify::FP_SUBNORMAL;
    }
    return FpClassify::FP_NORMAL;
}

// Task3
float abs(float x) {
    uint32_t bits = to_bits(x);

    return to_float((bits << 1) >> 1);
}

double abs(double x) {
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