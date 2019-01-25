#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP
# include <iostream>

class Fixed {
		int					value;
		const static int	bits;
	public:
		Fixed(void);
		Fixed(const Fixed &number);
		Fixed(const int number);
		Fixed(const float number);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		~Fixed(void);

		Fixed	&operator=(const Fixed &number);
		bool	operator<(const Fixed &number) const;
		bool	operator>(const Fixed &number) const;
		bool	operator>=(const Fixed &number) const;
		bool	operator<=(const Fixed &number) const;
		bool	operator==(const Fixed &number) const;
		bool	operator!=(const Fixed &number) const;
		Fixed	operator+(const Fixed &number) const;
		Fixed	operator-(const Fixed &number) const;
		Fixed	operator*(const Fixed &number) const;
		Fixed	operator/(const Fixed &number) const;
		Fixed	&operator++(void);
		Fixed	operator++( int );
		Fixed	&operator--(void);
		Fixed	operator--( int );

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed& min(Fixed const &a, Fixed const &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(Fixed const &a, Fixed const &b);
};
std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
