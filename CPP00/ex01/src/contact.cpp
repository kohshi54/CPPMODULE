#include "phonebook.hpp"

Contact::Contact() : firstname(), lastname(), nickname(), phonenumber(), darkestsecret()
{
	// std::cout << "default constructor Contac() called!!!!!!!!!!! " << std::endl;
	// std::cout << getContact().firstname << std::endl;
}

void Contact::setContact()
{
	try {
		// std::cout << "setContact() called!" << std::endl;
		std::cout << "please enter first name" << std::endl;
		std::cout << PROMPT << std::flush;
		std::cin >> this->firstname;
		if (std::cin.eof())
			throw std::runtime_error("EOF detected");
		std::cout << "please enter last name" << std::endl;
		std::cout << PROMPT << std::flush;
		std::cin >> this->lastname;
		if (std::cin.eof())
			throw std::runtime_error("EOF detected");
		std::cout << "please enter nickname" << std::endl;
		std::cout << PROMPT << std::flush;
		std::cin >> this->nickname;
		if (std::cin.eof())
			throw std::runtime_error("EOF detected");
		std::cout << "please enter phone number" << std::endl;
		std::cout << PROMPT << std::flush;
		std::cin >> this->phonenumber;
		if (std::cin.eof())
			throw std::runtime_error("EOF detected");
		std::cout << "please enter darkest secret" << std::endl;
		std::cout << PROMPT << std::flush;
		std::cin >> this->darkestsecret;
		if (std::cin.eof())
			throw std::runtime_error("EOF detected");
	}
	catch (...) {
		std::cin.clear();
		std::clearerr(stdin);
		std::cout << std::endl << std::flush;
	}

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

bool Contact::isValid()
{
	if (this->firstname.empty())
		return (false);
	if (this->lastname.empty())
		return (false);
	if (this->nickname.empty())
		return (false);
	if (this->phonenumber.empty())
		return (false);
	if (this->darkestsecret.empty())
		return (false);
	return (true);
}

std::string Contact::getFirstName() const { return firstname; }
std::string Contact::getLastName() const { return lastname; }
std::string Contact::getNickName() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phonenumber; }
std::string Contact::getDarkestSecret() const { return darkestsecret; }
