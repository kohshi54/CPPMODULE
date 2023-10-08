#include <gtest/gtest.h>
#include "Zombie.hpp"

class ZombieTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        // You can put setup code here if needed
    }

    virtual void TearDown() {
        // Cleanup code, if needed
    }
};

TEST_F(ZombieTest, DefaultConstructor) {
    Zombie z;
    // If you have a way to get the name, you can check if it's empty here.
}

TEST_F(ZombieTest, SetNameAndAnnounce) {
    Zombie z;
    z.setName("Bob");
    
    // Assuming you can redirect and capture std::cout output, check the announce
    std::stringstream ss;
    std::streambuf* oldbuf = std::cout.rdbuf(ss.rdbuf());
    z.announce();
    std::string expected = "Bob: BraiiiiiiinnnzzzZ...\n";
    ASSERT_EQ(ss.str(), expected);
    std::cout.rdbuf(oldbuf); // restore normal output
}

TEST_F(ZombieTest, DestructorMessage) {
    std::stringstream ss;
    std::streambuf* oldbuf = std::cout.rdbuf(ss.rdbuf());
    {
        Zombie z;
        z.setName("Alice");
    } // Destructor called at the end of this scope
    std::string expected = "Alice destroyed\n";
    ASSERT_EQ(ss.str(), expected);
    std::cout.rdbuf(oldbuf); // restore normal output
}

TEST_F(ZombieTest, ZombieHorde) {
    Zombie z;
    Zombie* horde = z.zombieHorde(3, "Zombie1");
    
    // Again, if you can capture std::cout output, check that three zombies have been announced.
    std::stringstream ss;
    std::streambuf* oldbuf = std::cout.rdbuf(ss.rdbuf());
    for (int i = 0; i < 3; ++i) {
        horde[i].announce();
    }
    std::string expected = "Zombie1: BraiiiiiiinnnzzzZ...\nZombie1: BraiiiiiiinnnzzzZ...\nZombie1: BraiiiiiiinnnzzzZ...\n";
    ASSERT_EQ(ss.str(), expected);
    std::cout.rdbuf(oldbuf); // restore normal output

    delete[] horde; // Remember to delete the dynamically allocated memory!
}
