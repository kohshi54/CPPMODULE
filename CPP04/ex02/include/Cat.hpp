#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public:
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &rhs);
        ~Cat();

        void makeSound() const;
    
    private:
        Brain* _brain;
};

#endif