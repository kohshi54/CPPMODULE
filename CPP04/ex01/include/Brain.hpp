#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "Color.hpp"

class Brain
{
    public:
        Brain();
        Brain(const Brain &other);
        Brain& operator=(const Brain &rhs);
        ~Brain();

    private:
        std::string ideas[100];
};

#endif