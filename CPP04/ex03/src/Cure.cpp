#include "Cure.hpp"

AMateria* Cure::clone() const
{
    return new Cure(*this);
}