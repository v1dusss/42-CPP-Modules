#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("default")
{
	for (auto& materia : _materias){
		materia = nullptr;
	}
	for (auto& garbage : _garbage){
		garbage = nullptr;
	}
}

Character::Character(const std::string& name) : _name("default")
{
	_name = name;
	for (auto& materia : _materias){
		materia = nullptr;
	}
	for (auto& garbage : _garbage){
		garbage = nullptr;
	}
}

Character::Character(const Character& other) : _name(other._name)
{
	for (size_t i = 0; i < 4; ++i){
		_materias[i] = other._materias[i] ? other._materias[i]->clone() : nullptr;
	}
	for (int i = 0; i < 100; ++i){
		if (_garbage[i]){
			_garbage[i] = other._garbage[i]->clone();
		}
		else{
			_garbage[i] = nullptr;
		}
	}
}

Character::~Character()
{
	for (auto& materia : _materias){
		delete materia;
	}
	for (auto& garbage : _garbage){
		delete garbage;
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
			if (other._materias[i])
				_materias[i] = other._materias[i]->clone();
			else
				_materias[i] = nullptr;
		}
		for (auto& garbage : _garbage){
			if (garbage)
				delete garbage;
		}
		for (int i = 0; i < 100; ++i){
			if (other._garbage[i]){
				_garbage[i] = other._garbage[i]->clone();
			}
			else{
				_garbage[i] = nullptr;
			}
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
	if (m && m != _materias[0] && m != _materias[1] && m != _materias[2] && m != _materias[3])
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
		for (auto& garbage : _garbage){
			if (!garbage){
				garbage = _materias[idx];
				break;
			}
		}
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