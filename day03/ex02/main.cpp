#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include <iostream>
#include <time.h>

int main(void) {
	srand(time(0));
	FragTrap a("a");
	FragTrap b("b");
	FragTrap c;
	ScavTrap d("d");
	ScavTrap e("e");
	a.meleeAttack(b.name());
	b.takeDamage(a.melee());
	b.rangedAttack(c.name());
	c.takeDamage(b.ranged());
	b.vaulthunter_dot_exe(a.name());
	a.takeDamage(b.matk());
	c.vaulthunter_dot_exe(b.name());
	b.takeDamage(c.matk());
	b.vaulthunter_dot_exe(c.name());
	c.takeDamage(b.matk());
	a.vaulthunter_dot_exe(b.name());
	b.takeDamage(a.matk());
	a.beRepaired(12);
	d.challengeNewcomer(b.name());
	e.challengeNewcomer(c.name());
	d.challengeNewcomer(a.name());
	e.challengeNewcomer(d.name());
	d.rangedAttack(a.name());
	a.takeDamage(d.ranged());
	c.vaulthunter_dot_exe(e.name());
	e.takeDamage(c.matk());
	e.meleeAttack(d.name());
	d.takeDamage(e.melee());
	return (0);
}
