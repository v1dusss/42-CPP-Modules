#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() = delete
{
}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int grade) : _name(name), _grade(grade)
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	this->_name = other._name;
	this->_grade = other._grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other)
{
	this->_name = other._name;
	this->_grade = other._grade;
	return (*this);
}

std::string const& Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int& Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	this->_grade++;
}
