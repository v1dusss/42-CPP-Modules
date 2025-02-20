#include "Cat.hpp"
#include "Dog.hpp"

// int main()
// {
// 	Dog* dog = new Dog();
// 	Cat* cat = new Cat();
// 	Cat* ben = new Cat();

// 	dog->makeSound();
// 	cat->makeSound();

// 	std::cout << "give me an idea" << std::endl;

// 	dog->setBrainIdea("I'm a dog", 0);
// 	cat->setBrainIdea("I'm a cat", 0);
// 	ben = cat;
// 	std::cout << "I have an idea" << std::endl;

// 	ben->setBrainIdea("I hate dogs", 1);

// 	std::cout << "-------------------" << std::endl;
// 	std::cout << "Dog: "<< dog->getBrainIdea(0) << std::endl;
// 	std::cout << "Dog: "<< dog->getBrainIdea(1) << std::endl;
	
// 	std::cout << "-------------------" << std::endl;
	
// 	std::cout << "Cat: " << cat->getBrainIdea(0) << std::endl;
// 	std::cout << "Cat: " << cat->getBrainIdea(1) << std::endl;
	
// 	std::cout << "-------------------" << std::endl;

// 	std::cout << "copy: " << ben->getBrainIdea(0) << std::endl;
// 	std::cout << "copy: " << ben->getBrainIdea(1) << std::endl;
	
// 	std::cout << "-------------------" << std::endl;
// 	delete ben;
// 	delete dog;
// 	delete cat;

// 	return 0;
// }

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void deepCopyTest()
{
    std::cout << "### Creating original Cat ###" << std::endl;
    Cat originalCat;
    originalCat.setBrainIdea("I love sleeping", 0);
    originalCat.setBrainIdea("I chase mice", 1);

    std::cout << "\n### Creating a copy using Copy Constructor ###" << std::endl;
    Cat copiedCat(originalCat);

    std::cout << "\n### Modifying original Cat's brain ###" << std::endl;
    originalCat.setBrainIdea("I hate water", 1);

    std::cout << "\n### Checking if the copy remains unchanged ###" << std::endl;
    std::cout << "Original Cat Idea[0]: " << originalCat.getBrainIdea(0) << std::endl;
    std::cout << "Original Cat Idea[1]: " << originalCat.getBrainIdea(1) << std::endl;
    
    std::cout << "Copied Cat Idea[0]: " << copiedCat.getBrainIdea(0) << std::endl;
    std::cout << "Copied Cat Idea[1]: " << copiedCat.getBrainIdea(1) << std::endl;

    std::cout << "\n### Test Passed if Copied Cat's Idea[1] is NOT 'I hate water' ###\n" << std::endl;
}

int main()
{
    deepCopyTest();
    return 0;
}
