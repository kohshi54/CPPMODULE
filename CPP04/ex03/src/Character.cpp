#include "Character.hpp"

Character::Character() : _name(""), _inventory()
{
    for(int i = 0; i < 4; ++i)
    {
        this->_inventory[i] = NULL;
    }
#ifdef DEBUG
    std::cout << GREEN << "Character default constructor called" << std::endl;
#endif
}

Character::Character(std::string const &name) : _name(name)
{
    for(int i = 0; i < 4; ++i)
    {
        this->_inventory[i] = NULL;
    }
#ifdef DEBUG
    std::cout << GREEN << "Character parameterized constructor called" << RESET << std::endl;
#endif
}

Character::Character(const Character &other) : _name(other._name)
{
#ifdef DEBUG
    std::cout << GREEN << "Character copy constructor called" << RESET << std::endl;
#endif
    for (int i = 0; i < 4; ++i)
    {
        this->_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
    }
}

Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
#ifdef DEBUG
        std::cout << YELLOW << "Character copy assignment operator called" << RESET << std::endl;
#endif
        for (int i = 0; i < 4; ++i)
        {
            delete this->_inventory[i];
            this->_inventory[i] = rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL;
        }
        this->_name = rhs._name;
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
        delete this->_inventory[i];
    }
#ifdef DEBUG
    std::cout << RED << "Character destructor called" << RESET << std::endl;
#endif
}

std::string const &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx)
{
    if (0 <= idx && idx <= 3)
    {
        this->_inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (0 <= idx && idx <= 3)
    {
        if (this->_inventory[idx] != NULL)
        {
            this->_inventory[idx]->use(target);
        }
    }
}