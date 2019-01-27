#ifndef PEON_HPP
# define PEON_HPP
# include "Victim.hpp"

class Peon : public Victim {
public:
	Peon(void);
	Peon(std::string n);
	Peon(const Peon& s);
	~Peon(void);
};
//std::ostream&	operator<<(std::ostream& o, const Peon& s);

#endif
