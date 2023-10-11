#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{

}

Zombie::~Zombie()
{
	std::cout << this->getName() << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

const std::string& Zombie::getName()
{
	return (this->_name);
}