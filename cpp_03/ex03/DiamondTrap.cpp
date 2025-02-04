#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap("DiamondTrap"), FragTrap("DiamondTrap")
{
	_hitpoints = FragTrap::_hitpoints;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ScavTrap(other), FragTrap(other)
{
	
}

DiamondTrap::~DiamondTrap()
{
	
}

void DiamondTrap::attack(std::string const & target)
{
	
}

void DiamondTrap::whoAmI()
{
	
}
