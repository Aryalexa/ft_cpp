
#include "Point.hpp"

Point::Point(): x(0), y(0)
{
}
Point::Point(const float xf, const float yf): x(xf), y(yf)
{
}
Point::Point(const Point &other): x(other.x), y(other.y)
{
}
Point &Point::operator=(const Point &other)
{
	(void)other;
	throw std::runtime_error("Copy assignment is not allowed.");
    return *this; // unreachable, but compiler needs it.
}
Point::~Point()
{
}
Fixed Point::getX() const
{
	return x;
}
Fixed Point::getY() const
{
	return y;
}
std::ostream &operator<<(std::ostream &ost, const Point &p)
{
	ost << "P(" << p.getX() << ", " << p.getY() << ")";
	return ost;
}
Point Point::operator+(const Point &other) const
{
	return Point((x + other.x).toFloat(), (y + other.y).toFloat());
}
Point Point::operator-(const Point &other) const
{
	return Point((x - other.x).toFloat(), (y - other.y).toFloat());
}