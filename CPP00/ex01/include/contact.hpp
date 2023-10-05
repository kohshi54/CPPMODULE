#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <iostream>

class Contact {
	public:
		Contact();
		void setContact();
		Contact getContact();
		void showFourColumn(int index);
		void showAllColumn(int index);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
		std::string darkestsecret;
};

#endif