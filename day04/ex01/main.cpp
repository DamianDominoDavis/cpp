#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main(void) {
	Character* chr = new Character("chr");
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	Enemy* m = new SuperMutant();
	
	std::cout << *chr;
	chr->equip(pr);
	std::cout << *chr;
	while(b->getHP())
		chr->attack(b);
	
	chr->equip(pf);
	std::cout << *chr;
	while(chr->getAP() >= 8 && m && m->getHP())
		chr->attack(m);
	std::cout << *chr;
	return (0);
}
