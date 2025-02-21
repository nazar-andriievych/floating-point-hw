#pragma once

#pragma once

#include <cstdint>

enum Classify {
    ZERO,
    NORMAL,
    SUBNORMAL,
    INFINITE,
    NaN
};

// Task 1
uint32_t to_bits(float value);
float to_float(uint32_t value);
uint64_t to_bits(double value);
double to_double(uint64_t value);

// Extra functions
uint32_t get_sign(uint32_t value);
uint64_t get_sign(uint64_t value);
uint32_t get_exponent(uint32_t value);
uint64_t get_exponent(uint64_t value);
uint32_t get_mantissa(uint32_t value);
uint64_t get_mantissa(uint64_t value);

// Task 2
bool isfinite(float x);
bool isfinite(double x);
bool isinf(float x);
bool isinf(double x);
bool isposinf(float x);
bool isposinf(double x);
bool isneginf(float x);
bool isneginf(double x);
bool iszero(float x);
bool iszero(double x);
bool isposzero(float x);
bool isposzero(double x);
bool isnegzero(float x);
bool isnegzero(double x);
bool isnan(float x);
bool isnan(double x);
bool isnormal(float x);
bool isnormal(double x);
bool issubnormal(float x);
bool issubnormal(double x);
bool issigned(float x);
bool issigned(double x);
Classify classify(float x);
Classify classify(double x);

// Task 3
float absolute(float x);
double absolute(double x);
float min(float x, float y);
double min(double x, double y);
float max(float x, float y);
double max(double x, double y);
float clamp(float x, float low, float high);
double clamp(double x, double low, double high);

// Task 4
bool isequal(float x, float y);
bool isequal(double x, double y);
bool isnearlyequal(float x, float y, float epsilon);
bool isnearlyequal(double x, double y, double epsilon);
bool less(float x, float y);
bool less(double x, double y);
bool nearlyless(float x, float y, float epsilon);
bool nearlyless(double x, double y, double epsilon);
bool greater(float x, float y);
bool greater(double x, double y);
bool nearlygreater(float x, float y, float epsilon);
bool nearlygreater(double x, double y, double epsilon);

// Task 6
void cheaksForTask6();