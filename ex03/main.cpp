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

	if (bsp(a, b, c, p1) == true)
		std::cout << "p1 : True" << std::endl;
	else
		std::cout << "p1 : False" << std::endl;

	if (bsp(a, b, c, p2) == true)
		std::cout << "p2 : True" << std::endl;
	else
		std::cout << "p2 : False" << std::endl;

	if (bsp(a, b, c, p3) == true)
		std::cout << "p3 : True" << std::endl;
	else
		std::cout << "p3 : False" << std::endl;

	if (bsp(a, b, c, p4) == true)
		std::cout << "p4 : True" << std::endl;
	else
		std::cout << "p4 : False" << std::endl;

	if (bsp(a, b, c, p5) == true)
		std::cout << "p5 : True" << std::endl;
	else
		std::cout << "p5 : False" << std::endl;
	
	return (0);
}