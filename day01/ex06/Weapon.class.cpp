#include <string>
#include "Weapon.class.hpp"

Weapon Weapon::W = Weapon();

Weapon::Weapon(void) : type("") {}
Weapon::Weapon(std::string s) : type(s) {}

void Weapon::setType(std::string ntype) {
	type = ntype;
}

std::string Weapon::getType(void) const {
	return (type);
}
