#pragma onec

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure() override;

	[[nodiscard]] AMateria* clone() const override;
	void use(ICharacter& target) override;
};
