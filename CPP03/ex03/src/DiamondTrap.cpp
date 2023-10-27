#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name")
{
	// this->setName(name); // if you use ClapTrap::setName(), than the _name of ClapTrap is set and not DiamondTrap.
	this->_name = name;
	this->setHitPoints(this->FragTrap::getHitPoints());
	this->setEnergyPoints(this->ScavTrap::getEnergyPoints());
	this->setAttackDamage(this->FragTrap::getAttackDamage());
	std::cout << "DiamondTrap parameterized constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->_name = rhs._name;
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::getName() << std::endl;
}