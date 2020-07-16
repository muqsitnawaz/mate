
#include <gtest/gtest.h>

#include "mate/algorithm/identity.hpp"

TEST(IdentityTest, Additive)
{
    constexpr auto identity = mate::get_identity<int, mate::Addition>();
    EXPECT_EQ(identity, 0);
}

TEST(IdentityTest, Multiplicative)
{
    constexpr auto identity = mate::get_identity<int, mate::Multiplication>();
    EXPECT_EQ(identity, 1);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}