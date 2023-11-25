#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &name, int isSigned, int requiredGrade);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void validateRequiredGradeToSign(const Bureaucrat& b);
        void validateRequiredGradeToExecute(const Bureaucrat& b);

    private:
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        static const int _requiredGradeToSign = 25;
        static const int _requiredGradeToExec = 5;
};

#endif