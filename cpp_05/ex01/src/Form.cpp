#include "Form.hpp"


Form::Form(std::string const &name, unsigned int const gradeToSign, unsigned int const gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << name << " created, with grade to sign " << gradeToSign << " and grade to execute " << gradeToExecute << std::endl;
}

Form::Form(Form const &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	if (other._gradeToSign < 1 || other._gradeToExecute < 1)
	throw Form::GradeTooHighException();
	if (other._gradeToSign > 150 || other._gradeToExecute > 150)
	throw Form::GradeTooLowException();
	_isSigned = other._isSigned;
	std::cout << "Form " << other._name << " copied" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

Form& Form::operator=(Form const &other)
{
	
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

std::string const& Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

unsigned int Form::getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int Form::getGradeToExecute() const
{

	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
	std::cout << GREEN << bureaucrat.getName() << " signed the Form" << _name << RESET << std::endl;
	std::cout << bureaucrat.getName() << " with grade " << bureaucrat.getGrade() << " signed the Form" << _name << " with grade to sign " << _gradeToSign << std::endl;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return (RED "Grade is to high!" RESET);
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return (RED "Grade is to low!" RESET);
}

std::ostream& operator<<(std::ostream &out, Form const &form)
{
	out << "Form Name: " << form.getName() << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute() << ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return out;
}
