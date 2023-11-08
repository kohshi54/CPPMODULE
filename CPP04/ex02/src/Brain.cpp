#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called." << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = "";
    }
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called." << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain &rhs)
{
    if (this != &rhs)
    {
        std::cout << "Brain copy assignment operator called." << std::endl;
        for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}