
#include <gtest/gtest.h>

#include "mate/algebra/ring.hpp"

TEST(RingTest, Construct)
{
    mate::Set_type<int> set = {0};
    auto group = mate::make_group<int, mate::Addition>(set);
    group.print();

//    const auto rng = mate::make_ring(group);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}