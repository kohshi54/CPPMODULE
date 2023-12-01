#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && std::isalpha(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal)
{
	bool hasSign = false;

	for (size_t i = 0; i < literal.length(); ++i)
	{
		if ((literal[i] == '+' || literal[i] == '-') && !hasSign)
		{
			hasSign = true;
			continue ;
		}
		if (std::isdigit(literal[i]) == false)
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	bool hasSign = false;
	bool hasDecimalPoint = false;
	bool hasExponent = false;
	bool hasFloatSuffix = false;

	for (size_t i = 0; i < literal.length(); ++i)
	{
		if (literal[i] == '.' && !hasDecimalPoint)
		{
			hasDecimalPoint = true;
			continue ;
		}
		if ((literal[i] == 'e' || literal[i] == 'E') && !hasExponent)
		{
			hasExponent = true;
			if (i + 1 < literal.length() && (literal[i + 1] == '+' || literal[i + 1] == '-'))
				++i;
			continue ;
		}
		if ((literal[i] == 'f' || literal[i] == 'F') && i == literal.length() - 1)
		{
			hasFloatSuffix = true;
			continue ;
		}
		if (std::isdigit(literal[i]))
		{
			continue ;
		}
		if ((literal[i] == '+' || literal[i] == '-') && !hasSign)
		{
			hasSign = true;
			continue ;
		}
		return false;
	}
	return hasFloatSuffix;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	bool hasSign = false;
	bool hasDecimalPoint = false;
	bool hasExponent = false;
	bool hasFloatSuffix = false;

	for (size_t i = 0; i < literal.length(); ++i)
	{
		if (literal[i] == '.' && !hasDecimalPoint)
		{
			hasDecimalPoint = true;
			continue ;
		}
		if ((literal[i] == 'e' || literal[i] == 'E') && !hasExponent)
		{
			hasExponent = true;
			if (i + 1 < literal.length() && (literal[i + 1] == '+' || literal[i + 1] == '-'))
				++i;
			continue ;
		}
		if ((literal[i] == 'f' || literal[i] == 'F') && i == literal.length() - 1)
		{
			hasFloatSuffix = true;
			continue ;
		}
		if (std::isdigit(literal[i]))
		{
			continue ;
		}
		if ((literal[i] == '+' || literal[i] == '-') && !hasSign)
		{
			hasSign = true;
			continue ;
		}
		return false;
	}
	return !hasFloatSuffix;
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
		std::cout << "isChar!" << std::endl;
		_char = static_cast<char>(literal[0]);
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	if (isInt(literal))
	{
		std::cout << "isInt!" << std::endl;
		_int = std::stod(literal);
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
	if (isFloat(literal))
	{
		std::cout << "isFloat!" << std::endl;
		_float = std::stof(literal);
		_char = static_cast<char>(_float);
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
	}
	if (isDouble(literal))
	{
		std::cout << "isDouble!" << std::endl;
		_double = std::stod(literal);
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
	}
	if (std::isprint(static_cast<unsigned int>(_char)))
		std::cout << _char << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << _int << std::endl;
	std::cout << _float << std::endl;
	std::cout << _double << std::endl;
}
