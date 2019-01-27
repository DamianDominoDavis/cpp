#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	_n_index = 0;
	for (int i = 0; i < 4; i += 1)
		_inventory[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &ms) {
	*this = ms;
}
MateriaSource& MateriaSource::operator= (const MateriaSource &ms) {
	if (this != &ms) {
		for (int i = 0; i < 4; i += 1)
			_inventory[i] = ms._inventory[0]->clone();
		_n_index = ms._n_index;
	}
	return (*this);
}
MateriaSource::~MateriaSource(void) {}

void MateriaSource::learnMateria(AMateria *m) {
	if (_n_index < 3)
		_inventory[_n_index++] = m;
}
AMateria* MateriaSource::createMateria(const std::string &type) {
	if (type == "ice")
		return (new Ice());
	else if (type == "cure")
		return (new Cure());
	return (NULL);
}
