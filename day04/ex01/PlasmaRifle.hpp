#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include "AWeapon.hpp"

class PlasmaRifle: public AWeapon {
	std::string	_name;
	int			_apcost;
	int			_damage;
public:
	PlasmaRifle(void);
	PlasmaRifle(const PlasmaRifle &weapon);
	virtual ~PlasmaRifle(void);

	PlasmaRifle		&operator=(PlasmaRifle const & weapon);

	virtual void	attack(void) const;
};

#endif
