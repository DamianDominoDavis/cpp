#include <iostream>
#include "Scalar.hpp"

int main(int c, char const **v) {
	if (c == 2) {
		Scalar a(v[1]);
		std::cout << a;
	}
	return (0);
}
