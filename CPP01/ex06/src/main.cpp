#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl test;

	if (argc != 2)
	{
		std::cout << "Invlid input." << std::endl;
		return (1);
	}
	test.complain(argv[1]);
}