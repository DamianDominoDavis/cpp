#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

<<<<<<< HEAD

=======
>>>>>>> 4ad56b74fd7b019472b40effc2995309ed75fa15
const int Fixed::bits = 8;

// de/constructors
Fixed::Fixed(void): value(0) {}
Fixed::Fixed(const Fixed &number) {
	*this = number;
}
Fixed::Fixed(const int number): value(number << Fixed::bits) {}
Fixed::Fixed(const float number): value(roundf(number * (1 << Fixed::bits))) {}
Fixed::~Fixed(void) {}

// member functions
int		Fixed::getRawBits(void) const {
	return (value);
}
void	Fixed::setRawBits(int const raw) {
	value = raw;
}
int		Fixed::toInt(void) const {
	return this->value / (1 << Fixed::bits);
}
float	Fixed::toFloat(void) const {
	return (value / (float)(1 << Fixed::bits));
}

// operators
Fixed	&Fixed::operator=(const Fixed &number) {
	value = number.getRawBits();
	return (*this);
}
bool	Fixed::operator<(const Fixed &number) const {
	return (value < number.getRawBits());
}
bool	Fixed::operator>(const Fixed &number) const {
	return (value > number.getRawBits());
}
bool	Fixed::operator>=(const Fixed &number) const {
	return (value >= number.getRawBits());
}
bool	Fixed::operator<=(const Fixed &number) const {
	return (value <= number.getRawBits());
}
bool	Fixed::operator==(const Fixed &number) const {
	return (value == number.getRawBits());
}
bool	Fixed::operator!=(const Fixed &number) const {
	return (value != number.getRawBits());
}
Fixed	Fixed::operator+(const Fixed &number) const {
	return (Fixed(toFloat() + number.toFloat()));
}
Fixed	Fixed::operator-(const Fixed &number) const {
	return (Fixed(toFloat() - number.toFloat()));
}
Fixed	Fixed::operator*(const Fixed &number) const {
	return (Fixed(toFloat() * number.toFloat()));
}
Fixed	Fixed::operator/(const Fixed &number) const {
	return (Fixed(toFloat() / number.toFloat()));
}
Fixed&	Fixed::operator++(void) {
	value++;
	return (*this);
}
Fixed	Fixed::operator++(int) {
	Fixed o(*this);
	++(*this);
	return (o);
}
Fixed&	Fixed::operator--(void) {
	value--;
	return (*this);
}
Fixed	Fixed::operator--(int) {
	Fixed o(*this);
	--(*this);
	return (o);
}

// static
Fixed&			Fixed::min(Fixed &a, Fixed &b) {
	return ((a < b) ? a : b);
}
const Fixed&	Fixed::min(const Fixed &a, const Fixed &b) {
	return ((a < b) ? a : b);
}
Fixed&			Fixed::max(Fixed &a, Fixed &b) {
	return ((a > b) ? a : b);
}
const Fixed&	Fixed::max(const Fixed &a, const Fixed &b) {
	return ((a > b) ? a : b);
}

// tostring
std::ostream &operator<<(std::ostream &o, const Fixed &f) {
	o << f.toFloat();
	return (o);
}
