#pragma once

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float xf, const float yf);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();
};
bool bsp( Point const a, Point const b, Point const c, Point const point);

