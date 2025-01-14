#include <iostream>

#pragma once

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();

	void announce( void );
	std::string get_name();
	void set_name(std::string name);
};

Zombie* newZombie( std::string name );
void randomChump(std::string name);