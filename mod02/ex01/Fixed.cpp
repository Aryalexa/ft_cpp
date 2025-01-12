
#include "Fixed.hpp"

const int Fixed::W = 8; // number of fractional bits

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

Fixed::Fixed(const int i) : rawValue(i << W)
{
	std::cout << "Int constructor called" << std::endl;	
}
Fixed::Fixed(const float fp) : rawValue(std::roundf(fp * (1 << W)))
{
	std::cout << "Float constructor called" << std::endl;	
}

float Fixed::toFloat( void ) const
{
	return 1.0 * rawValue / (1 << W);	
}
int Fixed::toInt( void ) const
{
	return rawValue >> W;
}

std::ostream &operator<<(std::ostream &ost, const Fixed &fpt)
{
	ost << fpt.toFloat();
	return ost;
}