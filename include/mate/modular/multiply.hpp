
#pragma once

#include "mate/arithmetic/multiply.hpp"
#include "mate/core/domain.hpp"
#include "mate/modular/mod.hpp"

namespace mate
{
    template <Domain dmn>
    inline constexpr dmn multiply(dmn op1, dmn op2, dmn modulus) noexcept
    {
        // TODO: Change the implementation to use barret reduction.
        return mod(multiply(op1, op2), modulus);
    }
}