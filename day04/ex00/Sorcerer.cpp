#include <string>
#include <ostream>
#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer(void) {}

Sorcerer::Sorcerer(std::string n, std::string t) : _name(n), _title(t) {
	std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer& s) {
	*this = s;
	std::cout << _name << ", " << _title << ", is duplicated !" << std::endl;
}

Sorcerer::~Sorcerer(void) {
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer&		Sorcerer::operator= (const Sorcerer& s) {
	_name = s.name();
	_title = s.title();
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const Sorcerer& s) {
	o << "I am " << s.name() << ", " << s.title() << ", and I like ponies !" << std::endl;
	return (o);
}

std::string		Sorcerer::name(void) const { return (_name); }
std::string		Sorcerer::title(void) const { return (_title); }

void			Sorcerer::polymorph(const Victim& v) const {
	v.getPolymorphed();
}
