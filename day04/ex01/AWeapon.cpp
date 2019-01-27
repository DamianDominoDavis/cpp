#include "AWeapon.hpp"

AWeapon::AWeapon(void) {}
AWeapon::AWeapon(const std::string & name, int apcost, int damage): _name(name), _apcost(apcost), _damage(damage) {}
AWeapon::AWeapon(const AWeapon &weapon) {
	*this = weapon;
}
AWeapon::~AWeapon(void) {}

std::string		AWeapon::getName(void) const { return _name; }
int				AWeapon::getAPCost(void) const { return _apcost; }
int				AWeapon::getDamage(void) const { return _damage; }

AWeapon		& AWeapon::operator=(const AWeapon & right) {
	_name = right.getName();
	_apcost = right.getAPCost();
	_damage = right.getDamage();
	return (*this);
}
