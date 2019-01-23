#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP
# include <string>

class Zombie {
	private:
		std::string name;
		std::string type;

	public:
		static const std::string names[];
		static const std::string types[];
		static std::string rtype(void);
		static std::string rname(void);
		Zombie(void);
		void announce(void);
};

#endif
