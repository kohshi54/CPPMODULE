#include <gtest/gtest.h>
#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);

class PointTest : public testing::Test {

};

TEST_F(PointTest, InsideTriangle) {
    Point a(0.0, 0.0);
    Point b(8.0, 0.0);
    Point c(0.0, 8.0);

    EXPECT_TRUE(bsp(a, b, c, Point(2.0, 2.0)));
    EXPECT_TRUE(bsp(a, b, c, Point(1.0, 1.0)));
    EXPECT_TRUE(bsp(a, b, c, Point(8.0, 0.0)));
    EXPECT_TRUE(bsp(a, b, c, Point(0.0, 8.0)));
}

TEST_F(PointTest, OnTriangleEdges) {
    Point a(0.0, 0.0);
    Point b(8.0, 0.0);
    Point c(0.0, 8.0);

    EXPECT_TRUE(bsp(a, b, c, Point(4.0, 0.0)));
    EXPECT_TRUE(bsp(a, b, c, Point(0.0, 4.0)));
    EXPECT_TRUE(bsp(a, b, c, Point(4.0, 4.0)));
}

TEST_F(PointTest, OutsideTriangle) {
    Point a(0.0, 0.0);
    Point b(8.0, 0.0);
    Point c(0.0, 8.0);

    EXPECT_FALSE(bsp(a, b, c, Point(0.0, 9.0)));
    EXPECT_FALSE(bsp(a, b, c, Point(9.0, 0.0)));
    EXPECT_FALSE(bsp(a, b, c, Point(-1.0, -1.0)));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
