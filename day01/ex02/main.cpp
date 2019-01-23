#include <cstdlib>
#include <time.h>
#include "ZombieEvent.class.hpp"

int main(void)
{
	std::srand (time(NULL));
	ZombieEvent::setZombieType(Zombie::rtype());
	Zombie *z = ZombieEvent::randomChump(Zombie::rname());
	z->announce();
	delete z;
	return (0);
}
