#include "Array.hpp"
#include <iostream>

int main()
{
	{
		Array<int>a(4);
		for (size_t i = 0; i < a.size(); ++i)
		{
			a[i] = i * 10;
		}
		for (size_t i = 0; i < a.size(); ++i)
		{
			std::cout << a[i] << std::endl;
		}
		try
		{
			a[4]; // these will cause exception
			a[-1];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "==============" << std::endl;
	{
		Array<std::string>a(4);
		std::string tmp[] = {"first", "second", "thrid", "fourth"};
		for (size_t i = 0; i < a.size(); ++i)
		{
			a[i] = tmp[i];
		}
		for (size_t i = 0; i < a.size(); ++i)
		{
			std::cout << a[i] << std::endl;
		}
		try
		{
			a[4];
			a[-1];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
	return 0;
}

#ifdef DEBUG
__attribute__((destructor))
static void end()
{
	system("leaks -q array");
}
#endif
