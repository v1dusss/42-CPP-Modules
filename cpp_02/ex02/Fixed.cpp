#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = value << fractionalBits;
}
Fixed::Fixed(const float value) : fixedPointValue(roundf(value * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointValue = fixed.fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &fixed)
		this->fixedPointValue = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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

bool Fixed::operator>(Fixed &other)
{
	if (this->fixedPointValue > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed &other)
{
	if (this->fixedPointValue < other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed &other)
{
	if (this->fixedPointValue <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed &other)
{
	if (this->fixedPointValue >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed &other)
{
	if (this->fixedPointValue == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed &other)
{
	if (this->fixedPointValue != other.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(Fixed &other)
{
	this->fixedPointValue += other.getRawBits();
	return (*this);
}

Fixed Fixed::operator-(Fixed &other)
{
	this->fixedPointValue -= other.getRawBits();
	return (*this);
}

Fixed Fixed::operator*(Fixed &other)
{
	this->fixedPointValue *= other.getRawBits();
	return (*this);
}

Fixed Fixed::operator/(Fixed &other)
{
	this->fixedPointValue /= other.getRawBits();
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->fixedPointValue--;
}

Fixed& Fixed::operator++()
{
	this->fixedPointValue++;
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

