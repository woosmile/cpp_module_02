#ifndef POINT_H
# define POINT_H

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &other);
		Point& operator=(const Point &other);
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif