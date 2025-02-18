#pragma once

#include <iostream>

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