#include "Base.hpp"
#include <iostream>

int main()
{
	{
		Base *a = new A;
		Base *b = new B;
		Base *c = new C;
		identify(a);
		identify(b);
		identify(c);

		identify(*a);
		identify(*b);
		identify(*c);

		delete a;
		delete b;
		delete c;
	}
	std::cout << "=================" << std::endl;
	{
		Base *random1 = generate();
		identify(random1);
		identify(*random1);
		delete random1;

		Base *random2 = generate();
		identify(random2);
		identify(*random2);
		delete random2;

		Base *random3 = generate();
		identify(random3);
		identify(*random3);
		delete random3;
	}
	return 0;
}

#ifdef DEBUG
	__attribute__((destructor))
	static void end()
	{
		system("leaks -q identify");
	}
#endif
