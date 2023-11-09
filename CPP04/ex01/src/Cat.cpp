#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
    this->_brain = new Brain(*other._brain);
    // *this = other;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        std::cout << YELLOW << "Cat copy assignment operator called" << RESET << std::endl;
        Brain *newBrain = new Brain(*rhs._brain);
        delete this->_brain;
        this->_brain = newBrain;
        Animal::operator=(rhs);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << RED << "Cat destructor called" << RESET << std::endl;
    delete this->_brain;
}

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}