
#pragma once

#include "mate/domain.hpp"

namespace mate
{
    template <Domain dmn>
    inline constexpr dmn mod(dmn value, dmn modulus)
    {
        return value % modulus;
    }
}