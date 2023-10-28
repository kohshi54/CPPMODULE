#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
    public:
        WrongDog();
        WrongDog(const WrongDog &other);
        WrongDog &operator=(const WrongDog &rhs);
        ~WrongDog();

        void makeSound() const;
};

#endif