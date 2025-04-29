#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

bool ScalarConverter::isChar(const std::string &str)
{
	if (str.length() == 1 && std::isprint(str[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &str)
{
	if (str == "0" || str == "-0" || str == "+0")
		return true;

	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (i == str.length())
		return false;

	for (; i < str.length(); i++){
		if (!std::isdigit(str[i]))
			return false;
	}

	try
	{
		long value = std::stol(str);
		if (value < INT_MIN || value > INT_MAX)
			return false;
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
		return true;

	size_t len = str.length();
	if (len < 2 || str[len - 1] != 'f')
		return false;

	std::string core = str.substr(0, len - 1);
	bool dotSeen = false;
	bool digitSeen = false;
	size_t i = 0;

	if (core[i] == '+' || core[i] == '-')
		i++;

	for (; i < core.length(); ++i)
	{
		if (core[i] == '.'){
			if (dotSeen)
				return false;
			dotSeen = true;
		}
		else if (std::isdigit(core[i]))
			digitSeen = true;
		else
			return false;
	}
	return dotSeen && digitSeen;
}

bool ScalarConverter::isDouble(const std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
		return true;

	bool dotSeen = false;
	bool digitSeen = false;
	size_t i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;

	for (; i < str.length(); ++i)
	{
		if (str[i] == '.'){
			if (dotSeen)
				return false;
			dotSeen = true;
		}
		else if (std::isdigit(str[i]))
			digitSeen = true;
		else
			return false;
	}
	return dotSeen && digitSeen;
}

void ScalarConverter::convertToChar(const char &c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" <<std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" <<std::endl;
}

void ScalarConverter::convertToInt(const int &num)
{
	if (std::isprint(num))
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void ScalarConverter::convertToFloat(const float &num)
{
	(void)num;
}

void ScalarConverter::convertToDouble(const double &num)
{
	(void)num;
}

const char* typeToString(t_type type) {
	switch (type) {
		case CHAR: return "CHAR";
		case INT: return "INT";
		case FLOAT: return "FLOAT";
		case DOUBLE: return "DOUBLE";
		default: return "UNKNOWN";
	}
}

void ScalarConverter::convert(const std::string &str)
{
	t_type type;

	if (!str.empty())
	{
		if (isInt(str))
			type = INT;
		else if (isChar(str))
			type = CHAR;
		else if (isFloat(str))
			type = FLOAT;
		else if (isDouble(str))
			type = DOUBLE;
		else{
			std::cerr << "Invalid type" << std::endl;
			return;
		}
	}
	else{
		std::cerr << "Empty string" << std::endl;
		return;
	}

	std::cout << "Input: " << str << std::endl;
	std::cout << "Type: " << typeToString(type) << std::endl;
	std::cout << std::endl;

	switch (type)
	{
		case CHAR:
			convertToChar(str[0]);
			break;
		case INT:
			convertToInt(std::stoi(str));
			break;
		case FLOAT:
			convertToFloat(std::stof(str));
			break;
		case DOUBLE:
			convertToDouble(std::stod(str));
			break;
	}
}