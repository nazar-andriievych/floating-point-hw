#include "functions.h"
#include <iostream>

int main() {
	cheaksForTask6();

	double d = 1.5;
	uint64_t bits = to_bits(d);
	std::cout << bits << " " << get_mantissa(bits);
	return 0;
}