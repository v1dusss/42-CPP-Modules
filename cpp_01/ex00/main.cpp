

#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Bar");
	delete zombie;
	randomChump("Foo");
	return 0;
}