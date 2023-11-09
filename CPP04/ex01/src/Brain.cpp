#include "Brain.hpp"

Brain::Brain()
{
#ifdef DEBUG
    std::cout << GREEN << "Brain default constructor called." << RESET << std::endl;
#endif
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = "";
    }
}

Brain::Brain(const Brain &other)
{
#ifdef DEBUG
    std::cout << GREEN << "Brain copy constructor called." << RESET << std::endl;
#endif
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain &rhs)
{
    if (this != &rhs)
    {
	#ifdef DEBUG
        std::cout << YELLOW << "Brain copy assignment operator called." << RESET << std::endl;
	#endif
        for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
#ifdef DEBUG
    std::cout << RED << "Brain destructor called." << RESET << std::endl;
#endif
}
