#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {}
PowerFist::PowerFist(const PowerFist &weapon) {
	*this = weapon;
}
PowerFist::~PowerFist(void) {}
PowerFist&	PowerFist::operator=(const PowerFist &weapon) {
	_name = weapon.getName();
	_damage = weapon.getDamage();
	_apcost = weapon.getAPCost();
	return (*this);
}

void		PowerFist::attack(void) const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
