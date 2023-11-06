#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;

    public:
        AAnimal();
        Animal(std::string type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &rhs);
        virtual ~Animal();

        virtual void makeSound() const = 0;

        const std::string &getType() const;
};

#endif
