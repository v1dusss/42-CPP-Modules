#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool _isSigned = false;
	unsigned int const _gradeToSign;
	unsigned int const _gradeToExecute;
	AForm() = delete;

public:
	AForm(std::string const &name, unsigned int const gradeToSign, unsigned int const gradeToExecute);
	AForm(AForm const &other);
	~AForm();

	AForm &operator=(AForm const &other);

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
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &aForm);