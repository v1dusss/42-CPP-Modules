#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 145, 137), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const 
{
}