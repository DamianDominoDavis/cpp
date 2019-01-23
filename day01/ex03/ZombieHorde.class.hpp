#ifndef ZOMBIEHORDE_CLASS_HPP
# define ZOMBIEHORDE_CLASS_HPP
# include <string>
# include "Zombie.class.hpp"

class ZombieHorde {
	private:
		int n;
		Zombie *zombies;
		
	public:
		ZombieHorde(int n);
		~ZombieHorde(void);

		void announce(void);
};

#endif
