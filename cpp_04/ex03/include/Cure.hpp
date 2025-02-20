#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& copy);
	Cure& operator=(const Cure& other);
	~Cure() override;

	[[nodiscard]] AMateria* clone() const override;
	void use(ICharacter& target) override;
};
