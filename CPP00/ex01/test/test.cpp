#include <gtest/gtest.h>
#include "phonebook.hpp"

namespace {

TEST(Contact, DefaultConstructor) {
	const Contact c;

	EXPECT_STREQ("", c.getFirstName().c_str());
	EXPECT_STREQ("", c.getLastName().c_str());
	EXPECT_STREQ("", c.getNickName().c_str());
	EXPECT_STREQ("", c.getPhoneNumber().c_str());
	EXPECT_STREQ("", c.getDarkestSecret().c_str());
}

TEST(Contact, setContact) {
	Contact  c;

    std::istringstream testInput("kohshi\nyamaguchi\nky\n1234567890\nsecret");
    // Save the old buffer of cin and set the new buffer for cin
    std::streambuf* oldCinBuffer = std::cin.rdbuf(testInput.rdbuf());
	c.setContact(); 
    // Reset cin's buffer to its original state
    std::cin.rdbuf(oldCinBuffer);

	EXPECT_STREQ(c.getFirstName().c_str(), "kohshi");
    EXPECT_STREQ(c.getLastName().c_str(), "yamaguchi");
	EXPECT_STREQ(c.getNickName().c_str(), "ky");
	EXPECT_STREQ(c.getPhoneNumber().c_str(), "1234567890");
	EXPECT_STREQ(c.getDarkestSecret().c_str(), "secret");
}

TEST(Contact, getContact) {
	Contact  c;

    std::istringstream testInput("kohshi\nyamaguchi\nky\n1234567890\nsecret");
    // Save the old buffer of cin and set the new buffer for cin
    std::streambuf* oldCinBuffer = std::cin.rdbuf(testInput.rdbuf());
    c.setContact(); 
    // Reset cin's buffer to its original state
    std::cin.rdbuf(oldCinBuffer);

    Contact cr = c.getContact();

	EXPECT_STREQ(cr.getFirstName().c_str(), "kohshi");
    EXPECT_STREQ(cr.getLastName().c_str(), "yamaguchi");
	EXPECT_STREQ(cr.getNickName().c_str(), "ky");
	EXPECT_STREQ(cr.getPhoneNumber().c_str(), "1234567890");
	EXPECT_STREQ(cr.getDarkestSecret().c_str(), "secret");
}

TEST(Contact, showFourColumn) {
	Contact  c;

    std::istringstream testInput("John\nDoe\nJD\n1234567890\nsecret");
    // Save the old buffer of cin and set the new buffer for cin
    std::streambuf* oldCinBuffer = std::cin.rdbuf(testInput.rdbuf());
    c.setContact(); 
    // Reset cin's buffer to its original state
    std::cin.rdbuf(oldCinBuffer);

	std::ostringstream oss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf(oss.rdbuf());

    c.showFourColumn(0);

    // Reset cout's buffer to its original
    std::cout.rdbuf(oldCoutStreamBuf);

    // The exact expected output might vary based on truncateText's behavior.
    std::string expectedOutput = "         0|      John|       Doe|        JD|\n";
    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST(Contact, showAllColumn) {
    Contact c;

    std::istringstream testInput("John\nDoe\nJD\n1234567890\nsecret");
    // Save the old buffer of cin and set the new buffer for cin
    std::streambuf* oldCinBuffer = std::cin.rdbuf(testInput.rdbuf());
    c.setContact(); 
    // Reset cin's buffer to its original state
    std::cin.rdbuf(oldCinBuffer);

    // Redirect cout to our ostringstream
    std::ostringstream oss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf(oss.rdbuf());

    c.showAllColumn(0); // index is not used in the method, so any value is fine

    // Reset cout's buffer to its original
    std::cout.rdbuf(oldCoutStreamBuf);

    std::string expectedOutput = 
        "first name: John\n"
        "last name: Doe\n"
        "nickname: JD\n"
        "phone number: 1234567890\n"
        "darkest secret: secret\n";
    EXPECT_EQ(oss.str(), expectedOutput);
}

}
