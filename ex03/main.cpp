#include "Point.hpp"

int main(void)
{
	Point a(6,6);
	Point b(3,2);
	Point c(10,2);

	Point p1(0,0);
	Point p2(6,2);
	Point p3(8,4);
	Point p4(6,4);
	Point p5(4.32,3.76);

	if (bsp(a, b, c, p5) == true)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	return (0);
}