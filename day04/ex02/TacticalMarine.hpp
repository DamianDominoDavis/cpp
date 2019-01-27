#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"

class TacticalMarine  : public ISpaceMarine {
private:
	int			_hp;
public:
	virtual ~TacticalMarine(void);
	TacticalMarine(void);
	TacticalMarine(const TacticalMarine &marine);
	TacticalMarine& operator= (const TacticalMarine &marine);
	virtual void battleCry(void) const;
	virtual void rangedAttack(void) const;
	virtual void meleeAttack(void) const;
	int getHP(void) const;
	virtual ISpaceMarine* clone(void) const;
};

#endif
