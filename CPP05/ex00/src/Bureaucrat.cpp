#include "Bureaucrat.hpp"

/*
Bureaucrat::Bureaucrat() : _name(""), _grade(70)
{
#ifdef DEBUG
    std::cout << GREEN << "Bureaucrat defualt constructor called" << RESET << std::endl;
#endif
}
*/

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
#ifdef DEBUG
    std::cout << GREEN << "Bureaucrat parameterized constructor called" << RESET << std::endl;
#endif
    validateGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade())
{
#ifdef DEBUG
    std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
#endif
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
    {
#ifdef DEBUG
    std::cout << YELLOW << "Bureaucrat copy assignment operator called" << RESET << std::endl;
#endif
        // this->_name = rhs.getName(); // does not copy since _name is const
        this->_grade = rhs.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
#ifdef DEBUG
    std::cout << RED << "Bureaucrat destructor called" << RESET <<std::endl;
#endif
}

const std::string& Bureaucrat::getName() const
{
// #ifdef DEBUG
//     std::cout << BLUE << "Bureaucrat getName() called" << RESET << std::endl;
// #endif
    return this->_name;
}

int Bureaucrat::getGrade() const
{
// #ifdef DEBUG
//     std::cout << BLUE << "Bureaucrat getGrade() called" << RESET << std::endl;
// #endif
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
#ifdef DEBUG
    std::cout << BLUE << "Bureaucrat incrementGrade() called" << RESET << std::endl;
#endif
    this->_grade--; // 1 is the highest.
    validateGrade();
}

void Bureaucrat::decrementGrade()
{
#ifdef DEBUG
    std::cout << BLUE << "Bureaucrat decrementGrade() called" << RESET << std::endl;
#endif
    this->_grade++; // 150 is the lowest.
    validateGrade();
}

void Bureaucrat::validateGrade()
{
#ifdef DEBUG
    std::cout << BLUE << "Bureaucrat validateGrade() called" << RESET << std::endl;
#endif
    if (this->_grade < 1)
    {
#ifdef DEBUG
    std::cout << MAGENTA << "Bureaucrat GradeTooHighException occurred" << RESET << std::endl;
#endif
        throw Bureaucrat::GradeTooHighException();
    }
    else if (this->_grade > 150)
    {
#ifdef DEBUG
    std::cout << MAGENTA << "Bureaucrat GradeTooLowException occurred" << RESET << std::endl;
#endif
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
#ifdef DEBUG
    std::cout << MAGENTA << "GradeTooHighException::what() called" << RESET << std::endl;
#endif
    return "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
#ifdef DEBUG
    std::cout << MAGENTA << "GradeTooLowExecption::what() called" << RESET << std::endl;
#endif
    return "grade too low";
}
