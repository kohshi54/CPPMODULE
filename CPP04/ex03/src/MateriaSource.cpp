#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        this->_sources[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
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
    std::cout << "MateriaSource destructor called" << std::endl;
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
