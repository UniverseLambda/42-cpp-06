#include "serializer.hpp"

#include <iostream>

int main(void) {
	Data dta = "BONCHOUUUUUUR";
	Data *ptr = &dta;
	uintptr_t raw = serialize(ptr);
	Data *resultPtr = deserialize(raw);

	std::cout << "dta value:          " << dta << std::endl;
	std::cout << "ptr value:          " << ptr << std::endl;
	std::cout << "raw value:          " << raw << " (in hexadecimal: 0x" << std::hex << raw << ")" << std::endl;
	std::cout << "resultPtr value:    " << resultPtr << std::endl;
	std::cout << "*(resultPtr) value: " << (*resultPtr) << std::endl;

	return 0;
}
