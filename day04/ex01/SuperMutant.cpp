#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy::Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}
SuperMutant::SuperMutant(const SuperMutant &enemy) {
	*this = enemy;
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}
SuperMutant::~SuperMutant(void) {
	std::cout << "Aaargh ..." << std::endl;
}
SuperMutant&	SuperMutant::operator=(const SuperMutant &enemy) {
	_hp = enemy.getHP();
	_type = enemy.getType();
	return (*this);
}

void			SuperMutant::takeDamage(int damage) {
	Enemy::takeDamage(damage - 3);
}
