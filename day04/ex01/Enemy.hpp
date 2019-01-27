#include <string>
#ifndef ENEMY_HPP
# define ENEMY_HPP

class Enemy
{
public:
	Enemy(int hp, const std::string &type);
	Enemy(Enemy const & enemy);
	Enemy(void);
	virtual ~Enemy(void);

	Enemy	&operator=(Enemy const &enemy);

	std::string		getType(void) const;
	int				getHP(void) const;
	virtual void	takeDamage(int damage);

protected:
	int				_hp;
	std::string		_type;
};

#endif
