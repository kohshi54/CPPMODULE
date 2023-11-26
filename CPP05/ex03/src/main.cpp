#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Intern.hpp"

int main()
{
   {
      Intern someRandomIntern;
      AForm* rrf;
      rrf = someRandomIntern.makeForm("robotomy request", "Bender");
      (void)rrf;
   }
   return 0;
}
