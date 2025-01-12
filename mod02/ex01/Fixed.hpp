
#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int rawValue;
	static const int W; // number of fractional bits

public:
	// 1. defualt constructor
	Fixed();
	// 2. copy constructor
	Fixed(const Fixed &other);
	// 3. copy assignment operator overload
	Fixed &operator=(const Fixed &other);
	// 4. destructor
	~Fixed();
	Fixed(const int i);
	Fixed(const float fp);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

};

std::ostream &operator<<(std::ostream &ost, const Fixed &fpt);


