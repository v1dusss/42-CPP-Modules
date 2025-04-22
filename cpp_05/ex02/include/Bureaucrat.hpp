#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const _name;
	unsigned int _grade;
	Bureaucrat() = delete;

public:
	Bureaucrat(std::string const &name, unsigned int grade);
	Bureaucrat(Bureaucrat const &other);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &other);

	std::string const &getName() const;
	unsigned int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &aForm) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

// ANSI escape codes for color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"