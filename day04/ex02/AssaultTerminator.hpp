#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP
# include "ISpaceMarine.hpp"
class AssaultTerminator: public ISpaceMarine {
private:
	int _hp;
public:
	virtual ~AssaultTerminator(void);
	AssaultTerminator(void);
	AssaultTerminator(const AssaultTerminator &marine);
	AssaultTerminator & operator=(const AssaultTerminator &marine);
	virtual ISpaceMarine *clone(void) const;
	virtual void battleCry(void) const;
	virtual void rangedAttack(void) const;
	virtual void meleeAttack(void) const;
	int getHP(void) const;
};

#endif
