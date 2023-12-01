#include <iostream>
#include <typeinfo>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	(void)argc;
	char a;
	int b;
	float c;
	double d;

	std::cout << "Type of a: " << typeid(a).name() << std::endl;
	std::cout << "Type of b: " << typeid(b).name() << std::endl;
	std::cout << "Type of c: " << typeid(c).name() << std::endl;
	std::cout << "Type of d: " << typeid(d).name() << std::endl;

	if (argc != 2)
	{
		std::cout << "There must be one argument" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
