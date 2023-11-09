#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("")
{
    std::cout << GREEN << "AAnimal constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << GREEN << "AAnimal parametrized constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	if (this == &rhs)
		return *this;
	std::cout << YELLOW << "AAnimal copy assignment operator called" << RESET << std::endl;
	this->_type = rhs._type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << RED << "AAnimal destructor called" << RESET << std::endl;
}

const std::string &AAnimal::getType() const
{
    return this->_type;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal is making a sound" << std::endl;
}