#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap parameterized constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
	{
		std::cout << "No hitPoints or energyPoints!" << std::endl;
		return ;
	}

	std::cout << "ScavTrap"
				<< " "
				<< this->getName()
				<< " "
				<< "attacks"
				<< " "
				<< target
				<< ", causing"
				<< " "
				<< this->getAttackDamage()
				<< " "
				<< "points of damage!" << std::endl;

	if (this->getEnergyPoints() != 0)
		this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}