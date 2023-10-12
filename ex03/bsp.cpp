#include "Point.hpp"

Point	getVec(Point const start, Point const end)
{
	return (Point(end.getFloatX() - start.getFloatX(), end.getFloatY() - start.getFloatY()));
}

float	getVecCrossProd(Point const v1, Point const v2)
{
	return ((v1.getFloatX() * v2.getFloatY()) - (v1.getFloatY() * v2.getFloatX()));
}

bool	checkDirection(float vec_cross_1, float vec_cross_2)
{
	if (vec_cross_1 == 0 || vec_cross_2 == 0)
	{
		return (false);
	}
	else
	{
		if (vec_cross_1 > 0 && vec_cross_2 < 0)
		{
			return (false);
		}
		else if (vec_cross_1 < 0 && vec_cross_2 > 0)
		{
			return (false);
		}
	}
	return (true);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	vec_ab = getVec(a, b);
	Point	vec_bc = getVec(b, c);
	Point	vec_ca = getVec(c, a);

	Point	vec_ap = getVec(a, point);
	Point	vec_bp = getVec(b, point);
	Point	vec_cp = getVec(c, point);

	if (!checkDirection(getVecCrossProd(vec_ab, vec_bc), getVecCrossProd(vec_ab, vec_ap)) || \
		!checkDirection(getVecCrossProd(vec_bc, vec_ca), getVecCrossProd(vec_bc, vec_bp)) || \
		!checkDirection(getVecCrossProd(vec_ca, vec_ab), getVecCrossProd(vec_ca, vec_cp)))
	{
		return (false);
	}

	return (true);
}