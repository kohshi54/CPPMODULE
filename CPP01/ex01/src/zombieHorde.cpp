#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	try {
		Zombie *zombies = new Zombie[N];

		for (int i = 0; i < N; ++i)
		{
			zombies[i].setName(name);
		}
		return (zombies);
	} catch (const std::bad_alloc&) {
		std::cout << "Failed to allocate zombieHorde." << std::endl;
		return (NULL);
	}
}