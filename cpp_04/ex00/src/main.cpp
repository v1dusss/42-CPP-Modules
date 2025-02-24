#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal bob;
	Cat jim;
	Dog tim;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "-------------------------------" << std::endl;
	std::cout << "meta: " << meta->getType() << std::endl;
	std::cout << "dog: " << dog->getType() << std::endl;
	std::cout << "cat: " << cat->getType() << std::endl;
	std::cout << "wrong_cat: " << wrong_cat->getType() << std::endl;
	std::cout << "bob: " << bob.getType() << std::endl;
	std::cout << "jim: " << jim.getType() << std::endl;
	std::cout << "tim: " << tim.getType() << std::endl;

	std::cout << "-------------------------------" << std::endl;
	std::cout << "meta: ";
	meta->makeSound();
	std::cout << "dog: ";
	dog->makeSound();
	std::cout << "cat: ";
	cat->makeSound();
	std::cout << "wrong_cat: ";
	wrong_cat->makeSound();
	std::cout << "bob: ";
	bob.makeSound();
	std::cout << "jim: ";
	jim.makeSound();
	std::cout << "tim: ";
	tim.makeSound();
	std::cout << "-------------------------------" << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete wrong_cat;
	return 0;
}