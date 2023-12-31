#include "Animal.hpp"

Animal::Animal() : _type("")
{
#ifdef DEBUG
    std::cout << GREEN << "Animal constructor called" << RESET << std::endl;
#endif
}

Animal::Animal(std::string type) : _type(type)
{
#ifdef DEBUG
    std::cout << GREEN << "Animal parametrized constructor called" << RESET << std::endl;
#endif
}

Animal::Animal(const Animal &other) : _type(other._type)
{
#ifdef DEBUG
    std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
#endif
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	#ifdef DEBUG
		std::cout << YELLOW << "Animal copy assignment operator called" << RESET << std::endl;
	#endif
	}
    return *this;
}

Animal::~Animal()
{
#ifdef DEBUG
    std::cout << RED << "Animal destructor called" << RESET << std::endl;
#endif
}

const std::string &Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    std::cout << "animal is making a sound" << std::endl;
}