#include <iostream>
#include <cstdlib>
#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap(void): _hp(100), _hpmax(100), _mp(100), _mpmax(100),
	_level(1), _name("Clap"), _melee(10), _matk(10), _ranged(10),
	_armor(5) {
	std::cout << _name << " trapped" << std::endl;
}
ClapTrap::ClapTrap(std::string name): _hp(100), _hpmax(100), _mp(100),
	_mpmax(100), _level(1), _name(name), _melee(10), _matk(10), _ranged(10),
	_armor(5) {
	std::cout << _name << " trapped" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &f) {
	*this = f;
	std::cout << _name << " clapped" << std::endl;
}
ClapTrap::~ClapTrap(void) {
	std::cout << _name << " untrapped" << std::endl;
}
ClapTrap&	ClapTrap::operator=(ClapTrap const &f) {
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

int	ClapTrap::hp(void) const { return (_hp); }
int	ClapTrap::hpmax(void) const { return (_hpmax); }
int	ClapTrap::mp(void) const { return (_mp); }
int	ClapTrap::mpmax(void) const { return (_mpmax); }
int	ClapTrap::level(void) const { return (_level); }
std::string		ClapTrap::name(void) const { return (_name); }
int	ClapTrap::melee(void) const { return (_melee); }
int	ClapTrap::ranged(void) const { return (_ranged); }
int	ClapTrap::armor(void) const { return (_armor); }
int	ClapTrap::matk(void) const { return (_matk); }

void	ClapTrap::rangedAttack(const std::string &target) const {
	std::cout << _name << " (reluctantly) throws rocks " << target << " for " << _ranged << "!"
		<< std::endl;
}
void	ClapTrap::meleeAttack(const std::string &target) const
{
	std::cout << _name << " (reluctantly) flails " << target << " for " << _melee << "!"
		<< std::endl;
}
void	ClapTrap::takeDamage(int amount) {
	amount = std::max(1, amount - _armor);
	_hp = std::max(0, _hp - amount);
	std::cout << _name << " takes " << amount << "! " << _hp << "/" << _hpmax
		<< std::endl;
	if (_hp == 0)
		std::cout << _name << " isn't moving." << std::endl;
}
void	ClapTrap::beRepaired(int amount) {
	amount = std::min(_hpmax - _hp, amount);
	_hp += amount;
	std::cout << _name << " repairs " << amount << "! " << _hp << "/" << _hpmax
		<< std::endl;
}
