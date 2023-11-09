#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Color.hpp"

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &rhs);
        virtual ~Animal();

        virtual void makeSound() const;

        const std::string &getType() const;
};

#endif
