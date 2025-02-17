#pragma once

#include <iostream>

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const &other);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &other);

	std::string const &getName() const;
	std::string const &getGrade() const;
	void incrementGrade();
	void decrementGrade();
};