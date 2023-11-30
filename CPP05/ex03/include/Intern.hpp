#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();

        AForm* makeForm(const std::string& name, const std::string& target);

	private:
		Intern(const Intern& other);
        Intern& operator=(const Intern& rhs);

		static AForm* (* const makeFormExecute[])(const std::string&);
		static AForm* makeShrubberyCreationForm(const std::string& target);
		static AForm* makeRobotomyRequestForm(const std::string& target);
		static AForm* makePresidentialPardonForm(const std::string& target);
};

#endif
