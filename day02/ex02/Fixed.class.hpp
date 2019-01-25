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
	int		getRawBits(void) const;
	void	setRawBits(const int v);
	int		toInt(void) const;
	float	toFloat(void) const;
	~Fixed(void);

	Fixed	&operator=(const Fixed &n);
	bool	operator<(const Fixed &n) const;
	bool	operator>(const Fixed &n) const;
	bool	operator>=(const Fixed &n) const;
	bool	operator<=(const Fixed &n) const;
	bool	operator==(const Fixed &n) const;
	bool	operator!=(const Fixed &n) const;
	Fixed	operator+(const Fixed &n) const;
	Fixed	operator-(const Fixed &n) const;
	Fixed	operator*(const Fixed &n) const;
	Fixed	operator/(const Fixed &n) const;
	Fixed	&operator++(void);
	Fixed	operator++( int );
	Fixed	&operator--(void);
	Fixed	operator--( int );

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<(std::ostream &o, const Fixed &f);

#endif
