#include "Fixed.hpp"

class Point {
private:
	Fixed _x;
	Fixed _y;

public:
	Point();
	Point(const Point &point);
	Point(const Fixed &x, const Fixed &y);
	~Point();
	Point &operator=(const Point &point);
	float getX() const;
	float getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);