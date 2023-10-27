#include "gtest/gtest.h"
#include "DiamondTrap.hpp"
#include <sstream>
#include <iostream>

class DiamondTrapTest : public ::testing::Test {
protected:
    DiamondTrap diamondTrap;
};

TEST_F(DiamondTrapTest, WhoAmI) {
    diamondTrap = DiamondTrap("TestName");
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    diamondTrap.whoAmI();

    std::cout.rdbuf(old);

    EXPECT_EQ(buffer.str(), "DiamondTrap name: TestName\nClapTrap name: TestName_clap_name\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}