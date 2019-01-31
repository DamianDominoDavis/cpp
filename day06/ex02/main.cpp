#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify_from_pointer(Base *b) {
	if (dynamic_cast<A*>(b))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(b))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(b))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &b) {
	try {
		(void)dynamic_cast<A&>(b);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<B&>(b);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<C&>(b);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast &e) {}
}

Base *rbase(void) {
	switch (rand() % 3) {
		case 2: return new A();
		case 1: return new B();
		default: return new C();
	}
}

int main(void) {
	srand(time(0));
	Base *b = rbase();
	Base& r = *b;
	identify_from_pointer(b);
	identify_from_reference(r);
	delete b;
	return 0;
}
