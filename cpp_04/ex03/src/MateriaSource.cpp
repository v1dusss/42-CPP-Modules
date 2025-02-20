#include "MateriaSource.hpp"
#include "AMateria.hpp"


MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; ++i) {
		_materias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; ++i) {
		if (_materias[i]) {
			delete _materias[i];
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other) {
		for (size_t i = 0; i < 4; ++i) {
			_materias[i] = other._materias[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m)
	{
		for (size_t i = 0; i < 4; ++i) {
			if (!_materias[i]) {
				_materias[i] = m;
				break;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (size_t i = 0; i < 4; ++i) {
		if (_materias[i] && _materias[i]->getType() == type) {
			return _materias[i]->clone();
		}
	}
	return nullptr;
}
