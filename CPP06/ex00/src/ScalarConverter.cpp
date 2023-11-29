#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string& literal)
{
    return std::isalpha(literal[0]) && literal.length() == 1 && std::isprint(static_cast<unsigned int>(literal[0]));
}

bool ScalarConverter::isInt(const std::string& literal)
{
    size_t i = 0;
    while (literal[i])
    {
        if (std::isdigit(literal[i]) == false)
            return false;
        i++;
    }
    return true;
}

void ScalarConverter::convert(const std::string& literal)
{
    std::istringstream iss(literal);

    if (isChar(literal))
    {
        std::cout << static_cast<char>(literal[0]) << std::endl;
        // char c;
        // iss >> c;
        // std::cout << c << std::endl;
    }
    if (isInt(literal))
    {
        int digit;
        iss >> digit;
        std::cout << digit << std::endl;
    }
}