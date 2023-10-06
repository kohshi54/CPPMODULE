#include "phonebook.hpp"

PhoneBook::PhoneBook() : phoneBook(), index()
{
}

void PhoneBook::addPhoneBook(Contact newContact)
{
	// std::cout << "addPhoneBook() called!" << std::endl;
	this->phoneBook[this->index] = newContact;
	if (index != CONTACTSIZE - 1)
		this->index++;
	else
		this->index = 0;
}

void PhoneBook::getPhoneBook()
{
	// std::cout << "getPhoneBook() called!" << std::endl;
	this->phoneBook->getContact();
}

void PhoneBook::searchPhoneBook()
{
	// std::cout << "searchPhoneBook() called! " << std::endl;
	for (int j = 0; j < CONTACTSIZE; j++)
	{
		this->phoneBook[j].showFourColumn(j);
	}
}

void PhoneBook::displayEntry()
{
	int index;

	std::cout << "please enter entry to display!" << std::endl;
	std::cout << PROMPT << std::flush;
	try {
		std::cin >> index;
		if (std::cin.eof())
		{
			std::cout << "EOF detected." << std::endl;	
			throw std::runtime_error("EOF detected");
		}
		else if (std::cin.fail())
		{
			std::cout << "Invalid input." << std::endl;
			std::cin.clear();
			std::clearerr(stdin);
			std::cin.ignore(INT_MAX, '\n');
			throw std::runtime_error("Invalid input");
		}
		else if (index < 0 || CONTACTSIZE - 1 < index)
		{
			std::cout << "Invalid entry specified." << std::endl;
			throw std::runtime_error("Invalid entry");
		}
		this->phoneBook[index].showAllColumn(index);
	}
	catch (...) {
		std::cin.clear();
		std::clearerr(stdin);
	}
}