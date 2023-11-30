#include "ShrubberyCreationForm.hpp"

/*
// 名前なしrequiredGradeなしは存在しないとしてデフォルトコンストラクタは作らない
ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
#ifdef DEBUG
    std::cout << GREEN << "ShrubberyCreationForm constructor called" << RESET << std::endl;
#endif
}
*/

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : AForm(name, this->_requiredGradeToSign)
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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

    std::string filename = this->getName() + "_shrubbery";

    std::ofstream file(filename.c_str());
    if (!file)
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    file << "    _\\/_\n"
         << "     /\\ \n"
         << "     /\\ \n"
         << "    /  \\ \n"
         << "    /~~\\o \n"
         << "   /o   \\ \n"
         << "  /~~*~~~\\ \n"
         << " o/    o \\ \n"
         << " /~~~~~~~~\\~` \n"
         << "/__*_______\\ \n"
         << "     || \n"
         << "   \\====/ \n"
         << "    \\__/ \n";

    file.close();

	std::cout << "Ascii tree written to " << filename << std::endl;
}
