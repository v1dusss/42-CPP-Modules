#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("player_1");
	diamond.print_status();
	ScavTrap scav("player_2");
	FragTrap frag("player_3");

	diamond.highFivesGuys();
	diamond.attack("player_2");
	scav.takeDamage(10);
	diamond.beRepaired(10);
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();

	scav.attack("player_3");
	frag.takeDamage(10);
	scav.beRepaired(10);

	frag.attack("player_1");
	diamond.takeDamage(10);
	frag.beRepaired(10);

	return 0;
}
