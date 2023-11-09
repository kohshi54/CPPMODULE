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
    std::cout << DEBUG << "MateriaSource copy constructor called" << RESET << std::endl;
#endif
    for (int i = 0; i < 4; ++i)
    {
        if (other._sources[i])
            _sources[i] = other._sources[i]->clone();
        else
            _sources[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete _sources[i];
            if (other._sources[i])
                _sources[i] = other._sources[i]->clone();
            else
                _sources[i] = NULL;
        }
    }
    return *this;
}
MateriaSource::~MateriaSource()
{
#ifdef DEBUG
    std::cout << GREEN << "MateriaSource destructor called" << RESET << std::endl;
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
        if (_sources[i] == NULL)
        {
            _sources[i] = m;
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_sources[i] && _sources[i]->getType() == type)
            return _sources[i]->clone();
    }
    return NULL;
}
