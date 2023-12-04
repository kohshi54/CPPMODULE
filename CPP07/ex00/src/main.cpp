#include <iostream>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	std::cout << " hello" << std::endl;
	return (0);
}

#ifdef DEBUG
__attribute__((destructor))
static void end()
{
	system("leaks -q convert");
}
#endif
