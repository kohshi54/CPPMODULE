#include "phonebook.hpp"

Contact::Contact() : firstname(), lastname(), nickname(), phonenumber(), darkestsecret()
{
	// std::cout << "default constructor Contac() called!!!!!!!!!!! " << std::endl;
	// std::cout << getContact().firstname << std::endl;
}

void Contact::setContact()
{
	// std::cout << "setContact() called!" << std::endl;
	std::cout << "please enter first name" << std::endl;
	std::cin >> this->firstname;
	std::cout << "please enter last name" << std::endl;
	std::cin >> this->lastname;
	std::cout << "please enter nickname" << std::endl;
	std::cin >> this->nickname;
	std::cout << "please enter phone number" << std::endl;
	std::cin >> this->phonenumber;
	std::cout << "please enter darkest secret" << std::endl;
	std::cin >> this->darkestsecret;
}

Contact Contact::getContact()
{
	// std::cout << "getContact() called" << std::endl;
	// std::cout << "Contact set for Sir. " << this->firstname << std::endl;
	return (*this);
}

std::string truncateText(std::string text)
{
	if (text.size() < COLUMNWIDTH)
		return (text);
	return (text.substr(0, COLUMNWIDTH - 1) + ".");
}

void Contact::showFourColumn(int index)
{
    std::cout << std::right << std::setw(10) << index << "|";
    std::cout << std::right << std::setw(10) << truncateText(this->firstname) << "|";
	std::cout << std::right << std::setw(10) << truncateText(this->lastname) << "|";
	std::cout << std::right << std::setw(10) << truncateText(this->nickname) << "|";
	std::cout << std::endl;
}

void Contact::showAllColumn(int index)
{
	(void)index;
	std::cout << "first name: " << this->firstname << std::endl;
	std::cout << "last name: " << this->lastname << std::endl;
	std::cout << "nickname: " << this->nickname << std::endl;
	std::cout << "phone number: " << this->phonenumber << std::endl;
	std::cout << "darkest secret: " << this->darkestsecret << std::endl;
}


// first name, last name, nickname, phone number, and
// darkest secret.