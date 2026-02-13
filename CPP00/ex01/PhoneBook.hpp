#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook();

		void	addContact();
		void	search();
		
	private:
		int		id;
		int		count;
		Contact	contacts[8];
		
		void	indexContact(const Contact &contact);
		void	displayList();
		void	displayContact(int position);
};



#endif