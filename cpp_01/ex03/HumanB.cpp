#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (weapon == NULL)
	{
		std::cout << this->name << " has no weapon for attacking" << std::endl;
	}
	else
	{
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
	
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
