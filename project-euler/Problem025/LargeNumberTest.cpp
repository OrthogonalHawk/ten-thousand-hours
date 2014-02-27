#include <gtest/gtest.h>
#include <iostream>

#include "LargeNumber.h"

TEST(LargeNumber, Constructor)
{
    LargeNumber myNumber;
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
