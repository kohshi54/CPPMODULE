#include "gtest/gtest.h"
#include "FragTrap.hpp"
#include <sstream>
#include <iostream>

class FragTrapTest : public ::testing::Test {
protected:
    FragTrap fragTrap;
};

TEST_F(FragTrapTest, HighFivesGuys) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    fragTrap.highFivesGuys();

    std::cout.rdbuf(old);

    EXPECT_EQ(buffer.str(), "FragTrap requests highfive!\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
