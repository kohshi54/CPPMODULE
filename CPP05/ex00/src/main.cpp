#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        // Bureaucrat("bob", 151);
        Bureaucrat h = Bureaucrat("bob", 0);
        std::cout << h << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}