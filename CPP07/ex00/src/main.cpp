#include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}

/*
int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int a = 1;
	int b = 2;
	swap<int>(a, b);
	std::cout << "a=" << a << std::endl;
	std::cout << "b=" << b << std::endl;
	std::cout << min<int>(1, 2) << std::endl;
	std::cout << max<int>(1, 2) << std::endl;

	std::cout << min<float>(1.3f, 12.3f) << std::endl;

	std::cout << " hello" << std::endl;
	return (0);
}
*/

#ifdef DEBUG
__attribute__((destructor))
static void end()
{
	system("leaks -q whatever");
}
#endif
