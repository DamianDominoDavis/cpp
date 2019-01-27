#include "AMateria.hpp"

AMateria::AMateria(void) {}
AMateria::AMateria(const std::string &type) {
	_xp = 0;
	_type = type;
}
AMateria::AMateria(const AMateria &src) {
	*this = src;
}
AMateria::~AMateria(void) {}
AMateria& AMateria::operator= (const AMateria &rhs) {
	if (this != &rhs) {
		_xp = rhs._xp;
		_type = rhs._type;
	}
	return (*this);
}

const std::string& AMateria::getType(void) const { return (_type); }
unsigned int    AMateria::getXP(void) const { return (_xp); }
