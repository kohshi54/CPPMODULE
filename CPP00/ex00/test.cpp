#include <gtest/gtest.h>
#include "megaphone.hpp"

TEST(ToUpperTest, Lower1) {
	std::string test1 = "hello";
	toUpperCase(test1);
	EXPECT_STREQ("HELLO", test1.c_str());
}

TEST(ToUpperTest, Lower2) {
	std::string test2 = "world";
	toUpperCase(test2);
	EXPECT_STREQ("WORLD", test2.c_str());
}

TEST(ToUpperTest, Upper1) {
	std::string test1 = "HELLO";
	toUpperCase(test1);
	EXPECT_STREQ("HELLO", test1.c_str());
}

TEST(ToUpperTest, Upper2) {
	std::string test2 = "WORLD";
	toUpperCase(test2);
	EXPECT_STREQ("WORLD", test2.c_str());
}

TEST(ToUpperTest, Symbol1) {
	std::string test1 = "******";
	toUpperCase(test1);
	EXPECT_STREQ("******", test1.c_str());
}

TEST(ToUpperTest, Symbol2) {
	std::string test2 = "&&&&&&";
	toUpperCase(test2);
	EXPECT_STREQ("&&&&&&", test2.c_str());
}