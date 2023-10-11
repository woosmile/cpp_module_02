#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

	Point	vec_a(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
	Point	vec_b(c.getX().toFloat() - b.getX().toFloat(), c.getY().toFloat() - b.getY().toFloat());
	Point	vec_c(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() - a.getY().toFloat());

	Point	vec_ap(point.getX().toFloat() - a.getX().toFloat(), point.getY().toFloat() - a.getY().toFloat());
	Point	vec_bp(point.getX().toFloat() - b.getX().toFloat(), point.getY().toFloat() - b.getY().toFloat());
	Point	vec_cp(point.getX().toFloat() - c.getX().toFloat(), point.getY().toFloat() - c.getY().toFloat());

	Fixed	vec_tri_cross = (vec_a.getX().toFloat() * vec_c.getY().toFloat()) - (vec_a.getY().toFloat() * vec_c.getX().toFloat());
	Fixed	vec_point_cross = (vec_a.getX().toFloat() * vec_ap.getY().toFloat()) - (vec_a.getY().toFloat() * vec_ap.getX().toFloat());

		std::cout << vec_tri_cross.toFloat() << std::endl;
			std::cout << vec_point_cross.toFloat() << std::endl;
	if (vec_tri_cross.toFloat() > 0)
	{
		if (vec_point_cross.toFloat() <= 0)
		{
			return (false);
		}
	}
	else if (vec_tri_cross.toFloat()  == 0)
		return (false);
	else if (vec_tri_cross.toFloat()  < 0)
	{
		if (vec_point_cross.toFloat()  >= 0)
			return (false);
	}
	std::cout << "2" << std::endl;
	vec_tri_cross = (vec_b.getX().toFloat() * vec_a.getY().toFloat()) - (vec_b.getY().toFloat() * vec_a.getX().toFloat());
	vec_point_cross = (vec_b.getX().toFloat() * vec_bp.getY().toFloat()) - (vec_b.getY().toFloat() * vec_bp.getX().toFloat());

	if (vec_tri_cross.toFloat()  > 0)
	{
		if (vec_point_cross.toFloat()  <= 0)
			return (false);
	}
	else if (vec_tri_cross.toFloat()  == 0)
		return (false);
	else if (vec_tri_cross.toFloat()  < 0)
	{
		if (vec_point_cross.toFloat()  >= 0)
			return (false);
	}

	vec_tri_cross = (vec_c.getX().toFloat() * vec_a.getY().toFloat()) - (vec_c.getY().toFloat() * vec_a.getX().toFloat());
	vec_point_cross = (vec_c.getX().toFloat() * vec_cp.getY().toFloat()) - (vec_c.getY().toFloat() * vec_cp.getX().toFloat());

	if (vec_tri_cross.toFloat() > 0)
	{
		if (vec_point_cross.toFloat() <= 0)
			return (false);
	}
	else if (vec_tri_cross.toFloat() == 0)
		return (false);
	else if (vec_tri_cross.toFloat() < 0)
	{
		if (vec_point_cross.toFloat() >= 0)
			return (false);
	}
	return (true);
}