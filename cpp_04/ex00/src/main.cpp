#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal bob;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	bob.makeSound();
	delete meta;
	delete j;
	delete i;
	return 0;
}