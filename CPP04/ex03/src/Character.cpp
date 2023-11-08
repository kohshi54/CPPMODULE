#include "Character.hpp"

Character::Character() : _name(""), _inventory()
{
    for(int i = 0; i < 4; ++i)
    {
        this->_inventory[i] = NULL;
    }
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &other) : _name(other._name)
{
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        this->_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
    }
}
 
Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
        std::cout << "Character copy assignment operator called" << std::endl;
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
    std::cout << "Character destructor called" << std::endl;
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