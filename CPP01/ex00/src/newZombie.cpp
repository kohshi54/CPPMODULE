#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
	Zombie* newZombie;

	try {
		newZombie = new Zombie;
		newZombie->setName(name);
	} catch (const std::bad_alloc&) {
		std::cout << "Failed to create newZombie" << std::endl;
		return (NULL);
	}
	return (newZombie);
}
