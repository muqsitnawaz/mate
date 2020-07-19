
#pragma once

#include <ostream>

#include <type_traits>

namespace mate
{
    struct Addition {};
    struct Multiplication {};

    namespace meta_
    {
        template <typename T>
        inline constexpr bool is_add_v = std::is_same_v<T, Addition>;

        template <typename T>
        inline constexpr bool is_multiply_v = std::is_same_v<T, Multiplication>;
    }

    template <typename T>
    concept Operation = meta_::is_add_v<T> || meta_::is_multiply_v<T>;
}