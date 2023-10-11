#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__
#include <iostream>

class Zombie {
	public:
		Zombie();
		~Zombie();

		void announce( void );
		Zombie* zombieHorde( int N, std::string name );
		void setName(std::string name);
		const std::string& getName();

	private:
		std::string _name;
};

#endif
