#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
   {
      // should pass most, robotomy may fail.
      try {
         Bureaucrat bob("Bob", 50);
         Bureaucrat alice("Alice", 2);

         std::cout << bob << std::endl;
         std::cout << alice << std::endl;

         ShrubberyCreationForm shrubberyForm("Home");
         RobotomyRequestForm robotomyForm("Bob");
         PresidentialPardonForm pardonForm("Alice");

         bob.signForm(shrubberyForm);
         alice.signForm(robotomyForm);
         alice.signForm(pardonForm);

         bob.executeForm(shrubberyForm);
         alice.executeForm(robotomyForm);
         alice.executeForm(pardonForm);
      }
      catch (std::exception &e)
      {
         std::cerr << "Exception: " << e.what() << std::endl;
      }
   }
   std::cout << "========================" << std::endl;
   {
      // should fail
      try {
         Bureaucrat bob("Bob", 150);
         Bureaucrat alice("Alice", 150);

         std::cout << bob << std::endl;
         std::cout << alice << std::endl;

         ShrubberyCreationForm shrubberyForm("Home");
         RobotomyRequestForm robotomyForm("Bob");
         PresidentialPardonForm pardonForm("Alice");

         bob.signForm(shrubberyForm);
         alice.signForm(robotomyForm);
         alice.signForm(pardonForm);

         bob.executeForm(shrubberyForm);
         alice.executeForm(robotomyForm);
         alice.executeForm(pardonForm);
      }
      catch (std::exception &e)
      {
         std::cerr << "Exception: " << e.what() << std::endl;
      }
   }

   return 0;
}
