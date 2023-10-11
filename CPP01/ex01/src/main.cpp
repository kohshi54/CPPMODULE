#include "Zombie.hpp"

int main(void)
{
	Zombie zombie;

	zombie.setName("primary");
	zombie.announce();
	Zombie* zombies = zombie.zombieHorde(3, "secondary");
	std::cout << "------" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		zombies[i].announce();
	}
	std::cout << "------" << std::endl;
	delete[] zombies;
	return (0);
}