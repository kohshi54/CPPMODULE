#include "Intern.hpp"

Intern::Intern()
{
#ifdef DEBUG
    std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
#endif
}

/* Intern does not contain parameter, so do not need these.
Intern::Intern(const Intern& other)
{
#ifdef DEBUG
    std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
#endif
    (void)other;
}

Intern& Intern::operator=(const Intern& rhs)
{
#ifdef DEBUG
    std::cout << YELLOW << "Intern copy assignment operator called" << RESET << std::endl;
#endif
    (void)rhs;
    return *this;
}
*/

Intern::~Intern()
{
#ifdef DEBUG
    std::cout << RED << "Intern destructor callled" << RESET << std::endl;
#endif
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* (*const Intern::makeFormExecute[])(const std::string&) = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
#ifdef DEBUG
    std::cout << BLUE << "Intern makeForm() called" << RESET << std::endl;
#endif
    static const std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (size_t i = 0; i < forms->length(); ++i)
    {
        if (forms[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
			return (makeFormExecute[i])(target);
        }
    }
	throw std::runtime_error(std::string("Specified form does not exist"));
    return NULL;
}
