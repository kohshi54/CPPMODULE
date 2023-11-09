#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("")
{
#ifdef DEBUG
    std::cout << GREEN << "AAnimal constructor called" << RESET << std::endl;
#endif
}

AAnimal::AAnimal(std::string type) : _type(type)
{
#ifdef DEBUG
    std::cout << GREEN << "AAnimal parametrized constructor called" << RESET << std::endl;
#endif
}

AAnimal::AAnimal(const AAnimal &other)
{
#ifdef DEBUG
    std::cout << "AAnimal copy constructor called" << std::endl;
#endif
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	if (this == &rhs)
		return *this;
#ifdef DEBUG
	std::cout << YELLOW << "AAnimal copy assignment operator called" << RESET << std::endl;
#endif
	this->_type = rhs._type;
    return *this;
}

AAnimal::~AAnimal()
{
#ifdef DEBUG
    std::cout << RED << "AAnimal destructor called" << RESET << std::endl;
#endif
}

const std::string &AAnimal::getType() const
{
    return this->_type;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal is making a sound" << std::endl;
}