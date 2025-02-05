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

void PhoneBook::print_one_cell(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << str << "|";
}

void PhoneBook::print_contact_tabel()
{
	std::cout << "     Index|First name| Last name|  Nickname|" << std::endl;
	for (int i = 0; i < PHONEBOOK_SIZE && !contacts[i].get_first_name().empty(); i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		print_one_cell(contacts[i].get_first_name());
		print_one_cell(contacts[i].get_last_name());
		print_one_cell(contacts[i].get_nickname());
		std::cout << std::endl;
	}
}

void PhoneBook::search_contact()
{
	this->print_contact_tabel();
	std::string input;
	do {
		std::cout << "Enter the index of the contact: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Input cannot be empty" << std::endl;
		}
		else if (!is_numeric(input)) {
			std::cout << "Invalid input. Please use numerical digits only.\n";
		}
		else if (std::stoi(input) <= 0 || std::stoi(input) > PHONEBOOK_SIZE) {
			std::cout << "Invalid index. Please enter a number between 1 and " << PHONEBOOK_SIZE << ".\n";
		}
	} while (!is_numeric(input) || input.empty() || std::stoi(input) <= 0 || std::stoi(input) > PHONEBOOK_SIZE);
	//int index = std::stoi(input) - 1;

}
