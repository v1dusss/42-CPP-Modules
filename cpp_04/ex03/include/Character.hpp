#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _materias[4];
	
public:
	Character();
	Character(std::string const & name);
	Character(Character const & other);
	virtual ~Character();
	Character& operator=(Character const & other);

	std::string const & getName() const;
	void use(int idx, ICharacter& target);
	void equip(AMateria* m);
	void unequip(int idx);
};