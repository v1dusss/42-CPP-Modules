#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(20);
    mstack.push(30);
    mstack.push(8);
    std::cout << mstack.top() << std::endl;

    mstack.pop();
    std::cout << mstack.top() << std::endl;
    std::cout << mstack.size() << std::endl;

    mstack.push(50);
    mstack.push(100);
    mstack.push(3);
    mstack.push(0);

    std::cout << "Iterating through the stack" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    --it;
    while (++it != ite)
        std::cout << *it << std::endl;

    return 0;
}