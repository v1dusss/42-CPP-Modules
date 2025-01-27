#include "Fixed.hpp"

Fixed::Fixed()
{
}

Fixed::Fixed(const int value)
{
	fixedPointValue = value << fractionalBits;
}
Fixed::Fixed(const float value) : fixedPointValue(roundf(value * (1 << fractionalBits)))
{
}

Fixed::Fixed(const Fixed &fixed)
{
	this->fixedPointValue = fixed.fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	if(this != &fixed)
		this->fixedPointValue = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return (fixedPointValue >> fractionalBits);
}

bool Fixed::operator>(const Fixed &other) const
{
	if (this->fixedPointValue > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &other) const
{
	if (this->fixedPointValue < other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->fixedPointValue <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->fixedPointValue >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->fixedPointValue == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->fixedPointValue != other.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.fixedPointValue = (this->fixedPointValue + other.fixedPointValue) >> fractionalBits;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.fixedPointValue = (this->fixedPointValue - other.fixedPointValue) >> fractionalBits;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.fixedPointValue = (this->fixedPointValue * other.fixedPointValue) >> fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.fixedPointValue = (this->fixedPointValue / other.fixedPointValue) >> fractionalBits;
	return result;
}

Fixed& Fixed::operator--()
{
	this->fixedPointValue--;
	return (*this);
}

Fixed& Fixed::operator++()
{
	this->fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixedPointValue--;
	return (tmp);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixedPointValue++;
	return (tmp);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}