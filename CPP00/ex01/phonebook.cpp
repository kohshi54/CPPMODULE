#include "phonebook.hpp"

PhoneBook::PhoneBook() : index(), phoneBook()
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
	std::cin >> index;
    if (std::cin.fail()) 
    {
        std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        return ;
    }
	if (index < 0 || CONTACTSIZE - 1 < index)
	{
		std::cout << "wrong entry specified... " << std::endl;
		return ;
	}
	this->phoneBook[index].showAllColumn(index);
}