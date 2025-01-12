
#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int rawValue;
	static const int W; // number of fractional bits

public:
	static const float EPSILON; // smallest float EP :: 1+EP > 1
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

	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++();	// pre-inc
	Fixed operator++(int);	// post-inc
	Fixed &operator--();	// pre-dec
	Fixed operator--(int);	// post-dec

	static Fixed &min(Fixed &o1, Fixed &o2);
	static const Fixed &min(const Fixed &o1, const Fixed &o2);
	static Fixed &max(Fixed &o1, Fixed &o2);
	static const Fixed &max(const Fixed &o1, const Fixed &o2);
		
};

std::ostream &operator<<(std::ostream &ost, const Fixed &fpt);


