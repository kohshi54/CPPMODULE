#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
#ifdef DEBUG
    std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
#endif
    this->_brain = new Brain();
}

// to copy base objects as well, Animal copy constructor is called.
Dog::Dog(const Dog &other) : AAnimal(other)
{
#ifdef DEBUG
    std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
#endif
    this->_brain = new Brain(*other._brain);
    // *this = other;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
	#ifdef DEBUG
        std::cout << YELLOW << "Dog copy assignment operator called" << RESET << std::endl;
	#endif
        delete this->_brain;
        this->_brain = new Brain(*rhs._brain);
        AAnimal::operator=(rhs);
    }
    return *this;
}

Dog::~Dog()
{
#ifdef DEBUG
    std::cout << RED << "Dog destructor called" << RESET << std::endl;
#endif
    delete this->_brain;
}

void Dog::makeSound() const
{
    std::cout << "bark bark" << std::endl;
}