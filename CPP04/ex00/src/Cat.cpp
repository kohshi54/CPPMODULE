#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
	}
	std::cout << YELLOW << "Cat copy assignment operator called" << RESET << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meow meow" << std::endl;
}