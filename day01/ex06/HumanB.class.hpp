#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP
# include <string>
# include "Weapon.class.hpp"

class HumanB {
	private:
		std::string name;
		Weapon& wep;

	public:
		HumanB(std::string s);
		void setWeapon(Weapon& w);
		void attack(void);
};

#endif
