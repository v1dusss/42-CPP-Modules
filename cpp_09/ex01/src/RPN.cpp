#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy)
{
	this->input = copy.input;
	this->buffer = copy.buffer;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->input = other.input;
		this->buffer = other.buffer;
	}
	return *this;
}

int RPN::calculate_RPN(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			continue;
		else if (str[i] >= '0' && str[i] <= '9')
			buffer.push(str[i] - '0');
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (buffer.size() < 2)
				throw std::runtime_error("Error: number is missing");
			int b = buffer.top();
			buffer.pop();
			int a = buffer.top();
			buffer.pop();
			switch (str[i])
			{
				case '+':
					buffer.push(a + b);
					break;
				case '-':
					buffer.push(a - b);
					break;
				case '*':
					buffer.push(a * b);
					break;
				case '/':
					if (b == 0)
						throw std::runtime_error("Error: Division by zero");
					buffer.push(a / b);
					break;
				default:
					throw std::runtime_error("Error: Invalid operator");
			}
		}
		else
			throw std::runtime_error("Error: Invalid character");
	}

	if (buffer.size() < 1)
		throw std::runtime_error("Error: number is missing");
	if (buffer.size() > 1)
		throw std::runtime_error("Error: too many numbers");

	return buffer.top();
}