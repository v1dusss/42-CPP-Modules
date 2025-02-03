#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap("ScavTrap_1");
	ScavTrap scavTrap2("ScavTrap_2");
	ScavTrap scavTrap3("ScavTrap_3");

	scavTrap.attack("ScavTrap_2");
	scavTrap2.takeDamage(20);
	scavTrap.guardGate();
	scavTrap3.attack("ScavTrap_2");
	return 0;
}
