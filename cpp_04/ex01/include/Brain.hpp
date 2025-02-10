#pragma once

#include <iostream>

#define MAX_IDEAS 100

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
	~Brain();

	void setIdea(const std::string &idea, int index);
	std::string getIdea(int index) const;
};
