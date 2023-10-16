#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Parameterized constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
	{
		std::cout << "No hitPoints or energyPoints!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap"
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

	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->getName()
				<< " "
				<< "took"
				<< " "
				<< amount
				<< " "
				<< "points of damage!" << std::endl;

	if (this->getHitPoints() < amount)
		this->setHitPoints(0);
	else
		this->setHitPoints(this->getHitPoints() - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
	{
		std::cout << "No hitPoints or energyPoints!" << std::endl;
		return ;
	}

	std::cout << this->getName()
				<< " "
				<< "got"
				<< " "
				<< amount
				<< " "
				<< "hit points back!" << std::endl;

	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

const std::string& ClapTrap::getName() const
{
	return this->_name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

void ClapTrap::setName(const std::string& name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
}
