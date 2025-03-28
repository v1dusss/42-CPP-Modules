# pragma once

# include <iostream>
# include <string>
# include <cmath>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
} t_type;

class ScalarConverter
{
private:
	std::string	_str;
	t_type		_type;
	bool 		decimal;

	void setType();
	bool isChar();
	bool isInt();
	bool isFloat();
	bool isDouble();

	void printChar() const;
	void printInt() const;
	void printFloat() const;
	void printDoubl() const;

public:
	ScalarConverter();
	ScalarConverter(const std::string &str);
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &other);
};
