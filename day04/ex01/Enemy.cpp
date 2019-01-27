#include "Enemy.hpp"

Enemy::Enemy(void) : _hp(0), _type("Enemy") {}
Enemy::Enemy(int hp, const std::string & type) : _hp(hp), _type(type) {}
Enemy::Enemy(Enemy const &enemy) {
	*this = enemy;
}
Enemy::~Enemy(void) {}
Enemy&	Enemy::operator=(Enemy const &enemy) {
	_hp = enemy.getHP();
	_type = enemy.getType();
	return (*this);
}

std::string		Enemy::getType(void) const { return _type; }
int				Enemy::getHP(void) const { return _hp; }

void			Enemy::takeDamage(int damage) {
	if (damage >= 0)
		_hp = std::max(0, _hp - damage);
}
