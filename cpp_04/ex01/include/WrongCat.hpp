#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	~WrongCat();
	WrongCat &operator=(const WrongCat &assign);

	void makeSound() const;
};
