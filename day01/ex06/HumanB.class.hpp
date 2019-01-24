#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP
# include <string>
# include "Weapon.class.hpp"

class HumanB {
	private:
		std::string name;
		Weapon* wep;

	public:
		HumanB(std::string s);
		void setWeapon(Weapon w);
		void attack(void);
};

#endif

// int main()
// {
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 	}
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanB jim("Jim");
// 		jim.setWeapon(club);
// 		jim.attack();
// 		club.setType("some other type of club");
// 		jim.attack();
// 	}
// }
