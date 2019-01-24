#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP
# include <string>
# include "Weapon.class.hpp"

class HumanA {
	private:
		std::string name;
		Weapon& wep;

	public:
		HumanA(std::string s, Weapon& w);
		void setWeapon(Weapon& w);
		void attack(void);
};

#endif
