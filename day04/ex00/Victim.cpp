#include <string>
#include <ostream>
#include <iostream>
#include "Victim.hpp"

Victim::Victim(void) : _name("Dude") {
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::Victim(std::string n) : _name(n) {
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::Victim(const Victim& v) {
	*this = v;
	std::cout << _name << ", is duplicated !" << std::endl;
}

Victim::~Victim(void) {
	std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
}

Victim&		Victim::operator= (const Victim& v) {
	_name = v.name();
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const Victim& v) {
	o << "I'm " << v.name() << ", and I like otters !" << std::endl;
	return (o);
}

std::string		Victim::name(void) const { return (_name); }

void			Victim::getPolymorphed(void) const {
	std::cout << _name << " has been turned into a pink pony !" << std::endl;
}
