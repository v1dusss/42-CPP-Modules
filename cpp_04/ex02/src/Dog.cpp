#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
	std::cout << "Dog assignation operator called" << std::endl;
	this->type = obj.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

void Dog::setBrainIdea(const std::string &idea, int index)
{
	this->brain->setIdea(idea, index);
}

std::string Dog::getBrainIdea(int index) const
{
	return this->brain->getIdea(index);
}
