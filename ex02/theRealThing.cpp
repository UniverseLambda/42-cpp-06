#include "theRealThing.hpp"

#include <iostream>

#include <fstream>

Base::~Base() {}

Base *generate(void) {
	unsigned int val;

	{
		std::ifstream in("/dev/urandom", std::ios_base::in | std::ios_base::binary);

		in.read(reinterpret_cast<char *>(&val), sizeof(unsigned int));
	}

	val %= 3;

	if (val == 0) {
		return new A();
	} else if (val == 1) {
		return new B();
	} else {
		return new C();
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "juan." << std::endl;
	}
}

template<typename _ChildType>
bool tryRefCast(Base &p) {
	try {
		_ChildType &_tmp = dynamic_cast<_ChildType &>(p);

		(void)_tmp;
		return true;
	} catch (...) {
	}
	return false;
}

void identify(Base &p) {
	if (tryRefCast<A>(p)) {
		std::cout << "A" << std::endl;
		return;
	}

	if (tryRefCast<B>(p)) {
		std::cout << "B" << std::endl;
		return;
	}

	if (tryRefCast<C>(p)) {
		std::cout << "C" << std::endl;
		return;
	}

	std::cout << "man." << std::endl;
}
