#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &name, int isSigned, int requiredGrade);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void validateRequiredGradeToSign(const Bureaucrat& b);
        void validateRequiredGradeToExecute(const Bureaucrat& b);

    private:
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        static const int _requiredGradeToSign = 72;
        static const int _requiredGradeToExec = 45;
};

#endif