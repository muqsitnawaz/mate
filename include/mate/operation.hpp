
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

    template <typename T>
    concept Operation = is_add_t<T>() || is_multiply_t<T>();
}