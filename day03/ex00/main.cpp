#include <iostream>
#include <time.h>
#include "FragTrap.class.hpp"

int main(void) {
	srand(time(0));
	FragTrap a("a");
	FragTrap b("b");
	FragTrap c;
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
	std::cout << "NO CONTEST" << std::endl;
	return (0);
}
