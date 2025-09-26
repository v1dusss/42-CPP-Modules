#pragma once

#include <stack>


class RPN {
	private:
		std::string input;
		std::stack<int> buffer;

		bool validate(std::string str);
	public:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& other);
		~RPN();

		int calculate_RPN(std::string str);
};