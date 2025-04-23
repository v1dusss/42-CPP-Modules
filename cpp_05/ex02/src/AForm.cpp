#include "AForm.hpp"


AForm::AForm(std::string const &name, unsigned int const gradeToSign, unsigned int const gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm " << name << " created, with grade to sign " << gradeToSign << " and grade to execute " << gradeToExecute << std::endl;
}

AForm::AForm(AForm const &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	if (other._gradeToSign < 1 || other._gradeToExecute < 1)
	throw AForm::GradeTooHighException();
	if (other._gradeToSign > 150 || other._gradeToExecute > 150)
	throw AForm::GradeTooLowException();
	_isSigned = other._isSigned;
	std::cout << "AForm " << other._name << " copied" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << " destroyed" << std::endl;
}

AForm& AForm::operator=(AForm const &other)
{
	
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

std::string const& AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

unsigned int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int AForm::getGradeToExecute() const
{

	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return (RED "Grade is to high!" RESET);
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return (RED "Grade is to low!" RESET);
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return (RED "Form is not signed!" RESET);
}

std::ostream& operator<<(std::ostream &out, AForm const &aForm)
{
	out << "Form Name: " << aForm.getName() << ", Grade to Sign: " << aForm.getGradeToSign() << ", Grade to Execute: " << aForm.getGradeToExecute() << ", Signed: " << (aForm.isSigned() ? "Yes" : "No");
	return out;
}
