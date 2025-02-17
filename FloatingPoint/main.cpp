//#include <bit>                                        // C++20 header for bit_cast
//#include <inttypes.h>                                 // C header for integers of fixed width
#include <cinttypes>                                    // C++ header for integers of fixed width

uint32_t to_bytes(float const value)
{
    // *((uint32_t const*)(&value))                     // C implementation
    // std::bit_cast<uint32_t>(value)                   // C++20 implementation
    return *(reinterpret_cast<uint32_t const*>(&value));// C++ implementation
}

float to_float(uint32_t const value)
{
    // *((float const*)(&value))                        // C implementation
    // std::bit_cast<float>(value)                      // C++20 implementation
    return *(reinterpret_cast<float const*>(&value));   // C++ implementation
}
