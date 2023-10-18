#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& rhs);
		~ScavTrap();

		ScavTrap(const std::string& name);

		void attack(const std::string &target);
		void guardGate();
};

#endif