#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat Alice("Alice", 2);
	ShrubberyCreationForm Tom("Tom");
	PresidentialPardonForm Jerry("Jerry");
	RobotomyRequestForm Bob("Bob");

	std::cout << "==================================" << std::endl;
	std::cout << Alice << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << Tom << std::endl;
	std::cout << Jerry << std::endl;
	std::cout << Bob << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << std::endl;

	Alice.signForm(Tom);
	Alice.signForm(Jerry);
	Alice.signForm(Bob);
	std::cout << std::endl;
	Alice.executeForm(Tom);
	Alice.executeForm(Jerry);
	Alice.executeForm(Bob);

	std::cout << std::endl;
	return (0);
}
