
#pragma once

#include "domain.hpp"

#include "mate/arithmetic/abs.hpp"
#include "mate/arithmetic/subtract.hpp"

#include "utility/type.hpp"

namespace mate
{
    template <Domain dmn>
    class Modulus
    {
    public:
        using dmn_type = dmn;

    private:
        dmn value_;

    public:
        inline constexpr Modulus(dmn value) : value_(abs(value)) {}

        inline constexpr dmn operator*() const noexcept { return value_; }

        inline constexpr dmn get() const noexcept { return value_; }

        inline constexpr std::pair<dmn, dmn> bounds() const noexcept
        {
            const auto bound = subtract(value_, static_cast<dmn>(1));
            if constexpr (meta_::is_signed_integral_t<dmn>())
            {
                return std::make_pair(-bound, bound);
            }
            else if constexpr (meta_::is_unsigned_integral_t<dmn>())
            {
                return std::make_pair(0, bound);
            }
            else
            {
                throw std::logic_error("Unimplemented.");
            }
        }

        inline constexpr dmn width() const noexcept
        {
            const auto[lb, ub] = bounds();
            if constexpr (meta_::is_signed_integral_t<dmn>())
            {
                return ub + abs(lb) + 1;
            }
            else if constexpr (meta_::is_unsigned_integral_t<dmn>())
            {
                return ub;
            }
            else
            {
                throw std::logic_error("Unimplemented.");
            }
        }
    };
}