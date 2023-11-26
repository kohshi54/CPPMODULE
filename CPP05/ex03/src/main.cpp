#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
   {
      Intern someRandomIntern;
      AForm* rrf;
      rrf = someRandomIntern.makeForm("robotomy request", "Bender");
      (void)rrf;
   }
   std::cout << "============================" << std::endl;
   {
      Intern someRandomIntern;
      Bureaucrat bureaucrat("Alice", 5);
      AForm* form;

      // robotomy request form
      form = someRandomIntern.makeForm("robotomy request", "Bender");
      if (form)
      {
         std::cout << *form << std::endl;
         bureaucrat.signForm(*form);
         bureaucrat.executeForm(*form);
         delete form;
      }

      // shrubbery creation form
      form = someRandomIntern.makeForm("shrubbery creation", "Home");
      if (form)
      {
         std::cout << *form << std::endl;
         bureaucrat.signForm(*form);
         bureaucrat.executeForm(*form);
         delete form;
      }

      // presidential pardon form
      form = someRandomIntern.makeForm("presidential pardon", "Bob");
      if (form)
      {
         std::cout << *form << std::endl;
         bureaucrat.signForm(*form);
         bureaucrat.executeForm(*form);
         delete form;
      }

      // unknow form so fail
      form = someRandomIntern.makeForm("unknown form", "Unknown");
      if (!form)
      {
         std::cout << "Failed to create form: unknown form" << std::endl;
      }
   }
   return 0;
}
