#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog")
{
    std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &other)
{
    std::cout << "WrongDog copy constructor called" << std::endl;
    *this = other;
}

WrongDog &WrongDog::operator=(const WrongDog &rhs)
{
	if (this == &rhs)
		return *this;
    std::cout << "WrongDog copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog destructor called" << std::endl;
}

void WrongDog::makeSound() const
{
    std::cout << "bark bark" << std::endl;
}