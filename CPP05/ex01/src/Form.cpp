#include "Form.hpp"

Form::Form() : _name(""), _isSigned(0), _requiredGrade(1)
{
#ifdef DEBUG
    std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
#endif
    validateRequiredGrade();
}

Form::Form(const Form& other) : _name(other.getName()), _isSigned(getIsSigned()), _requiredGrade(other.getRequiredGrade())
{
#ifdef DEBUG
    std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
#endif
}

/*
Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs)
    {
    #ifdef DEBUG
        std::cout << YELLOW << "Form copy assignment operator called" << RESET << std::endl;
    #endif
        this->_name = rhs.getName(); // constなので代入できない
        this->
    }
    return *this;
}
*/

Form::~Form()
{
#ifdef DEBUG
    std::cout << RED << "Form destructor called" << RESET << std::endl;
#endif
}

void Form::validateRequiredGrade()
{
#ifdef DEBUG
    std::cout << BLUE << "Form validateGrade() called" << RESET << std::endl;
#endif
    if (this->_requiredGrade < 1)
    {
#ifdef DEBUG
    std::cout << MAGENTA << "Form GradeTooHighException occurred" << RESET << std::endl;
#endif
        throw Form::GradeTooHighException();
    }
    else if (this->_requiredGrade > 150)
    {
#ifdef DEBUG
    std::cout << MAGENTA << "Form GradeTooLowException occurred" << RESET << std::endl;
#endif
        throw Form::GradeTooLowException();
    }
}

const std::string& Form::getName() const
{
    return this->_name;
}

int Form::getRequiredGrade() const
{
    return this->_requiredGrade;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

void Form::beSigned(const Bureaucrat& b)
{
#ifdef DEBUG
    std::cout << BLUE << "Form beSigned() called" << RESET << std::endl;
#endif
    if (b.getGrade() <= this->_requiredGrade)
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}


std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << ", form signedState: " << f.getIsSigned() << ", requiredGrade: " << f.getRequiredGrade();
    return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
#ifdef DEBUG
    std::cout << MAGENTA << "Form GradeTooHighException::what() called" << RESET << std::endl;
#endif
    return "grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
#ifdef DEBUG
    std::cout << MAGENTA << "Form GradeTooLowExecption::what() called" << RESET << std::endl;
#endif
    return "grade too low";
}