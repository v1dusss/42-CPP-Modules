# include "iter.hpp"
# include <iostream>

void printInt(const int &i)
{
	std::cout << BOLD CYAN << i << RESET << " ";
}

void printChar(const char &c)
{
	std::cout << BOLD MAGENTA << c << RESET << " ";
}

void setToZero(int &i)
{
	i = 0;
}

void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}

int main()
{
	std::cout << BOLD BLUE << "=== Testing iter function template ===" << RESET << std::endl << std::endl;

	// Test with integers
	int arr[5] = {1, 2, 3, 4, 5};
	std::cout << BOLD GREEN << "Original int array:\t" << RESET;
	iter(arr, 5, printInt);
	std::cout << std::endl;

	std::cout << BOLD YELLOW << "Setting to zero:\t" << RESET;
	iter(arr, 5, setToZero);
	iter(arr, 5, printInt);
	std::cout << std::endl << std::endl;

	// Test with characters
	char chars[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
	std::cout << BOLD GREEN << "Original chars:\t\t" << RESET;
	iter(chars, 5, printChar);
	std::cout << std::endl;

	std::cout << BOLD YELLOW << "Converting to upper:\t" << RESET;
	iter(chars, 5, toUpper);
	iter(chars, 5, printChar);
	std::cout << std::endl << std::endl;

	return 0;
}