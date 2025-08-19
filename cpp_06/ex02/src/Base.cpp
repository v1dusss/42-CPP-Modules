#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base()
{}

Base* generate(void)
{
	std::srand(std::time(NULL));
	int random = std::rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << RED "Generated class A" RESET << std::endl;
			return new A();
		case 1:
			std::cout << RED "Generated class B" RESET << std::endl;
			return new B();
		case 2:
			std::cout << RED "Generated class C" RESET << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A";
		return;
	}
	catch (std::exception&) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B";
		return;
	}
	catch (std::exception&) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C";
		return;
	}
	catch (std::exception&) {}
}
