#include <cstdlib>
#include <time.h>
#include "ZombieHorde.class.hpp"

int main(void)
{
	srand(time(NULL));
	ZombieHorde *h = new ZombieHorde(5);
	h->announce();
	delete h;
	return (0);
}
