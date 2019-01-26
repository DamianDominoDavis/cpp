<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:53:37 by ofedorov          #+#    #+#             */
/*   Updated: 2017/07/06 09:42:53 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
>>>>>>> 4ad56b74fd7b019472b40effc2995309ed75fa15
#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

<<<<<<< HEAD
const int	Fixed::_bits = 8;

Fixed::Fixed( void ): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &number )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = number;
}

Fixed::Fixed( int const number ): _value(number << Fixed::_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const number ): _value(roundf(number * (1 << Fixed::_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( Fixed const &number )
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = number.getRawBits();
	return *this;
}

int		Fixed::getRawBits( void ) const
{
	return this->_value;
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return this->_value / (float)(1 << Fixed::_bits);
}

int		Fixed::toInt( void ) const
{
	return this->_value / (1 << Fixed::_bits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

bool	Fixed::operator<( Fixed const &number ) const
{
	return (this->_value < number.getRawBits());
}

bool	Fixed::operator>( Fixed const &number ) const
{
	return (this->_value > number.getRawBits());
}

bool	Fixed::operator>=( Fixed const &number ) const
{
	return (this->_value >= number.getRawBits());
}

bool	Fixed::operator<=( Fixed const &number ) const
{
	return (this->_value <= number.getRawBits());
}

bool	Fixed::operator==( Fixed const &number ) const
{
	return (this->_value == number.getRawBits());
}

bool	Fixed::operator!=( Fixed const &number ) const
{
	return (this->_value != number.getRawBits());
}

Fixed	Fixed::operator+( Fixed const &number ) const
{
	return (Fixed(this->toFloat() + number.toFloat()));
}

Fixed	Fixed::operator-( Fixed const &number ) const
{
	return (Fixed(this->toFloat() - number.toFloat()));
}

Fixed	Fixed::operator*( Fixed const &number ) const
{
	return (Fixed(this->toFloat() * number.toFloat()));
}

Fixed	Fixed::operator/( Fixed const &number ) const
{
	return (Fixed(this->toFloat() / number.toFloat()));
}

Fixed	&Fixed::operator++( void )
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed	&Fixed::operator--( void )
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed &Fixed::min(Fixed & a, Fixed & b)
{
	return (a < b) ? a : b;
}

Fixed const 	&Fixed::min(Fixed const & a, Fixed const & b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b) ? a : b;
}

Fixed const 	&Fixed::max(Fixed const & a, Fixed const & b)
{
	return (a > b) ? a : b;
=======
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
>>>>>>> 4ad56b74fd7b019472b40effc2995309ed75fa15
}
