#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal bob;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* w = new WrongCat();
	std::cout << "-------------------------------" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << w->getType() << " " << std::endl;
	std::cout << "-------------------------------" << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	w->makeSound();
	meta->makeSound();

	bob.makeSound();
	std::cout << "-------------------------------" << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete w;
	return 0;
}