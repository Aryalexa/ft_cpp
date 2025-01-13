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
	Fixed getX() const;
	Fixed getY() const;
	Point operator+(const Point &other) const;
	Point operator-(const Point &other) const;
};

std::ostream &operator<<(std::ostream &ost, const Point &p);

bool bsp( Point const a, Point const b, Point const c, Point const point);

