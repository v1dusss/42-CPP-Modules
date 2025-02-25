#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

Animal& Animal::operator=(const Animal &assign)
{
	this->type = assign.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}