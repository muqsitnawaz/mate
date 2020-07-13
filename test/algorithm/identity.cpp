
#include <gtest/gtest.h>

TEST(IdentityTest, ZeroPrecision)
{
    ASSERT_TRUE(5 != 2);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}