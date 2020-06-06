
#pragma once

#include "mate/domain.hpp"
#include "mate/operation.hpp"

#include "mate/arithmetic/add.hpp"
#include "mate/arithmetic/multiply.hpp"

namespace mate
{
    template <Domain dmn, Operation opr>
    inline dmn compute(dmn op1, dmn op2)
    {
        if constexpr (is_add_t<opr>())
        {
            return add(op1, op2);
        }
        else
        {
            return multiply(op1, op2);
        }
    }
}