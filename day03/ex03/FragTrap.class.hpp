#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP
# include "ClapTrap.class.hpp"

class FragTrap : public ClapTrap {
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
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &src);
	~FragTrap(void);

	FragTrap&	operator=(FragTrap const &right);
	void		rangedAttack(const std::string &target) const;
	void		meleeAttack(const std::string &target) const;
	void		takeDamage(int amount);
	void		beRepaired(int amount);
	void		vaulthunter_dot_exe(const std::string &target);
};

#endif
