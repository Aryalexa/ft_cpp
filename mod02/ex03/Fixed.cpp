
#include "Fixed.hpp"


const int Fixed::W = 8; // number of fractional bits
const float Fixed::EPSILON = 1.0 / (1 << W);

Fixed::Fixed(): rawValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
	// std::cout << "W = " << W << std::endl;
	// std::cout << "EPSILON = " << EPSILON << std::endl;
	// std::cout << "Fixed(EPSILON) = " << Fixed(EPSILON) << std::endl;
}
Fixed::Fixed(const Fixed &other): rawValue(other.rawValue)
{
	// std::cout << "Copy constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other) // self assignment check
		return *this;
	rawValue = other.rawValue;
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits called" << std::endl;
	return rawValue;
}
void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits called" << std::endl;
	rawValue = raw;
}

// overload constructors
Fixed::Fixed(const int i) : rawValue(i << W)
{
	// std::cout << "Int constructor called" << std::endl;	
}
Fixed::Fixed(const float fp) : rawValue(roundf(fp * (1 << W)))
{
	// std::cout << "Float constructor called" << std::endl;	
}

// getters, setters
float Fixed::toFloat( void ) const
{
	return 1.0 * rawValue / (1 << W);	
}
int Fixed::toInt( void ) const
{
	return rawValue >> W;
}

// overload: print
std::ostream &operator<<(std::ostream &ost, const Fixed &fpt)
{
	ost << fpt.toFloat();
	return ost;
}

// overload: comparison
bool Fixed::operator==(const Fixed &other) const 
{
	return (rawValue == other.rawValue);
}
bool Fixed::operator!=(const Fixed &other) const 
{
	return !(*this == other); // using ==
}
bool Fixed::operator<(const Fixed &other) const 
{
	return (rawValue < other.rawValue);
}
bool Fixed::operator>(const Fixed &other) const 
{
	return (other < *this); // using <
}
bool Fixed::operator<=(const Fixed &other) const 
{
	return !(other < *this); // using <
}
bool Fixed::operator>=(const Fixed &other) const 
{
	return !(other < *this); // using <
}

// overload: arithmetic
Fixed Fixed::operator+(const Fixed &other) const
{
	// op1 - big ints
	// int rawSum = rawValue + other.rawValue;
	// float f = 1.0 * rawSum / (1 << W);
	// return  Fixed(f);
	// op2 - float sum
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

// overload: inc / dec
Fixed &Fixed::operator++()
{
	*this = *this + Fixed(EPSILON);
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	*this = *this + Fixed(EPSILON);	
	return tmp;
}
Fixed &Fixed::operator--()
{
	*this = *this - Fixed(EPSILON);
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	*this = *this - Fixed(EPSILON);	
	return tmp;
}

// overload: min, max
Fixed &Fixed::min(Fixed &o1, Fixed &o2)
{
	if (o1 <= o2)
		return o1;
	return o2;
}
const Fixed &Fixed::min(const Fixed &o1, const Fixed &o2)
{
	if (o1 <= o2)
		return (o1);
	return o2;
}
Fixed &Fixed::max(Fixed &o1, Fixed &o2)
{
	if (o1 >= o2)
		return o1;
	return o2;
}
const Fixed &Fixed::max(const Fixed &o1, const Fixed &o2)
{
	if (o1 >= o2)
		return (o1);
	return o2;
}