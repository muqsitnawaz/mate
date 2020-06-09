
#pragma once

#include "mate/domain.hpp"
#include "mod.hpp"

namespace mate
{
    template <Domain dmn>
    inline constexpr dmn multiply(dmn op1, dmn op2, dmn modulus) noexcept
    {
        // TODO: Change the implementation to use barret reduction.
        return mod(op1 * op2, modulus);
    }
}