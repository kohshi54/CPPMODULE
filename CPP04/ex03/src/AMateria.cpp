#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{
    std::cout << "AMaetria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "AMaetria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other.getType())
{
    std::cout << "AMaetria copy constructor called" << std::endl;
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
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria use function called" << target.getName() << std::endl;
}