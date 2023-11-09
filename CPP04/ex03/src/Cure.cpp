#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
#ifdef DEBUG
	std::cout << GREEN << "Cure default constructor called" << RESET << std::endl;
#endif
}

Cure::Cure(const Cure &other) : AMateria(other)
{
#ifdef DEBUG
	std::cout << GREEN << "Cure copy constructor called" << RESET << std::endl;
#endif
}

Cure &Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
	{
#ifdef DEBUG
		std::cout << GREEN << "Cure copy assignment operator called" << RESET << std::endl;
#endif
		AMateria::operator=(rhs);
	}
	return *this;
}

Cure::~Cure()
{
#ifdef DEBUG
	std::cout << GREEN << "Cure destructor called" << RESET << std::endl;
#endif
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}