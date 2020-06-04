
#include <fmt/format.h>

#include <mate/algorithms.hpp>

using namespace mate;

int main()
{
    fmt::print("Additive identity: {}\n", mate::get_identity<int, Addition>());
    fmt::print("Multiplicative identity: {}\n", mate::get_identity<int, Multiplication>());

    using IntSet = std::unordered_set<int>;

    IntSet set = {1, 2, 3};

    fmt::print("Has additive identity: {}\n", has_identity<Addition>(set));
    fmt::print("Has multiplicative identity: {}\n", has_identity<Multiplication>(set));
}