#include <iostream>
#include <cmath>

#pragma once

class Fixed
{
private:
	int fixedPointValue;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(Fixed &other);
	bool operator<(Fixed &other);
	bool operator<=(Fixed &other);
	bool operator>=(Fixed &other);
	bool operator==(Fixed &other);
	bool operator!=(Fixed &other);
	Fixed operator+(Fixed &other);
	Fixed operator-(Fixed &other);
	Fixed operator*(Fixed &other);
	Fixed operator/(Fixed &other);
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);
