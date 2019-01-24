#include <iostream>
#include "HumanA.class.hpp"

HumanA::HumanA(std::string s, Weapon& w) : name(s), wep(w) {}
		
void HumanA::setWeapon(Weapon& w) {
	wep = w;
}

void HumanA::attack(void) {
	std::cout << name << " attacked with his " << wep.getType() << std::endl;
}
