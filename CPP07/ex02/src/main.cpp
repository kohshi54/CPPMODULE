#include "Array.hpp"
#include <iostream>

int main()
{
	/*
	{
		int* a = new int();
		std::cout << *a << std::endl;
		std::string* str = new std::string();
		std::cout << *str << std::endl;
	}
	std::cout << "==============" << std::endl;
	{
		Array<int> *a = new Array<int>;
		std::cout << *a << std::endl;
		Array<std::string> *str = new Array<std::string>;
		std::cout << *str << std::endl;
	}
	*/
	std::cout << "==============" << std::endl;
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

/*
#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/

#ifdef DEBUG
__attribute__((destructor))
static void end()
{
	system("leaks -q array");
}
#endif
