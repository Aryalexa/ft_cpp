#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a; // default constr
	Fixed b( a ); // copy constr
	Fixed b2 = a; // copy constr 
	Fixed c; //default
	c = b; // =
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	a.setRawBits(3);
	std::cout << a.getRawBits() << std::endl;

	return 0;
}