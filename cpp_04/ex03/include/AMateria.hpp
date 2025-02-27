#pragma once

#include <iostream>

class ICharacter;

class AMateria
{
protected:
	std::string _type;
public:
	AMateria();
	AMateria(std::string const & copy);
	AMateria(AMateria const & other);
	virtual ~AMateria();
	AMateria& operator=(AMateria const & other);

	std::string const & getType() const; //Returns the materia type
	[[nodiscard]] virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};