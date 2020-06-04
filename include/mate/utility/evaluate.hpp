
#pragma once

#include "../domain.hpp"
#include "../operation.hpp"

#include "../algorithm/add.hpp"
#include "../algorithm/multiply.hpp"

namespace mate
{
    template <Domain dmn, Operation opr>
    inline dmn evaluate(dmn op1, dmn op2)
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