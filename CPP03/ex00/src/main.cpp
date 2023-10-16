#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("a");
	a.attack("hello");
	a.takeDamage(5);
	a.beRepaired(10);
	a.attack("world");
	a.takeDamage(15);
	a.attack("no");
}