#include "phonebook.hpp"

int main(void)
{
	PhoneBook myPhoneBook;
	std::string input;

	while (1)
	{
		std::cout << "Please input a command (ADD, SEARCH, EXIT)" << std::endl;
		std::cout << PROMPT;
		std::cin >> input;
	
		if (input == "EXIT")
			break ;
		else if(input == "ADD")
		{
			Contact newContact;
			std::cout << "COMMAND " << input << " entered!" << std::endl;
			newContact.setContact();
			/* add validation here */
			// newContact.getContact();
			myPhoneBook.addPhoneBook(newContact);

			// myPhoneBook.getPhoneBook();
		}
		else if (input == "SEARCH")
		{
			std::cout << "COMMAND " << input << " entered!" << std::endl;
			myPhoneBook.searchPhoneBook();
			myPhoneBook.displayEntry();
		}
		else
			std::cout << "please enter valid command" << std::endl;
		std::cout << "------------------" << std::endl;
	}
	return (0);
}