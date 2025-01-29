#include "Fixed.hpp"
#include "Point.hpp"

float Area(Point const a, Point const b, Point const c)
{
	return fabs((a.getX()) * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float Area_sum = Area(a, b, c);
	float Area_1 = Area(a, b, point);
	float Area_2 = Area(a, point, c);
	float Area_3 = Area(point, b, c);

	std::cout << "1 + 2 + 3: " << Area_1 + Area_2 + Area_3 << std::endl;
	std::cout << "sum: " << Area_sum << std::endl;

	if (Area_1 == 0 || Area_2 == 0 || Area_3 == 0)
		return false;
	if (Area_sum >= Area_1 + Area_2 + Area_3)
		return true;
	return false;
}
