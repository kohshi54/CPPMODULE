#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
#ifdef DEBUG
    std::cout << GREEN <<"MateriaSource constructor called" << RESET << std::endl;
#endif
    for (int i = 0; i < 4; ++i)
    {
        this->_sources[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
#ifdef DEBUG
    std::cout << GREEN << "MateriaSource copy constructor called" << RESET << std::endl;
#endif
    for (int i = 0; i < 4; ++i)
    {
		if (other._sources[i])
			this->_sources[i] = other._sources[i]->clone();
        else
			this->_sources[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
#ifdef DEBUG
    std::cout << YELLOW << "MateriaSource copy constructor called" << RESET << std::endl;
#endif
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete this->_sources[i];
            if (other._sources[i])
                this->_sources[i] = other._sources[i]->clone();
            else
                this->_sources[i] = NULL;
        }
    }
    return *this;
}
MateriaSource::~MateriaSource()
{
#ifdef DEBUG
    std::cout << RED << "MateriaSource destructor called" << RESET << std::endl;
#endif
    for (int i = 0; i < 4; ++i)
    {
        delete this->_sources[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->_sources[i] == NULL)
        {
            this->_sources[i] = m;
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->_sources[i] && this->_sources[i]->getType() == type)
            return this->_sources[i]->clone();
    }
    return NULL;
}
