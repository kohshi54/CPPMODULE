#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& rhs);
		~DiamondTrap();

		DiamondTrap(const std::string& name);

		void whoAmI();
	
	private:
		std::string _name;

};

#endif