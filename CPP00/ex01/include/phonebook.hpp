#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

# include <iostream>
# include <string>
#include <iomanip>

# define PROMPT "> "
# define CONTACTSIZE 8
# define COLUMNWIDTH 10

class Contact {
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;

	public:
		Contact();
		void setContact();
		Contact getContact();
		void showFourColumn(int index);
		void showAllColumn(int index);
};

class PhoneBook {
	Contact	phoneBook[CONTACTSIZE];
	int		index;

	public:
		PhoneBook();
		void addPhoneBook(Contact newContact);
		void getPhoneBook();
		void searchPhoneBook();
		void displayEntry();
		void exitPhoneBook();
};

#endif