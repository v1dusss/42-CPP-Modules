#include <iostream>

#pragma once

class Fixed
{
private:
	int fixedPointValue;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};