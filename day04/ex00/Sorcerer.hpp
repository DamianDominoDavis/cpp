#ifndef SORCERER_HPP
# define SORCERER_HPP value
# include <string>
# include "Victim.hpp"

class Sorcerer {
	std::string _name;
	std::string _title;
	Sorcerer(void);
public:
	Sorcerer(std::string n, std::string t);
	Sorcerer(const Sorcerer& s);
	~Sorcerer(void);
	Sorcerer&		operator= (const Sorcerer& s);
	std::string		name(void) const;
	std::string		title(void) const;
	void			polymorph(const Victim& v) const;
};
std::ostream&	operator<<(std::ostream& o, const Sorcerer& s);

#endif
