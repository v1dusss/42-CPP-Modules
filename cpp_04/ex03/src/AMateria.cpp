#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
}

AMateria::AMateria(const std::string& copy) : _type(copy)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

const std::string& AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}