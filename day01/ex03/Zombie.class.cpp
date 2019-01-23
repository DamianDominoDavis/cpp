#include <string>
#include <iostream>
#include "Zombie.class.hpp"

const std::string Zombie::names[] = {"bastian", "bediah", "bert", "ddeus",
	"derick", "dolph", "fferson", "fflesby", "garth", "ginald"};
const std::string Zombie::types[] = {"ghuol", "lhic", "skleleton", "zmobie",
	"zobmie"};

Zombie::Zombie(std::string n, std::string t) {
	this->name = n;
	this->type = t;
	this->announce();
}

Zombie::Zombie(void) {
	this->name = rname();
	this->type = rtype();
}

void Zombie::announce(void) {
	std::cout << "(" << name << " <" << type << ">) announce" << std::endl;
}

std::string Zombie::rname(void) {
	return (names[std::rand() % (sizeof(names) / sizeof(names[0]))]);
}

std::string Zombie::rtype(void) {
	return (types[std::rand() % (sizeof(types) / sizeof(types[0]))]);
}
