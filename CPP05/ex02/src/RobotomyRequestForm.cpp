#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
#ifdef DEBUG
    std::cout << GREEN << "RobotomyRequestForm constructor called" << RESET << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, int isSigned, int requiredGrade) : AForm(name, isSigned, requiredGrade)
{
#ifdef DEBUG
    std::cout << GREEN << "RobotomyRequestForm parameterized constructor called" << RESET << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
#ifdef DEBUG
    std::cout << GREEN << "RobotomyRequestForm copy construcotr called" << RESET << std::endl;
#endif
}

/*
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
#ifdef DEBUG
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
#endif
    if (this != &rhs)
    {
        AForm::operator=(rhs); // constをメンバーに持ってるから使えない
    }
    return *this;
}
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
#ifdef DEBUG
    std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
#endif
}

void RobotomyRequestForm::validateRequiredGradeToSign(const Bureaucrat& b)
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

void RobotomyRequestForm::validateRequiredGradeToExecute(const Bureaucrat& b)
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