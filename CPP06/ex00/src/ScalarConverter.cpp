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

bool ScalarConverter::isFloat(const std::string& literal)
{
	bool hasDecimalPoint = false;
	bool hasExponent = false;
	bool hasFloatSuffix = false;

	for (size_t i = 0; i < literal.length(); ++i)
	{
		if (literal[i] == '.' && !hasDecimalPoint)
		{
			hasDecimalPoint = true;
		}
		else if ((literal[i] == 'e' || literal[i] == 'E') && !hasExponent)
		{
			hasExponent = true;
			if (i + 1 < literal.length() && (literal[i + 1] == '+' || literal[i + 1] == '-'))
			{
				++i;
			}
		}
		else if ((literal[i] == 'f' || literal[i] == 'F') && i == literal.length() - 1)
		{
			hasFloatSuffix = true;
		}
		else if (!std::isdigit(literal[i]) && literal[i] != '+' && literal[i] != '-')
		{
			return false;
		}
	}
	return hasDecimalPoint || hasExponent || hasFloatSuffix;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	(void)literal;
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
		/* delete this later */
		std::cout << "stoi(): " << std::stod(literal) << std::endl;

		int digit;
		iss >> digit;
		std::cout << digit << std::endl;
	}
	if (isFloat(literal))
	{
		/* delete this later */
		std::cout << "stof(): " << std::stof(literal) << "f" << std::endl;

		float fdigit;
		iss >> fdigit;
		std::cout << fdigit << std::endl;
	}
	if (isDouble(literal))
	{
		/* delete this later */
		std::cout << "stod(): " << std::stod(literal) << std::endl;

		double ddigit;
		iss >> ddigit;
		std::cout << ddigit << std::endl;
	}
}
