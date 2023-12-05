#include "iter.hpp"

void print(int i)
{
	std::cout << i << std::endl;
}

template <typename T>
void printTemplate(T element)
{
	std::cout << element << std::endl;
}

int main(void)
{
	{
		int array[] = {1, 2, 3, 4};
		std::cout << "normal function" << std::endl;
		iter(array, 4, print);
	}
	std::cout << "=================" << std::endl;
	{
		std::cout << "function template int" << std::endl;
		int array[] = {5, 6, 7, 8};
		iter(array, 4, printTemplate<int>);
	}
	std::cout << "=================" << std::endl;
	{
		std::cout << "function template string" << std::endl;
		std::string a[] = {"hello", "world"};
		iter(a, 2, printTemplate<std::string>);		
	}
	return 0;
}

#ifdef DEBUG
__attribute__((destructor))
static void end()
{
	system("leaks -q convert");
}
#endif
