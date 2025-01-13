#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;

	std::string command;
	int index = 0;
	while(1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact(index++);
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
		if (index == PHONEBOOK_SIZE)
			index = 0;
	}
	return 0;
}