
#pragma once

#include "mate/domain.hpp"

namespace mate
{
    template <Domain dmn>
    inline constexpr dmn subtract(dmn op1, dmn op2) noexcept
    {
        return op1 - op2;
    }
}