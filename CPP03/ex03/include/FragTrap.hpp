#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap();

		FragTrap(const std::string& name);

		void highFivesGuys(void);
};

#endif