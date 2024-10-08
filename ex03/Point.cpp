#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}

Point::Point(const Point &other)
{
	*this = other;
}

Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->~Point();
		new(this) Point(other._x.toFloat(), other._y.toFloat());
		return (*this);
	}
	return (*this);
}

Point::~Point()
{
}

float	Point::getFloatX(void) const
{
	return (_x.toFloat());
}

float	Point::getFloatY(void) const
{
	return (_y.toFloat());
}