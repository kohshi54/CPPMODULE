#include "Base.hpp"

Base* generate(void)
{
	static int i;
	Base *re;

	switch (i++ % 3)
	{
		case 0:
			re = new A;
			break ;
		case 1:
			re = new B;
			break ;
		case 2:
			re = new C;
			break ;
		default:
			re = new A;
	}
	return re;
}

void identify(Base* p)
{
#ifdef DEBUG
	std::cout << "Base pointer passed" << std::endl;
#endif
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
#ifdef DEBUG
	std::cout << "Base reference passed" << std::endl;
#endif
	try
	{
		Base &n = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)n;
	}
	catch(const std::bad_cast&)
	{
	}
	try
	{
		Base &n = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)n;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		Base &n = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)n;
	}
	catch(const std::exception& e)
	{
	}
}
