
#pragma once

class Fixed
{
private:
	int rawValue;
	static const int W = 8; // number of fractional bits

public:
	// 1. defualt constructor
	Fixed();
	// 2. copy constructor
	Fixed(const Fixed &other);
	// 3. copy assignment operator overload
	Fixed &operator=(const Fixed &other);
	// 4. destructor
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};
