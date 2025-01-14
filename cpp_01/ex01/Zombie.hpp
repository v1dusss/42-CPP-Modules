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
	void set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );