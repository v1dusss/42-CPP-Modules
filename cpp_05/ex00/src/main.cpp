#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("1", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("2", 151);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("3", 150);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("4", 1);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}