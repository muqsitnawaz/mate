
#pragma once

#include <ostream>

#include <type_traits>

namespace mate
{
    struct Addition {};
    struct Multiplication {};

    template <typename T>
    inline constexpr bool is_add_t() noexcept
    {
        return std::is_same_v<T, Addition>;
    }

    template <typename T>
    inline constexpr bool is_multiply_t() noexcept
    {
        return std::is_same_v<T, Multiplication>;
    }

    template <typename Op>
    concept Operation = is_add_t<Op>() || is_multiply_t<Op>();
}