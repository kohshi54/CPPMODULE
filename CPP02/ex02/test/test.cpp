#include <gtest/gtest.h>
#include "Fixed.hpp"

class FixedTest : public ::testing::Test {

};

TEST_F(FixedTest, DefaultConstructor) {
    Fixed fixed;
    EXPECT_EQ(fixed.getRawBits(), 0);
}

TEST_F(FixedTest, IntConstructor) {
    Fixed fixed(42);
    EXPECT_EQ(fixed.getRawBits(), 42 << 8);
}

TEST_F(FixedTest, FloatConstructor) {
    Fixed fixed(3.14f);
    // Due to rounding, expect a value close to 3.14 in Fixed representation
    EXPECT_NEAR(fixed.toFloat(), 3.14f, 0.01);
}

TEST_F(FixedTest, CopyConstructor) {
    Fixed original(100);
    Fixed copy(original);
    EXPECT_EQ(copy.getRawBits(), original.getRawBits());
}

TEST_F(FixedTest, AssignmentOperator) {
    Fixed original(100);
    Fixed copy;
    copy = original;
    EXPECT_EQ(copy.getRawBits(), original.getRawBits());
}

TEST_F(FixedTest, ComparisonOperators) {
    Fixed a(5);
    Fixed b(10);
    Fixed c(5);

    EXPECT_TRUE(a < b);
    EXPECT_FALSE(a > b);
    EXPECT_TRUE(a <= c);
    EXPECT_TRUE(a >= c);
    EXPECT_TRUE(a == c);
    EXPECT_FALSE(a != c);
}

TEST_F(FixedTest, ArithmeticOperators) {
    Fixed a(5);
    Fixed b(10);

    Fixed sum = a + b;
    Fixed diff = b - a;
    Fixed mul = a * b;
    Fixed div = b / a;

    EXPECT_EQ(sum.getRawBits(), 15 << 8);
    EXPECT_EQ(diff.getRawBits(), 5 << 8);
    EXPECT_EQ(mul.getRawBits(), 50 << 8);
    EXPECT_EQ(div.getRawBits(), 2 << 8);
}


TEST_F(FixedTest, IncrementDecrementOperators) {
    Fixed a(5);
    Fixed b = a++;

    EXPECT_EQ(a.getRawBits(), (5 << 8)+1);
    EXPECT_EQ(b.getRawBits(), 5 << 8);

    Fixed c(10);
    Fixed d = --c;

    EXPECT_EQ(c.getRawBits(), (10 << 8)-1);
    EXPECT_EQ(d.getRawBits(), (10 << 8)-1);
}

TEST_F(FixedTest, MinMaxFunctions) {
    Fixed a(5);
    Fixed b(10);

    Fixed min_result = Fixed::min(a, b);
    Fixed max_result = Fixed::max(a, b);

    EXPECT_EQ(min_result.getRawBits(), a.getRawBits());
    EXPECT_EQ(max_result.getRawBits(), b.getRawBits());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
