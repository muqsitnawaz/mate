
#pragma once

#include "domain.hpp"

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
        inline constexpr Modulus(dmn value) : value_(value) {}

        inline constexpr dmn value() noexcept { return value_; }
    };
}