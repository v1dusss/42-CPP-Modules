#include "PhoneBook.hpp"
#include <cctype>
#include <string>

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact(int index)
{
	std::string input;
	std::cout << "First name: ";
	std::getline(std::cin, input);
	contacts[index].set_first_name(input);
	std::cout << "Last name: ";
	std::getline(std::cin, input);
	contacts[index].set_last_name(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	contacts[index].set_nickname(input);
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	contacts[index].set_phone_number(input);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	contacts[index].set_darkest_secret(input);
}

void PhoneBook::search_contact()
{
	std::cout << "Index: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	int index = std::stoi(input);
	if (index < 0 || index >= PHONEBOOK_SIZE)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].get_darkest_secret() << std::endl;
}
