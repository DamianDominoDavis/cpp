#include <string>
#include "ZombieEvent.class.hpp"

std::string ZombieEvent::type = "none";

void ZombieEvent::setZombieType(std::string t) {
	ZombieEvent::type = t;
}

Zombie* ZombieEvent::randomChump(std::string name) {
	return (new Zombie(name, ZombieEvent::type));
}
