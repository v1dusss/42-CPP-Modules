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

	ScalarConverter(const std::string &str) = delete;
	ScalarConverter(const ScalarConverter &other) = delete;

	static bool isChar(const std::string &str);
	static bool isInt(const std::string &str);
	static bool isFloat(const std::string &str);
	static bool isDouble(const std::string &str);

	static void convertToChar(const char &c);
	static void convertToInt(const int &num);
	static void convertToFloat(const float &num);
	static void convertToDouble(const double &num);

public:
	ScalarConverter();
	~ScalarConverter();

	static void convert(const std::string &str);
};
