#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    {
        // Initial grade normal
        try
        {
            Bureaucrat h = Bureaucrat("bob", 1);
            std::cout << h << std::endl;
            Form f = Form("visa", 0, 2);
            std::cout << f << std::endl;
            h.signForm(f);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "==============================" << std::endl;
    {
        // grade too low so cannot sign form
        try
        {
            Bureaucrat h = Bureaucrat("bob", 4);
            std::cout << h << std::endl;
            Form f = Form("visa", 0, 2);
            std::cout << f << std::endl;
            h.signForm(f);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "==============================" << std::endl;
    {
        // form cannot create because the grade is too low
        try
        {
            Bureaucrat h = Bureaucrat("bob", 4);
            std::cout << h << std::endl;
            Form f = Form("visa", 0, 151);
            std::cout << f << std::endl;
            h.signForm(f);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "==============================" << std::endl;
    {
        // form cannot create because the grade is too high
        try
        {
            Bureaucrat h = Bureaucrat("bob", 4);
            std::cout << h << std::endl;
            Form f = Form("visa", 0, 0);
            std::cout << f << std::endl;
            h.signForm(f);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}