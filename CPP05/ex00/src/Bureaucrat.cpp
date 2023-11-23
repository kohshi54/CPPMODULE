#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(70)
{
#ifdef DEBUG
    std::cout << "Bureaucrat defualt constructor called" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
#ifdef DEBUG
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
#endif
    validateGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade())
{
#ifdef DEBUG
    std::cout << "Bureaucrat copy constructor called" << std::endl;
#endif
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
    {
#ifdef DEBUG
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
#endif
        this->_name = rhs.getName();
        this->_grade = rhs.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
#ifdef DEBUG
    std::cout << "Bureaucrat destructor called" << std::endl;
#endif
}

const std::string& Bureaucrat::getName() const
{
#ifdef DEBUG
    std::cout << "Bureaucrat getName() called" << std::endl;
#endif
    return this->_name;
}

int Bureaucrat::getGrade() const
{
#ifdef DEBUG
    std::cout << "Bureaucrat getGrade() called" << std::endl;
#endif
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
#ifdef DEBUG
    std::cout << "Bureaucrat incrementGrade() called" << std::endl;
#endif
    this->_grade--; // 1 is the highest.
    validateGrade();
}

void Bureaucrat::decrementGrade()
{
#ifdef DEBUG
    std::cout << "Bureaucrat decrementGrade() called" << std::endl;
#endif
    this->_grade++; // 150 is the lowest.
    validateGrade();
}

void Bureaucrat::validateGrade()
{
#ifdef DEBUG
    std::cout << "Bureaucrat validateGrade() called" << std::endl;
#endif
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
#ifdef DEBUG
    std::cout << "GradeTooHighException::what() called" << std::endl;
#endif
    return "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
#ifdef DEBUG
    std::cout << "GradeTooLowExecption::what() called" << std::endl;
#endif
    return "grade too low";
}