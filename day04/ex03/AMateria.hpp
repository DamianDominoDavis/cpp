#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include <cstdlib>
# include "ICharacter.hpp"

class AMateria {
	protected:
		unsigned int		_xp;
		std::string			_type;
	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &a);
		AMateria&			operator= (const AMateria &a);
		virtual ~AMateria(void);

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target) = 0;
		unsigned int		getXP(void) const;
		const std::string   &getType(void) const;
};

#endif
