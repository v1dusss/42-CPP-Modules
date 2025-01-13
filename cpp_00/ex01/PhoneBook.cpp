#include "PhoneBook.hpp"
#include <cctype>
#include <string>

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

bool is_alpha(const std::string& str) {
	for (char c : str) {
		if (!std::isalpha(c)) {
			return false;
		}
	}
	return true;
}

bool is_numeric(const std::string& str) {
	for (char c : str) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
	return true;
}

void PhoneBook::add_contact(int index)
{
	std::string input;

	// First name
	do {
		std::cout << "First name: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Input cannot be empty" << std::endl;
		}
		else if (!is_alpha(input)) {
			std::cout << "Invalid input. Please use alphabetical letters only.\n";
		}
	} while (!is_alpha(input) || input.empty());
	contacts[index].set_first_name(input);

	// Last name
	do {
		std::cout << "Last name: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Input cannot be empty" << std::endl;
		}
		else if (!is_alpha(input)) {
			std::cout << "Invalid input. Please use alphabetical letters only.\n";
		}
	} while (!is_alpha(input) || input.empty());
	contacts[index].set_last_name(input);

	// Nickname
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	contacts[index].set_nickname(input);

	// Phone number
	do {
		std::cout << "Phone number: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Input cannot be empty" << std::endl;
		}
		else if (!is_numeric(input)) {
			std::cout << "Invalid input. Please use numerical digits only.\n";
		}
	} while (!is_numeric(input) || input.empty());
	contacts[index].set_phone_number(input);

	// Darkest secret
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
