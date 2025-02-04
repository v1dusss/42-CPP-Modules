#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap scav("ScavTrap");
	FragTrap frag("FragTrap");

	scav.attack("FragTrap");
	frag.takeDamage(20);
	frag.attack("ScavTrap");
	scav.takeDamage(20);
	scav.guardGate();
	frag.highFivesGuys();
	return 0;
}
