#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap"), _guardGateMode(false)
{
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap_" << _name << " has been spawned!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardGateMode(false)
{
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap_" << _name << " has been spawned!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), _guardGateMode(other._guardGateMode)
{
	std::cout << "copy constructor called: ScavTrap" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "assignation operator called: ScavTrap" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		this->_guardGateMode = other._guardGateMode;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap_" << _name << " has been destroyed!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (_guardGateMode == true) {
		std::cout << "ScavTrap_" << _name << " is already in gate keeper mode!" << std::endl;
	}
	else if (_energyPoints > 0) {
		std::cout << "ScavTrap_" << _name << " has entered gate keeper mode!" << std::endl;
		_guardGateMode = true;
		_energyPoints -= 1;
	}
	else {
		std::cout << "ScavTrap_" << _name << " is out of energy!" << std::endl;
	}
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		std::cout << "ScavTrap_" << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "ScavTrap_" << _name << " is out of energy!" << std::endl;
		return;
	}
}
