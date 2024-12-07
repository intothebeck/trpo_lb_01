#include <gtest/gtest.h>

class Calculator {
public:
    Calculator() : addCount(0) {}

    int add(int a, int b) {
        addCount++;
        return a + b;
    }

    int getAddCount() {
        return addCount;
    }

private:
    int addCount;
};

class CalculatorTest : public ::testing::Test {
protected:
    void SetUp() override {
        calculator = new Calculator();
    }

    void TearDown() override {
        delete calculator;
    }

    Calculator* calculator;
};

TEST_F(CalculatorTest, AddFunctionTest) {
    EXPECT_EQ(calculator->add(2, 3), 5);
    EXPECT_EQ(calculator->add(10, 5), 15);
    EXPECT_EQ(calculator->add(-100, 100), 0);
}

TEST_F(CalculatorTest, AddCountTest) {
    EXPECT_EQ(calculator->getAddCount(), 0);
    calculator->add(2, 3);
    EXPECT_EQ(calculator->getAddCount(), 1);
    calculator->add(10, 5);
    EXPECT_EQ(calculator->getAddCount(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
