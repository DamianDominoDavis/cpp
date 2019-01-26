#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP
# include <iostream>

class Fixed {
<<<<<<< HEAD
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
=======
	int					value;
	static const int	bits;
public:
	Fixed(void);
	Fixed(const Fixed &n);
	Fixed(const int n);
	Fixed(const float n);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
	~Fixed(void);
	Fixed	&operator=(const Fixed &n);
>>>>>>> 4ad56b74fd7b019472b40effc2995309ed75fa15
};

std::ostream & operator<<(std::ostream &o, const Fixed &f);

#endif
