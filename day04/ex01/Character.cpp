#include <iostream>
#include "Character.hpp"

Character::Character(void) : _name("Human"), _ap(40), _weapon(NULL) {}
Character::Character(const std::string & name) : _name(name), _ap(40), _weapon(NULL) {}
Character::Character(const Character & character) {
	*this = character;
}
Character::~Character(void) {}

Character&		Character::operator= (const Character & character) {
	_name = character.getName();
	_ap = character.getAP();
	_weapon = character.getWeapon();
	return (*this);
}

void		Character::recoverAP(void) {
	_ap = std::min(40, _ap + 10);
}

void		Character::equip(AWeapon *weapon) {
	_weapon = weapon;
}

void		Character::attack(Enemy *enemy) {
	if (_weapon && _ap >= _weapon->getAPCost()) {
		_ap -= _weapon->getAPCost();
		std::cout << _name << " attacks " << enemy->getType() << " with a "
			<< _weapon->getName() << std::endl;
		_weapon->attack();
		enemy->takeDamage(_weapon->getDamage());
		if (!enemy->getHP())
			delete enemy;
	}
}

std::string		Character::getName(void) const { return _name; }
int				Character::getAP(void) const { return _ap; }
AWeapon*		Character::getWeapon(void) const { return _weapon; }

std::ostream&	operator<<(std::ostream&o, const Character & character) {
	if (character.getWeapon())
		return (o << character.getName() << " has " << character.getAP()
			<< " AP and wields a " << character.getWeapon()->getName()
			<< std::endl);
	else
		return (o << character.getName() << " has " << character.getAP()
			<< " AP and is unarmed" << std::endl);
}
