#include <gtest/gtest.h>
#include "ScalarConverter.hpp"

class ConverterTest : public :: testing::Test {

};

TEST_F(ConverterTest, IsChar)
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
