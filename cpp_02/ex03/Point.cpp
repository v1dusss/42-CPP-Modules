#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point &point)
{
	this->_x = point._x;
	this->_y = point._y;
}

Point::Point(const Fixed &x, const Fixed &y)
{
	this->_x = x;
	this->_y = y;
}

Point::~Point()
{
}

Point& Point::operator=(const Point &point)
{
	this->_x = point._x;
	this->_y = point._y;
	return *this;
}

float Point::getX() const
{
	return this->_x.toFloat();
}

float Point::getY() const
{
	return this->_y.toFloat();
}

