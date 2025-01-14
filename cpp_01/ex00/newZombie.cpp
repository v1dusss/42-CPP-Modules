#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombie = new Zombie();
	zombie->set_name(name);
	zombie->announce();
	return zombie;
}
