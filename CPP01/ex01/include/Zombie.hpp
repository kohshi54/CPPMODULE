#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__
#include <iostream>

class Zombie {
	public:
		Zombie* zombieHorde( int N, std::string name );
		void setName(std::string name);
		void announce( void );
		Zombie();
		~Zombie();

	private:
		std::string name;
};

#endif
