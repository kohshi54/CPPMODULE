#include <gtest/gtest.h>
#include "ScalarConverter.hpp"

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

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
