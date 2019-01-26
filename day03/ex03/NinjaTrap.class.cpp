#include <iostream>
#include <cstdlib>
#include "NinjaTrap.class.hpp"

NinjaTrap::NinjaTrap(void): _hp(100), _hpmax(100), _mp(50), _mpmax(50),
	_level(1), _name("%"), _melee(20), _matk(15), _ranged(15),
	_armor(3) {
	std::cout << _name << " shh" << std::endl;
}
NinjaTrap::NinjaTrap(std::string name): _hp(100), _hpmax(100), _mp(50),
	_mpmax(50), _level(1), _name(name), _melee(20), _matk(15), _ranged(15),
	_armor(3) {
	std::cout << _name << " shh" << std::endl;
}
NinjaTrap::NinjaTrap(const NinjaTrap &f) {
	*this = f;
	std::cout << _name << " *dup*" << std::endl;
}
NinjaTrap::~NinjaTrap(void) {
	std::cout << _name << " *poof*" << std::endl;
}
NinjaTrap&	NinjaTrap::operator=(NinjaTrap const &f) {
	_hp = f.hp();
	_hpmax = f.hpmax();
	_mp = f.mp();
	_mpmax = f.mpmax();
	_level = f.level();
	_name = f.name();
	_melee = f.melee();
	_ranged = f.ranged();
	_armor = f.armor();
	_matk = f.matk();
	return (*this);
}

void	NinjaTrap::rangedAttack(const std::string &target) const {
	std::cout << _name << " snipes " << target << "! " << _ranged << "!"
		<< std::endl;
}
void	NinjaTrap::meleeAttack(const std::string &target) const
{
	std::cout << _name << " pounces on " << target << "! " << _melee << "!"
		<< std::endl;
}
void	NinjaTrap::takeDamage(int amount) {
	amount = std::max(1, amount - _armor);
	_hp = std::max(0, _hp - amount);
	std::cout << _name << " weakens " << amount << "! " << _hp << "/" << _hpmax
		<< std::endl;
	if (_hp == 0)
		std::cout << _name << " is no more." << std::endl;
}
void	NinjaTrap::beRepaired(int amount) {
	amount = std::min(_hpmax - _hp, amount);
	_hp += amount;
	std::cout << _name << " heals " << amount << "! " << _hp << "/" << _hpmax
		<< std::endl;
}

void	NinjaTrap::ninjaShoebox(const ClapTrap &target)
{
	static std::string phrases[] = {" smokebombs ", " hypnotizes ", " poisons "};

	if (_mp >= 25) {
		_mp -= 25;
		std::cout << _name << phrases[rand() % (sizeof(phrases) / sizeof(phrases[0]))]
			<< target.name() << std::endl;
	}
	else
		std::cout << _name << " must rest" << std::endl;
}
