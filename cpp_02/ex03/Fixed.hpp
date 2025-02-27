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

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed &min(Fixed &value_1, Fixed &value_2);
	static const Fixed &min(Fixed const &value_1, Fixed const &value_2);
	static Fixed &max(Fixed &value_1, Fixed &value_2);
	static const Fixed &max(Fixed const &value_1, Fixed const &value_2);

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);
