#include <iostream>
#include "HumanB.class.hpp"

HumanB::HumanB(std::string s) {
	name = s;
}
		
void HumanB::setWeapon(Weapon w) {
	wep = &w;
}

void HumanB::attack(void) {
	std::cout << name << " attacked with his " << wep->getType() << std::endl;
}

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
