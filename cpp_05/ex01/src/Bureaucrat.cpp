#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, unsigned int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat " << name << " created, with grade " << grade << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

std::string const& Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << YELLOW << this->_name << " couldn't sign " << form.getName() << " because grade is too low." RESET << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return (RED "Grade is to high!" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return (RED "Grade is to low!" RESET);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
