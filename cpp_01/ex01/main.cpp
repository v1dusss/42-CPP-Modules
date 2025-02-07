#include "Zombie.hpp"

int main()
{
	Zombie* horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	// for (int i = 0; i < 5; i++)
	// 	horde[i].announce();
	return 0;
}