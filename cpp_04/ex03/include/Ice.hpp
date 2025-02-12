#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& copy);
	Ice& operator=(const Ice& rhs);
	virtual ~Ice();
	
	AMateria* clone() const;
	void use(ICharacter& target);
};