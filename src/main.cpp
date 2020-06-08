
#include <fmt/format.h>

#include "mate/group.hpp"
#include "mate/quotient_group.hpp"

using namespace mate;

int main()
{
    fmt::print("Additive identity: {}\n", get_identity<int, Addition>());
    fmt::print("Multiplicative identity: {}\n", get_identity<int, Multiplication>());

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
    Set set3 = {0, 1, -1};
    auto group3 = make_group<int, Addition>(set3);

    // Works.
    Set set4 = { 0 };
    auto group4 = make_group<int, Addition>(set4);

    // Works.
//    auto quot_group = make_quotient_group<int, Addition>(5);
//    quot_group.print();
//
//    auto quot_group1 = make_quotient_group<uint, Addition>(5);
//    quot_group1.print();
}