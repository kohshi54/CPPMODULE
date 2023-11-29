#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    public:
        Form(const std::string& name, bool isSigned, int requiredGrade);
        Form(const Form& other);
        ~Form();

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

        const std::string& getName() const;
        int getRequiredGrade() const;
        bool getIsSigned() const;
        void validateRequiredGrade();

        void beSigned(const Bureaucrat& b);

    private:
		Form();
        Form& operator=(const Form& rhs); // privateで未定義にしておくことで使えなくする。
        const std::string _name;
        bool _isSigned;
        const int _requiredGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif