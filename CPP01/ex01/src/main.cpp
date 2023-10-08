#include "Zombie.hpp"

int main(void)
{
	Zombie zombie;

	zombie.setName("original");
	zombie.announce();
	Zombie* zombies = zombie.zombieHorde(3, "second");
	delete[] zombies;
	return (0);
}