#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <iostream>

class Zombie {
	public:
		Zombie();
		~Zombie();
		void announce( void );
		Zombie* newZombie( std::string name );
		void randomChump( std::string name );

		void setName(std::string name);
		std::string getName();

	private:
		std::string name;
};

#endif