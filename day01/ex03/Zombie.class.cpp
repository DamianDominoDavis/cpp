#include <string>
#include <iostream>
#include "Zombie.class.hpp"

const std::string Zombie::names[] = {"bastian", "bediah", "bert", "ddeus",
	"derick", "dolph", "fferson", "fflesby", "garth", "ginald"};
const std::string Zombie::types[] = {"ghuol", "lhic", "skleleton", "zmobie",
	"zobmie"};

Zombie::Zombie(void) {
	name = rname();
	type = rtype();
}

void Zombie::announce(void) {
	std::cout << name << " <" << type << ">: Gr";
	while (rand() % 2)
		std::cout << "r";
	while (rand() % 3)
		std::cout << "a";
	while (rand() % 2)
		std::cout << "h";
	while (rand() % 2)
		std::cout << "r";
	std::cout << std::endl;
}

std::string Zombie::rname(void) {
	return (names[rand() % (sizeof(names) / sizeof(names[0]))]);
}

std::string Zombie::rtype(void) {
	return (types[rand() % (sizeof(types) / sizeof(types[0]))]);
}
