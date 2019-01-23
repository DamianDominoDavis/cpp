#include <string>
#include <iostream>
#include "Zombie.class.hpp"

const std::string Zombie::names[] = {"bastian", "bediah", "bert", "ddeus",
	"derick", "dolph", "fferson", "fflesby", "garth", "ginald"};
const std::string Zombie::types[] = {"ghuol", "lhic", "skleleton", "zmobie",
	"zobmie"};

std::string Zombie::rname(void) {
	return (names[rand() % (sizeof(names) / sizeof(names[0]))]);
}

std::string Zombie::rtype(void) {
	return (types[rand() % (sizeof(types) / sizeof(types[0]))]);
}

Zombie::Zombie(std::string n, std::string t) {
	name = n;
	type = t;
	announce();
}

void Zombie::announce(void) const {
	std::cout << "(" << name << " <" << type << ">) Grrahr" << std::endl;
}
