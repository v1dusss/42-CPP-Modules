#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat();
	Cat(const Cat &copy);
	~Cat();
	Cat &operator=(const Cat &assign);

	void makeSound() const;
	void setBrainIdea(const std::string &idea, int index);
	std::string getBrainIdea(int index) const;
};
