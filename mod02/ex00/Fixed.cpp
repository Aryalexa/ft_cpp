
#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other): rawValue(other.rawValue)
{
	std::cout << "Copy constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other) // self assignment check
		return *this;
	rawValue = other.rawValue;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits called" << std::endl;
	return rawValue;
}
void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits called" << std::endl;
	rawValue = raw;
}