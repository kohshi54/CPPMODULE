#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
#ifdef DEBUG
    std::cout << GREEN << "PresidentialPardonForm constructor called" << RESET << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, int isSigned, int requiredGrade) : AForm(name, isSigned, requiredGrade)
{
#ifdef DEBUG
    std::cout << GREEN << "PresidentialPardonForm parameterized constructor called" << RESET << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
#ifdef DEBUG
    std::cout << GREEN << "PresidentialPardonForm copy construcotr called" << RESET << std::endl;
#endif
}

/*
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
#ifdef DEBUG
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
#endif
    if (this != &rhs)
    {
        AForm::operator=(rhs); // constをメンバーに持ってるから使えない
    }
    return *this;
}
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
#ifdef DEBUG
    std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
#endif
}

void PresidentialPardonForm::validateRequiredGradeToSign(const Bureaucrat& b)
{
    if (b.getGrade() <= this->_requiredGradeToSign)
    {
        b.signForm(*this);
    }
    else
    {
        // throw exeption?
        Bureaucrat::GradeTooLowException();
    }
}

void PresidentialPardonForm::validateRequiredGradeToExecute(const Bureaucrat& b)
{
    if (b.getGrade() <= this->_requiredGradeToExec)
    {
        // execute form?
    }
    else
    {
        // throw exeption?
        Bureaucrat::GradeTooLowException();
    }
}