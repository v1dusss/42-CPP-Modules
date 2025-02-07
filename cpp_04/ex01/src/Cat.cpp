#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
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
