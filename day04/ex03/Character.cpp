#include "Character.hpp"

Character::Character(void) {}
Character::Character(const std::string &name) {
	_name = name;
	_n_index = 0;
	for (int i = 0; i < 4; i += 1)
		_inventory[i] = NULL;
}
Character::Character(const Character &a) {
	*this = a;
}
Character& Character::operator= (const Character &a) {
	if (this != &a) {
		_name = a._name;
		_n_index = a._n_index;
		for (int i = 0; i < 4; i += 1)
			_inventory[i] = a._inventory[i]->clone();
	}
	return (*this);
}
Character::~Character(void) {}

const std::string& Character::getName(void) const { return (_name); }

void Character::equip(AMateria *m) {
	if (_n_index < 3)
		_inventory[_n_index++] = m;
}
void Character::unequip(int idx) {
	if (idx >= 0 && idx < _n_index) {
		_inventory[idx] = NULL;
		_n_index--;
	}
}
void Character::use(int idx, ICharacter &target) {
	if (idx < _n_index)
		_inventory[idx]->use(target);
}
