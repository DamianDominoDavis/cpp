#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

const int Fixed::bits = 8;

// de/constructors
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
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// member functions
int		Fixed::getRawBits(void) const {
	return value;
}
void	Fixed::setRawBits(const int v) {
	value = v;
}
float	Fixed::toFloat(void) const {
	return value / (float)(1 << Fixed::bits);
}
int		Fixed::toInt(void) const {
	return value / (1 << Fixed::bits);
}

// operators
Fixed	&Fixed::operator=(const Fixed &n) {
	std::cout << "Assignation operator called" << std::endl;
	value = n.getRawBits();
	return *this;
}
bool	Fixed::operator<(const Fixed &n) const {
	return (value < n.getRawBits());
}
bool	Fixed::operator>(const Fixed &n) const {
	return (value > n.getRawBits());
}
bool	Fixed::operator>=(const Fixed &n) const {
	return (value >= n.getRawBits());
}
bool	Fixed::operator<=(const Fixed &n) const {
	return (value <= n.getRawBits());
}
bool	Fixed::operator==(const Fixed &n) const {
	return (value == n.getRawBits());
}
bool	Fixed::operator!=(const Fixed &n) const {
	return (value != n.getRawBits());
}
Fixed	Fixed::operator+(const Fixed &n) const {
	return (Fixed(toFloat() + n.toFloat()));
}
Fixed	Fixed::operator-(const Fixed &n) const {
	return (Fixed(toFloat() - n.toFloat()));
}
Fixed	Fixed::operator*(const Fixed &n) const {
	return (Fixed(toFloat() * n.toFloat()));
}
Fixed	Fixed::operator/(const Fixed &n) const {
	return (Fixed(toFloat() / n.toFloat()));
}
Fixed	&Fixed::operator++(void) {
	value++;
	return (*this);
}
Fixed	Fixed::operator++( int ) {
	Fixed o(*this);
	++(*this);
	return (o);
}
Fixed	&Fixed::operator--(void) {
	value--;
	return (*this);
}
Fixed	Fixed::operator--( int ) {
	Fixed o(*this);
	--(*this);
	return (o);
}

// static
Fixed&			Fixed::min(Fixed & a, Fixed & b) {
	return ((a < b) ? a : b);
}
const Fixed&	Fixed::min(const Fixed & a, const Fixed & b) {
	return ((a < b) ? a : b);
}
Fixed&			Fixed::max(Fixed & a, Fixed & b) {
	return ((a > b) ? a : b);
}
const Fixed&	Fixed::max(const Fixed & a, const Fixed & b) {
	return ((a > b) ? a : b);
}

// tostring
std::ostream & operator<<(std::ostream & o, const Fixed &f) {
	o << f.toFloat();
	return (o);
}
