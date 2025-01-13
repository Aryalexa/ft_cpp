#include "Point.hpp"


/**
 * given the line from by the points r1 and r2
 * this function returns the sign of the point p relative to the line
 * - 0 if p in the line
 * - negative in one side
 * - positive in the other
 */
int	sign(const Point &r1, const Point &r2, const Point &p)
{
	const Fixed zero(0);
	Fixed m = (r1.getY() - r2.getY()) / (r1.getX() - r2.getX());
	Fixed o = r1.getY() - m * r1.getX();
	Fixed num = m * p.getX() + o - p.getY();
	if (num == zero)
		return 0;
	if (num < zero)
		return -1;
	return 1;
}

/**
 * BSP: binary space partitioning.
 * Check whether a point is inside of a triangle or not.
 * @arg a, b, c : vertices of the triangle
 * @arg point : the point to check.
 * @return True if point is inside the triangle (no edges), False otherwise.
 */
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (sign(a, b, c) == 0)
		return false;
	return (
		sign(a, b, c) == sign(a, b, point)
		&& sign(b, c, a) == sign(b, c, point)
		&& sign(c, a, b) == sign(c, a, point)
	);
}