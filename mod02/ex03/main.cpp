#include "Point.hpp"
#include <iostream>

int main( void ) {
	
	Point a(0,0);
	Point b(2,0);
	Point c(0,2);

	std::cout << std::endl;
	std::cout << "Triangle " << a << " "<< b << " " << c << std::endl;
	std::cout << "Tests:" << std::endl;

	/*
	2 - c
	    | \
	1 - |   p
	    |   q \
	0 - a - - - b 
		0   1   2
	*/
	Point p(1,1);
	Point p2(0,1);
	Point q(1,0.5f);
	Point r(1,0.75f);
	Point s(3,-1);
	Point t(-5,-1);

	std::cout << a << " vertex: " <<(!bsp(a, b, c, a) ? "ok" : "fail") << std::endl;
	std::cout << p << " edge: " << (!bsp(a, b, c, p) ? "ok" : "fail") << std::endl;
	std::cout << p2 << " edge 2: " << (!bsp(a, b, c, p2) ? "ok" : "fail") << std::endl;
	std::cout << q << " inside: " << (bsp(a, b, c, q) ? "ok" : "fail") << std::endl;
	std::cout << r << " inside: " << (bsp(a, b, c, r) ? "ok" : "fail") << std::endl;
	std::cout << s << " outside in line: " << (!bsp(a, b, c, s) ? "ok" : "fail") << std::endl;
	std::cout << t << " outside random: " << (!bsp(a, b, c, t) ? "ok" : "fail") << std::endl;
	std::cout << std::endl;

	return 0;
}