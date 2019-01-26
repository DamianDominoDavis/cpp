#ifndef NINJATRAP_CLASS_HPP
# define NINJATRAP_CLASS_HPP
# include "ClapTrap.class.hpp"

class NinjaTrap : public ClapTrap {
	int			_hp;
	int			_hpmax;
	int			_mp;
	int			_mpmax;
	int			_level;
	std::string	_name;
	int			_melee;
	int			_matk;
	int			_ranged;
	int			_armor;
public:
	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &src);
	~NinjaTrap(void);

	NinjaTrap&	operator=(NinjaTrap const &right);
	void		rangedAttack(const std::string &target) const;
	void		meleeAttack(const std::string &target) const;
	void		takeDamage(int amount);
	void		beRepaired(int amount);
	void		ninjaShoebox(const ClapTrap &target);
};

#endif
