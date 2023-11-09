#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	std::cout << "===========================" << std::endl;

	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		AMateria* extra;
		extra = src->createMateria("cure");
		me->equip(extra); // inventory full, so does nothing.
		delete extra;
		extra = src->createMateria("cure");
		me->equip(extra); // inventory full, so does nothing.
		delete extra;
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		delete bob;
		delete me;
		delete src;
	}

	std::cout << "===========================" << std::endl;

	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->use(-1, *bob); // non-existent
		me->use(0, *bob);
		me->use(1, *bob); // non-existent
		me->use(2, *bob); // non-existent
		me->use(3, *bob); // non-existent
		me->use(4, *bob); // extra
		delete bob;
		delete me;
		delete src;
	}

	std::cout << "===========================" << std::endl;

	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		me->unequip(0); // non-existent
		me->unequip(0); // non-existent
		me->unequip(1); // non-existent
		me->unequip(2); // non-existent
		delete bob;
		delete me;
		delete src;
	}
    return 0;
}

#ifdef DEBUG
__attribute__((destructor))
static void destructor() {
    system("leaks -q Animal");
}
#endif