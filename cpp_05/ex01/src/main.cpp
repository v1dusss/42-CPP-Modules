#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form Bob("Bob", 1, 1);
	Bureaucrat Alice("Alice", 2);

	std::cout << Bob << std::endl;
	std::cout << Alice << std::endl;
	std::cout << std::endl;

	try
	{
		Bob.beSigned(Alice);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//Alice.incrementGrade();

	Alice.signForm(Bob);

	std::cout << std::endl;
	std::cout << Bob << std::endl;
	return (0);
}
