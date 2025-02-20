#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(const Dog& copy);
	~Dog();
	Dog &operator=(const Dog &obj);

	virtual void makeSound() const;
	void setBrainIdea(const std::string &idea, int index);
	std::string getBrainIdea(int index) const;
};
