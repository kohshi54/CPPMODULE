#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Color.hpp"

class Bureaucrat
{
    public:
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void validateGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
  
    private:
		Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);

        const std::string _name;
        int _grade; // grade must be in range of 1(highest) to 150(lowest).
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif