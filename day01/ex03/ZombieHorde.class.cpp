#include <string>
#include <iostream>
#include "ZombieHorde.class.hpp"

ZombieHorde::ZombieHorde(int x) {
	n = x;
	zombies = new Zombie[n];
}

ZombieHorde::~ZombieHorde() {
	delete [] zombies;
}

void ZombieHorde::announce(void) {
	std::cout << "announcing..." << std::endl;
	for (int i = 0; i < n; i++)
		zombies[i].announce();
}
