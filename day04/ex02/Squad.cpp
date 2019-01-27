#include <iostream>
#include "Squad.hpp"

Squad::Squad(void): _unitCount(0) {}
Squad::Squad(const ISquad &squad) {
	_unitCount = squad.getCount();
	for (int i = 0 ; i < _unitCount; i++)
		_pool[i] = squad.getUnit(i)->clone();
}
ISquad&	Squad::operator= (const ISquad &squad) {
	for (int i = 0 ; i < _unitCount; i++)
		delete _pool[i];
	_unitCount = squad.getCount();
	for (int i = 0 ; i < _unitCount; i++)
		_pool[i] = squad.getUnit(i)->clone();
	return (*this);
}
Squad::~Squad(void) {
	for (int i = 0 ; i < _unitCount; i++)
		delete _pool[i];
}

int		Squad::getCount(void) const { return _unitCount; }

ISpaceMarine*	Squad::getUnit(int i) const {
	if (i >= 0 && i < _unitCount)
		return (_pool[i]);
	return (NULL);
}

int		Squad::push(ISpaceMarine* marine) {
	if (_unitCount < 50) {
		_pool[_unitCount] = marine;
		_unitCount++;
		return (0);
	}
	else
		return 1;
}
