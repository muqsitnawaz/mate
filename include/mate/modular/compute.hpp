
#pragma once

#include "mate/core/domain.hpp"
#include "mate/core/operation.hpp"
#include "mate/modular/add.hpp"
#include "mate/modular/multiply.hpp"

namespace mate
{
    template <Domain dmn, Operation opr>
    inline constexpr dmn compute(dmn op1, dmn op2, dmn modulus)
    {
        // TODO: Change calls below to use modular versions.
        if constexpr (meta_::is_add_v<opr>)
        {
            return add(op1, op2, modulus);
        }
        else
        {
            return multiply(op1, op2, modulus);
        }
    }
}