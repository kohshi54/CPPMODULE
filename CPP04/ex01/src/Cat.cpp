#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
    // *this = other;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        std::cout << "Cat copy assignment operator called" << std::endl;
        delete this->_brain;
        this->_brain = new Brain(*rhs._brain);
        Animal::operator=(rhs);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}