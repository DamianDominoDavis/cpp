#include <iostream>
#include <cstdlib>
#include "FragTrap.class.hpp"

FragTrap::FragTrap(void): _hp(100), _hpmax(100), _mp(100), _mpmax(100),
	_level(1), _name("Frag"), _melee(30), _matk(25), _ranged(20),
	_armor(5) {
	std::cout << _name << " created" << std::endl;
}
FragTrap::FragTrap(std::string name): _hp(100), _hpmax(100), _mp(100),
	_mpmax(100), _level(1), _name(name), _melee(30), _matk(25), _ranged(20),
	_armor(5) {
	std::cout << _name << " created" << std::endl;
}
FragTrap::FragTrap(const FragTrap &f) {
	*this = f;
	std::cout << _name << " copied" << std::endl;
}
FragTrap::~FragTrap(void) {
	std::cout << _name << " destroyed" << std::endl;
}
FragTrap&	FragTrap::operator=(FragTrap const &f) {
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

void	FragTrap::rangedAttack(const std::string &target) const {
	std::cout << _name << " range attacks " << target << " for " << _ranged << "!"
		<< std::endl;
}
void	FragTrap::meleeAttack(const std::string &target) const
{
	std::cout << _name << " melee attacks " << target << " for " << _melee << "!"
		<< std::endl;
}
void	FragTrap::takeDamage(int amount) {
	amount = std::max(1, amount - _armor);
	_hp = std::max(0, _hp - amount);
	std::cout << _name << " takes " << amount << "! " << _hp << "/" << _hpmax
		<< std::endl;
	if (_hp == 0)
		std::cout << _name << " is dead!" << std::endl;
}
void	FragTrap::beRepaired(int amount) {
	amount = std::min(_hpmax - _hp, amount);
	_hp += amount;
	std::cout << _name << " regains " << amount << "! " << _hp << "/" << _hpmax
		<< std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	static std::string phrases[] = {" verbs ", " spooks ", " swears "};

	if (_mp >= 25) {
		_mp -= 25;
		std::cout << _name << phrases[rand() % (sizeof(phrases) / sizeof(phrases[0]))]
			<< "at " << target << "!" << std::endl;
	}
	else
		std::cout << _name << " is out of MP." << std::endl;
}
