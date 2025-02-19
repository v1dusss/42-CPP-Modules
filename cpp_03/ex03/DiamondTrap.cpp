#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap"), ScavTrap("DiamondTrap"), FragTrap("DiamondTrap")
{
	std::cout << "DiamondTrap default constructor" << std::endl;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_name = "DiamondTrap";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap name constructor" << std::endl;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_name = "DiamondTrap";
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return (*this);

	ClapTrap::operator=(static_cast<const ClapTrap&>(other));
	this->_name = other._name;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << _name << ", and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
