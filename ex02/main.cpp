#include "theRealThing.hpp"

#include <iostream>
#include <iomanip>

void test(Base *p) {
	std::cout << "identifiy(Base *): ";
	identify(p);

	std::cout << "identifiy(Base &): ";
	identify(*p);
}

int main(void) {
	for (int i = 0; i < 20; ++i) {
		std::cout << "================= TEST " << std::setw(2) << i << " =================" << std::endl;
		Base *p = generate();

		test(p);

		delete p;
	}

	return 0;
}
