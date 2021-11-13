#pragma once

// Huh... C++11
// #include <cstdint>

// C99, SO WE CAN'T USE IT (NO C AUTHORIZED IN C++ PROJECT). WTF 42?!
// #include <stdint.h>

#include <string>

typedef std::string Data ;
typedef unsigned long uintptr_t;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);
