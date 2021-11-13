#pragma once

// Huh... C++11
// #include <cstdint>

// C99, SO WE CAN'T USE IT (NO C AUTHORIZED IN C++ PROJECT). WTF 42?!
// #include <stdint.h>

#include <string>

typedef unsigned long uintptr_t;

/*
 * For the correctors, this is not a class, it's data structure (aka aggregate)
 * as asked by the subject. So it does not have to be canonical, as this does
 * not apply in this case.
 */
struct Data {
	std::string myBeautifulString;
	int someRandomNumber;
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);
