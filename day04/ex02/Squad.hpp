#ifndef SQUAD_HPP
# define SQUAD_HPP
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad {
private:
	ISpaceMarine	*_pool[50];
	int				_unitCount;
public:
	Squad(void);
	Squad(const ISquad &squad);
	ISquad& operator= (const ISquad &squad);
	virtual ~Squad(void);

	virtual int getCount(void) const;
	virtual ISpaceMarine* getUnit(int i) const;
	virtual int push(ISpaceMarine* marine);
};

#endif
