#include "AForm.hpp"

/*
// 抽象クラスだしrequiredGrade設定は必ずしそうなので引数なしデフォルトコンストラクタは要らなさそう。
AForm::AForm() : _name(""), _isSigned(false), _requiredGrade(1)
{
#ifdef DEBUG
    std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
#endif
    validateRequiredGrade();
}
*/

AForm::AForm(const std::string& name, int requiredGrade) : _name(name), _isSigned(false), _requiredGrade(requiredGrade)
{
#ifdef DEBUG
    std::cout << GREEN << "AForm parameterized construcotr called" << RESET << std::endl;
#endif
    validateRequiredGrade();
}

AForm::AForm(const AForm& other) : _name(other.getName()), _isSigned(getIsSigned()), _requiredGrade(other.getRequiredGrade())
{
#ifdef DEBUG
    std::cout << GREEN << "AForm copy constructor called" << RESET << std::endl;
#endif
}

/*
// const属性を持つので後から代入はできないものとする。
AForm& AForm::operator=(const AForm& rhs)
{
    if (this != &rhs)
    {
    #ifdef DEBUG
        std::cout << YELLOW << "AForm copy assignment operator called" << RESET << std::endl;
    #endif
        this->_name = rhs.getName(); // constなので代入できない
        this->
    }
    return *this;
}
*/

AForm::~AForm()
{
#ifdef DEBUG
    std::cout << RED << "AForm destructor called" << RESET << std::endl;
#endif
}

void AForm::validateRequiredGrade()
{
#ifdef DEBUG
    std::cout << BLUE << "AForm validateGrade() called" << RESET << std::endl;
#endif
    if (this->_requiredGrade < highestGrade)
    {
#ifdef DEBUG
    std::cout << MAGENTA << "AForm GradeTooHighException occurred" << RESET << std::endl;
#endif
        throw AForm::GradeTooHighException();
    }
    else if (this->_requiredGrade > lowestGrade)
    {
#ifdef DEBUG
    std::cout << MAGENTA << "AForm GradeTooLowException occurred" << RESET << std::endl;
#endif
        throw AForm::GradeTooLowException();
    }
}

const std::string& AForm::getName() const
{
    return this->_name;
}

int AForm::getRequiredGrade() const
{
    return this->_requiredGrade;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

void AForm::beSigned(const Bureaucrat& b)
{
#ifdef DEBUG
    std::cout << BLUE << "AForm beSigned() called" << RESET << std::endl;
#endif
    if (b.getGrade() <= this->_requiredGrade)
        this->_isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm name: " << f.getName() << ", signedState: " << f.getIsSigned() << ", requiredGrade: " << f.getRequiredGrade();
    return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
#ifdef DEBUG
    std::cout << MAGENTA << "AForm GradeTooHighException::what() called" << RESET << std::endl;
#endif
    return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
#ifdef DEBUG
    std::cout << MAGENTA << "AForm GradeTooLowExecption::what() called" << RESET << std::endl;
#endif
    return "grade too low";
}
