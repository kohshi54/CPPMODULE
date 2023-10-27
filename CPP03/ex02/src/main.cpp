#include "FragTrap.hpp"

int main()
{
	FragTrap a("a");
	std::cout << a.getName() << std::endl;
	std::cout << a.getHitPoints() << std::endl;
	std::cout << a.getEnergyPoints() << std::endl;
	std::cout << a.getAttackDamage() << std::endl;
	a.highFivesGuys();
}