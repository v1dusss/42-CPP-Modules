#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &assign)
{
	std::cout << "Cat assignation operator called" << std::endl;
	this->type = assign.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

void Cat::setBrainIdea(const std::string &idea, int index)
{
	this->brain->setIdea(idea, index);
}

std::string Cat::getBrainIdea(int index) const
{
	return this->brain->getIdea(index);
}
