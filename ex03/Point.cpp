#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y)
{
}

Point::Point(const Point &other)
{
	*this = other;
}

Point& Point::operator=(const Point &other)
{
	return (*this);
}

Point::~Point()
{
}
