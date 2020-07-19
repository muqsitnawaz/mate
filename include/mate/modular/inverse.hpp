
#pragma once

#include "mate/core/concepts.hpp"
#include "mate/core/operation.hpp"

namespace mate
{
    template <UnsignedInteger dmn, Operation opr>
    inline constexpr dmn inverse(dmn value, dmn modulus) noexcept
    {
        if constexpr (meta_::is_add_v<opr>)
        {
            return mod(modulus - mod(value, modulus), modulus);
        }
        else
        {
            throw std::runtime_error("Multiplicative inverse is undefined over integers.");
        }
    }
}