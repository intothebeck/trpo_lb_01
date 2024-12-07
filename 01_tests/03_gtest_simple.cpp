#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(AddFunctionTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(10, 5), 15);
}

TEST(AddFunctionTest, NegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5);
    EXPECT_EQ(add(-10, -5), -15);
}

TEST(AddFunctionTest, MixedNumbers) {
    EXPECT_EQ(add(2, -3), -1);
    EXPECT_EQ(add(-10, 5), -5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
