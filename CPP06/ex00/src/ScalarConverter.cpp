#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && std::isalpha(literal[0]);
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
	char _char = 0;
	int _int = 0;
	float _float = 0.0f;
	double _double = 0.0;

	if (isChar(literal))
	{
		if (std::isprint(static_cast<unsigned int>(literal[0])))
			_char = static_cast<char>(literal[0]);
		else
			std::cout << "Non displayable" << std::endl;
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
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
	std::cout << _char << std::endl;
	std::cout << _int << std::endl;
	std::cout << _float << std::endl;
	std::cout << _double << std::endl;
}
