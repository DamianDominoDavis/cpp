#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {}
PlasmaRifle::PlasmaRifle(PlasmaRifle const & weapon) {
	*this = weapon;
}
PlasmaRifle::~PlasmaRifle(void) {}
PlasmaRifle&	PlasmaRifle::operator=(const PlasmaRifle & weapon) {
	_name = weapon.getName();
	_damage = weapon.getDamage();
	_apcost = weapon.getAPCost();
	return (*this);
}

void		PlasmaRifle::attack(void) const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
