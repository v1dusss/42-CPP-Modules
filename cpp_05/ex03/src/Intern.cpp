#include "Intern.hpp"


AForm* Intern::makeShrubberyCreationForm(std::string const &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(std::string const &target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(std::string const &target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const &formName, std::string const &target) const
{
	if (formName == "shrubbery creation")
		return makeShrubberyCreationForm(target);
	else if (formName == "robotomy request")
		return makeRobotomyRequestForm(target);
	else if (formName == "presidential pardon")
		return makePresidentialPardonForm(target);
	throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const noexcept 
{
	return (YELLOW "Intern: Unknown form type" RESET);
}
