#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &copy);
	virtual ~Animal();
	Animal &operator=(const Animal &assign);

	virtual void makeSound() const;
};
