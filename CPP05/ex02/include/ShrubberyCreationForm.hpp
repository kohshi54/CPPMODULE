#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &name, int isSigned, int requiredGrade);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void validateRequiredGradeToSign(const Bureaucrat& b);
        void validateRequiredGradeToExecute(const Bureaucrat& b);

    private:
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        static const int _requiredGradeToSign = 145;
        static const int _requiredGradeToExec = 137;
};

#endif