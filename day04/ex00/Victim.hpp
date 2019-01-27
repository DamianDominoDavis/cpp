#ifndef VICTIM_HPP
# define VICTIM_HPP value
# include <string>

class Victim {
	std::string _name;
public:
	Victim(void);
	Victim(std::string n);
	Victim(const Victim& s);
	~Victim(void);
	Victim&		operator= (const Victim& s);
	std::string		name(void) const;
	void			getPolymorphed(void) const;
};
std::ostream&	operator<<(std::ostream& o, const Victim& s);

#endif