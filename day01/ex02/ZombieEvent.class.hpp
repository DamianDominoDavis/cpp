#ifndef ZOMBIEEVENT_CLASS_HPP
# define ZOMBIEEVENT_CLASS_HPP
# include <string>
# include "Zombie.class.hpp"

class ZombieEvent {
	public:
		static std::string type;

		static void setZombieType(std::string t);
		static Zombie* randomChump(std::string name);
};

#endif
