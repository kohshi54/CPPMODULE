#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other)
{
    std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
	}
	std::cout << YELLOW << "Dog copy assignment operator called" << RESET << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "bark bark" << std::endl;
}