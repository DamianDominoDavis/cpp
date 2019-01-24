#include <iostream>
#include "HumanB.class.hpp"

HumanB::HumanB(std::string s) : name(s) {}
		
void HumanB::setWeapon(Weapon& w) {
	wep = &w;
}

void HumanB::attack(void) {
	std::cout << name << " attacked with his " << wep->getType() << std::endl;
}
