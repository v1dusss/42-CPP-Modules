#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Dog* j = new Dog();
	Cat* i = new Cat();

	j->makeSound();
	i->makeSound();

	std::cout << "give me an idea" << std::endl;

	j->setBrainIdea("I'm a dog", 0);
	i->setBrainIdea("I'm a cat", 0);

	std::cout << "I have an idea" << std::endl;

	std::cout << j->getBrainIdea(0) << std::endl;
	std::cout << i->getBrainIdea(0) << std::endl;
	delete j;
	delete i;

	return 0;
}