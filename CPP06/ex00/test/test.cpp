#include <gtest/gtest.h>
#include "ScalarConverter.hpp"

TEST(ConverterTest, IsChar)
{
	EXPECT_TRUE(ScalarConverter::isChar("a"));
	EXPECT_TRUE(ScalarConverter::isChar("b"));
	EXPECT_FALSE(ScalarConverter::isChar("1"));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
