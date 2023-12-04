#include "Array.hpp"

int main()
{
	Array<int>a;
	(void)a;
	return 0;
}

#ifdef DEBUG
__attribute__((destructor))
static void end()
{
	system("leaks -q convert");
}
#endif
