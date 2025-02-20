#include "Character.hpp"
#include "AMateria.hpp"
#include <algorithm>

Character::Character(const std::string& name) : _name("default")
{
	_name = name;
	for (auto& materia : _materias){
		materia = nullptr;
	}
}

Character::Character(const Character& other) : _name(other._name)
{
	for (size_t i = 0; i < 4; ++i){
		_materias[i] = other._materias[i] ? other._materias[i]->clone() : nullptr;
	}
}

Character::~Character()
{
	for (auto& materia : _materias){
		delete materia;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (auto& materia : _materias){
			delete materia;
		}
		for (size_t i = 0; i < 4; ++i){
			_materias[i] = other._materias[i] ? other._materias[i]->clone() : nullptr;
		}
	}
	return *this;
}

const std::string& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		for (auto& materia : _materias) {
			if (!materia) {
				materia = m;
				break;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && static_cast<size_t>(idx) < 4)
	{
		_materias[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && static_cast<size_t>(idx) < 4 && _materias[idx])
	{
		_materias[idx]->use(target);
	}
}