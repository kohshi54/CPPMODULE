#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	(void)name;
	Zombie newZombie;
	newZombie.setName("third");
	newZombie.announce();
}
