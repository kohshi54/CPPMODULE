#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    public:
        AForm(const std::string& name, int requiredGrade);
        AForm(const AForm& other);
        virtual ~AForm();

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
        virtual void execute(Bureaucrat const & executor) const = 0;

    private:
        AForm();
        AForm& operator=(const AForm& rhs); // privateで未定義にしておくことで使えなくする。

        const std::string _name;
        bool _isSigned;
        const int _requiredGrade;

        static const int highestGrade = 1;
        static const int lowestGrade = 150;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif
