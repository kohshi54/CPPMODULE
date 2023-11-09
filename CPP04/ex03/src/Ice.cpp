#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
#ifdef DEBUG
	std::cout << GREEN << "Ice default constructor called" << RESET << std::endl;
#endif
}

Ice::Ice(const Ice& other) : AMateria(other)
{
#ifdef DEBUG
	std::cout << GREEN << "Ice copy constructor called" << RESET << std::endl;
#endif
}

Ice &Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
#ifdef DEBUG
		std::cout << YELLOW << "Ice copy assignment operator called" << RESET << std::endl;
#endif
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice()
{
#ifdef DEBUG
	std::cout << RED << "Ice destructor called" << RESET << std::endl;
#endif
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}