#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const 
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	
	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << _target + "_shrubbery" << std::endl;
		return;
	}
	file << "                     .o00o" << std::endl;
	file << "                   o000000oo" << std::endl;
	file << "                  00000000000o" << std::endl;
	file << "                 00000000000000" << std::endl;
	file << "              oooooo  00000000  o88o" << std::endl;
	file << "           ooOOOOOOOoo  ```''  888888" << std::endl;
	file << "         OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
	file << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
	file << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
	file << "         OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
	file << "           OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
	file << "             OO:F_P:O `QQQ/  /Q'" << std::endl;
	file << "                \\\\. \\\\ |  // |" << std::endl;
	file << "                d\\\\ \\\\\\\\|_////" << std::endl;
	file << "                qP| \\\\ _' `|Ob" << std::endl;
	file << "                   \\\\  / \\\\  \\\\Op" << std::endl;
	file << "                   |  | O| |" << std::endl;
	file << "           _       /\\\\. _/ /|." << std::endl;
	file << "            `---__/|_\\\\   /|/|  __" << std::endl;
	file << "                  `-'  `-'`-'-'" << std::endl;

	file.close();
}