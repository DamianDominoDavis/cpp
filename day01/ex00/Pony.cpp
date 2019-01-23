# include <string>
# include <iostream>
#include "Pony.hpp"

Pony::Pony(void) {
	std::cout << "Magical pony Uniquity says ";
}

Pony::~Pony(void) {
	std::cout << "\"Remember, kids: Solidarity is a Tool of the Occult!\""
		<< "\u2122" << std::endl;
}

void Pony::ponyOnTheHeap(void) {
	Pony once;
	(void)once;
}

void Pony::ponyOnTheStack(void) {
	Pony* twice = new Pony();
	delete twice;
}
