
#pragma once

#include "mate/core/domain.hpp"
#include "mate/core/operation.hpp"

namespace mate
{
    template <Domain dmn, Operation opr>
    inline constexpr dmn get_identity()
    {
        if constexpr (std::is_integral<dmn>())
        {
            if constexpr (meta_::is_add_v<opr>)
            {
                // Additive identity.
                return static_cast<dmn>(0);
            }
            else
            {
                // Multiplicative identity.
                return static_cast<dmn>(1);
            }
        }
        else
        {
            throw std::logic_error("Unknown domain.");
        }
    }
}