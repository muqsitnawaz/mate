
#pragma once

#include <type_traits>

namespace mate
{
    template <typename T>
    inline constexpr bool is_signed_integral_t() noexcept
    {
        return std::is_integral_v<T> && std::is_signed_v<T>;
    }

    template <typename T>
    concept SignedInteger = is_signed_integral_t<T>();

    template <typename T>
    inline constexpr bool is_unsigned_integral_t() noexcept
    {
        return std::is_integral_v<T> && std::is_unsigned_v<T>;
    }

    template <typename T>
    concept UnsignedInteger = is_unsigned_integral_t<T>();

    template <typename T>
    concept Domain = SignedInteger<T> || UnsignedInteger<T>;
}