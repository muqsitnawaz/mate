
#pragma once

#include <type_traits>

namespace mate
{
    namespace meta_
    {
        template <typename T>
        inline constexpr bool is_signed_integral_t() noexcept
        {
            return std::is_integral_v<T> && std::is_signed_v<T>;
        }

        template <typename T>
        inline constexpr bool is_unsigned_integral_t() noexcept
        {
            return std::is_integral_v<T> && std::is_unsigned_v<T>;
        }
    }

    template <typename T>
    concept SignedInteger = meta_::is_signed_integral_t<T>();

    template <typename T>
    concept UnsignedInteger = meta_::is_unsigned_integral_t<T>();

    template <typename T>
    concept Domain = SignedInteger<T> || UnsignedInteger<T>;
}