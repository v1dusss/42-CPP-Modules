#include "ClapTrap.hpp"

int main()
{
	ClapTrap player1("jan");
	ClapTrap player2("steffen");

	player2.attack("jan");
	player1.takeDamage(10);
	player2.beRepaired(5);
	return 0;
}
