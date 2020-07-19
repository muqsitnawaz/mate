
#include <gtest/gtest.h>

#include "mate/polynomial.hpp"

TEST(PolynomialTest, Construct)
{
    mate::polynomial<uint32_t> poly(4);
    poly.print();

    mate::polynomial<uint32_t> poly1({0, 5, 2, 3});
    poly1.print();
}

TEST(PolynomialTest, Operations)
{
    mate::polynomial<uint32_t> poly1({1, 5, 7, 8});
    mate::polynomial<uint32_t> poly2({0, 5, 2, 3});

    const auto sum = poly1 + poly2;
    sum.print();

    const auto prod = poly1 * poly2;
    prod.print();

    const auto mod = prod % 5;
    mod.print();
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}