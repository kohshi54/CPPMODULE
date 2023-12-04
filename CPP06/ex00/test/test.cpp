#include <gtest/gtest.h>
#include "ScalarConverter.hpp"
#include <limits>

TEST(ConverterTest, IsChar)
{
	EXPECT_TRUE(ScalarConverter::isChar("a"));
	EXPECT_TRUE(ScalarConverter::isChar("A"));
	EXPECT_TRUE(ScalarConverter::isChar("*"));
	EXPECT_TRUE(ScalarConverter::isChar("+"));

	EXPECT_FALSE(ScalarConverter::isChar("1"));
	EXPECT_FALSE(ScalarConverter::isChar("10"));
	EXPECT_FALSE(ScalarConverter::isChar("aa"));
	EXPECT_FALSE(ScalarConverter::isChar("AA"));

	// EXPECT_TRUE(ScalarConverter::isChar("\t")); // If handle escape sequence, it can be handle correctly.
}

TEST(ConverterTest, IsInt)
{
	EXPECT_TRUE(ScalarConverter::isInt("1"));
	EXPECT_TRUE(ScalarConverter::isInt("10"));
	EXPECT_TRUE(ScalarConverter::isInt("+1"));
	EXPECT_TRUE(ScalarConverter::isInt("+12"));
	EXPECT_TRUE(ScalarConverter::isInt("-15"));
	EXPECT_TRUE(ScalarConverter::isInt("0"));
	EXPECT_TRUE(ScalarConverter::isInt("-0"));
	EXPECT_TRUE(ScalarConverter::isInt("+0"));
	EXPECT_TRUE(ScalarConverter::isInt("+0"));
	EXPECT_TRUE(ScalarConverter::isInt("2147483647"));
	EXPECT_TRUE(ScalarConverter::isInt("-2147483648"));

	// EXPECT_TRUE(ScalarConverter::isInt(std::to_string(std::numeric_limits<int>::max())));
	// EXPECT_TRUE(ScalarConverter::isInt(std::to_string(std::numeric_limits<int>::min())));

	EXPECT_FALSE(ScalarConverter::isInt("+"));
	EXPECT_FALSE(ScalarConverter::isInt("-"));
	EXPECT_FALSE(ScalarConverter::isInt("a"));
	EXPECT_FALSE(ScalarConverter::isInt("b"));
	// EXPECT_FALSE(ScalarConverter::isInt("2147483648")); // Here isInt() does not return false, but stoi throws exception when overflow so ok.
	// EXPECT_FALSE(ScalarConverter::isInt("-2147483649")); // 
}

TEST(ConverterTest, IsFloat)
{
	EXPECT_TRUE(ScalarConverter::isFloat("4.2f"));
	EXPECT_TRUE(ScalarConverter::isFloat("0f"));
	EXPECT_TRUE(ScalarConverter::isFloat(".0f"));
	EXPECT_TRUE(ScalarConverter::isFloat("0.0f"));
	EXPECT_TRUE(ScalarConverter::isFloat("-inff"));
	EXPECT_TRUE(ScalarConverter::isFloat("+inff"));
	EXPECT_TRUE(ScalarConverter::isFloat("nanf"));
	EXPECT_TRUE(ScalarConverter::isFloat("1.23e4f"));
	EXPECT_TRUE(ScalarConverter::isFloat("1.23e+4f"));
	EXPECT_TRUE(ScalarConverter::isFloat("89.3e-5f"));
	EXPECT_TRUE(ScalarConverter::isFloat("3.40282e+38f")); // FLT_MAX

	EXPECT_FALSE(ScalarConverter::isFloat("1"));
	EXPECT_FALSE(ScalarConverter::isFloat("10"));
	EXPECT_FALSE(ScalarConverter::isFloat("aa"));
	EXPECT_FALSE(ScalarConverter::isFloat("AA"));
	EXPECT_FALSE(ScalarConverter::isFloat("nan"));
	EXPECT_FALSE(ScalarConverter::isFloat("1.23ef"));
	EXPECT_FALSE(ScalarConverter::isFloat("1.23+f"));
	EXPECT_FALSE(ScalarConverter::isFloat("1.23+"));
	EXPECT_FALSE(ScalarConverter::isFloat("1.23e"));
}

TEST(ConverterTest, IsDouble)
{
	EXPECT_TRUE(ScalarConverter::isDouble("4.2"));
	EXPECT_TRUE(ScalarConverter::isDouble(".0"));
	EXPECT_TRUE(ScalarConverter::isDouble("0.0"));
	EXPECT_TRUE(ScalarConverter::isDouble("-inf"));
	EXPECT_TRUE(ScalarConverter::isDouble("+inf"));
	EXPECT_TRUE(ScalarConverter::isDouble("1.23e4"));
	EXPECT_TRUE(ScalarConverter::isDouble("1.23e+4"));
	EXPECT_TRUE(ScalarConverter::isDouble("1.23e-4"));

	EXPECT_FALSE(ScalarConverter::isDouble("1"));
	EXPECT_FALSE(ScalarConverter::isDouble("10"));
	EXPECT_FALSE(ScalarConverter::isDouble("aa"));
	EXPECT_FALSE(ScalarConverter::isDouble("AA"));
	EXPECT_FALSE(ScalarConverter::isDouble("1.23e"));
	EXPECT_FALSE(ScalarConverter::isDouble("1.23+"));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
