#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
#ifdef DEBUG
    std::cout << GREEN << "ShrubberyCreationForm constructor called" << RESET << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, int isSigned, int requiredGrade) : AForm(name, isSigned, requiredGrade)
{
#ifdef DEBUG
    std::cout << GREEN << "ShrubberyCreationForm parameterized constructor called" << RESET << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
#ifdef DEBUG
    std::cout << GREEN << "ShrubberyCreationForm copy construcotr called" << RESET << std::endl;
#endif
}

/*
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
#ifdef DEBUG
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
#endif
    if (this != &rhs)
    {
        AForm::operator=(rhs); // constをメンバーに持ってるから使えない
    }
    return *this;
}
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
#ifdef DEBUG
    std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
#endif
}

void ShrubberyCreationForm::validateRequiredGradeToSign(const Bureaucrat& b)
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

void ShrubberyCreationForm::validateRequiredGradeToExecute(const Bureaucrat& b)
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