#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Color.hpp"
#include "AForm.hpp"
class AForm;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void validateGrade();
        void signForm(AForm& f) const;

        void executeForm(AForm const & form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
  
    private:
        const std::string _name;
        int _grade; // grade must be in range of 1(highest) to 150(lowest).
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
