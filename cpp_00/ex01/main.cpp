#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;

	std::string command;
	int index = 0;

	std::cout << GREEN << "📞 Welcome to the PhoneBook! 📖" << RESET << std::endl;
	std::cout << "Use: " << BOLD << "[ADD] [SEARCH] [EXIT]" << RESET << std::endl << std::endl;

	while(true)
	{
		std::cout << "Enter a command: " << BOLD;
		command = get_input(command);

		std::cout << RESET;
		if (command == "ADD") {
			phonebook.add_contact(index);
			index = (index + 1) % PHONEBOOK_SIZE;
		}
		else if (command == "SEARCH") {
			phonebook.search_contact();
		}
		else if (command == "EXIT") {
			std::cout << GREEN << "👋 Exiting PhoneBook. Goodbye! 👋" << RESET << std::endl;
			break;
		}
		else {
			std::cout << YELLOW << "Invalid command" << RESET << ". Use: " << BOLD << "[ADD] [SEARCH] [EXIT]" << RESET << std::endl;
		}
	}
	return 0;
}