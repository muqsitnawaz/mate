
#pragma once

#include "mate/domain.hpp"
#include "mate/operation.hpp"

#include "mate/arithmetic/add.hpp"
#include "mate/arithmetic/multiply.hpp"
#include "mod.hpp"

namespace mate
{
    template <Domain dmn, Operation opr>
    inline constexpr dmn compute(dmn op1, dmn op2, dmn modulus)
    {
        if constexpr (meta_::is_add_v<opr>)
        {
            return mod(add(op1, op2), modulus);
        }
        else
        {
            return mod(multiply(op1, op2), modulus);
        }
    }
}