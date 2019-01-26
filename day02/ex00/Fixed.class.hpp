#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed {
<<<<<<< HEAD
		int					value;
		static const int	bits;
	public:
		Fixed(void);
		Fixed(Fixed const &number);
		~Fixed(void);
		Fixed	&operator=(Fixed const &number);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
=======
	int					value;
	static const int	bits;
public:
	Fixed(void);
	Fixed(Fixed const &number);
	~Fixed(void);
	Fixed	&operator=(Fixed const &number);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
>>>>>>> 4ad56b74fd7b019472b40effc2995309ed75fa15
};

#endif
