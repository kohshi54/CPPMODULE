#include <gtest/gtest.h>
#include "phonebook.hpp"
#include <sstream>

class PhoneBookTest : public ::testing::Test {
protected:
    PhoneBook phoneBook;
    Contact  c;
    std::ostringstream testOutput;
    std::streambuf* oldCoutBuffer;

    void SetUp() override {
        // Redirect cout to capture output
        oldCoutBuffer = std::cout.rdbuf(testOutput.rdbuf());

        std::istringstream testInput("John\nDoe\nJD\n1234567890\nsecret");
        std::streambuf* oldCinBuffer = std::cin.rdbuf(testInput.rdbuf());
        c.setContact();
        std::cin.rdbuf(oldCinBuffer);
    }

    void TearDown() override {
        // Reset cout to its original state
        std::cout.rdbuf(oldCoutBuffer);
    }
};

TEST_F(PhoneBookTest, ConstructorTest) {
    EXPECT_NE(&phoneBook, nullptr);
}

TEST_F(PhoneBookTest, AddPhoneBookTest) {
    phoneBook.addPhoneBook(c);
    // Assertion to check the contact was added is needed. Perhaps a getter method in PhoneBook.
}

TEST_F(PhoneBookTest, GetPhoneBookTest) {
    phoneBook.getPhoneBook();
    // Assertion to check the retrieved contact details is needed.
}

TEST_F(PhoneBookTest, SearchPhoneBookTest) {
    phoneBook.searchPhoneBook();
    std::string expectedOutput = "         0|      John|       Doe|        JD|\n";
    EXPECT_EQ(testOutput.str(), expectedOutput);
}

TEST_F(PhoneBookTest, DisplayEntryTest) {
    // For this test, you'll also need to mock cin input for the index
    std::istringstream testInput("0");  // Assuming we're asking for the first entry
    std::streambuf* oldCinBuffer = std::cin.rdbuf(testInput.rdbuf());

    phoneBook.displayEntry();

    std::cin.rdbuf(oldCinBuffer);

    std::string expectedOutput = "please enter first name\nplease enter last name\nplease enter nickname\nplease enter phone number\nplease enter darkest secret\nplease enter entry to display!\nfirst name: \nlast name: \nnickname: \nphone number: \ndarkest secret: \n";
    EXPECT_EQ(testOutput.str(), expectedOutput);
}

// ... other tests ...
