#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat Alice("Alice", 2);
	ShrubberyCreationForm Tom("Tom");

	std::cout << Alice << std::endl;
	std::cout << Tom << std::endl;
	std::cout << std::endl;

	Alice.signForm(Tom);
	try
	{
		Tom.execute(Alice);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	//Alice.incrementGrade();

	std::cout << std::endl;
	return (0);
}
