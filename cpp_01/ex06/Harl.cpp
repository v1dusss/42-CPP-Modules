#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n\n";
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << "\n\n";
}

void Harl::complain(std::string level)
{
	void (Harl::*functions[4])() = { 
		&Harl::debug, 
		&Harl::info, 
		&Harl::warning, 
		&Harl::error
	};
	std::string arr[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	int i;
	for (i = 0; i < 4; i++)
	{
		if (level == arr[i])
			break;
	}
	if (i == 4){
		std::cerr << "[ Probably complaining about insignificant problems ]\n";
		return;
	}

	switch (i) {
		case 0:
			(this->*functions[0])();
			[[fallthrough]];
		case 1:
			(this->*functions[1])();
			[[fallthrough]];
		case 2:
			(this->*functions[2])();
			[[fallthrough]];
		case 3:
			(this->*functions[3])();
			break;
	}
}
