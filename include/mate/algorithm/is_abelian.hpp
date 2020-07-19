
#pragma once

#include "mate/algebra/group.hpp"

namespace mate
{
    template <Domain dmn, Operation opr>
    inline constexpr auto is_abelian(group<dmn, opr>) noexcept
    {
        if constexpr (std::is_integral_v<dmn>)
        {
            return true;
        }
        else
        {
            throw std::logic_error("Unimplemented.");
        }
    }
}