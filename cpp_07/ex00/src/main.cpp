# include "whatever.hpp"
# include <iostream>

int main( void ) {
	std::cout << BOLD BLUE << "=== Template Functions Demo ===" << RESET << std::endl;
	std::cout << std::endl;

	// Integer test
	int a = 2;
	int b = 3;
	std::cout << BOLD YELLOW << "🔢 Integer Test:" << RESET << std::endl;
	std::cout << "  Before swap: " << GREEN << "a = " << a << ", b = " << b << RESET << std::endl;
	::swap( a, b );
	std::cout << "  After swap:  " << GREEN << "a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << "  " << BLUE << "min(a, b) = " << ::min( a, b ) << RESET << std::endl;
	std::cout << "  " << RED << "max(a, b) = " << ::max( a, b ) << RESET << std::endl;
	std::cout << std::endl;

	// String test
	std::string c = "Bob";
	std::string d = "Alice";
	std::cout << BOLD YELLOW << "📝 String Test:" << RESET << std::endl;
	std::cout << "  Before swap: " << GREEN << "c = \"" << c << "\", d = \"" << d << "\"" << RESET << std::endl;
	::swap(c, d);
	std::cout << "  After swap:  " << GREEN << "c = \"" << c << "\", d = \"" << d << "\"" << RESET << std::endl;
	std::cout << "  " << BLUE << "min(c, d) = \"" << ::min( c, d ) << "\"" << RESET << std::endl;
	std::cout << "  " << RED << "max(c, d) = \"" << ::max( c, d ) << "\"" << RESET << std::endl;
	std::cout << std::endl;

	return 0;
}