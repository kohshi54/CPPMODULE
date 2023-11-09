#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{
#ifdef DEBUG
	std::cout << GREEN << "AMaetria default constructor called" << RESET << std::endl;
#endif
}

AMateria::AMateria(std::string const &type) : _type(type)
{
#ifdef DEBUG
    std::cout << GREEN << "AMaetria parameterized constructor called" << RESET << std::endl;
#endif
}

AMateria::AMateria(const AMateria &other) : _type(other.getType())
{
#ifdef DEBUG
    std::cout << GREEN << "AMaetria copy constructor called" << RESET << std::endl;
#endif
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

AMateria::~AMateria()
{
#ifdef DEBUG
    std::cout << GREEN << "AMateria destructor called" << RESET << std::endl;
#endif
}

std::string const &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << GREEN << "AMateria use function called" << target.getName() << std::endl;
}