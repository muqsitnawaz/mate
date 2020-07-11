
#pragma once

#include <tuple>

#include "../domain.hpp"

namespace mate
{
    template <Domain dmn>
    inline constexpr std::pair<dmn, dmn> modulus_bounds(dmn modulus) noexcept
    {
        const auto bound = subtract(modulus, static_cast<dmn>(1));
        if constexpr (meta_::is_signed_integral_t<dmn>())
        {
            return std::make_pair(-bound, bound);
        }
        else if constexpr (meta_::is_unsigned_integral_t<dmn>())
        {
            return std::make_pair(0, bound);
        }
    }

    template <Domain dmn>
    inline constexpr dmn modulus_width(dmn modulus) noexcept
    {
        const auto[lb, ub] = modulus_bounds(modulus);
        if constexpr (meta_::is_signed_integral_t<dmn>())
        {
            return ub + abs(lb) + 1;
        }
        else if constexpr (meta_::is_unsigned_integral_t<dmn>())
        {
            return ub;
        }
    }
}