#include "Bureaucrat.hpp"

int main(void)
{
    {
        // Initial grade normal
        try
        {
            Bureaucrat h = Bureaucrat("bob", 1);
            std::cout << h << std::endl;
            h.decrementGrade();
            std::cout << h << std::endl;
            h.incrementGrade();
            std::cout << h << std::endl;
            h.incrementGrade();
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "============================" << std::endl;
    {
        // Initial grade too high
        try
        {
            Bureaucrat h = Bureaucrat("bob", 0);
            std::cout << h << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "============================" << std::endl;
    {
        // Initial grade too low
        try
        {
            Bureaucrat h = Bureaucrat("bob", 151);
            std::cout << h << std::endl;
        }
        catch (std::exception &e)
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
		system("leaks -q Bureaucrat");
	}
#endif
