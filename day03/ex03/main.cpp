#include <iostream>
#include <time.h>
#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "NinjaTrap.class.hpp"

int main(void) {
	srand(time(0));
	FragTrap a("Avian");
	FragTrap b("Floran");
	FragTrap c;
	ScavTrap d("Apex");
	ScavTrap e("Novakid");
	ClapTrap f("Hylotl");
	NinjaTrap g("Glitch");
	
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

	g.ninjaShoebox(b);
	g.ninjaShoebox(d);
	g.ninjaShoebox(g);
	g.ninjaShoebox(f);
	g.meleeAttack(a.name());
	a.takeDamage(g.melee());
	b.rangedAttack(g.name());
	g.takeDamage(b.ranged());
	g.rangedAttack(c.name());
	c.takeDamage(g.ranged());

	std::cout << a.name() << " has " << a.hp() << " health left." << std::endl;
	std::cout << b.name() << " has " << b.hp() << " health left." << std::endl;
	std::cout << c.name() << " has " << c.hp() << " health left." << std::endl;
	std::cout << d.name() << " has " << d.hp() << " health left." << std::endl;
	std::cout << e.name() << " has " << e.hp() << " health left." << std::endl;
	std::cout << g.name() << " has " << g.hp() << " health left." << std::endl;
	std::cout << f.name() << " has " << f.hp() << " health left." << std::endl;
}
