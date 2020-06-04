
#pragma once

#include "../domain.hpp"

namespace mate
{
    template <Domain domain>
    inline domain add(domain op1, domain op2) noexcept
    {
        return op1 + op2;
    }
}