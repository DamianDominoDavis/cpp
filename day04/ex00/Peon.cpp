#include <string>
#include <ostream>
#include <iostream>
#include "Peon.hpp"

Peon::Peon(void) {
	std::cout << "Zog zog!" << std::endl;
}

Peon::Peon(std::string n) : Victim(n) {
	std::cout << "Zog zog!" << std::endl;
}

Peon::Peon(const Peon& v) {
	*this = v;
	std::cout << "zzzzzzg..." << std::endl;
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}

// Peon&		Peon::operator= (const Peon& p) {
// 	_name = p.name();
// 	return (*this);
// }

// std::ostream&	operator<<(std::ostream& o, const Peon& p) {
// 	o << "I'm " << p.name() << ", and I like otters !" << std::endl;
// 	return (o);
// }

// std::string		Peon::name(void) const { return (_name); }

// void			Peon::getPolymorphed(void) const {
// 	std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
// }
