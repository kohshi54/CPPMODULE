#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal)
{
	bool hasSign = false;

	for (size_t i = 0; i < literal.length(); ++i)
	{
		if ((literal[i] == '+' || literal[i] == '-') && !hasSign)
		{
			hasSign = true;
			if (literal.length() == 1)
				return false;
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

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
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
			if (literal.length() == 1)
				return false;
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

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
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
		if (std::isdigit(literal[i]))
		{
			continue ;
		}
		if ((literal[i] == '+' || literal[i] == '-') && !hasSign)
		{
			hasSign = true;
			if (literal.length() == 1)
				return false;
			continue ;
		}
		return false;
	}
	return true;
}

void ScalarConverter::convert(const std::string& literal)
{
	char _char = 0;
	int _int = 0;
	float _float = 0.0f;
	double _double = 0.0;

	if (isChar(literal))
	{
#ifdef DEBUG
		std::cout << "isChar!" << std::endl;
#endif
		try
		{
			_char = static_cast<char>(literal[0]);
			_int = static_cast<int>(_char);
			_float = static_cast<float>(_char);
			_double = static_cast<double>(_char);
		}
		catch (const std::exception& e)
		{
			std::cerr << "isChar: " << e.what() << std::endl;
		}
	}
	else if (isInt(literal))
	{
#ifdef DEBUG
		std::cout << "isInt!" << std::endl;
#endif
		try
		{
			_int = std::stoi(literal);
			_char = static_cast<char>(_int);
			_float = static_cast<float>(_int);
			_double = static_cast<double>(_int);
		}
		catch(const std::exception& e)
		{
			std::cout << "isInt: " << e.what() << std::endl;
		}		
	}
	else if (isFloat(literal))
	{
#ifdef DEBUG
		std::cout << "isFloat!" << std::endl;
#endif
		try
		{
			_float = std::stof(literal);
			_char = static_cast<char>(_float);
			_int = static_cast<int>(_float);
			_double = static_cast<double>(_float);
		}
		catch(const std::exception& e)
		{
			std::cerr << "isFloat: " << e.what() << std::endl;
		}
	}
	else if (isDouble(literal))
	{
#ifdef DEBUG
		std::cout << "isDouble!" << std::endl;
#endif
		try
		{
			_double = std::stod(literal);
			_char = static_cast<char>(_double);
			_int = static_cast<int>(_double);
			_float = static_cast<float>(_double);
		}
		catch(const std::exception& e)
		{
			std::cerr << "isDouble: " << e.what() << std::endl;
		}
	}
	if (std::isprint(static_cast<unsigned int>(_char)))
		std::cout << "char: " << _char << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}
