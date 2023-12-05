#include "iter.hpp"

void print(int i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	int array[] = {1, 2, 3, 4};
	iter(array, 4, print);
	return 0;
}

#ifdef DEBUG
__attribute__((destructor))
static void end()
{
	system("leaks -q convert");
}
#endif
