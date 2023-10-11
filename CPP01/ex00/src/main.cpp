#include "Zombie.hpp"

int main(void)
{
	Zombie first("first");
	Zombie* second;

	first.announce();
	second = first.newZombie("second");
	second->announce();
	second->randomChump("third");
	delete second;
}

// __attribute__((destructor))
// static void    end()
// {
//     system("leaks -q Zombie");
// }