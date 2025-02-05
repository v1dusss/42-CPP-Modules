#include <iostream>
#include <iomanip>
#include "Contact.hpp"

#pragma once

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