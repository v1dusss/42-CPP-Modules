#include "Animal.hpp"

Animal::Animal()
{
}

Animal::Animal(std::string type)
{
	this->type = type;
}

Animal::Animal(const Animal &copy)
{
	this->type = copy.type;
}

Animal::~Animal()
{
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
