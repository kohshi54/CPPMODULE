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
	EXPECT_FALSE(ScalarConverter::isInt("2147483648"));
	EXPECT_FALSE(ScalarConverter::isInt("-2147483649"));

}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}