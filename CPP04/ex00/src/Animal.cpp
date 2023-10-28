#include "Animal.hpp"

Animal::Animal() : _type("")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal parametrized constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &rhs)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

const std::string &Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    std::cout << "animal is making a sound" << std::endl;
}