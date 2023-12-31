#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter
{
    public:
        Character();
        Character(std::string const &name);
        Character(const Character &other);
        Character &operator=(const Character &rhs);
        virtual ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:
        std::string _name;
        AMateria *_inventory[4];
};

#endif
