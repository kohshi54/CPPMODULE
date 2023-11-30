#include "RobotomyRequestForm.hpp"

/*
// 名前なしrequiredGradeなしは存在しないとしてデフォルトコンストラクタは作らない
RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
#ifdef DEBUG
    std::cout << GREEN << "RobotomyRequestForm constructor called" << RESET << std::endl;
#endif
}
*/

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : AForm(name, RobotomyRequestForm::_requiredGradeToSign)
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
    {
        std::cerr << "Failed to execute: form not signed" << std::endl;
        throw std::runtime_error("Form is not signed.");
    }
    if (executor.getGrade() > this->_requiredGradeToExec)
    {
        std::cerr << "Failed to execute: grade too low" << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }

    std::cout << "Drilling noises..." << std::endl;

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    if (std::rand() % 2)
        std::cout << getName() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy of " << getName() << " failed." << std::endl;
}
