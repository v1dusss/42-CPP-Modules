#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap_" << _name << " has been spawned!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap_" << _name << " has been spawned!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap_" << _name << " has been destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "copy constructor called: FragTrap" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "assignation operator called: FragTrap" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitpoints = copy._hitpoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "High-Five! " << std::endl;
}
