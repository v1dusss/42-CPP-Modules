# pragma once

# include <iostream>
# include <string>
# include <cmath>
#include <sstream>

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

// ANSI escape codes for color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"