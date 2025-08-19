#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	std::cout << BOLD BLUE "=== Testing Base* generate() and identify functions ===" RESET << std::endl;

	// Test random generation
	for (int i = 0; i < 3; i++)
	{
		std::cout << YELLOW "\nTest " << i + 1 << ":" RESET << std::endl;
		Base* instance = generate();

		std::cout << GREEN "Pointer: " RESET;
		identify(instance);
		std::cout << GREEN " | Reference: " RESET;
		identify(*instance);
		std::cout << std::endl;

		delete instance;
	}

	std::cout << BOLD BLUE "\n=== Testing specific instances ===" RESET << std::endl;

	// Test specific instances
	Base* instances[] = {new A(), new B(), new C()};
	std::string names[] = {"A", "B", "C"};

	for (int i = 0; i < 3; i++)
	{
		std::cout << YELLOW << names[i] << " instance:" << RESET << " Pointer: " << GREEN;
		identify(instances[i]);
		std::cout << RESET << " | Reference: " << GREEN;
		identify(*instances[i]);
		std::cout << RESET << std::endl;
		delete instances[i];
	}

	return 0;
}
