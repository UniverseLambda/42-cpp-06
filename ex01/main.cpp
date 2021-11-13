#include "serializer.hpp"

#include <iostream>
#include <iomanip>

void printDataContent(std::string varName, const Data &dta) {
	std::cout << varName << ".myBeautifulString:" << std::setw(15 - varName.size()) << " " << dta.myBeautifulString << std::endl;
	std::cout << varName << ".someRandomNumber: " << std::setw(15 - varName.size()) << " " << dta.someRandomNumber << std::endl;
}

int main(void) {
	Data dta = { "BONCHOUUUUUUR", 42 };
	Data *ptr = &dta;
	uintptr_t raw = serialize(ptr);
	Data *resultPtr = deserialize(raw);

	printDataContent("dta", dta);
	std::cout << "ptr value:                        " << ptr << std::endl;
	std::cout << "raw value:                        " << raw << " (in hexadecimal: 0x" << std::hex << raw << ")" << std::dec << std::endl;
	std::cout << "resultPtr value:                  " << resultPtr << std::endl;
	printDataContent("*(resultPtr)", (*resultPtr));

	return 0;
}
