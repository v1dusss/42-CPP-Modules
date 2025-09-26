#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv)
{
	RPN rpn;

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <RPN_expression>" << std::endl;
		return 1;
	}

	try {
		int result = rpn.calculate_RPN(argv[1]);
		std::cout << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}