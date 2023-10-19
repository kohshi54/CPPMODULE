#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap parameterized constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap requests highfive!" << std::endl;
}