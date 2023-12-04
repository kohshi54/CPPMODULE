#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>

class ScalarConverter
{
	public:
		static void convert(const std::string& literal);
		static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);

	private:
		ScalarConverter();
		~ScalarConverter();
};

#endif
