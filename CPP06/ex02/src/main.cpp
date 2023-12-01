#include "Base.hpp"
#include <iostream>

int main()
{
	Base *a = new A;
	Base *b = new B;
	Base *c = new C;
	identify(a);
	identify(b);
	identify(c);
	
	Base &ra = *a;
	Base &rb = *b;
	Base &rc = *c;
	identify(ra);
	identify(rb);
	identify(rc);
	// std::cout << "hello" << std::endl;
	return 0;
}
