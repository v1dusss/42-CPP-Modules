#include <iostream>
#include <iomanip>
#include "Contact.hpp"

#pragma once

// ANSI escape codes for color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

#ifndef PHONEBOOK_SIZE
#define PHONEBOOK_SIZE 8
#endif
class PhoneBook
{
private:
	Contact contacts[PHONEBOOK_SIZE];
	void print_contact_tabel();
	void print_one_cell(std::string str);

public:
	PhoneBook();
	~PhoneBook();

	void add_contact(int index);
	void search_contact();
};