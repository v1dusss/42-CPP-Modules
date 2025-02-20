#include "Brain.hpp"

Brain::Brain()
{
}

Brain::Brain(const Brain &copy)
{
	// for (int i = 0; i < MAX_IDEAS; i++)
	// 	this->ideas[i] = copy.ideas[i];
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy) {
		for (int i = 0; i < MAX_IDEAS; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain got deleted" << std::endl;
}

void Brain::setIdea(const std::string &idea, int index)
{
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	return(this->ideas[index]);
}
