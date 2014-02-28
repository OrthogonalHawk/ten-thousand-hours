#include <gtest/gtest.h>
#include <iostream>

#include "LargeNumber.h"

TEST(LargeNumber, Constructor)
{
    LargeNumber myNumber;

    EXPECT_EQ("0", myNumber.toString());
}

TEST(LargeNumber, Initialization)
{
    LargeNumber myNumber;
    myNumber.initialize(10);
    EXPECT_EQ("10", myNumber.toString());
}

TEST(LargeNumber, Addition)
{
    LargeNumber myNumber1;
    LargeNumber myNumber2;

    myNumber1.initialize(1);
    myNumber2.initialize(3);

    LargeNumber mySum = myNumber1 + myNumber2;

    EXPECT_EQ("4", mySum.toString());

    mySum = mySum + myNumber2 + myNumber2;

    EXPECT_EQ("10", mySum.toString());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
