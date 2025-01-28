#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point a( Fixed( 0 ), Fixed( 0 ) );
	Point b( Fixed( 0 ), Fixed( 4 ) );
	Point c( Fixed( 4 ), Fixed( 0 ) );
	Point point( Fixed( 2 ), Fixed( 1 ) );

	std::cout << "Point a: " << a.getX() << ", " << a.getY() << std::endl;
	std::cout << "Point b: " << b.getX() << ", " << b.getY() << std::endl;
	std::cout << "Point c: " << c.getX() << ", " << c.getY() << std::endl;

	std::cout << "Point point: " << point.getX() << ", " << point.getY() << std::endl;

	bool result = bsp( a, b, c, point );

	if (result == true)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	return 0;
}