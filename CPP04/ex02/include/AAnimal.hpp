#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Color.hpp"

class AAnimal
{
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &rhs);
        virtual ~AAnimal();

        virtual void makeSound() const = 0;

        const std::string &getType() const;
};

#endif

