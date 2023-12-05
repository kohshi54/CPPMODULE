#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	// std::vector<int> vec = {1, 2, 3, 4, 5}; this initialization is from c++11.

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const NotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "===================" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 4);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
