#include <iostream>
#include <cstdlib>
#include "ScavTrap.class.hpp"

ScavTrap::ScavTrap(void): _hp(100), _hpmax(100), _mp(50), _mpmax(50),
	_level(1), _name("DEFAULT"), _melee(20), _matk(15), _ranged(15),
	_armor(3) {
	std::cout << _name << " CREAUUUUGH" << std::endl;
}
ScavTrap::ScavTrap(std::string name): _hp(100), _hpmax(100), _mp(50),
	_mpmax(50), _level(1), _name(name), _melee(20), _matk(15), _ranged(15),
	_armor(3) {
	std::cout << _name << " CRRRRRREAH" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &f) {
	*this = f;
	std::cout << _name << " COPOPAAA" << std::endl;
}
ScavTrap::~ScavTrap(void) {
	std::cout << _name << " DSSSTRRR" << std::endl;
}
ScavTrap&	ScavTrap::operator=(ScavTrap const &f) {
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

void	ScavTrap::rangedAttack(const std::string &target) const {
	std::cout << _name << " GOES LONG ON " << target << "! " << _ranged << "!"
		<< std::endl;
}
void	ScavTrap::meleeAttack(const std::string &target) const
{
	std::cout << _name << " GOES HAM ON " << target << "! " << _melee << "!"
		<< std::endl;
}
void	ScavTrap::takeDamage(int amount) {
	amount = std::max(1, amount - _armor);
	_hp = std::max(0, _hp - amount);
	std::cout << _name << " SUFFERS " << amount << "! " << _hp << "/" << _hpmax
		<< std::endl;
	if (_hp == 0)
		std::cout << _name << " IS DEAD!" << std::endl;
}
void	ScavTrap::beRepaired(int amount) {
	amount = std::min(_hpmax - _hp, amount);
	_hp += amount;
	std::cout << _name << " REVIVES " << amount << "! " << _hp << "/" << _hpmax
		<< std::endl;
}

void	ScavTrap::challengeNewcomer(const std::string &target)
{
	static std::string phrases[] = {" NYYANGH ", " HRR! HNNAAARR! ", " RAGH! MEOWOWOW! "};

	if (_mp >= 25) {
		_mp -= 25;
		std::cout << _name << phrases[rand() % (sizeof(phrases) / sizeof(phrases[0]))]
			<< target << " is afraid and hurt." << std::endl;
	}
	else
		std::cout << _name << " CAN'T MAKE THE MAGIC" << std::endl;
}
