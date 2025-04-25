#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string const _target;
	RobotomyRequestForm() = delete;

public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

	void execute(Bureaucrat const &executor) const;
};