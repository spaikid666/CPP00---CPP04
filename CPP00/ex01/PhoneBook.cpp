#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : id(0), count(0) {}

static	std::string	readNonEmptyField(const std::string &prompt)
{
	std::string	input;

	std::cout << prompt;
	std::cout << "> ";

	while (true)
	{
		if (!getline(std::cin, input))
		{
			std::cout << "Input error or EOF\nExiting the program ...\n";
			exit(1);
		}
		if (!input.empty())
			return input;
		
		std::cout << "Field cannot be empty. Please try again.\n> ";
	}
}

static	Contact	createContact()
{
	Contact		contact;
	std::string	name;
	std::string surname;
	std::string	nickname;
	std::string	phone;
	std::string	secret;

	name = readNonEmptyField("Add Name:\n");
	surname = readNonEmptyField("Add Last Name:\n");
	nickname = readNonEmptyField("Add Nickname:\n");
	phone = readNonEmptyField("Add Phone:\n");
	secret = readNonEmptyField("Add Secret:\n");

	contact.setFirstName(name);
	contact.setLastName(surname);
	contact.setNickname(nickname);
	contact.setPhone(phone);
	contact.setSecret(secret);

	return contact;
}

void PhoneBook::indexContact(const Contact &contact)
{
	contacts[id] = contact;

	if (count < 8)
		count++;
	
	id = (id + 1) % 8;
}

void	PhoneBook::addContact()
{
	Contact	c;

	c = createContact();
	indexContact(c);
}


static	void printField(const std::string &field, bool boolean)
{
	std::string output = field;

	if (boolean == true)
	{
		if (output.length() > 10)
		{
			output = output.substr(0, 9) + ".";
		}
		std::cout << std::setw(10) << output;
	}
	else
		std::cout << output;
}

void PhoneBook::displayContact(int position)
{
	std::cout << "First Name : ";
	printField(contacts[position - 1].getName(), false);
	std::cout << "\n";
	std::cout << "Last Name : ";
	printField(contacts[position - 1].getLastName(), false);
	std::cout << "\n";
	std::cout << "Nickname : ";
	printField(contacts[position - 1].getNickname(), false);
	std::cout << "\n";
	std::cout << "Phone : ";
	printField(contacts[position - 1].getPhone(), false);
	std::cout << "\n";
	std::cout << "Secret : ";
	printField(contacts[position - 1].getSecret(), false);
	std::cout << "\n";

}

void PhoneBook::displayList()
{
	std::cout << "--------------------------------------------------------\n";
	std::cout << "|Index     |First Name|Last Name |Nickname  |Phone     |\n";

	for (int i = 0; i < count; ++i)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1 << "|";
		printField(contacts[i].getName(), true);
		std::cout << "|";
		printField(contacts[i].getLastName(), true);
		std::cout << "|";
		printField(contacts[i].getNickname(), true);
		std::cout << "|";
		printField(contacts[i].getPhone(), true);
		std::cout << "|\n";
	}
	std::cout << "--------------------------------------------------------\n";
}


void	PhoneBook::search()
{
	if (count == 0)
	{
		std::cout << "The PhoneBook is empty, please add a contact first\n\n";
		return;
	}
	
	std::string	input;
	
	std::cout << "Please select a contact to be displayed from the list below:\n";
	
	displayList();
	
	while (true)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nInput error or EOF\nExiting the program ...\n";
			std::exit(0);
		}

		if (std::atoi(input.c_str()) > 0 && std::atoi(input.c_str()) < 9)
		{
			displayContact(std::atoi(input.c_str()));
			break;
		}
		else
			std::cout << "Error: Please provide a number between 1 - 8\n";
	}
}