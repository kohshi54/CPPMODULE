#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(const std::string &name);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
        
    private:
        RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        static const int _requiredGradeToSign = 72;
        static const int _requiredGradeToExec = 45;
};

#endif