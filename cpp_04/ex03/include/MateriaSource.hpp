#pragma once

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource {
private:
	AMateria* _materias[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& copy);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void learnMateria(AMateria* m) override;
	AMateria* createMateria(const std::string& type) override;
};