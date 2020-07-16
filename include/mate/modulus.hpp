
#pragma once

#include "domain.hpp"

#include "mate/arithmetic/abs.hpp"
#include "mate/arithmetic/subtract.hpp"

#include "utility/type.hpp"
#include "utility/mod.hpp"

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
        inline constexpr explicit Modulus(dmn value) : value_(abs(value)) {}

        inline constexpr operator dmn() const { return value_; }

        inline constexpr std::pair<dmn, dmn> bounds() const noexcept
        {
            return modulus_bounds(value_);
        }

        inline constexpr size_t width() const noexcept
        {
            return modulus_width(value_);
        }
    };
}