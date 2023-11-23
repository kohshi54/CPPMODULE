#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        // Bureaucrat("bob", 151);
        Bureaucrat("bob", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}