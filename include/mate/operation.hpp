
#pragma once

#include <type_traits>

namespace mate
{
    struct Addition {};
    struct Multiplication {};

    template <typename Op>
    concept Operation = std::is_same_v<Op, Addition> || std::is_same_v<Op, Multiplication>;
}