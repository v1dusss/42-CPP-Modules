#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->brain = new Brain(*copy.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	if (this->brain)
		delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &assign)
{
	// std::cout << "Cat assignation operator called" << std::endl;
	// this->type = assign.type;
	// return *this;
	if (this != &assign)
	{
		Animal::operator=(assign);
		*brain = *assign.brain;
	}
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
