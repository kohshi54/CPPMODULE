#include <iostream>
#include <typeinfo>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "There must be one argument" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}

#ifdef DEBUG
__attribute__((destructor))
static void end()
{
	system("leaks -q convert");
}
#endif
