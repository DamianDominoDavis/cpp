#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

const int Fixed::bits = 8;

Fixed::Fixed(void): value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &n) {
	std::cout << "Copy constructor called" << std::endl;
	*this = n;
}

Fixed::Fixed(const int n): value(n << Fixed::bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n): value(roundf(n * (1 << Fixed::bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &n) {
	std::cout << "Assignation operator called" << std::endl;
	value = n.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &f) {
	o << f.toFloat();
	return (o);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	return (value);
}

void	Fixed::setRawBits(const int raw) {
	value = raw;
}

int		Fixed::toInt(void) const {
	return (value / (1 << Fixed::bits));
}

float	Fixed::toFloat(void) const {
	return (value / (float)(1 << Fixed::bits));
}
