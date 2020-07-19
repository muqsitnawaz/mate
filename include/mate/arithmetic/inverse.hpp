
#pragma once

#include "mate/core/concepts.hpp"
#include "mate/core/operation.hpp"

namespace mate
{
    template <SignedInteger dmn, Operation opr>
    inline constexpr dmn inverse(dmn value) noexcept
    {
        if constexpr (meta_::is_add_v<opr>)
        {
            return -value;
        }
        else
        {
            throw std::runtime_error("Multiplicative inverse is undefined over integers.");
        }
    }
}