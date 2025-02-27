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
	std::cout << std::endl;

	// First name
	do {
		std::cout << "First name: ";
		input = get_input(input);
		if (input.empty())
		{
			std::cout << YELLOW << "Input cannot be empty" << RESET << std::endl;
		}
		else if (!is_alpha(input)) {
			std::cout << YELLOW << "Invalid input. Please use alphabetical letters only." << RESET << std::endl;
		}
	} while (!is_alpha(input) || input.empty());
	contacts[index].set_first_name(input);

	// Last name
	do {
		std::cout << "Last name: ";
		input = get_input(input);
		if (input.empty())
		{
			std::cout << YELLOW << "Input cannot be empty" << RESET << std::endl;
		}
		else if (!is_alpha(input)) {
			std::cout << YELLOW << "Invalid input. Please use alphabetical letters only." << RESET << std::endl;
		}
	} while (!is_alpha(input) || input.empty());
	contacts[index].set_last_name(input);

	// Nickname
	std::cout << "Nickname: ";
	input = get_input(input);
	contacts[index].set_nickname(input);

	// Phone number
	do {
		std::cout << "Phone number: ";
		input = get_input(input);
		if (input.empty())
		{
			std::cout << YELLOW << "Input cannot be empty" << RESET << std::endl;
		}
		else if (!is_numeric(input)) {
			std::cout << YELLOW << "Invalid input. Please use numerical digits only." << RESET << std::endl;
		}
	} while (!is_numeric(input) || input.empty());
	contacts[index].set_phone_number(input);

	// Darkest secret
	std::cout << "Darkest secret: ";
	input = get_input(input);
	contacts[index].set_darkest_secret(input);

	std::cout << GREEN << "Contact added successfully!" << RESET << std::endl << std::endl;
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
		std::cout << std::endl << std::endl;
	}
}

void PhoneBook::search_contact()
{
	std::cout << std::endl;
	this->print_contact_tabel();
	std::string input;
	do {
		std::cout << "Enter the index of the contact: ";
		input = get_input(input);
		if (input.empty()) {
			std::cout << YELLOW << "Input cannot be empty" << RESET << std::endl;
		}
		else if (!is_numeric(input)) {
			std::cout << YELLOW<< "Invalid input. Please use numerical digits only." << RESET << std::endl;
		}
		else if (std::atoi(input.c_str()) <= 0 || std::atoi(input.c_str()) > PHONEBOOK_SIZE || input.length() != 1) {
				std::cout << YELLOW << "Invalid index. Please enter a number between 1 and " << PHONEBOOK_SIZE << RESET << std::endl;
		}
	} while (!is_numeric(input) || input.empty() || std::atoi(input.c_str()) <= 0 || std::atoi(input.c_str()) > PHONEBOOK_SIZE);

	int index = std::atoi(input.c_str()) - 1;
	std::cout << std::endl;
	std::cout << std::setw(15) << std::right << "First name" << ": " << contacts[index].get_first_name() << std::endl;
	std::cout << std::setw(15) << std::right << "Last name" << ": " << contacts[index].get_last_name() << std::endl;
	std::cout << std::setw(15) << std::right << "Nickname" << ": " << contacts[index].get_nickname() << std::endl;
	std::cout << std::setw(15) << std::right << "Phone number" << ": " << contacts[index].get_phone_number() << std::endl;
	std::cout << std::setw(15) << std::right << "Darkest secret" << ": " << contacts[index].get_darkest_secret() << std::endl;
	std::cout << std::endl;
}

std::string get_input(std::string prompt)
{
	std::getline(std::cin, prompt);
	if (std::cin.eof()) {
		exit(1);
	}
	return prompt;
}
