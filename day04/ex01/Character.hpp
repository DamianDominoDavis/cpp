#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "AWeapon.hpp"
# include "Enemy.hpp"
# include <string>

class Character {
private:
	std::string		_name;
	int				_ap;
	AWeapon			*_weapon;
public:
	Character(void);
	Character(const Character &character);
	Character(const std::string &name);
	~Character(void);

	Character&operator=(const Character &character);

	void			recoverAP(void);
	void			equip(AWeapon* weapon);
	void			attack(Enemy* enemy);
	std::string		getName(void) const;
	int				getAP(void) const;
	AWeapon*		getWeapon(void) const;
};

std::ostream&	operator<<(std::ostream&o, const Character &character);

#endif
