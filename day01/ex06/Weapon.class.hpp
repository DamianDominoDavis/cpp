#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP
# include <string>

class Weapon {
private:
	std::string	type;
public:
	//Weapon(void);
	Weapon(std::string s);
	void setType(std::string ntype);
	std::string getType(void) const;
};

#endif
