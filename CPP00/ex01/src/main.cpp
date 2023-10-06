#include "phonebook.hpp"

int main(void)
{
	PhoneBook myPhoneBook;
	std::string input;

	while (1)
	{
		try {
			std::cout << "============================================" << std::endl;
			std::cout << "Please input a command (ADD, SEARCH, EXIT)" << std::endl;
			std::cout << PROMPT << std::flush;
			std::cin >> input;

			if (std::cin.eof()) {
				std::cout << std::endl << std::flush;
				throw std::runtime_error("EOF detected");
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
					std::cout << "input not valid, not added" << std::endl;
			}
			else if (input == "SEARCH")
			{
				std::cout << "COMMAND " << input << " entered!" << std::endl;
				myPhoneBook.searchPhoneBook();
				myPhoneBook.displayEntry();
			}
			else
				std::cout << "please enter valid command" << std::endl;
		}
		catch (...) {
			std::cin.clear();
			std::clearerr(stdin);
		}
	}
	return (0);
}