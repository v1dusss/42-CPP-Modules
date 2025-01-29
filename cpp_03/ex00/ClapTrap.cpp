#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "ClapTrap";
	this->_hitpoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitpoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->_name = other._name;
	this->_hitpoints = other._hitpoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string& target)
{
	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	
}
