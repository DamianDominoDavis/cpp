#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed {
		int					value;
		static const int	bits;
	public:
		Fixed(void);
		Fixed(Fixed const &number);
		~Fixed(void);
		Fixed	&operator=(Fixed const &number);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
