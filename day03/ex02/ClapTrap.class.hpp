#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP
# include <string>

class ClapTrap {
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
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap(void);

	ClapTrap&	operator=(ClapTrap const &right);

	int			hp(void) const;
	int			hpmax(void) const;
	int			mp(void) const;
	int			mpmax(void) const;
	int			level(void) const;
	std::string	name(void) const;
	int			melee(void) const;
	int			matk(void) const;
	int			ranged(void) const;
	int			armor(void) const;

	void		rangedAttack(const std::string &target) const;
	void		meleeAttack(const std::string &target) const;
	void		takeDamage(int amount);
	void		beRepaired(int amount);
};

#endif
