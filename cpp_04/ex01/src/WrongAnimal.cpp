#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->type = copy.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->type = assign.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}