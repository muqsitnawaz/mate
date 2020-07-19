
#pragma once

#include "mate/arithmetic/add.hpp"
#include "mate/arithmetic/multiply.hpp"
#include "mate/core/domain.hpp"
#include "mate/core/operation.hpp"

namespace mate
{
    template <Domain dmn, Operation opr>
    inline constexpr dmn apply(dmn op1, dmn op2)
    {
        if constexpr (meta_::is_add_v<opr>)
        {
            return add(op1, op2);
        }
        else
        {
            return multiply(op1, op2);
        }
    }

    template <Domain dmn, Operation opr>
    inline constexpr dmn apply(dmn op1, dmn op2, dmn modulus)
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