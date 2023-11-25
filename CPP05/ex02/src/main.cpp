#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Bureaucratの作成
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 2);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        // フォームの作成
        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Bob");
        PresidentialPardonForm pardonForm("Alice");

        // フォームの署名
        bob.signForm(shrubberyForm);
        alice.signForm(robotomyForm);
        alice.signForm(pardonForm);

        // フォームの実行
        bob.executeForm(shrubberyForm);
        alice.executeForm(robotomyForm);
        alice.executeForm(pardonForm);

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
