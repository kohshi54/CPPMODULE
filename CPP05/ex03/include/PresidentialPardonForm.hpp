#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(const std::string &name);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;
        
    private:
        PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        static const int _requiredGradeToSign = 25;
        static const int _requiredGradeToExec = 5;
};

#endif
