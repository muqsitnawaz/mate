
#pragma once

#include "mate/arithmetic/add.hpp"
#include "mate/core/domain.hpp"
#include "mate/modular/mod.hpp"

namespace mate
{
    template <Domain dmn>
    inline constexpr dmn add(dmn op1, dmn op2, dmn modulus) noexcept
    {
        return mod(add(op1, op2), modulus);
    }
}