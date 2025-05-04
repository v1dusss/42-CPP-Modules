#pragma once

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
private:
	std::string _formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *makeShrubberyCreationForm(std::string const &target) const;
	AForm *makeRobotomyRequestForm(std::string const &target) const;
	AForm *makePresidentialPardonForm(std::string const &target) const;

public:
	Intern() = default;
	Intern(Intern const &other) = default;
	Intern &operator=(Intern const &other) = default;
	~Intern() = default;
	
	AForm *makeForm(std::string const &formName, std::string const &target) const;

	class UnknownFormException : public std::exception
	{
	public:
		virtual const char *what() const noexcept override;
	};
};
