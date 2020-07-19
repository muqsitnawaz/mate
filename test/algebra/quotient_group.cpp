
#include <gtest/gtest.h>

#include "mate/algebra/quotient_group.hpp"

TEST(GroupTest, Construct)
{
    // Works.
    const auto group = mate::make_quotient_group<int, mate::Addition>(mate::Modulus(5));
    group.print();

    // Works.
    mate::Set_type<uint> set5 = {0, 1, 2, 3, 4, 5, 6};
    auto quot_group1 = mate::make_quotient_group<uint, mate::Addition>(set5, mate::Modulus<uint>(5));
    quot_group1.print();
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}