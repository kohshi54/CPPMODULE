#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
#ifdef DEBUG
    std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
#endif
    this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
#ifdef DEBUG
    std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
#endif
    this->_brain = new Brain(*other._brain);
    // *this = other;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
	#ifdef DEBUG
        std::cout << YELLOW << "Cat copy assignment operator called" << RESET << std::endl;
	#endif
        Brain *newBrain = new Brain(*rhs._brain);
        delete this->_brain;
        this->_brain = newBrain;
        AAnimal::operator=(rhs);
    }
    return *this;
}

Cat::~Cat()
{
#ifdef DEBUG
    std::cout << RED << "Cat destructor called" << RESET << std::endl;
#endif
    delete this->_brain;
}

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}