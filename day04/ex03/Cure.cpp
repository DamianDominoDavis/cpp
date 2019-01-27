#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}
Cure::Cure(const Cure &c) {
	*this = c;
}
Cure& Cure::operator= (const Cure &c) {
	if (this != &c)
		_xp = c._xp;
	return (*this);
}
Cure::~Cure(void) {}

AMateria* Cure::clone(void) const {
	return (new Cure());
}
void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
