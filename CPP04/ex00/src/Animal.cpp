#include "Animal.hpp"

Animal::Animal() : _type("")
{
    std::cout << GREEN << "Animal constructor called" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << GREEN << "Animal parametrized constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this == &rhs)
		return *this;
	std::cout << YELLOW << "Animal copy assignment operator called" << RESET << std::endl;
	this->_type = rhs._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

const std::string &Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    std::cout << "animal is making a sound" << std::endl;
}