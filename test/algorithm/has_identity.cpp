
#include <gtest/gtest.h>

#include "mate/algorithm/has_identity.hpp"

TEST(IdentityTest, Additive)
{
    const mate::Set_type<int> set { 1, 2, 3, 4, 5 };
    EXPECT_FALSE(mate::has_identity<mate::Addition>(set));

    const mate::Set_type<int> set1 { 0, 1, 2, 3, 4, 5 };
    EXPECT_TRUE(mate::has_identity<mate::Addition>(set1));
}

TEST(IdentityTest, Multiplicative)
{
    const mate::Set_type<int> set { 2, 3, 4, 5 };
    EXPECT_FALSE(mate::has_identity<mate::Multiplication>(set));

    const mate::Set_type<int> set1 { 1, 2, 3, 4, 5 };
    EXPECT_TRUE(mate::has_identity<mate::Multiplication>(set1));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}