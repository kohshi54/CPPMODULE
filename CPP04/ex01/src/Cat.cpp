#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this == &rhs)
		return *this;
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}