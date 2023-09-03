
#include "../Example.hpp"
#include <gtest/gtest.h>

struct ExampleTests :public ::testing::Test
{
    int *x;

    int GetX()
    {
        return *x;
    }

    virtual void SetUp() override{
        x = new int(42);
    }

    virtual void TearDown() override
    {
        delete x;
    }
};

TEST_F(ExampleTests,MAC)
{
    int x = GetX();
    int y = 16;
    int sum = 100;
    int oldsum = sum;
    int expectednewSum = oldsum + x * y;
    
    EXPECT_EQ(
        expectednewSum,
        MAC(x,y,sum)
    );

    EXPECT_EQ(
        expectednewSum,
        sum
    );
}


bool f()
{
    return false;
}

// TEST(ExampleTests,DemonstrateGTestMacros)
// {
//     EXPECT_EQ(true,true);
//     const bool result = f();
//     EXPECT_EQ(true,result);
//     // ASSERT_TRUE(false);
//     // EXPECT_TRUE(false);
// }

// TEST(ExampleTests,MAC)
// {
//     int x = 42;
//     int y = 16;
//     int sum = 100;
//     int oldsum = sum;
//     int expectednewSum = oldsum+x*y;
//     EXPECT_EQ(
//         expectednewSum,
//         MAC(x,y,sum)
//     );

//     EXPECT_EQ(
//         expectednewSum,
//         sum
//     );
// }

// TEST(ExampleTests,Square)
// {
//     int x = 5;
//     int expectedSquare = x * x;
//     EXPECT_EQ(
//         expectedSquare,
//         Square(x)
//     );
// }