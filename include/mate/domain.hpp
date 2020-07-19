
#pragma once

#include <type_traits>

namespace mate
{
    namespace meta_
    {
        template <typename T>
        inline constexpr bool is_signed_integer_v = std::is_integral_v<T> and std::is_signed_v<T>;

        template <typename T>
        inline constexpr bool is_unsigned_integer_v = std::is_integral_v<T> and std::is_unsigned_v<T>;
    }

    template <typename T>
    concept SignedInteger = meta_::is_signed_integer_v<T>;

    template <typename T>
    concept UnsignedInteger = meta_::is_unsigned_integer_v<T>;

    template <typename T>
    concept Integer = SignedInteger<T> or UnsignedInteger<T>;

    template <typename T>
    concept Domain = Integer<T>;
}