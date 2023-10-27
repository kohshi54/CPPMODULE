#include "gtest/gtest.h"
#include "ScavTrap.hpp"

class ScavTrapTest : public ::testing::Test {
protected:
    ScavTrap scavTrap;
};

TEST_F(ScavTrapTest, AttackWithNoHitPointsOrEnergyPoints) {
    scavTrap.setHitPoints(0);
    scavTrap.setEnergyPoints(0);
    // Assume that the last message can be retrieved somehow
    scavTrap.attack("Enemy");
    // Check last message or other relevant state
}

TEST_F(ScavTrapTest, AttackWithNonZeroEnergyPoints) {
    scavTrap.setHitPoints(10);
    scavTrap.setEnergyPoints(10);
    scavTrap.setName("ST");
    scavTrap.setAttackDamage(5);
    scavTrap.attack("Enemy");
    // Check last message or other relevant state
    EXPECT_EQ(scavTrap.getEnergyPoints(), 9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
