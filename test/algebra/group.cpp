
#include <gtest/gtest.h>

#include "mate/algebra/group.hpp"

TEST(GroupTest, ThrowsOnMake)
{
    const auto fn_invalid_group = []()
    {
        // Not closed.
        mate::Set_type<int> set = {0, 1, 2, 3, -3, -2, -1};
        const auto group = mate::make_group<int, mate::Addition>(set);
    };
    EXPECT_THROW(fn_invalid_group(), std::invalid_argument);

    const auto fn_invalid_group1 = []()
    {
        // Not invertible.
        mate::Set_type<int> set = {-1, 1};
        const auto group = mate::make_group<int, mate::Addition>(set);
    };
    EXPECT_THROW(fn_invalid_group1(), std::invalid_argument);
}

TEST(GroupTest, Make)
{
    const auto fn_valid_group = []()
    {
        mate::Set_type<int> set = {0};
        auto group = mate::make_group<int, mate::Addition>(set);
    };
    EXPECT_NO_THROW(fn_valid_group());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}