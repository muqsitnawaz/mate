
#include <gtest/gtest.h>

#include "mate/algorithm/is_prime.hpp"

TEST(PrimeTest, TruePrimes)
{
    EXPECT_TRUE(mate::is_prime<long int>(65537));

    // Fails due to overflow.
    EXPECT_TRUE(mate::is_prime<int>(65537));
}

TEST(PrimeTest, FalsePrime)
{
    EXPECT_FALSE(mate::is_prime<int>(4));
    EXPECT_FALSE(mate::is_prime<long int>(1024));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}