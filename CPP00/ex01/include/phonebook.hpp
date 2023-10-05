#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

# include <iostream>
# include <string>
# include <iomanip>

#include "contact.hpp"

# define PROMPT "> "
# define CONTACTSIZE 8
# define COLUMNWIDTH 10

class PhoneBook {
	public:
		PhoneBook();
		void addPhoneBook(Contact newContact);
		void getPhoneBook();
		void searchPhoneBook();
		void displayEntry();
		void exitPhoneBook();

	private:
			Contact	phoneBook[CONTACTSIZE];
			int		index;

};

#endif