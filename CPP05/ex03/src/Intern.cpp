#include "Intern.hpp"

Intern::Intern()
{
#ifdef DEBUG
    std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
#endif
}

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

Intern::~Intern()
{
#ifdef DEBUG
    std::cout << RED << "Intern destructor callled" << RESET << std::endl;
#endif
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
#ifdef DEBUG
    std::cout << BLUE << "Intern makeForm() called" << RESET << std::endl;
#endif
    static const std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int index = -1;
    for (int i = 0; i < 3; ++i)
    {
        if (forms[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            index = i;
        }
    }
    switch (index)
    {
        case 0:
            return new ShrubberyCreationForm(target);
        case 1:
            return new RobotomyRequestForm(target);
        case 2:
            return new PresidentialPardonForm(target);
    }
    return NULL;
}