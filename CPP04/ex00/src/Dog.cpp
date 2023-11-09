#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		std::cout << YELLOW << "Dog copy assignment operator called" << RESET << std::endl;
		Animal::operator=(rhs);
	}
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