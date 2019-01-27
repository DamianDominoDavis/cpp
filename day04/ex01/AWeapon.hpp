#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <string>

class AWeapon {
private:
	std::string	_name;
	int			_apcost;
	int			_damage;
public:
	AWeapon(void);
	AWeapon(const std::string & name, int apcost, int damage);
	AWeapon(const AWeapon &weapon);
	virtual ~AWeapon(void);
	AWeapon&	operator= (const AWeapon & right);

	std::string	getName(void) const;
	int			getAPCost(void) const;
	int			getDamage(void) const;

	virtual void attack(void) const = 0;
};

#endif
