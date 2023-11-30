#include "PresidentialPardonForm.hpp"

/*
// 名前なしrequiredGradeなしは存在しないとしてデフォルトコンストラクタは作らない
PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
#ifdef DEBUG
    std::cout << GREEN << "PresidentialPardonForm constructor called" << RESET << std::endl;
#endif
}
*/

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : AForm(name, PresidentialPardonForm::_requiredGradeToSign)
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

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
    {
        std::cout << "Failed to execute: form not signed" << std::endl;
        throw std::runtime_error("Form is not signed.");
    }
    if (executor.getGrade() > this->_requiredGradeToExec)
    {
        std::cout << "Failed to execute: grade too low" << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }

    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
