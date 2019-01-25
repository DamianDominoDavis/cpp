#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP
# include <iostream>

class Fixed {
		int					value;
		static const int	bits;
	public:
		Fixed(void);
		Fixed(const Fixed &n);
		Fixed(const int n);
		Fixed(const float n);
		Fixed	&operator=(const Fixed &n);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream & operator<<(std::ostream &o, const Fixed &f);

#endif
