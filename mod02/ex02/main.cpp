#include "Fixed.hpp"
#include <iostream>



int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed one(1);
	Fixed eps(Fixed::EPSILON); // 0.00390625
	Fixed ltEps(0.0010f); // 0 "less than eps"
	Fixed zero;

	std::cout << "🔅prints" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << one << std::endl;
	std::cout << eps << std::endl;
	std::cout << ltEps << std::endl;
	std::cout << "🔅sums" << std::endl;
	std::cout << b + one << std::endl;
	std::cout << one + eps  << std::endl;
	std::cout << one + ltEps  << std::endl;
	std::cout << "🔅compare" << std::endl;
	std::cout << (one > a) << std::endl;
	std::cout << (one + eps > one) << std::endl;
	std::cout << (one + ltEps > one) << std::endl;
	std::cout << "🔅inc" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "🔅min-max" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "🔅div" << std::endl;
	std::cout << one / zero << std::endl;
	return 0;
}