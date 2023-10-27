#include "gtest/gtest.h"
#include "ClapTrap.hpp"

class ClapTrapTest : public ::testing::Test {
protected:
    ClapTrap clapTrap;
};

TEST_F(ClapTrapTest, AttackWithNoHitPointsOrEnergyPoints) {
    clapTrap.setHitPoints(0);
    clapTrap.setEnergyPoints(0);
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    clapTrap.attack("Enemy");
    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "No hitPoints or energyPoints!\n");
}

TEST_F(ClapTrapTest, AttackWithNonZeroEnergyPoints) {
    clapTrap.setHitPoints(10);
    clapTrap.setEnergyPoints(10);
    clapTrap.setName("CT");
    clapTrap.setAttackDamage(5);
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    clapTrap.attack("Enemy");
    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "ClapTrap CT attacks Enemy, causing 5 points of damage!\n");
    EXPECT_EQ(clapTrap.getEnergyPoints(), 9);
}

TEST_F(ClapTrapTest, TakeDamageMoreThanHitPoints) {
    clapTrap.setHitPoints(10);
    clapTrap.takeDamage(20);
    EXPECT_EQ(clapTrap.getHitPoints(), 0);
}

TEST_F(ClapTrapTest, TakeDamageLessThanHitPoints) {
    clapTrap.setHitPoints(10);
    clapTrap.takeDamage(5);
    EXPECT_EQ(clapTrap.getHitPoints(), 5);
}

TEST_F(ClapTrapTest, TakeDamageEqualToHitPoints) {
    clapTrap.setHitPoints(10);
    clapTrap.takeDamage(10);
    EXPECT_EQ(clapTrap.getHitPoints(), 0);
}

TEST_F(ClapTrapTest, BeRepairedWithNoHitPointsOrEnergyPoints) {
    clapTrap.setHitPoints(0);
    clapTrap.setEnergyPoints(0);
    clapTrap.beRepaired(10);
    EXPECT_EQ(clapTrap.getHitPoints(), 0);
    EXPECT_EQ(clapTrap.getEnergyPoints(), 0);
}

TEST_F(ClapTrapTest, BeRepairedWithNonZeroHitPointsAndEnergyPoints) {
    clapTrap.setHitPoints(10);
    clapTrap.setEnergyPoints(10);
    clapTrap.beRepaired(10);
    EXPECT_EQ(clapTrap.getHitPoints(), 20);
    EXPECT_EQ(clapTrap.getEnergyPoints(), 9);
}

TEST_F(ClapTrapTest, BeRepairedWithEnergyPointsEqualToZero) {
    clapTrap.setHitPoints(10);
    clapTrap.setEnergyPoints(0);
    clapTrap.beRepaired(10);
    EXPECT_EQ(clapTrap.getHitPoints(), 10);
    EXPECT_EQ(clapTrap.getEnergyPoints(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
