#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2){
		std::cerr << "\033[33m"<< "Usage: ./ex06 [DEBUG|INFO|WARNING|ERROR]" << "\033[0m" << std::endl;
		return 1;
	}

	harl.complain(argv[1]);

	return 0;
}