#include "phonebook.hpp"

int main(void)
{
	PhoneBook myPhoneBook;
	std::string input;

	while (1)
	{
		std::cout << "============================================" << std::endl;
		std::cout << "Please input a command (ADD, SEARCH, EXIT)" << std::endl;
		std::cout << PROMPT << std::flush;

		try {
			std::cin >> input;
			if (std::cin.eof())
				throw std::runtime_error("EOF detected");
		}
		catch (...)	{
			std::cout << std::endl << std::flush;
			std::cin.clear();
			std::clearerr(stdin);
			continue ;
		}

		if (input == "EXIT")
			break ;
		else if(input == "ADD")
		{
			Contact newContact;
			std::cout << "COMMAND " << input << " entered!" << std::endl;
			newContact.setContact();
			if (newContact.isValid())
				myPhoneBook.addPhoneBook(newContact);
			else
				std::cout << "Invalid input, not added." << std::endl;
		}
		else if (input == "SEARCH")
		{
			std::cout << "COMMAND " << input << " entered!" << std::endl;
			myPhoneBook.searchPhoneBook();
			myPhoneBook.displayEntry();
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}