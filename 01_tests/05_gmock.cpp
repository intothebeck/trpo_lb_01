#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

class Addition {
public:
    virtual int add(int a, int b) {
        return a + b;
    }
};

class Subtraction {
public:
    virtual int subtract(int a, int b) {
        return a - b;
    }
};

class Calculator {
public:
    Calculator(Addition* add, Subtraction* sub) : addition(add), subtraction(sub) {}

    int add(int a, int b) {
        return addition->add(a, b);
    }

    int subtract(int a, int b) {
        return subtraction->subtract(a, b);
    }

private:
    Addition* addition;
    Subtraction* subtraction;
};

class MockAddition : public Addition {
public:
    MOCK_METHOD(int, add, (int a, int b), (override));
};

class MockSubtraction : public Subtraction {
public:
    MOCK_METHOD(int, subtract, (int a, int b), (override));
};

TEST(CalculatorTest, AdditionTest) {
    MockAddition mockAddition;
    MockSubtraction mockSubtraction;

    Calculator calc(&mockAddition, &mockSubtraction);

    EXPECT_CALL(mockAddition, add(5, 3)).WillOnce(Return(8));
    EXPECT_CALL(mockAddition, add(-2, 7)).WillOnce(Return(5));

    EXPECT_EQ(calc.add(5, 3), 8);
    EXPECT_EQ(calc.add(-2, 7), 5);
}

TEST(CalculatorTest, SubtractionTest) {
    MockAddition mockAddition;
    MockSubtraction mockSubtraction;

    Calculator calc(&mockAddition, &mockSubtraction);

    EXPECT_CALL(mockSubtraction, subtract(10, 4)).WillOnce(Return(6));
    EXPECT_CALL(mockSubtraction, subtract(0, 0)).WillOnce(Return(0));

    EXPECT_EQ(calc.subtract(10, 4), 6);
    EXPECT_EQ(calc.subtract(0, 0), 0);
}

int main(int argc, char* argv[]) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
