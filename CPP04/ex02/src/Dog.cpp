#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
}

// to copy base objects as well, Animal copy constructor is called.
Dog::Dog(const Dog &other) : AAnimal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain(*other._brain);
    // *this = other;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        std::cout << "Dog copy assignment operator called" << std::endl;
        delete this->_brain;
        this->_brain = new Brain(*rhs._brain);
        AAnimal::operator=(rhs);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

void Dog::makeSound() const
{
    std::cout << "bark bark" << std::endl;
}