#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a("a");
	a.attack("hello");
	std::cout << a.getName() << std::endl;
	std::cout << a.getHitPoints() << std::endl;
	std::cout << a.getEnergyPoints() << std::endl;
	std::cout << a.getAttackDamage() << std::endl;
	a.takeDamage(5);
	a.beRepaired(10);
	a.attack("world");
	a.takeDamage(15);
	a.attack("no");
	a.highFivesGuys();
	a.whoAmI();
}