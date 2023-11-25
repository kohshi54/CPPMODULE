#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(const std::string& name, bool isSigned, int requiredGrade);
        AForm(const AForm& other);
        ~AForm();

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

        const std::string& getName() const;
        int getRequiredGrade() const;
        bool getIsSigned() const;
        void validateRequiredGrade();

        void beSigned(const Bureaucrat& b);

    private:
        AForm& operator=(const AForm& rhs); // privateで未定義にしておくことで使えなくする。
        const std::string _name;
        bool _isSigned;
        const int _requiredGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif