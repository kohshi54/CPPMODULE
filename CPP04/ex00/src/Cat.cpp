#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		std::cout << YELLOW << "Cat copy assignment operator called" << RESET << std::endl;
		Animal::operator=(rhs);
	}
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