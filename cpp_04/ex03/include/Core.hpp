#pragma once

#include <iostream>
#include "AMateria.hpp"

class Core : public AMateria
{
public:
	Core();
	Core(const Core& copy);
	Core& operator=(const Core& rhs);
	virtual ~Core();
	
	AMateria* clone() const;
	void use(ICharacter& target);
};