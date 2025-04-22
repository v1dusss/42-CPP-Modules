#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool _isSigned = false;
	unsigned int const _gradeToSign;
	unsigned int const _gradeToExecute;
	Form() = delete;

public:
	Form(std::string const &name, unsigned int const gradeToSign, unsigned int const gradeToExecute);
	Form(Form const &other);
	~Form();

	Form &operator=(Form const &other);

	std::string const &getName() const;
	bool isSigned() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;

	void beSigned(Bureaucrat const &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, Form const &form);