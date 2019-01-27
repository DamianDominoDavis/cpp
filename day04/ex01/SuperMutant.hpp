#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include "Enemy.hpp"

class SuperMutant : public Enemy {
public:
	SuperMutant(void);
	SuperMutant(const SuperMutant &enemy);
	virtual ~SuperMutant(void);

	SuperMutant	& operator=(const SuperMutant &enemy);
	virtual void takeDamage(int damage);
};

#endif
