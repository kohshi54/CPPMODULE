#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat bureaucrat("Alice", 5);
	AForm* form;

	{
		// shrubbery creation form
		try
		{
			form = someRandomIntern.makeForm("shrubbery creation", "Home");
			std::cout << *form << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "====================" << std::endl;
	{
		// robotomy request form
		try
		{
			form = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *form << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "====================" << std::endl;
	{
		try
		{
			form = someRandomIntern.makeForm("presidential pardon", "Bob");
			std::cout << *form << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "====================" << std::endl;
	{
		// unknow form so fail
		try
		{
			form = someRandomIntern.makeForm("unknown form", "Unknown");
		}
		catch (const std::exception &e)
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
