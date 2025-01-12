#include "Point.hpp"
#include <iostream>

int main( void ) {
	
	Point a(0,0);
	Point b(2,0);
	Point c(0,2);

	/*
	2 *
	  |
	1 |   o
	  |   o
	0 * - - - * 
		  1   2
	*/
	Point p(1,1);
	Point q(1,0.5f);
	Point r(1,0.75f);

	std::cout << "vertex: " <<(!bsp(a, b, c, a) ? "ok" : "fail") << std::endl;
	std::cout << "edge: " << (!bsp(a, b, c, p) ? "ok" : "fail") << std::endl;
	std::cout << "inside: " << (bsp(a, b, c, q) ? "ok" : "fail") << std::endl;
	std::cout << "inside: " << (bsp(a, b, c, r) ? "ok" : "fail") << std::endl;

	return 0;
}