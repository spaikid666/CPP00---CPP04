#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static	void valid_arguments()
{
	std::cout << "* Please provide a valid command *\n";
	std::cout << " - Use: 'ADD' to save a new contact\n";
	std::cout << " - Use: 'SEARCH' to display a specific contact\n";
	std::cout << " - Use: 'EXIT' to exit\n";
}


int	main (void)
{
	std::string cmd;
	PhoneBook pb;

	std::cout << "Hello! This is your Crappy Awesome Phonebook from the 80's\n";

	while (true)
	{
		valid_arguments();
		std::cout << "> ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << "\nInput error or EOF\nExiting the program ...\n";
			break;
		}

		else if (cmd == "ADD")
			pb.addContact();

		else if (cmd == "SEARCH")
			pb.search();

		else if (cmd == "EXIT")
			break;
	}

	return 0;
}
