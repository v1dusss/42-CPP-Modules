#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const & other);
	virtual ~AMateria();
	AMateria& operator=(AMateria const & other);

	std::string const & getType() const; //Returns the materia type
	[[nodiscard]] virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};