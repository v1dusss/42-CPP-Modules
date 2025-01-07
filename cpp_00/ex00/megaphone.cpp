#include <iostream>
#include <cctype>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "\033[31m* LOUD AND UNBEARABLE FEEDBACK NOISE *\033[0m" << std::endl;
	} else {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j] != '\0'; j++) {
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
