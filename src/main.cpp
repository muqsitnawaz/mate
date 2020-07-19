
#include <fmt/format.h>

#include "mate/algebra/group.hpp"
#include "mate/algebra/quotient_group.hpp"
#include "mate/algorithm/prime.hpp"

using namespace mate;

int main()
{
    using Set = std::unordered_set<int>;

    Set set = {1, 2, 3};

    fmt::print("Has additive identity: {}\n", has_identity<Addition>(set));
    fmt::print("Has multiplicative identity: {}\n", has_identity<Multiplication>(set));

    // Throws an exception -- not closed.
//    Set set1 = {0, 1, 2, 3, -3, -2, -1};
//    auto group1 = make_group<int, Addition>(set1);

    // Throws an exception -- not invertible.
//    Set set2 = {-1, 1};
//    auto group2 = make_group<int, Multiplication>(set2);

    // Throws an exception -- not closed.
//    Set set3 = {0, 1, -1};
//    auto group3 = make_group<int, Addition>(set3);

    // Works.
    Set set4 = {0};
    auto group4 = make_group<int, Addition>(set4);

    // Works.
    auto quot_group = make_quotient_group<int, Addition>(Modulus(5));
    quot_group.print();

    // Works.
    std::unordered_set<uint> set5 = {0, 1, 2, 3, 4, 5, 6};
    Modulus<uint> mod5(5u);
    auto quot_group1 = make_quotient_group<uint, Addition>(set5, mod5);
    quot_group1.print();

    // Miller rabin test fails when 65537 is int: overflow. Add assertions.
    fmt::print("Is prime: {}.\n", is_prime<long int>(65537, 10));
}