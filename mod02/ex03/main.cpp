#include "Point.hpp"
#include <iostream>


const std::string inOrOut(const bool &b)
{
	if (b)
		return "in";
	return "out";
}

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

	std::cout << a << " vertex: " << inOrOut(bsp(a, b, c, a)) << std::endl;
	std::cout << p << " edge: " << inOrOut(bsp(a, b, c, p)) << std::endl;
	std::cout << p2 << " edge 2: " << inOrOut(bsp(a, b, c, p2)) << std::endl;
	std::cout << q << " inside: " << inOrOut(bsp(a, b, c, q)) << std::endl;
	std::cout << r << " inside: " << inOrOut(bsp(a, b, c, r)) << std::endl;
	std::cout << s << " outside in line: " << inOrOut(bsp(a, b, c, s)) << std::endl;
	std::cout << t << " outside random: " << inOrOut(bsp(a, b, c, t)) << std::endl;
	std::cout << std::endl;

	return 0;
}