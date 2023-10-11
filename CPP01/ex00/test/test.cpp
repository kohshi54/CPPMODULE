#include <gtest/gtest.h>
#include "Zombie.hpp"


namespace {

TEST(ZombieTest, NewZombieSuccessfulCreation) {
    std::string expectedName = "TestZombie";
	Zombie testZombie(expectedName);

    Zombie* testZombie2 = testZombie.newZombie(expectedName);

    ASSERT_NE(testZombie2, nullptr) << "Zombie object was not created.";
    EXPECT_EQ(testZombie2->getName(), expectedName) << "Zombie name was not set correctly.";
    
    delete testZombie2;  // Clean up the dynamically allocated memory.
}

}
